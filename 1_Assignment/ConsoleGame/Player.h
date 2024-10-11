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
	void SetActorLocation(FIntPoint _Pos);

	void Move();
	bool CanMove(const FIntPoint& _pos);
	void SetBackScreenSize(const FSize& _size);

private:
	FIntPoint Pos;
	FSize mMaxBackScreenSize;
	ConsoleImage PlayerImage;
};

