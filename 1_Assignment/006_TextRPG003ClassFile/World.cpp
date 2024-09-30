#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include <conio.h>
#include "Player.h"

void UWorld::InPlayer(class UPlayer& _Player)
{
	char InputName[100] = {0,};
	bool hasName = false;
	int Select = -1;

	while (Select != 'a')
	{
		system("cls");

		if (!hasName) {
			std::cout << "�̸��� �����ּ���" << std::endl;
			std::cin >> InputName;
		}

		printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
		printf_s("a. ����\n");
		printf_s("b. ���Է�\n");

		Select = _getch();

		switch (Select)
		{
		case 'a':
		case 'A':
			hasName = true;
			break;
		case 'b':
		case 'B':
			hasName = false;
			break;
		default:
			printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n");
			char _ = _getch();
			hasName = true;
			break;
		}
	}

	_Player.SetName(InputName);

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