#pragma once

namespace crt
{
	// GotoXY - устанавливает курсов в позицию x, y консоли
	void GotoXY(int x, int y);

	void ShowCursor(bool visible);

	void SetTextColor(int color);

	void SetTextBackground(int color);
}