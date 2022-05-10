#include "App.h"
#include "common.h"

bool App_Init()
{
	return true;
}

void processInput()
{

}

void update()
{

}

void render()
{
	system("cls");
	puts("Hello Game");
}

int32 App_Run()
{
	while (true)
	{
		processInput(); // 입력처리
		update(); // 게임 업데이트
		render(); // 게임 출력
	}
	return 0;
}