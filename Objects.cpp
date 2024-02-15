#include "Objects.h"
Objects::Rectangle Objects::createRectangle(int h, int w, int x, int y) {
	Rectangle rectangle;
	rectangle.height = h;
	rectangle.width = w;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.id = (x * y - h) / (h * w - x);
	Objects::rectangles.push_back(rectangle);
	return rectangle;
}
Objects::Circle Objects::createCircle(int r, int x, int y) {
	Circle circle;
	circle.radius = r;
	circle.x = x;
	circle.y = y;
	circle.id = (x * y - r) / (r - x);
	Objects::circles.push_back(circle);
	return circle;
}

Objects::Rectangle Objects::updateRectangle(Objects::Rectangle rectangle, int h, int w, int x, int y) {
	for (int i = 0; i < Objects::rectangles.size(); i++) {
		if (Objects::rectangles[i].id==rectangle.id) {
			Objects::rectangles[i].x += x;
			Objects::rectangles[i].y += y;
			Objects::rectangles[i].height += h;
			Objects::rectangles[i].width += w;
			break;
		}
	}
	rectangle.height += h;
	rectangle.width += w;
	rectangle.x += x;
	rectangle.y += y;
	return rectangle;
}
void Objects::destroyRectangle(Objects::Rectangle rectangle) {
	for (int i = 0; i < Objects::rectangles.size(); i++) {
		if (Objects::rectangles[i].id == rectangle.id) {
			Objects::rectangles.erase(Objects::rectangles.begin() + i);
			break;
		}
	}
}

bool Objects::isOnCollisionWith(Objects::Rectangle rectangle1, Objects::Rectangle rectangle2) {
	return ((((rectangle1.x + rectangle1.width) >= rectangle2.x) && ((rectangle1.y - rectangle1.height) <= rectangle2.y)));
}