#include "stdafx.h"
#include "battleScene.h"
#include "stageManager.h"
#include "player.h"


battleScene::battleScene()
	: _UI(NULL)
{
}


battleScene::~battleScene()
{
}

HRESULT battleScene::init(int stage)
{
	// �� Ÿ�� �������� (���߿� DATABASE �̿��ؼ� ������ ����)
	if (_enemyType == ENEMY_WILD)
		;
	else if (_enemyType == ENEMY_TRAINNER)
	{
		string tempPath = ".\\bmps\\battleScene\\enemy\\" + _destScene + "_enemy.bmp";
		IMAGEMANAGER->addImage(_destScene + "_enemy", tempPath.c_str(), POKEMON_WIDTH, POKEMON_HEIGHT, false, true, MAGENTA);
	}
	
	// ���������(�޸�)���� ���ϸ� ��������
	if (DATABASE->getVPlayerPokemon()->size() == 0) return E_FAIL;

	_playerPokemon = DATABASE->getVPlayerPokemon();
	_enemyPokemon = DATABASE->getVEnemyPokemon();

	// �÷��̾ �� ó�� ������ ���ϸ� ����
	// �� ó������ ���ʷ� ���鼭 HP�� 0 �Ʒ��� �ƴ� ���ϸ��� ã��
	_playerCurrentPokemon = 0;
	while ((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP() <= 0)
	{
		_playerCurrentPokemon++;

		// �÷��̾� ���ϸ��� ���ʷ� 0���� 5���� ����
		// ���� �÷��̾� ���ϸ��� 6�̻��̶�� ��� ���ϸ��� �׾��ִٴ� �� �̹Ƿ� ������ ������
		if (_playerCurrentPokemon >= 6)
			return E_FAIL;

		// ���� �� ó�� �������� ���ϸ��� ���� ������� ũ�ų� ���ٸ� ���� ��� ���ϸ��� �׾��ִٴ� ���̹Ƿ� ����!!!!
		if (_playerCurrentPokemon >= _playerPokemon->size())
			return E_FAIL;
	}

	// ���� �ݵ�� �� ó�� ���ͺ��� ����(ü���� ������� �÷��̾ �̱��� ���� ä�� ������ ������ ��� ���ϸ� ü���� �ʱ�ȭ�ǹǷ�)
	_enemyCurrentPokemon = 0;
	
	// �÷��̾ ����ġ�� ȹ���Ͽ��°�?
	_isGetEXP = false;

	_sequence = BATTLE_INTRO;
	_fight = PLAYER_ATTACK;
	_end = END_END;

	// ����� �̹��� ���
	IMAGEMANAGER->addFrameImage("battle_player", ".\\bmps\\battleScene\\battle_player.bmp", POKEMON_WIDTH * 8, POKEMON_HEIGHT, 8, 1, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("battle_player_ball", ".\\bmps\\battleScene\\battle_player_ball.bmp", POKEMON_WIDTH * 8, POKEMON_HEIGHT, 8, 1, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("pokeball_shake", ".\\bmps\\battleScene\\pokeball_shake.bmp", 70 * 3, 60, 3, 1, false, true, MAGENTA);

	// �׽�Ʈ��
	_playerImageRect = RectMakeCenter(LIMIT_X_LEFT - POKEMON_WIDTH / 2, LIMIT_Y_BOTTOM - POKEMON_HEIGHT / 2, POKEMON_WIDTH, POKEMON_HEIGHT);
	_enemyImageRect = RectMakeCenter(LIMIT_X_RIGHT + POKEMON_WIDTH / 2, LIMIT_Y_TOP + POKEMON_HEIGHT / 2, POKEMON_WIDTH, POKEMON_HEIGHT);

	_introTime = 0;
	_frameTime = 0;
	_attackTime = 0;
	_frameX = 0;

	DIALOGUE->loadingTextFile(".\\textData\\battleScene_intro.txt");
	DIALOGUE->setPoint(PointMake(LIMIT_X_LEFT + 22, LIMIT_Y_BOTTOM + 5));

	if (_enemyType == ENEMY_WILD)
		DIALOGUE->replaceAll("@", "�߻��� " + (*_enemyPokemon)[_enemyCurrentPokemon]->getName());
	else if (_enemyType == ENEMY_TRAINNER)
	{
		this->setGymLeaderName(stage);
	}

	DIALOGUE->replaceAll("#", (*_playerPokemon)[_playerCurrentPokemon]->getName());

	// ���α׷�����
	_enemyHPBar = new progressBar;
	_enemyHPBar->init("hpBar", 155, 129, 72, 4, (*_enemyPokemon)[_enemyCurrentPokemon]->getCurrentHP(), (*_enemyPokemon)[_enemyCurrentPokemon]->getMaxHP());
	_playerHPBar = new progressBar;
	_playerHPBar->init("hpBar", 316, 225, 72, 4, (*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxHP());
	_playerEXPBar = new progressBar;
	_playerEXPBar->init("expBar", 244, 250, 144, 3);

	_playerChangePokemonNum = INT_MAX;
	_enemyChangePokemonNum = INT_MAX;

	// �÷��̾�, �� �׾����� �ʱ�ȭ == �ϴ� �� �� false
	_enemyIsDie = false;
	_playerIsDie = false;

	// UI �ʱ�ȭ
	if (_UI == NULL)
		_UI = new battleSceneUI;
	_UI->setMemoryAddressLink(this);
	_UI->init();

	return S_OK;
}

void battleScene::setGymLeaderName(int stage)
{
	switch (stage)
	{
		case 1:
			DIALOGUE->replaceAll("@", "�Ը�");
		break;
		
		case 2:
			DIALOGUE->replaceAll("@", "�絵");
		break;
		
		case 3:
			DIALOGUE->replaceAll("@", "����");
		break;
		
		case 4:
			DIALOGUE->replaceAll("@", "����");
		break;
		
		case 5:
			DIALOGUE->replaceAll("@", "����");
		break;
		
		case 6:
			DIALOGUE->replaceAll("@", "ȣ��");
		break;
		
		case 7:
			DIALOGUE->replaceAll("@", "���");
		break;
		
		case 8:
			DIALOGUE->replaceAll("@", "����");
		break;
		
		case 9:
			DIALOGUE->replaceAll("@", "�ù�");
		break;
		
		case 10:
			DIALOGUE->replaceAll("@", "����");
		break;
		
		case 11:
			DIALOGUE->replaceAll("@", "�ϸ�");
		break;
		
		case 12:
			DIALOGUE->replaceAll("@", "ī��");
		break;
		
		case 13:
			DIALOGUE->replaceAll("@", "����");
		break;
	}
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
			_attackTime = 0;
			_isGetEXP = false;
			_monsterBall = RectMake(LIMIT_X_LEFT - 70, LIMIT_Y_BOTTOM - 120, 70, 60);
			_enemyImageRect = RectMake(LIMIT_X_RIGHT - POKEMON_WIDTH, LIMIT_Y_TOP, POKEMON_WIDTH, POKEMON_HEIGHT);
			_isMonsterCatch = false;
		break;

		case BATTLE_FIGHT:
			_attackTime++;
			switch (_fight)
			{
				case PLAYER_CATCH:
					if (!_isMonsterCatch)
					{
						_frameX = 2;

						_monsterBall.left += 2;
						_monsterBall.right += 2;
						_monsterBall.top--;
						_monsterBall.bottom--;

						RECT temp;
						if (IntersectRect(&temp, &_monsterBall, &_enemyImageRect))
						{
							_isMonsterCatch = true;
							_monsterBall = RectMakeCenter(LIMIT_X_RIGHT - 60, _enemyImageRect.bottom - 30, 70, 60);
						}
					}
					else
					{
						this->frameUpdate();
					}
				break;

				case PLAYER_ATTACK:
					if (_playerChangePokemonNum != INT_MAX)
					{
						_fight = PLAYER_CHANGE;
						return;
					}

					if ((*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()]->getType() == SKILL_PHYSIC)
					{
						if (_attackTime <= 20)
						{
							_playerImageRect.left += 2;
							_playerImageRect.right += 2;
							_playerImageRect.top--;
							_playerImageRect.bottom--;

							if (_attackTime == 20)
							{
								(*_enemyPokemon)[_enemyCurrentPokemon]->hitDamager(calcDamage((*_playerPokemon)[_playerCurrentPokemon], (*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()], (*_enemyPokemon)[_enemyCurrentPokemon]));
								(*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()]->useSkill();
							}
						}
						else if (_attackTime <= 40)
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
											_playerEXPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP(), false);
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
									_attackTime = 0;

									_UI->selectReset();
								}
							}
						}
					}
					else if ((*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()]->getType() == SKILL_SPECIAL)
					{
						ELEMENT tempEl = (*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()]->getElement();
						string skillKey;
						if ((*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()]->getName() == "������Ÿ")
							skillKey = "������Ÿ";
						else
							skillKey = this->elementString(tempEl) + "_player";

						if (_attackTime == 1)
							EFFECTMANAGER->play(skillKey, WINSIZEX / 2, WINSIZEY / 2);
						else if (_attackTime == 2)
						{
							(*_enemyPokemon)[_enemyCurrentPokemon]->hitDamager(calcDamage((*_playerPokemon)[_playerCurrentPokemon], (*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()], (*_enemyPokemon)[_enemyCurrentPokemon]));
							(*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()]->useSkill();
						}
						else
						{
							if (EFFECTMANAGER->isEffectEnd(skillKey))
							{
								if (_enemyHPBar->isChangeDone((*_enemyPokemon)[_enemyCurrentPokemon]->getCurrentHP(), (*_enemyPokemon)[_enemyCurrentPokemon]->getMaxHP()))
								{
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
												_playerEXPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP(), false);
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
										_attackTime = 0;

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
							_playerHPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxHP(), true);
							_playerEXPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP(), false);
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
							DIALOGUE->loadingTextFile(".\\textData\\battleScene_fight.txt");
							DIALOGUE->replaceAll("@", (*_enemyPokemon)[_enemyCurrentPokemon]->getName());
							DIALOGUE->replaceAll("#", (*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()]->getName());
							_attackTime = 0;

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
						if (_attackTime <= 20)
						{
							_enemyImageRect.left -= 2;
							_enemyImageRect.right -= 2;
							_enemyImageRect.top++;
							_enemyImageRect.bottom++;

							if (_attackTime == 20)
							{
								(*_playerPokemon)[_playerCurrentPokemon]->hitDamager(calcDamage((*_enemyPokemon)[_enemyCurrentPokemon], (*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()], (*_playerPokemon)[_playerCurrentPokemon]));
								(*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()]->useSkill();
							}
						}
						else if (_attackTime <= 40)
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
						ELEMENT tempEl = (*_playerPokemon)[_playerCurrentPokemon]->getVSkill()[_UI->getCurrentPlayerSkill()]->getElement();
						string skillKey;
						if ((*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()]->getName() == "������Ÿ")
							skillKey = "������Ÿ_e";
						else
							skillKey = this->elementString(tempEl) + "_enemy";

						if (_attackTime == 1)
							EFFECTMANAGER->play(skillKey, WINSIZEX / 2, WINSIZEY / 2);
						else if (_attackTime == 2)
						{
							(*_playerPokemon)[_playerCurrentPokemon]->hitDamager(calcDamage((*_enemyPokemon)[_enemyCurrentPokemon], (*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()], (*_playerPokemon)[_playerCurrentPokemon]));
							(*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[_UI->getCurrentEnemySkill()]->useSkill();
						}
						else
						{
							if (EFFECTMANAGER->isEffectEnd(this->elementString(tempEl) + "_enemy"))
							{
								if (_playerHPBar->isChangeDone((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxHP()))
								{
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
							int changePokemon = 0;
							for (int i = 0; i < _enemyPokemon->size(); ++i)
							{
								if ((*_enemyPokemon)[i]->getCurrentHP() != 0)
								{
									changePokemon = i;
									break;
								}

								changePokemon = _enemyPokemon->size();
							}
							_enemyCurrentPokemon = changePokemon;
							if (_enemyCurrentPokemon >= _enemyPokemon->size())
							{
								_enemyCurrentPokemon--;
								_sequence = BATTLE_FINAL;
								DIALOGUE->loadingTextFile(".\\textData\\battleScene_final_win.txt");
								_attackTime = 0;
								stageManager* tempStage = (stageManager*)SCENEMANAGER->findScene(_destScene);
								tempStage->setIsWin(true);
							}
							else
							{
								_end = END_CHANGE;
								DIALOGUE->loadingTextFile(".\\textData\\battleScene_end_change.txt");
								DIALOGUE->replaceAll("#", "��");
								DIALOGUE->replaceAll("@", (*_enemyPokemon)[_enemyCurrentPokemon]->getName());
								_enemyHPBar->setGauge((*_enemyPokemon)[_enemyCurrentPokemon]->getCurrentHP(), (*_enemyPokemon)[_enemyCurrentPokemon]->getMaxHP(), true);
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
							int changePokemon = 0;
							for (int i = 0; i < _playerPokemon->size(); ++i)
							{
								if ((*_playerPokemon)[i]->getCurrentHP() != 0)
								{
									changePokemon = i;
									break;
								}

								changePokemon = _playerPokemon->size();
							}
							_playerCurrentPokemon = changePokemon;
							if (_playerCurrentPokemon >= _playerPokemon->size())
							{
								_playerCurrentPokemon--;
								_sequence = BATTLE_FINAL;
								DIALOGUE->loadingTextFile(".\\textData\\battleScene_final_lose.txt");
								_attackTime = 0;
							}
							else
							{
								_end = END_CHANGE;
								DIALOGUE->loadingTextFile(".\\textData\\battleScene_end_change.txt");
								DIALOGUE->replaceAll("#", "��");
								DIALOGUE->replaceAll("@", (*_playerPokemon)[_playerCurrentPokemon]->getName());
								_playerHPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxHP(), true);
								_playerEXPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP(), false);
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
					SCENEMANAGER->changeScene(_destScene);
				}
			}
			else
			{
				_attackTime++;
				if (_attackTime % 50 == 0)
				{
					SCENEMANAGER->changeScene(_destScene);
					if (_enemyType == ENEMY_TRAINNER)
						DATABASE->getPlayerMemory()->setBadgeCount(DATABASE->getPlayerMemory()->getBadgeCount() + 1);
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
			if (_enemyType == ENEMY_TRAINNER)
				IMAGEMANAGER->findImage(_destScene + "_enemy")->render(getMemDC(), _enemyImageRect.left, _enemyImageRect.top);
		break;
		
		case BATTLE_BALLTHROW:
			DIALOGUE->render(getMemDC());
			IMAGEMANAGER->findImage("battle_player_ball")->frameRender(getMemDC(), LIMIT_X_LEFT, LIMIT_Y_BOTTOM - POKEMON_HEIGHT, _frameX, 0);
			IMAGEMANAGER->findImage("battle_player")->frameRender(getMemDC(), _playerImageRect.left, _playerImageRect.top, _frameX, 0);
			if (_enemyType == ENEMY_TRAINNER)
				IMAGEMANAGER->findImage(_destScene + "_enemy")->render(getMemDC(), _enemyImageRect.left, _enemyImageRect.top);
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
	{
		if (_fight == PLAYER_CATCH)
		{
			IMAGEMANAGER->findImage("pokeball_shake")->frameRender(getMemDC(), _monsterBall.left, _monsterBall.top, _frameX, 0);
			IMAGEMANAGER->findImage("battle_player")->frameRender(getMemDC(), _playerImageRect.left, _playerImageRect.top, 0, 0);
		}
		else
			IMAGEMANAGER->findImage((*_playerPokemon)[_playerCurrentPokemon]->getName() + "_back")->frameRender(getMemDC(), _playerImageRect.left, _playerImageRect.top, _frameX, 0);
	}
	if (!(_isMonsterCatch &&
		_fight == PLAYER_CATCH))
	{
		if (!(_enemyType == ENEMY_TRAINNER &&
			(_sequence == BATTLE_INTRO ||
			 _sequence == BATTLE_BALLTHROW)))
		IMAGEMANAGER->findImage((*_enemyPokemon)[_enemyCurrentPokemon]->getName() + "_front")->frameRender(getMemDC(), _enemyImageRect.left, _enemyImageRect.top);
	}

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
		
		case BATTLE_FIGHT:
			if (_fight == PLAYER_CATCH)
			{
				if (_frameTime < 100)
				{
					if (_frameTime < 25)
						_frameX = 0;
					else if (_frameTime < 50)
						_frameX = 2;
					else
						_frameX = 1;
				}
				else if (_frameTime < 200)
				{
					if (_frameTime < 125)
						_frameX = 0;
					else if (_frameTime < 150)
						_frameX = 2;
					else
						_frameX = 1;
				}
				else if (_frameTime < 300)
				{
					if (_frameTime < 225)
						_frameX = 0;
					else if (_frameTime < 250)
						_frameX = 2;
					else
						_frameX = 1;
				}
				else
				{
					_sequence = BATTLE_FINAL;
					DIALOGUE->loadingTextFile(".\\textData\\battleScene_catch.txt");
					DIALOGUE->replaceAll("#", (*_enemyPokemon)[_enemyCurrentPokemon]->getName());
					pokemon* tempPokemon = new pokemon;
					tempPokemon->setStatus((*_enemyPokemon)[_enemyCurrentPokemon]->getName(),
						(*_enemyPokemon)[_enemyCurrentPokemon]->getLevel(),
						(*_enemyPokemon)[_enemyCurrentPokemon]->getIHP(),
						(*_enemyPokemon)[_enemyCurrentPokemon]->getIATK(),
						(*_enemyPokemon)[_enemyCurrentPokemon]->getIDEF(),
						(*_enemyPokemon)[_enemyCurrentPokemon]->getISPECIAL(),
						(*_enemyPokemon)[_enemyCurrentPokemon]->getISPEED(),
						(*_enemyPokemon)[_enemyCurrentPokemon]->getCurrentHP());

					for (int i = 0; i < (*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill().size(); ++i)
					{
						skill* tempSkill = new skill;
						tempSkill->setSkill((*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[i]->getName(),
							(*_enemyPokemon)[_enemyCurrentPokemon]->getVSkill()[i]->getCurrentPP());
						tempPokemon->addSkill(tempSkill);
					}

					_playerPokemon->push_back(tempPokemon);
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
		temp = "�븻";
		break;

	case ELEMENT_FIRE:
		temp = "��";
		break;

	case ELEMENT_WATER:
		temp = "��";
		break;

	case ELEMENT_ELECTRIC:
		temp = "����";
		break;

	case ELEMENT_PLANT:
		temp = "Ǯ";
		break;

	case ELEMENT_ICE:
		temp = "����";
		break;

	case ELEMENT_FIGHT:
		temp = "����";
		break;

	case ELEMENT_POISON:
		temp = "��";
		break;

	case ELEMENT_EARTH:
		temp = "��";
		break;

	case ELEMENT_WING:
		temp = "����";
		break;

	case ELEMENT_ESPER:
		temp = "������";
		break;

	case ELEMENT_INSECT:
		temp = "����";
		break;

	case ELEMENT_ROCK:
		temp = "����";
		break;

	case ELEMENT_GHOST:
		temp = "����";
		break;

	case ELEMENT_DRAGON:
		temp = "��";
		break;

	case ELEMENT_DARK:
		temp = "��";
		break;

	case ELEMENT_STEEL:
		temp = "��ö";
		break;
	}

	return temp;
}

void battleScene::setProgressBar()
{
	_enemyHPBar->setGauge((*_enemyPokemon)[_enemyCurrentPokemon]->getCurrentHP(), (*_enemyPokemon)[_enemyCurrentPokemon]->getMaxHP(), (int)true);
	_playerHPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentHP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxHP(), (int)true);
	_playerEXPBar->setGauge((*_playerPokemon)[_playerCurrentPokemon]->getCurrentEXP(), (*_playerPokemon)[_playerCurrentPokemon]->getMaxEXP(), (int)false);
}

// ��Ʋ�� �� �������� ��� �ؾ��ϳ� �������ִ� �Լ�
DAMAGE_JUDGEMENT battleScene::judgement(ELEMENT attackerSkill, ELEMENT defencer)
{
	// ����Ŀ�� �� ��ų�� �Ӽ��� ����ϴ� ���ϸ��� �Ӽ��� ���� �ٸ� ���� ����
	// ����
	// ������ �� ��
	// ������ ����
	// ������ ����
	// �����ڷ� : ���ϰ� �÷��� �Ӽ� ǥ
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

	// �� ����ġ���� ��� Ư���� ���(������ ����, ������ ����, ������ �� ��)�� ó��
	// �������� ���� �Ϲ� ������
	return DAMAGE_NORMAL;
}

int battleScene::calcDamage(pokemon* a, skill* s, pokemon* d)
{
	// �ڼӺ��� == �����ϴ� ���ϸ�� ����ϴ� ��ų�� �Ӽ��� ��ġ�ϴ��� ����
	int flux;
	if (a->getElement() == s->getElement())
		flux = 1.5;
	else
		flux = 1;

	// �Ӽ� ����
	float jud;
	if (this->judgement(s->getElement(), d->getElement()) == DAMAGE_NONE)
		jud = 0;
	else if (this->judgement(s->getElement(), d->getElement()) == DAMAGE_HALF)
		jud = 0.5;
	else if (this->judgement(s->getElement(), d->getElement()) == DAMAGE_NORMAL)
		jud = 1;
	else if (this->judgement(s->getElement(), d->getElement()) == DAMAGE_DOUBLE)
		jud = 2;

	// ������ (85~100)
	// 0~9999���� �̱�
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