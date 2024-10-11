#include "ConsoleEngine.h"
#include <Windows.h>

ConsoleEngine::ConsoleEngine()
{

}

void ConsoleEngine::Start()
{
	ConsoleEngine Engine;

	Engine.BeginPlay();

	while (true)
	{
		Engine.Tick();
		Engine.Render();
		// ���α׷� 250
		// 1000�� 1���Դϴ�.
		Sleep(250);
	}
	
}

void ConsoleEngine::BeginPlay()
{
	Window.BeginPlay();
	Window.SetScreenSize({20, 10});

	NewPlayer.BeginPlay();
	NewPlayer.SetBackScreenSize(Window.GetScreenSize());
}

void ConsoleEngine::Tick()
{
	NewPlayer.Tick();
}

void ConsoleEngine::Render()
{
	Window.Clear();

	ConsoleImage* BackBufferPtr = Window.GetBackBufferPtr();
	NewPlayer.Render(BackBufferPtr);

	Window.ScreenRender();
}