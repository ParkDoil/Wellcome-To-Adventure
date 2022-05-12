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
	//TexCopyWithWhite(text, L"�츮���� ������ ���ǹ��̴�.");
	TextCopy(text, L"�츮���� ������ ���ǹ��̴�.",0);
	
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