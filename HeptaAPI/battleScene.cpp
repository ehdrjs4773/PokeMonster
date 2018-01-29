#include "stdafx.h"
#include "battleScene.h"



battleScene::battleScene()
	: _UI(NULL)
{
}


battleScene::~battleScene()
{
}

HRESULT battleScene::init()
{
	// 적 타입 가져오기 (나중에 DATABASE 이용해서 가져올 생각)
	//if (_enemyType == ENEMY_WILD)
	//	;
	//else if (_enemyType == ENEMY_TRAINNER)
	//{
	//	string tempPath = ".\\bmps\\battleScene\\" + _destScene + "_enemy.bmp";
	//	IMAGEMANAGER->addImage(_destScene + "_enemy", tempPath.c_str(), POKEMON_WIDTH, POKEMON_HEIGHT, false, true, MAGENTA);
	//}
	_enemyType = ENEMY_WILD;
	
	// 내부저장소(메모리)에서 포켓몬 가져오기
	if (DATABASE->getVPlayerPokemon()->size() == 0) return E_FAIL;

	_playerPokemon = DATABASE->getVPlayerPokemon();
	_enemyPokemon = DATABASE->getVEnemyPokemon();

	// 플레이어가 맨 처음 내보낼 포켓몬 선택
	// 맨 처음부터 차례로 돌면서 HP가 0 아래가 아닌 포켓몬을 찾음
	_playerCurrentPokemon = 0;
	while ((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP() <= 0)
	{
		_playerCurrentPokemon++;

		// 플레이어 포켓몬은 차례로 0부터 5까지 가능
		// 현재 플레이어 포켓몬이 6이상이라면 모든 포켓몬이 죽어있다는 것 이므로 오류를 내뱉음
		if (_playerCurrentPokemon >= 6)
			return E_FAIL;

		// 또한 맨 처음 나가야할 포켓몬이 벡터 사이즈보다 크거나 같다면 역시 모든 포켓몬이 죽어있다는 뜻이므로 오류!!!!
		if (_playerCurrentPokemon >= _playerPokemon->size())
			return E_FAIL;
	}

	// 적은 반드시 맨 처음 몬스터부터 꺼냄(체육관 관장들은 플레이어가 이기지 못한 채로 전투가 끝나면 모든 포켓몬 체력이 초기화되므로)
	_enemyCurrentPokemon = 0;
	
	// 플레이어가 경험치를 획득하였는가?
	_isGetEXP = false;

	_sequence = BATTLE_INTRO;
	_fight = PLAYER_ATTACK;
	_end = END_END;

	// UI 초기화
	if (_UI == NULL)
		_UI = new battleSceneUI;
	_UI->setMemoryAddressLink(this);
	_UI->init();

	// 사용할 이미지 등록
	IMAGEMANAGER->addFrameImage("battle_player", ".\\bmps\\battleScene\\battle_player.bmp", POKEMON_WIDTH * 8, POKEMON_HEIGHT, 8, 1, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("battle_player_ball", ".\\bmps\\battleScene\\battle_player_ball.bmp", POKEMON_WIDTH * 8, POKEMON_HEIGHT, 8, 1, false, true, MAGENTA);

	// 테스트용
	_playerImageRect = RectMakeCenter(LIMIT_X_LEFT - POKEMON_WIDTH / 2, LIMIT_Y_BOTTOM - POKEMON_HEIGHT / 2, POKEMON_WIDTH, POKEMON_HEIGHT);
	_enemyImageRect = RectMakeCenter(LIMIT_X_RIGHT + POKEMON_WIDTH / 2, LIMIT_Y_TOP + POKEMON_HEIGHT / 2, POKEMON_WIDTH, POKEMON_HEIGHT);

	_introTime = 0;
	_frameTime = 0;
	_frameX = 0;

	DIALOGUE->loadingTextFile(".\\textData\\battleScene_intro.txt");
	DIALOGUE->setPoint(PointMake(LIMIT_X_LEFT + 22, LIMIT_Y_BOTTOM + 5));

	if (_enemyType == ENEMY_WILD)
		DIALOGUE->replaceAll("@", "야생의 " + (*_enemyPokemon)[_enemyCurrentPokemon]->getName());
	else if (_enemyType == ENEMY_TRAINNER)
		;

	DIALOGUE->replaceAll("#", (*_playerPokemon)[_playerCurrentPokemon]->getName());

	// 프로그레스바
	_enemyHPBar = new progressBar;
	_enemyHPBar->init("hpBar", 155, 129, 72, 4, (*_enemyPokemon)[_enemyCurrentPokemon]->getCurrentHP(), (*_enemyPokemon)[_enemyCurrentPokemon]->getMaxHP());
	_playerHPBar = new progressBar;
	_playerHPBar->init("hpBar", 316, 225, 72, 4, (*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxHP());
	_playerEXPBar = new progressBar;
	_playerEXPBar->init("expBar", 244, 250, 144, 3);

	_playerChangePokemonNum = INT_MAX;
	_enemyChangePokemonNum = INT_MAX;

	// 플레이어, 적 죽었는지 초기화 == 일단 둘 다 false
	_enemyIsDie = false;
	_playerIsDie = false;

	return S_OK;
}

void battleScene::release()
{

}

void battleScene::update()
{
	switch (_sequence)
	{
		case BATTLE_INTRO:
			if (_playerImageRect.left < LIMIT_X_LEFT)
			{
				_playerImageRect.left++;
				_playerImageRect.right++;
			}
			if (_enemyImageRect.right > LIMIT_X_RIGHT)
			{
				_enemyImageRect.left--;
				_enemyImageRect.right--;
			}
			else
			{
				_introTime++;
				if (_introTime % 70 == 0)
				{
					_sequence = BATTLE_BALLTHROW;
					DIALOGUE->setCurrentLine(DIALOGUE->getCurrentLine() + 2);
				}
			}
		break;
		
		case BATTLE_BALLTHROW:
			if (_playerImageRect.right > LIMIT_X_LEFT)
			{
				_playerImageRect.left--;
				_playerImageRect.right--;
			}
			if (_enemyType == ENEMY_TRAINNER)
			{
				if (_enemyImageRect.left < LIMIT_X_RIGHT)
				{
					_enemyImageRect.left++;
					_enemyImageRect.right++;
				}
			}

			this->frameUpdate();
		break;

		case BATTLE_SELECT:
			_frameTime = 0;
			_isGetEXP = false;
		break;

		case BATTLE_FIGHT:
			_frameTime++;
			switch (_fight)
			{
				case PLAYER_ATTACK:
					if (_playerChangePokemonNum != INT_MAX)
					{
						_fight = PLAYER_CHANGE;
						return;
					}

					if ((*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()]->getType() == SKILL_PHYSIC)
					{
						if (_frameTime <= 20)
						{
							_playerImageRect.left += 2;
							_playerImageRect.right += 2;
							_playerImageRect.top--;
							_playerImageRect.bottom--;

							if (_frameTime == 20)
								(*_enemyPokemon)[_enemyCurrentPokemon]->hitDamager(calcDamage((*_playerPokemon)[_playerCurrentPokemon], (*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()], (*_enemyPokemon)[_enemyCurrentPokemon]));
						}
						else if (_frameTime <= 40)
						{
							_playerImageRect.left -= 2;
							_playerImageRect.right -= 2;
							_playerImageRect.top++;
							_playerImageRect.bottom++;
						}
						else
						{
							if (_enemyHPBar->isChangeDone((*_enemyPokemon)[_enemyCurrentPokemon]->getCurrentHP(), (*_enemyPokemon)[_enemyCurrentPokemon]->getMaxHP()))
							{
								(*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()]->useSkill();

								if ((*_enemyPokemon)[_enemyCurrentPokemon]->getCurrentHP() <= 0)
								{
									if (!_isGetEXP)
									{
										float type;
										if (_enemyType == ENEMY_WILD)
											type = 1;
										else if (_enemyType == ENEMY_TRAINNER)
											type = 1.5;

										(*_playerPokemon)[_playerCurrentPokemon]->expPlus(type * 144 * (*_enemyPokemon)[_enemyCurrentPokemon]->getLevel() / 7);

										_isGetEXP = true;
									}

									if (_playerEXPBar->isChangeDone((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP()))
									{
										if ((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP() >= (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP())
										{
											(*_playerPokemon)[_playerCurrentPokemon]->levelUp();
											_playerEXPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP());
										}

										_sequence = BATTLE_END;
										_end = ENEMY_DIE;
										_fight = PLAYER_ATTACK;
										DIALOGUE->loadingTextFile(".\\textData\\battleScene_end_die.txt");
										DIALOGUE->replaceAll("#", (*_enemyPokemon)[_enemyCurrentPokemon]->getName());
									}
								}
								else
								{
									_fight = ENEMY_ATTACK;
									DIALOGUE->loadingTextFile(".\\textData\\battleScene_fight.txt");
									DIALOGUE->replaceAll("@", (*_enemyPokemon)[_enemyCurrentPokemon]->getName());
									DIALOGUE->replaceAll("#", (*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()]->getName());
									_frameTime = 0;

									_UI->selectReset();
								}
							}
						}
					}
					else if ((*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()]->getType() == SKILL_SPECIAL)
					{
						ELEMENT tempEl = (*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()]->getElement();
						string skillKey;
						if ((*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()]->getName() == "고무고무난타")
							skillKey = "고무고무난타";
						else
							skillKey = this->elementString(tempEl) + "_player";
						if (_frameTime == 1)
							EFFECTMANAGER->play(skillKey, WINSIZEX / 2, WINSIZEY / 2);
						else
						{
							if (EFFECTMANAGER->isEffectEnd(skillKey))
							{
								if (_enemyHPBar->isChangeDone((*_enemyPokemon)[_enemyCurrentPokemon]->getCurrentHP(), (*_enemyPokemon)[_enemyCurrentPokemon]->getMaxHP()))
								{
									(*_enemyPokemon)[_enemyCurrentPokemon]->hitDamager(calcDamage((*_playerPokemon)[_playerCurrentPokemon], (*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()], (*_enemyPokemon)[_enemyCurrentPokemon]));
									(*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()]->useSkill();

									if ((*_enemyPokemon)[_enemyCurrentPokemon]->getCurrentHP() <= 0)
									{
										if (!_isGetEXP)
										{
											float type;
											if (_enemyType == ENEMY_WILD)
												type = 1;
											else if (_enemyType == ENEMY_TRAINNER)
												type = 1.5;

											(*_playerPokemon)[_playerCurrentPokemon]->expPlus(type * 144 * (*_enemyPokemon)[_enemyCurrentPokemon]->getLevel() / 7);

											_isGetEXP = true;
										}

										if (_playerEXPBar->isChangeDone((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP()))
										{
											if ((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP() >= (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP())
											{
												(*_playerPokemon)[_playerCurrentPokemon]->levelUp();
												_playerEXPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP());
											}

											_sequence = BATTLE_END;
											_end = ENEMY_DIE;
											_fight = PLAYER_ATTACK;
											DIALOGUE->loadingTextFile(".\\textData\\battleScene_end_die.txt");
											DIALOGUE->replaceAll("#", (*_enemyPokemon)[_enemyCurrentPokemon]->getName());
										}
									}
									else
									{
										_fight = ENEMY_ATTACK;
										DIALOGUE->loadingTextFile(".\\textData\\battleScene_fight.txt");
										DIALOGUE->replaceAll("@", (*_enemyPokemon)[_enemyCurrentPokemon]->getName());
										DIALOGUE->replaceAll("#", (*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()]->getName());
										_frameTime = 0;

										_UI->selectReset();
									}
								}
							}
						}
					}
				break;
				
				case PLAYER_CHANGE:
					if (_playerCurrentPokemon != _playerChangePokemonNum &&
						_playerChangePokemonNum != INT_MAX)
					{
						_playerImageRect.left--;
						_playerImageRect.right--;

						if (_playerImageRect.right < LIMIT_X_LEFT)
						{
							_playerCurrentPokemon = _playerChangePokemonNum;
							_playerHPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxHP());
							_playerEXPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP());
							_playerChangePokemonNum = INT_MAX;
						}
					}
					else
					{
						_playerImageRect.left++;
						_playerImageRect.right++;

						if (_playerImageRect.left > LIMIT_X_LEFT)
						{
							_fight = ENEMY_ATTACK;
							_UI->setCurrentEnemySkill(RND->getInt((*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill().size()));
							// test
							_UI->setCurrentEnemySkill(0);
							DIALOGUE->loadingTextFile(".\\textData\\battleScene_fight.txt");
							DIALOGUE->replaceAll("@", (*_enemyPokemon)[_enemyCurrentPokemon]->getName());
							DIALOGUE->replaceAll("#", (*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()]->getName());
							_frameTime = 0;

							_UI->selectReset();
						}
					}
				break;
					
				case ENEMY_ATTACK:
					if (_enemyChangePokemonNum != INT_MAX)
					{
						_fight = ENEMY_CHANGE;
						return;
					}

					if ((*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()]->getType() == SKILL_PHYSIC)
					{
						if (_frameTime <= 20)
						{
							_enemyImageRect.left -= 2;
							_enemyImageRect.right -= 2;
							_enemyImageRect.top++;
							_enemyImageRect.bottom++;

							if (_frameTime == 20)
								(*_playerPokemon)[_playerCurrentPokemon]->hitDamager(calcDamage((*_enemyPokemon)[_enemyCurrentPokemon], (*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()], (*_playerPokemon)[_playerCurrentPokemon]));
						}
						else if (_frameTime <= 40)
						{
							_enemyImageRect.left += 2;
							_enemyImageRect.right += 2;
							_enemyImageRect.top--;
							_enemyImageRect.bottom--;
						}
						else
						{
							if (_playerHPBar->isChangeDone((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxHP()))
							{
								(*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()]->useSkill();

								if ((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP() <= 0)
								{
									_sequence = BATTLE_END;
									_end = PLAYER_DIE;
									_fight = PLAYER_ATTACK;
									DIALOGUE->loadingTextFile(".\\textData\\battleScene_end_die.txt");
									DIALOGUE->replaceAll("#", (*_playerPokemon)[_playerCurrentPokemon]->getName());
								}
								else
								{
									_sequence = BATTLE_SELECT;
									_fight = PLAYER_ATTACK;
								}
							}
						}
					}
					else if ((*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()]->getType() == SKILL_SPECIAL)
					{
						ELEMENT tempEl = (*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()]->getElement();
						if (_frameTime == 1)
							EFFECTMANAGER->play(this->elementString(tempEl) + "_enemy", WINSIZEX / 2, WINSIZEY / 2);
						else
						{
							if (EFFECTMANAGER->isEffectEnd(this->elementString(tempEl) + "_enemy"))
							{
								if (_playerHPBar->isChangeDone((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxHP()))
								{
									(*_playerPokemon)[_playerCurrentPokemon]->hitDamager(calcDamage((*_enemyPokemon)[_enemyCurrentPokemon], (*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()], (*_playerPokemon)[_playerCurrentPokemon]));
									(*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()]->useSkill();

									if ((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP() <= 0)
									{
										_sequence = BATTLE_END;
										_end = PLAYER_DIE;
										_fight = PLAYER_ATTACK;
										DIALOGUE->loadingTextFile(".\\textData\\battleScene_end_die.txt");
										DIALOGUE->replaceAll("#", (*_playerPokemon)[_playerCurrentPokemon]->getName());
									}
									else
									{
										_sequence = BATTLE_SELECT;
										_fight = PLAYER_ATTACK;
									}
								}
							}
						}
					}
				break;
			}
		break;

		case BATTLE_END:
			_UI->selectReset();
			switch (_end)
			{
				case ENEMY_DIE:
					if ((*_enemyPokemon)[_enemyCurrentPokemon]->getCurrentHP() <= 0)
					{
						_enemyImageRect.left += 3;
						_enemyImageRect.right += 3;

						if (_enemyImageRect.left > LIMIT_X_RIGHT)
						{
							_enemyCurrentPokemon++;
							if (_enemyCurrentPokemon >= _enemyPokemon->size())
							{
								_enemyCurrentPokemon--;
								_sequence = BATTLE_FINAL;
								DIALOGUE->loadingTextFile(".\\textData\\battleScene_final_win.txt");
								_frameTime = 0;
							}
							else
							{
								_end = END_CHANGE;
								DIALOGUE->loadingTextFile(".\\textData\\battleScene_end_change.txt");
								DIALOGUE->replaceAll("#", "적");
								DIALOGUE->replaceAll("@", (*_enemyPokemon)[_enemyCurrentPokemon]->getName());
								_enemyHPBar->setGauge((*_enemyPokemon)[_enemyCurrentPokemon]->getCurrentHP(), (*_enemyPokemon)[_enemyCurrentPokemon]->getMaxHP());
							}
						}
					}
				break;

				case PLAYER_DIE:
					if ((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP() <= 0)
					{
						_playerImageRect.left -= 3;
						_playerImageRect.right -= 3;

						if (_playerImageRect.right < LIMIT_X_LEFT)
						{
							_playerCurrentPokemon++;
							if (_playerCurrentPokemon >= _playerPokemon->size())
							{
								_playerCurrentPokemon--;
								_sequence = BATTLE_FINAL;
								DIALOGUE->loadingTextFile(".\\textData\\battleScene_final_lose.txt");
								_frameTime = 0;
							}
							else
							{
								_end = END_CHANGE;
								DIALOGUE->loadingTextFile(".\\textData\\battleScene_end_change.txt");
								DIALOGUE->replaceAll("#", "나");
								DIALOGUE->replaceAll("@", (*_playerPokemon)[_playerCurrentPokemon]->getName());
								_playerHPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxHP());
								_playerEXPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP());
							}
						}
					}
					break;

				case END_CHANGE:
					if (_playerImageRect.left < LIMIT_X_LEFT)
					{
						_playerImageRect.left++;
						_playerImageRect.right++;
					}
					if (_enemyImageRect.right > LIMIT_X_RIGHT)
					{
						_enemyImageRect.left--;
						_enemyImageRect.right--;
					}

					if (_playerImageRect.left >= LIMIT_X_LEFT &&
						_enemyImageRect.right <= LIMIT_X_RIGHT)
					{
						_sequence = BATTLE_SELECT;
					}
				break;
			}
		break;

		case BATTLE_FINAL:
			if (_UI->isRunAway())
			{
				if (_playerImageRect.right > LIMIT_X_LEFT)
				{
					_playerImageRect.left -= 2;
					_playerImageRect.right -= 2;

				}
				else
				{
					// test
					SCENEMANAGER->init("월드맵씬");
					SCENEMANAGER->changeScene(_destScene);
				}
			}
			else
			{
				_frameTime++;
				if (_frameTime % 50 == 0)
				{
					// test
					SCENEMANAGER->init("월드맵씬");
					SCENEMANAGER->changeScene(_destScene);
				}
			}
		break;
	}
	DIALOGUE->update();
	_UI->update();

	_enemyHPBar->setGauge((*_enemyPokemon)[_enemyCurrentPokemon]->getCurrentHP(), (*_enemyPokemon)[_enemyCurrentPokemon]->getMaxHP(), true);
	_playerHPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxHP(), true);
	_playerEXPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP(), false);

	EFFECTMANAGER->update();
}

void battleScene::render()
{
	switch (_sequence)
	{
		case BATTLE_INTRO:
			DIALOGUE->render(getMemDC());
			IMAGEMANAGER->findImage("battle_player")->frameRender(getMemDC(), _playerImageRect.left, _playerImageRect.top, _frameX, 0);
		break;
		
		case BATTLE_BALLTHROW:
			DIALOGUE->render(getMemDC());
			IMAGEMANAGER->findImage("battle_player_ball")->frameRender(getMemDC(), LIMIT_X_LEFT, LIMIT_Y_BOTTOM - POKEMON_HEIGHT, _frameX, 0);
			IMAGEMANAGER->findImage("battle_player")->frameRender(getMemDC(), _playerImageRect.left, _playerImageRect.top, _frameX, 0);
		break;
		
		case BATTLE_SELECT:
		break;
		
		case BATTLE_FIGHT:
			DIALOGUE->render(getMemDC());
		break;
		
		case BATTLE_END:
			DIALOGUE->render(getMemDC());
		break;
		
		case BATTLE_FINAL:
			DIALOGUE->render(getMemDC());
		break;
	}

	if (_sequence != BATTLE_INTRO &&
		_sequence != BATTLE_BALLTHROW)
		IMAGEMANAGER->findImage((*_playerPokemon)[_playerCurrentPokemon]->getName() + "_back")->frameRender(getMemDC(), _playerImageRect.left, _playerImageRect.top, _frameX, 0);
	IMAGEMANAGER->findImage((*_enemyPokemon)[_enemyCurrentPokemon]->getName() + "_front")->frameRender(getMemDC(), _enemyImageRect.left, _enemyImageRect.top);

	_UI->render();

	_enemyHPBar->render();
	_playerHPBar->render();
	_playerEXPBar->render();

	EFFECTMANAGER->render(getMemDC());
}

void battleScene::frameUpdate()
{
	_frameTime++;
	switch (_sequence)
	{
		case BATTLE_BALLTHROW:
			if (_frameTime % 12 == 0)
			{
				_frameX++;
				if (_frameX > IMAGEMANAGER->findImage("battle_player")->getMaxFrameX())
				{
					_frameX = 0;
					_frameTime = 0;

					_sequence = BATTLE_SELECT;

					_playerImageRect.left = LIMIT_X_LEFT;
					_playerImageRect.right = _playerImageRect.left + POKEMON_WIDTH;


					if (_enemyType == ENEMY_TRAINNER)
					{
						_enemyImageRect.right = LIMIT_X_RIGHT;
						_enemyImageRect.left = _enemyImageRect.right - POKEMON_WIDTH;
					}
				}
			}
		break;
	}
}

string battleScene::elementString(ELEMENT el)
{
	string temp;
	switch (el)
	{
	case ELEMENT_NORMAL:
		temp = "노말";
		break;

	case ELEMENT_FIRE:
		temp = "불";
		break;

	case ELEMENT_WATER:
		temp = "물";
		break;

	case ELEMENT_ELECTRIC:
		temp = "전기";
		break;

	case ELEMENT_PLANT:
		temp = "풀";
		break;

	case ELEMENT_ICE:
		temp = "얼음";
		break;

	case ELEMENT_FIGHT:
		temp = "격투";
		break;

	case ELEMENT_POISON:
		temp = "독";
		break;

	case ELEMENT_EARTH:
		temp = "땅";
		break;

	case ELEMENT_WING:
		temp = "비행";
		break;

	case ELEMENT_ESPER:
		temp = "에스퍼";
		break;

	case ELEMENT_INSECT:
		temp = "벌레";
		break;

	case ELEMENT_ROCK:
		temp = "바위";
		break;

	case ELEMENT_GHOST:
		temp = "유령";
		break;

	case ELEMENT_DRAGON:
		temp = "용";
		break;

	case ELEMENT_DARK:
		temp = "악";
		break;

	case ELEMENT_STEEL:
		temp = "강철";
		break;
	}

	return temp;
}

// 배틀할 때 데미지를 어떻게 해야하나 판정해주는 함수
DAMAGE_JUDGEMENT battleScene::judgement(ELEMENT attackerSkill, ELEMENT defencer)
{
	// 어태커가 쓴 스킬의 속성과 방어하는 포켓몬의 속성에 따라 다른 값을 리턴
	// 순서
	// 데미지 두 배
	// 데미지 절반
	// 데미지 없음
	// 참고자료 : 건하가 올려준 속성 표
	switch (attackerSkill)
	{
		case ELEMENT_NORMAL:
			if (defencer == ELEMENT_ROCK ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_GHOST)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_FIRE:
			if (defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_ICE ||
				defencer == ELEMENT_INSECT ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_DOUBLE;

			 else if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_WATER ||
				defencer == ELEMENT_ROCK ||
				defencer == ELEMENT_DRAGON)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_WATER:
			if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_EARTH ||
				defencer == ELEMENT_ROCK)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_WATER ||
				defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_DRAGON)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_ELECTRIC:
			if (defencer == ELEMENT_WATER ||
				defencer == ELEMENT_WING)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_ELECTRIC ||
				defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_DRAGON)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_EARTH)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_PLANT:
			if (defencer == ELEMENT_WATER ||
				defencer == ELEMENT_EARTH ||
				defencer == ELEMENT_ROCK)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_POISON ||
				defencer == ELEMENT_WING ||
				defencer == ELEMENT_INSECT ||
				defencer == ELEMENT_DRAGON ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_ICE:
			if (defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_EARTH ||
				defencer == ELEMENT_WING ||
				defencer == ELEMENT_DRAGON)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_WATER ||
				defencer == ELEMENT_ICE ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_FIGHT:
			if (defencer == ELEMENT_NORMAL ||
				defencer == ELEMENT_ICE ||
				defencer == ELEMENT_ROCK ||
				defencer == ELEMENT_DARK ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_POISON ||
				defencer == ELEMENT_WING ||
				defencer == ELEMENT_ESPER ||
				defencer == ELEMENT_INSECT)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_GHOST)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_POISON:
			if (defencer == ELEMENT_PLANT)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_POISON ||
				defencer == ELEMENT_EARTH ||
				defencer == ELEMENT_ROCK ||
				defencer == ELEMENT_GHOST)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_STEEL)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_EARTH:
			if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_ELECTRIC ||
				defencer == ELEMENT_POISON ||
				defencer == ELEMENT_ROCK ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_INSECT)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_WING)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_WING:
			if (defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_FIGHT ||
				defencer == ELEMENT_INSECT)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_ELECTRIC ||
				defencer == ELEMENT_ROCK ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_ESPER:
			if (defencer == ELEMENT_FIGHT ||
				defencer == ELEMENT_POISON)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_ESPER ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_DARK)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_INSECT:
			if (defencer == ELEMENT_PLANT ||
				defencer == ELEMENT_ESPER ||
				defencer == ELEMENT_DARK)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_FIGHT ||
				defencer == ELEMENT_POISON ||
				defencer == ELEMENT_WING ||
				defencer == ELEMENT_GHOST ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_ROCK:
			if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_ICE ||
				defencer == ELEMENT_WING ||
				defencer == ELEMENT_INSECT)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_FIGHT ||
				defencer == ELEMENT_EARTH ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_GHOST:
			if (defencer == ELEMENT_ESPER ||
				defencer == ELEMENT_GHOST)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_DARK ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;

			else if (defencer == ELEMENT_NORMAL)
				return DAMAGE_NONE;
		break;
		
		case ELEMENT_DRAGON:
			if (defencer == ELEMENT_DRAGON)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_DARK:
			if (defencer == ELEMENT_ESPER ||
				defencer == ELEMENT_GHOST)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_FIGHT ||
				defencer == ELEMENT_DARK ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
		
		case ELEMENT_STEEL:
			if (defencer == ELEMENT_ICE ||
				defencer == ELEMENT_ROCK)
				return DAMAGE_DOUBLE;

			else if (defencer == ELEMENT_FIRE ||
				defencer == ELEMENT_WATER ||
				defencer == ELEMENT_ELECTRIC ||
				defencer == ELEMENT_STEEL)
				return DAMAGE_HALF;
		break;
	}

	// 위 스위치문의 경우 특수한 경우(데미지 없음, 데미지 절반, 데미지 두 배)만 처리
	// 나머지는 전부 일반 데미지
	return DAMAGE_NORMAL;
}

int battleScene::calcDamage(pokemon* a, skill* s, pokemon* d)
{
	// 자속보정 == 공격하는 포켓몬과 사용하는 스킬의 속성이 일치하는지 여부
	int flux;
	if (a->getElement() == s->getElement())
		flux = 1.5;
	else
		flux = 1;

	// 속성 보정
	float jud;
	if (this->judgement(s->getElement(), d->getElement()) == DAMAGE_NONE)
		jud = 0;
	else if (this->judgement(s->getElement(), d->getElement()) == DAMAGE_HALF)
		jud = 0.5;
	else if (this->judgement(s->getElement(), d->getElement()) == DAMAGE_NORMAL)
		jud = 1;
	else if (this->judgement(s->getElement(), d->getElement()) == DAMAGE_DOUBLE)
		jud = 2;

	// 랜덤수 (85~100)
	// 0~9999숫자 뽑기
	int rnd;
	int percent = RND->getInt(10000);
	if (percent < 6152)
	{
		int arr[] = { 85, 87, 89, 90, 92, 94, 96, 98 };
		rnd = arr[RND->getInt(8)];
	}
	else if (percent < 9743)
	{
		int arr[] = { 86, 88, 91, 93, 95, 97, 99 };
		rnd = arr[RND->getInt(7)];
	}
	else
		rnd = 100;

	int damage;
	if (s->getType() == SKILL_PHYSIC)
	{
		damage = (s->getPower() * a->getAtk() * (a->getLevel() * 2 / 5 + 2) / d->getDef() / 50 + 2) * flux * jud * jud * rnd / 255;
	}
	else if (s->getType() == SKILL_SPECIAL)
	{
		damage = (s->getPower() * a->getSpecial() * (a->getLevel() * 2 / 5 + 2) / d->getDef() / 50 + 2) * flux * jud * jud * rnd / 255;
	}

	return damage;
}