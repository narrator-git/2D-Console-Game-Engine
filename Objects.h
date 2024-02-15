#pragma once
#include <vector>
class Objects
{
	public:
		struct Rectangle {
			int width, height, x, y;
			float id;
		};
		struct Circle {
			int radius, x, y;
			float id;
		};
		std::vector < Objects::Rectangle > rectangles;
		std::vector < Objects::Circle > circles;
		Rectangle createRectangle(int, int, int, int);
		Rectangle updateRectangle(Rectangle, int, int, int, int);
		void destroyRectangle(Rectangle);
		Circle createCircle(int, int, int);
		bool isOnCollisionWith(Rectangle, Rectangle);
};

