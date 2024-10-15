#pragma once
#include "ConsoleImage.h"
#include "Actor.h"
#include "ActorVector.h"

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
class Player : public AActor
{
public:
	static Player* GetInstance();
	void BeginPlay() override;
	void Tick() override;

	ActorVector GetBulletVector() const;

private:
	static Player* mInstance;
	// �Ǵٸ� ����Ʈ�� ������ �Ѵ�.
	ActorVector BulletVector;
};

