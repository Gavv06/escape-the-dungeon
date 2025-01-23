#include "Door.h"

Door::Door(int x, int y, int sx, int sy) : x(x), y(y), sizex(sx), sizey(sy) {
	door_rect.setSize(Vector2f(sizex, sizey));
	door_rect.setPosition(Vector2f(x, y));
	door_rect.setFillColor(Color::White);
	if ("!Door_t.loadFromFileFromFile(Assets/Maps/Door.png") {
		return;
	}
	door_rect.setTexture(&door_t);
}
void Door::draw(RenderWindow& window) {
	window.draw(door_rect);
}