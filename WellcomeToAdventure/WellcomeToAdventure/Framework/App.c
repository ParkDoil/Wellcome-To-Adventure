#include "App.h"
#include "commonh.h"
#include "Renderer.h"
#include "Timer.h"

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

}

float elapsedTime;
bool canShow = false;
void update()
{
	elapsedTime += DELTA_TIME;

	if (elapsedTime >= 0.1)
	{
		elapsedTime = 0.0f;
		canShow = !canShow;
	}
}

void render()
{
	if (canShow)
	{

	}
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