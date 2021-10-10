#pragma once

#include <iostream>
#include "SDL2/SDL.h"

class Star {

    public:
        Star();
        Star(SDL_Renderer *r, int x, int y, int speed, int size, SDL_Texture* texture);

        void update(float dt);
        void draw();

        int getY();
        void move(int x, int y);

        bool isOff(int w, int h);

    private:
        int speed;
        int size;
        int type;
        float x;
        float y;
        double angle;
        
        SDL_Renderer *renderer;
        SDL_Rect starRect;
        SDL_Texture* texture;

        float changeAngleTime;
        bool right;

};