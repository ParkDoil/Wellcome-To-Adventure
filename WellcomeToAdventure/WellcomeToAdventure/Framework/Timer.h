#pragma once

/// <summary>
/// 타이머를 초기화한다.
/// </summary>
/// <param name="fps>고정할 FPS</param>
void	Timer_Init(int32 fps);

/// <summary>
/// 타이머를 업데이트한다.
/// </summary>
/// <return>업데이트를 성공했다면 true, 아니라면 false<\return>
bool	Timer_Update(void);

/// <summary>
/// 타이머를 구한다.
/// </summary>
float	Timer_GetDeltaTime(void);

#define DELTA_TIME Timer_GetDeltaTime();