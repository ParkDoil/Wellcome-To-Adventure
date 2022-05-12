#include "App.h"
#include "commonh.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"
#include "Random.h"
#include "Text.h"

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


Text text[128];

void update()
{
	//TexCopyWithWhite(text, L"우리반의 존잘은 성권문이다.");
	TextCopy(text, L"우리반의 존잘은 성권문이다.",0);
	
	/*
	TextCopy(text, TEXT("DOWNLOAD..."));
	int32 length = TextLen(text);
	for (int32 i = 0; text[i].Char.UnicodeChar != '\0'; i++)
	{
		text[i].Attributes = BACK_COLOR_RED | TEXT_COLOR_WHITE | TEXT_COLOR_STRONG;
	}
	*/

}

void render()
{
	Renderer_DrawText(text, TextLen(text), 10, 10);
	Renderer_Flip();
}

void cleanup(void)
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