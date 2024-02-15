#pragma once
#include <vector>
#include "Objects.h"
class Screen
{
	public:
		int height, width;
		Screen();
		Objects objects;
		std::vector <char> coords;
		std::vector <char> pixels;
		void setSize(int, int);
		void drawScreen();
		void drawRectangle(Objects::Rectangle);
		void drawCircle(Objects::Circle);
		void clear();
	private:
		void defineGrid();
};

