#include "Control.h"


Control::Control(std::vector<Snake*>* snake):
	snake(snake)
{
	can_click = true;
}

void Control::listenClick()
{
	if (can_click) {
		if (IsKeyPressed(KEY_DOWN)) {
			if ((*snake)[0]->getDir() != DIR_VAL::UP) {
				(*snake)[0]->setDir((int)DIR_VAL::DOWN);
				can_click = false;
			}
		}
		if (IsKeyPressed(KEY_UP)) {
			if ((*snake)[0]->getDir() != DIR_VAL::DOWN) {
				(*snake)[0]->setDir((int)DIR_VAL::UP);
				can_click = false;
			}
		}
		if (IsKeyPressed(KEY_LEFT)) {
			if ((*snake)[0]->getDir() != DIR_VAL::RIGHT) {
				(*snake)[0]->setDir((int)DIR_VAL::LEFT);
				can_click = false;
			}
		}
		if (IsKeyPressed(KEY_RIGHT)) {
			if ((*snake)[0]->getDir() != DIR_VAL::LEFT) {
				(*snake)[0]->setDir((int)DIR_VAL::RIGHT);
				can_click = false;
			}
		}
	}
}

void Control::setClicked(bool val)
{
	can_click = val;
}
