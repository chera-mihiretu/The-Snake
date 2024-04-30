#include "Click.h"

bool Click::clicked(int x_1, int y_1, int x_2, int y_2) const
{
	
	if (y_1 <= GetTouchY() && GetTouchY() <= y_2) {
		if (x_1 <= GetTouchX() && GetTouchX() <= x_2) {
			return true;
		}
	}
	return false;

}
