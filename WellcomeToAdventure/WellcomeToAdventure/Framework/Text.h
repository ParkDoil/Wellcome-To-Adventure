#pragma once

#include "commonh.h"

typedef CHAR_INFO Text;

enum TextColor
{
	TEXT_COLOR_BLACK,
	TEXT_COLOR_BLUE = FOREGROUND_BLUE,
	TEXT_COLOR_RED = FOREGROUND_RED,
	TEXT_COLOR_GREEN = FOREGROUND_GREEN,
	TEXT_COLOR_CYAN = TEXT_COLOR_BLUE | TEXT_COLOR_GREEN,
	TEXT_COLOR_MAGENTA = TEXT_COLOR_RED | TEXT_COLOR_BLUE,
	TEXT_COLOR_YELLOW = TEXT_COLOR_RED | TEXT_COLOR_GREEN,
	TEXT_COLOR_WHITE = TEXT_COLOR_RED | TEXT_COLOR_BLUE | TEXT_COLOR_GREEN,
	TEXT_COLOR_STRONG = FOREGROUND_INTENSITY
};

enum BackgroundColor
{
	BACK_COLOR_BLACK,
	BACK_COLOR_BLUE = BACKGROUND_BLUE,
	BACK_COLOR_RED = BACKGROUND_RED,
	BACK_COLOR_GREEN = BACKGROUND_GREEN,
	BACK_COLOR_CYAN = BACK_COLOR_BLUE | BACK_COLOR_GREEN,
	BACK_COLOR_MAGENTA = BACK_COLOR_RED | BACK_COLOR_BLUE,
	BACK_COLOR_YELLOW = BACK_COLOR_RED | BACK_COLOR_GREEN,
	BACK_COLOR_WHITE = BACK_COLOR_RED | BACK_COLOR_BLUE | BACK_COLOR_GREEN,
	BACK_COLOR_STRONG = BACKGROUND_INTENSITY
};

/// <summary>
/// 텍스트를 복사한다.
/// </summary>
/// <param name="dest">복사할 텍스트 배열 주소값</param>
/// <param name="src">텍스트</param>
/// <param name="attributes">텍스트의 색상</param>
void TextCopy(Text* dest, const WCHAR* src, WORD attributes);

int32 TextLen(const Text* text);

#define TexCopyWithWhite(dest, src) TextCopy(dest, src,TEXT_COLOR_WHITE)