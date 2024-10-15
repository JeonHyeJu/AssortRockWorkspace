#include "Monster.h"
#include "Renderer.h"
#include "Player.h"

void Monster::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, 'M');
}

void Monster::Tick()
{
	// ���� ���
	// Monster::Tick();

	// 1. ��� �Ѿ��� �����´�.
	// 2. ��� �Ѿ� �� �ڽ��� ��ġ�� ���ؾ� �Ѵ�.
	//    ������ ����� ���� �����ָ� �հ����� ���� �־���ϴ���?

	// 1-1. ���������� ���� §��. 
	//      ������ ���� �����ϴ� ����� �����. ��ų�Ŵ��� ����� ����
	//      Ŭ���̾�Ʈ ���α׷��Ӱ� �̹���� ��ȣ�մϴ�.
	//      ������ �����ϴ� ����� �˾Ƴ��°� �� ����.
	//      ������ ����� ���� ������ ������� ������ ������� �ʴ°� ����.
	//      
	// 1-2. ������ ����� �̿��Ѵ�. ������ ����� ��κ� ������.
	//      �������̰� �����ϰ� ¥���� �ֱ� ������ 
	//      ������ ���忡�� Player Monster Bullet�� �� => AActor�� ���̴�.
	//      �ڷᱸ�� �ϳ����� �����ϰ� 100
	//      �������� �����ϴ� FindObject�� Find ���� ��ɵ��� ��κ� �����ϴ� ��ɵ�.
	//      Find(const char*) <= ������ ���ڿ� �񱳶� 2��� ������.

	bool isCrahsed = IsCrahsed();
	if (isCrahsed)
	{
		FIntPoint monsterPos = GetActorLocation();
		SetActorLocation(monsterPos + FIntPoint::UP);
	}
}

bool Monster::IsCrahsed()
{
	FIntPoint monsterPos = GetActorLocation();
	Player* player = Player::GetInstance();
	ActorVector bullets = player->GetBulletVector();

	for (int i = 0; i < bullets.size(); i++)
	{
		FIntPoint pos = bullets[i]->GetActorLocation();
		if (monsterPos.X == pos.X && monsterPos.Y == pos.Y)
		{
			return true;
		}
	}

	return false;
}
