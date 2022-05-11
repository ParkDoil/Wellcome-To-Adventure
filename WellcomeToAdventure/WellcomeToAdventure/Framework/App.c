#include "App.h"
#include "commonh.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"

bool App_Init()
{
	if (false == Renderer_Init())
	{
		return false;
	}
	return true;
}

void processInput()
{
	Input_Update();
}

char str[128] = "";
void update()
{
	sprintf_s(str, sizeof(str), "��������\n��������\n��������\n��������\n��������\n��������\n��������");
	if (Input_GetKey(VK_UP))
	{
		sprintf_s(str, sizeof(str), "��������\n��������\n��������\n��������\n��������\n��������\n��������");
	}
	if (Input_GetKey(VK_DOWN))
	{
		sprintf_s(str, sizeof(str), "��������\n��������\n��������\n��������\n��������\n��������\n��������");
	}
	if (Input_GetKey(VK_LEFT))
	{
		sprintf_s(str, sizeof(str), "��������\n��������\n��������\n��������\n��������\n��������\n��������");
	}
	if (Input_GetKey(VK_RIGHT))
	{
		sprintf_s(str, sizeof(str), "��������\n��������\n��������\n��������\n��������\n��������\n��������");
	}
	if (Input_GetKey(VK_LEFT)&&Input_GetKey(VK_DOWN)) //��
	{
		sprintf_s(str, sizeof(str), "��������\n��������\n��������\n��������\n��������\n��������\n��������");
	}
	if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_RIGHT)) //��
	{
		sprintf_s(str, sizeof(str), "��������\n��������\n��������\n��������\n��������\n��������\n��������");
	}
	if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_UP)) //��
	{
		sprintf_s(str, sizeof(str), "��������\n��������\n��������\n��������\n��������\n��������\n��������");
	}
	if (Input_GetKey(VK_RIGHT) && Input_GetKey(VK_DOWN)) //��
	{
		sprintf_s(str, sizeof(str), "��������\n��������\n��������\n��������\n��������\n��������\n��������");
	}
	if (Input_GetKey(VK_RIGHT) && Input_GetKey(VK_UP)) //��
	{
		sprintf_s(str, sizeof(str), "��������\n��������\n��������\n��������\n��������\n��������\n��������");
	}
	if (Input_GetKey(VK_UP) && Input_GetKey(VK_DOWN)) //��
	{
		sprintf_s(str, sizeof(str), "��������\n��������\n��������\n��������\n��������\n��������\n��������");
	}
}

void render()
{
	Renderer_DrawText(str, strlen(str));
	Renderer_Flip();
}

void cleanup()
{
	Renderer_Cleanup();
}

int32 App_Run()
{
	atexit(cleanup);

	Timer_Init(60);
	// Game Loop : ������ ���۽�Ű�� ����. 
	while (true)
	{
		// �ð��� ������Ʈ ���� ������ ���� ���� ����
		if (Timer_Update())
		{
			// DeltaTime : ������ ���� �ð�. ���� ���������κ��� ���� �������� ������ ������ �ɸ� �ð�.
			processInput(); // �Է�ó��
			update(); // ���� ������Ʈ
			render(); // ���� ���
		}
	
	}
	return 0;
}