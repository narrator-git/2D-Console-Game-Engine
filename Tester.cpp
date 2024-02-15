#include "Engine.h"
#include <iostream>
#include <thread>
#include <chrono>
/*
0x41	A key
0x42	B key
0x43	C key
0x44	D key
0x45	E key
0x46	F key
0x47	G key
0x48	H key
0x49	I key
0x4A	J key
0x4B	K key
0x4C	L key
0x4D	M key
0x4E	N key
0x4F	O key
0x50	P key
0x51	Q key
0x52	R key
0x53	S key
0x54	T key
0x55	U key
0x56	V key
0x57	W key
0x58	X key
0x59	Y key
0x5A	Z key
*/


/*
Я РЕАЛИЗОВАЛ ПЕРЕДВИЖЕНИЕ ПО ДИАГОНАЛИ И СОЗДАЛ АГАРИО
*/
int main() {
	Engine myEngine;
	std::wcout << "PRESS ANY KEY TO START";
	char pressedkey = myEngine.keyboard.currentKey();
	myEngine.screen.setSize(300, 250);
	bool speedBoostActive=0;
	int speed=1, speedBoostMillisecondsLeft=0;
	auto player = myEngine.screen.objects.createRectangle(7, 7, 1, 250);
	auto newFruit = myEngine.screen.objects.createRectangle(3, 3, 5, 230);
	auto newSpeedBoost = myEngine.screen.objects.createRectangle(5, 5, 30, 30);
	while (myEngine.gamestate) {
		speedBoostActive = speedBoostMillisecondsLeft!=0;
		if (speedBoostActive) { speedBoostMillisecondsLeft -= 100; }
		else { speed=1; }
		if (myEngine.keyboard.isKeyPressed(0x57)) { player = myEngine.screen.objects.updateRectangle(player, 0, 0, 0, speed); }
		if (myEngine.keyboard.isKeyPressed(0x53)) { player = myEngine.screen.objects.updateRectangle(player, 0, 0, 0, speed*(-1)); }
		if (myEngine.keyboard.isKeyPressed(0x44)) { player = myEngine.screen.objects.updateRectangle(player, 0, 0, speed, 0); }
		if (myEngine.keyboard.isKeyPressed(0x41)) { player = myEngine.screen.objects.updateRectangle(player, 0, 0, speed*(-1), 0); }
		if (myEngine.screen.objects.isOnCollisionWith(player, newFruit)) { myEngine.screen.objects.destroyRectangle(newFruit); player = myEngine.screen.objects.updateRectangle(player, 3, 3, 0, 0); newFruit = myEngine.screen.objects.createRectangle(3, 3, rand() % (myEngine.screen.width - 5), (rand() % ((myEngine.screen.height - 5) - 5 + 1)) + 5);}
		if (myEngine.screen.objects.isOnCollisionWith(player, newSpeedBoost)) { myEngine.screen.objects.destroyRectangle(newSpeedBoost); speed++; speedBoostMillisecondsLeft = 3000;}
		myEngine.screen.drawScreen();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}