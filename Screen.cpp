#include "Screen.h"
#include <iostream>
#include <vector>
Screen::Screen() :
    height(33),
    width(99),
    coords(std::vector <char>(height * width, '*')) {}

void Screen::drawScreen() {
    clear();
    for (auto i : objects.rectangles) {
        drawRectangle(i);
    }
    for (auto i : objects.circles) {
        drawCircle(i);
    }
    defineGrid();
    std::cout.write(pixels.data(), pixels.size());
    // Write the current pixel character
}

void Screen::drawRectangle(Objects::Rectangle rectangle) {
    int x = rectangle.x;
    int x1 = rectangle.x + rectangle.width - 1;
    int y = rectangle.y;
    int y1 = rectangle.y - rectangle.height + 1;
    for (int z = x; z <= x1; z++) {
        coords[(z-1) + (height - y) * width] = '#';
        coords[(z - 1) + (height - y1) * width] = '#';
    }
    for (int z = y; z >= y1; z--) {
        coords[(x-1) + (height - z) * width] = '#';
        coords[(x1-1) + (height - z) * width] = '#';
    }
}


void Screen::drawCircle(Objects::Circle circle) {
    for (int i = 1; i < circle.radius - 1; i++) {
        coords[(height - circle.y) * width + i + (circle.x - 1)] = '#';
        coords[(height - (circle.y - (circle.radius - 1))) * width + i + (circle.x - 1)] = '#';
        coords[(height - circle.y + i) * width + circle.x - 1] = '#';
        coords[(height - circle.y + i) * width + circle.x + circle.radius - 2] = '#';
    }
}


void Screen::setSize(int w, int h) {
    height = h;
    width = w;
    coords.resize(height * width);
    clear();
}

void Screen::defineGrid() {
    pixels.resize(height * width * 2);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i * width * 2 + j * 2] = coords[i * width + j];
            pixels[i * width * 2 + j * 2 + 1] = ' ';
        }
        pixels[i * width * 2 + width * 2 - 1] = '\n';
    }
}

void Screen::clear() {
    system("cls");
    coords=std::vector <char>(height * width, '*');

}