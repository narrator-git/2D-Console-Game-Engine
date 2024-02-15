#include "Keyboard.h"
#include <iostream>
#include <conio.h>
#include "Windows.h"
bool Keyboard::isKeyPressed(int key) {
	return GetAsyncKeyState(key);
}
char Keyboard::currentKey() {
	char pressedKey = _getch();
	return pressedKey;
}