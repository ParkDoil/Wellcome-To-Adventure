#pragma once

/// <summary>
/// Ÿ�̸Ӹ� �ʱ�ȭ�Ѵ�.
/// </summary>
/// <param name="fps>������ FPS</param>
void	Timer_Init(int32 fps);

/// <summary>
/// Ÿ�̸Ӹ� ������Ʈ�Ѵ�.
/// </summary>
/// <return>������Ʈ�� �����ߴٸ� true, �ƴ϶�� false<\return>
bool	Timer_Update(void);

/// <summary>
/// Ÿ�̸Ӹ� ���Ѵ�.
/// </summary>
float	Timer_GetDeltaTime(void);

#define DELTA_TIME Timer_GetDeltaTime();