#include "headers/star.hpp"

Star::Star() {
    
}

Star::Star(SDL_Renderer *r, int x, int y, int speed, int size, SDL_Texture* texture) {
    this->speed = speed;
	this->size = size;
	this->texture = texture;
    starRect.w = size;
	starRect.h = size;
    starRect.x = x; 
    starRect.y = y;
	this->x = x;
	this->y = y;
    renderer = r;
	type = rand() % 3;
	if (type < 2) {
		this->speed = speed / 2;
	}
	right = !!(rand() % 1);
	changeAngleTime = 0;
}

void Star::draw() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //SDL_RenderDrawRect(renderer, &starRect);
    //SDL_RenderFillRect(renderer, &starRect);
	SDL_RenderCopyEx(renderer, texture, NULL, &starRect, angle, NULL, SDL_FLIP_NONE);
}

void Star::update(float dt) {
	y += speed * dt;

	changeAngleTime += dt;
	if (changeAngleTime >= 7.f) {
		changeAngleTime -= 7.f;
		right = !right;
	}
	if (right) {
		angle += speed * dt;
	} else {
		angle -= speed * dt;
	}

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