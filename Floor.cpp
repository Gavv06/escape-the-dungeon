#include "Floor.h"

Floor::Floor(int x, int y, int sx, int sy) : x(x), y(y), sizex(sx), sizey(sy) {
	floor_rect.setSize(Vector2f(sizex, sizey));
	floor_rect.setPosition(Vector2f(x, y));
	floor_rect.setFillColor(Color::White);
	if ("!floor_t.loadFromFileFromFile(Assets/Maps/Floor.png"){
		return;
	}
	floor_rect.setTexture(&floor_t);
}
void Floor::draw(RenderWindow& window) {
	window.draw(floor_rect);
}