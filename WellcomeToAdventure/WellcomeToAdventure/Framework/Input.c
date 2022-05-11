#include "Input.h"
#include "commonh.h"

#define IS_KEY_DOWN(vkey) (0x8000 & 0x8000&GetAsyncKeyState(vkey))

bool s_preKeyStates[256];
bool s_currentKeyStates[256];
/// <summary>
/// 
/// </summary>
/// <param name=""></param>

void Input_Update(void)
{
	// 이전 프레임의 키 내용 저장.
	memcpy(s_preKeyStates, s_currentKeyStates, sizeof(s_currentKeyStates));

	//현재 프레임의 키 상태를 가져와야 함.
	for (int32 vkey = 0; vkey < 256; vkey++)
	{
		if (IS_KEY_DOWN(vkey))
		{
			s_currentKeyStates[vkey] = true;
		}
		else
		{
			s_currentKeyStates[vkey] = false;
		}
	}
}

bool Input_GetKeyDown(uint8 vkey)
{
	// 현재 프레임에 키가 눌렸다면 true, 아니면 false
	if (false == s_preKeyStates[vkey] && true == s_currentKeyStates[vkey])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input_GetKeyUp(uint8 vkey)
{
	// 현재 프레임에 키가 떼졌다면 true, 아니면 false
	if (true == s_preKeyStates[vkey] && false == s_currentKeyStates[vkey])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input_GetKey(uint8 vkey)
{
	// 이전 프레임과 현재 프레임에 모두 키가 눌렸다면 true, 아니면 false
	if (true == s_preKeyStates[vkey] && true == s_currentKeyStates[vkey])
	{
		return true;
	}
	else
	{
		return false;
	}
}