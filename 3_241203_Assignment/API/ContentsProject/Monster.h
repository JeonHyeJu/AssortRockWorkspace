#pragma once
#include <EngineCore/Actor.h>

// ���� :
class AMonster : public AActor
{
public:
	// constrcuter destructer
	AMonster();
	~AMonster();

	// delete Function
	AMonster(const AMonster& _Other) = delete;
	AMonster(AMonster&& _Other) noexcept = delete;
	AMonster& operator=(const AMonster& _Other) = delete;
	AMonster& operator=(AMonster&& _Other) noexcept = delete;

protected:
	void TestTimeEvent();

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

