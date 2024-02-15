#pragma once
#include "Keyboard.h"
#include "Screen.h"
#include "Objects.h"
class Engine
{
public:
	Keyboard keyboard;
	Screen screen;
	Objects objects;
	bool gamestate;
	Engine();
};

