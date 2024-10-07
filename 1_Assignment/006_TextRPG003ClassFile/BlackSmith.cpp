#include "BlackSmith.h"
#include "Player.h"
#include "Item.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>

int GetProbability(int _minVal, int _maxVal)
{
	int ret = _minVal + rand() % (_maxVal - _minVal + 1);
	return ret;
}

bool IsEnhanceSuccessed()
{
	const int MIN_VAL = 1;
	const int MAX_VAL = 2;
	bool isSuccess = GetProbability(MIN_VAL, MAX_VAL) == MAX_VAL;
	return isSuccess;
}

void BlackSmith::InPlayer(UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("�θ����� ���õ��� �ʾҽ��ϴ�");
		return;
	}

	Item* itemForCheck = _Player.GetItem();
	if (!itemForCheck)
	{
		Item* item = new Item;
		_Player.Equip(item);
	}
	
	_Player.SetGold(1000000);

	srand(time(nullptr));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������\n";
		int Select = _getch();
		
		switch (Select)
		{
		case '1': {
			Enhance(_Player);
			break;
		}
		case '2':
			return;
		default:
			break;
		}
	}
}

void BlackSmith::Enhance(UPlayer& _Player)
{
	// Ȯ���� ���δ� 2���� 1
	// 1���� �𿩾� �Ѵ�. �÷��̾��� ��ȭ �ܰ� * 100
	// ���� ���� 5���� �����ϰ� �ִ�. �׷��� 500���� �￩�� �Ѵ�.
	// 1~5������ ���а� ����Ȯ���� ������.
	// �ٿ������ �ʴ´�.
	// 6~10������ �����ϸ� 1�� �ٿ�ȴ�.
	// 10~15�� 0���� �����ϸ� 0���� ��������.
	// 15�� �̻��̸� ��ȭ�� ���ϰ� �ؾ����Ѵ�.

	const int REQUIRED_MONEY_PER_TRY = 100;
	Item* playerItem = _Player.GetItem();
	if (!playerItem) {
		std::cout << "�������� �����ϴ�." << std::endl;
		_getch();
		return;
	}

	int itemEnhanceScore = playerItem->GetEnhanceScore();
	int requiredMoney = (itemEnhanceScore + 1) * REQUIRED_MONEY_PER_TRY;
	int playerGold = _Player.GetGold();

	if (playerGold < requiredMoney) {
		std::cout << "�� ����" << std::endl;
		_getch();
		return;
	}

	bool isMaxEnhanceLevel = playerItem->isMaxEnhanceLevel();
	if (isMaxEnhanceLevel) {
		std::cout << "��ȭ �ְ� ���" << std::endl;
		_getch();
		return;
	}

	int lastGold = playerGold - REQUIRED_MONEY_PER_TRY;
	_Player.SetGold(lastGold);

	bool isSuccessed = IsEnhanceSuccessed();
	if (isSuccessed)
	{
		itemEnhanceScore += 1;
		std::cout << "��ȭ ����" << std::endl;
	}
	else 
	{
		if (itemEnhanceScore >= 6 && itemEnhanceScore <= 10) {
			itemEnhanceScore -= 1;
		}
		else if (itemEnhanceScore >= 11) {
			itemEnhanceScore = 0;
		}
		std::cout << "��ȭ ����" << std::endl;
	}

	playerItem->SetEnhanceScore(itemEnhanceScore);
	std::cout << "���� ������ ����: " << playerItem->GetEnhanceScore() << std::endl;
	_getch();
}