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
	// ���� �������� Ű ���� ����.
	memcpy(s_preKeyStates, s_currentKeyStates, sizeof(s_currentKeyStates));

	//���� �������� Ű ���¸� �����;� ��.
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
	// ���� �����ӿ� Ű�� ���ȴٸ� true, �ƴϸ� false
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
	// ���� �����ӿ� Ű�� �����ٸ� true, �ƴϸ� false
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
	// ���� �����Ӱ� ���� �����ӿ� ��� Ű�� ���ȴٸ� true, �ƴϸ� false
	if (true == s_preKeyStates[vkey] && true == s_currentKeyStates[vkey])
	{
		return true;
	}
	else
	{
		return false;
	}
}