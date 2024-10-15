#pragma once
#include "ConsoleImage.h"
#include "Actor.h"
#include "ActorVector.h"

class Player : public AActor
{
public:
	static Player* const GetInstance();
	void BeginPlay() override;
	void Tick() override;

	ActorVector GetBulletVector() const;

private:
	Player() = default;

	static Player* mInstance;
	// �Ǵٸ� ����Ʈ�� ������ �Ѵ�.
	ActorVector BulletVector;
};

