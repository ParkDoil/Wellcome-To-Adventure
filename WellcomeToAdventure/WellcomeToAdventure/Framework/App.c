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
		processInput(); // �Է�ó��
		update(); // ���� ������Ʈ
		render(); // ���� ���
	}
	return 0;
}