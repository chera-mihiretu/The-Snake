#include "Control.h"


Control::Control(std::vector<Snake*>* snake):
	snake(snake)
{
	
}

void Control::listenClick()
{
	if (IsKeyPressed(KEY_DOWN)) {
		if ((*snake)[0]->getDir() != DIR_VAL::UP) {
			(*snake)[0]->setDir((int)DIR_VAL::DOWN);
		}
	}
	if (IsKeyPressed(KEY_UP)) {
		if ((*snake)[0]->getDir() != DIR_VAL::DOWN) {
			(*snake)[0]->setDir((int)DIR_VAL::UP	);
		}
	}
	if (IsKeyPressed(KEY_LEFT)) {
		if ((*snake)[0]->getDir() != DIR_VAL::RIGHT) {
			(*snake)[0]->setDir((int)DIR_VAL::LEFT);
		}
	}
	if (IsKeyPressed(KEY_RIGHT)) {
		if ((*snake)[0]->getDir() != DIR_VAL::LEFT) {
			(*snake)[0]->setDir((int)DIR_VAL::RIGHT);
		}
	}
}
