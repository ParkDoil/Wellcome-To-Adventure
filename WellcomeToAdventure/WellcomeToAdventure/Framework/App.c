#include "App.h"
#include "commonh.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"
#include "Random.h"

#define INT32_MAX_VALUE 2147483647ll
#define INT32_MIN_VALUE -2147483648ll

bool App_Init()
{
	if (false == Renderer_Init())
	{
		return false;
	}
	if (false == Random_Init())
	{
		return false;
	}
	return true;
}

void processInput()
{
	Input_Update();
}

float elapsedTime;
float elapsed1Time;
bool canShow1 = false;
bool canShow2 = false;
char str1[128] = "";
char str2[128] = "";

void update()
{
	elapsedTime += DELTA_TIME;
	elapsed1Time += DELTA_TIME;

	if (elapsedTime >= 0.35)
	{
		float minfnum = -13920.13283;
		float maxfnum = 19383.18373;
		float resultfnum = Random_GetFNumberFromRange(minfnum, maxfnum);
		sprintf_s(str1, sizeof(str1), "�Ǽ������� : %.7f\n", resultfnum);
		elapsedTime = 0.0f;
		canShow1 = !canShow1;
	}
	if (elapsed1Time >= 0.55)
	{
		int32 minnum = INT32_MIN_VALUE;
		int32 maxnum = INT32_MAX_VALUE;
		int32 resultnum = Random_GetFNumberFromRange(minnum, maxnum);
		sprintf_s(str2, sizeof(str2), "\n�������� �� : %d\n", resultnum);
		elapsed1Time = 0.0f;
		canShow2 = !canShow2;
	}

}

void render()
{
	if (canShow1)
	{
		Renderer_DrawText(str1, strlen(str1));
	}
	if (canShow2)
	{
		Renderer_DrawText(str2, strlen(str2));
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