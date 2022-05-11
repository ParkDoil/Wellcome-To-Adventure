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
	// Game Loop : 게임을 동작시키는 루프. 
	while (true)
	{
		// 시간이 업데이트 됐을 때에만 게임 루프 실행
		if (Timer_Update())
		{
			// DeltaTime : 프레임 간의 시간. 이전 프레임으로부터 현재 프레임을 시작할 때까지 걸린 시간.
			processInput(); // 입력처리
			update(); // 게임 업데이트
			render(); // 게임 출력
		}
	
	}
	return 0;
}