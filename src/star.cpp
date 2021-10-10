#include "headers/star.hpp"

Star::Star() {
    
}

Star::Star(SDL_Renderer *r, int x, int y, int speed, int size) {
    this->speed = speed;
	this->size = size;
    starRect.w = size = starRect.h = size;
    starRect.x = x; 
    starRect.y = y;
	this->x = x;
	this->y = y;
    renderer = r;
	type = rand() % 3;
}

void Star::draw() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &starRect);
    SDL_RenderFillRect(renderer, &starRect);
}

void Star::update(float dt) {
	y += speed * dt;
    starRect.y = y;
	int angle = speed / 3;
	switch (type) {
		case 0:
			x += (rand() % angle + angle) * dt;
			starRect.x = x;
			break;
		case 1:
			x -= (rand() % angle + angle) * dt;
			starRect.x = x;
			break;
		case 2:
			break;
	}
}

int Star::getY() {
    return starRect.y;
}

void Star::move(int x, int y) {
    starRect.x = x;
    starRect.y = y;
	this->x = x;
	this->y = y;
}

bool Star::isOff(int w, int h) {
	return (starRect.x < -size || starRect.x > w + size || starRect.y < -size || starRect.y > h + size);
}