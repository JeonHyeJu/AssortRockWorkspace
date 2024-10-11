#pragma once
#include "ConsoleImage.h"

//class AActor
//{
//	FIntPoint Location;
//};
//
//class Monster
//{
//	
//};

// ȭ���򰡿� �̳༮�� ������
// �Ϲ����� ���ӿ���
class Player
{
public:
	void BeginPlay();
	void Tick();
	void Render(ConsoleImage* _BackBuffer);

	void Move();
	void SetBackScreenSize(const FSize& size);

	void SetActorLocation(FIntPoint _Pos);

private:
	FIntPoint Pos;
	FSize mMaxBackScreenSize;
	ConsoleImage PlayerImage;
};

