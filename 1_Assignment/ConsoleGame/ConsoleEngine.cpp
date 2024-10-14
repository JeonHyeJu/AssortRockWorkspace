#include "ConsoleEngine.h"
#include <Windows.h>
#include "GlobalValue.h"
#include "Actor.h"
#include <typeinfo>

// ConsoleEngine* Inst = new ConsoleEngine();
// ConsoleEngine* Inst = nullptr;

ConsoleEngine* ConsoleEngine::MainEngine = nullptr;

FIntPoint ConsoleEngine::WindowSize;
UConsoleWindow ConsoleEngine::Window;

ConsoleEngine::ConsoleEngine()
{

}

void ConsoleEngine::Start()
{
	// ������ ���� ��
	// �� ������ ������ ������ ������ Ŭ���� ��������� �ִ�.


	// ���ϳ��� ��ü ����� ���̻� ������ �ʴ� ���.
	// �ٽɰ�ü�� �޸� ��� �ִ��� �ڽ��� �Ӹ��ӿ� �־�� �Ѵ�.
	// ���� ���ϰ� ����ϱ� ���ؼ� �����ִ� ��ü���� �ִ�.
	// �������� ���ؼ� Window�� �ٽ��̴�. Window�� ��𼭵� ����Ҽ� �־�� �Ѵ�.
	// ����� �߰��ϸ� �������� �� ��ü�� �����Ҽ� �ְ� �Ѵ�.
	// �̶� �� �̱����� �ƴҼ��� �ִ�.
	// �����ڸ� private���� ���� �� 1���� ������� �ϴ� ��츦 ���Ѵ�.
	
	// unreal������ GEngine ���� ��������(extern)�� static���� �̷���� �ִ�.
	// ������ ������ ���ʿ� �������� ����.

	// �̶� ��κ� �����Ҵ� �Ұų� �ƴϳ�?
	// �� ������ �������? �����ͷ� ������ٴ°� �������� ������ ���ɼ��� �ִٴ� ��.
	// �ƴ϶�� ������ ���ɼ��� �ִ�.
	ConsoleEngine Engine;

	MainEngine = &Engine;

	Engine.BeginPlay();

	while (true)
	{
		Engine.Tick();
		Engine.Render();
		Engine.Collide();
		// ���α׷� 250
		// 1000�� 1���Դϴ�.
		Sleep(250);

	}
	
}

void ConsoleEngine::BeginPlay()
{
	Window.BeginPlay();

	WindowSize.X = 20;
	WindowSize.Y = 10;

	GlobalValue::WindowPtr = &Window;

	Window.SetScreenSize(WindowSize);

	Player* NewPlayer = SpawnActor<Player>();
	Monster* NewMonster = SpawnActor<Monster>();
}

void ConsoleEngine::Tick()
{
	for (size_t i = 0; i < AllActorVector.size(); i++)
	{
		AllActorVector[i]->Tick();
	}
}

void ConsoleEngine::Collide()
{
	for (int i = 0; i < AllActorVector.size()-1; i++) {
		ActorType prevActorType = AllActorVector[i]->getActorType();
		ActorType nextActorType = AllActorVector[i+1]->getActorType();
		int monsterIdx = -1;

		if (prevActorType == ActorType::Monster && nextActorType == ActorType::Bullet)
		{
			monsterIdx = i;
		}
		else if (prevActorType == ActorType::Bullet && nextActorType == ActorType::Monster)
		{
			monsterIdx = i+1;
		}

		if (monsterIdx != -1)
		{
			FIntPoint prevActorLoc = AllActorVector[i]->GetActorLocation();
			FIntPoint nextActorLoc = AllActorVector[i + 1]->GetActorLocation();

			if (prevActorLoc == nextActorLoc)
			{
				DestroyActor(monsterIdx);
			}
		}
	}
}

void ConsoleEngine::Render()
{
	Window.Clear();

	ConsoleImage* BackBufferPtr = Window.GetBackBufferPtr();
	for (size_t i = 0; i < AllActorVector.size(); i++)
	{
		AllActorVector[i]->Render(BackBufferPtr);
	}

	Window.ScreenRender();
}

void ConsoleEngine::DestroyActor(int _idx)
{
	AllActorVector.Delete(_idx);
}