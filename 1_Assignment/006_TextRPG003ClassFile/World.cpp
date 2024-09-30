#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include <conio.h>


void UWorld::InPlayer(class UPlayer& _Player)
{
	char InputName[100] = {0,};
	bool hasName = false;

	while (true)
	{
		system("cls");

		if (!hasName) {
			std::cout << "�̸��� �����ּ���" << std::endl;
			std::cin >> InputName;
		}

		printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
		printf_s("a. ����\n");
		printf_s("b. ���Է�\n");
		int Select = _getch();
		bool IsEnd = false;
		switch (Select)
		{
		case 'a':
		case 'A':
			hasName = true;
			IsEnd = true;
			break;
		case 'b':
		case 'B':
			hasName = false;
			continue;
		default:
			printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n");
			char _ = _getch();
			hasName = true;
			continue;
		}

		if (true == IsEnd)
		{
			break;
		}
	}

	// �������ʱ��� ���⼭ �� ������� ����
	// ������ ������ FightZone�� ��� �ȴ�.
	// ���� ��� �������� 
	
	// new�� �� ����� �ϴ°ų�?
	// 8�Ⱑ
	UTown TownZone;
	TownZone.SetName("�ʺ�����");

	// 10�Ⱑ
	UFightZone FightZone;
	FightZone.SetName("�ʺ������");

	while (true)
	{
		TownZone.InPlayer(_Player);
	}



}