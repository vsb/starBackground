#include <iostream>
#include <stdlib.h>
#include "headers/ui.hpp"
#include "SDL2/SDL.h"


#define FPS 60

/**
 * Limits update frequency rate. Bad implementation since it creates flickering due to
 * not basing updating on a time but to wait for X.
 *
 * @param starting_tick The tick which is retrieved every while-loop.
 * @return No return value.
 */
void fpsCap(Uint32 starting_tick) {
    // '1000 / FPS' is meant to be replaced with 'frameDelay'
    if ((1000 / FPS) > SDL_GetTicks() - starting_tick) {
        SDL_Delay(1000 / FPS - (SDL_GetTicks() - starting_tick));
    }
}

int main(int argc, char *argv[]) {

    // Ticks for fpsCap
    uint32_t startingTick;
    int endTick;
	float frameDelay = 1000.f / FPS;

    UI ui = UI();

    if (argc == 1) {
        ui.init("Stars", 2048, 1152, 300, false);
    } else if (argc == 4) {
        ui.init("Stars", atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), false);
    } else {
        std::cout << "INVALID ARGUMENT, INPUT IS: \nWIDTH(px) HEIGHT(px) STARS(amount)" << std::endl;
        return -1;
    }


    SDL_Event event;
    bool isRunning = true;
	float startTime = SDL_GetTicks();
    while(isRunning) {
        // Get the number of milliseconds since the SDL library initialization.
        startingTick = SDL_GetTicks();
		float delta = startingTick - startTime;
		startTime = startingTick;
        

        // --- USE THIS WHEN: You have an application window and want to be able to close it.
        
        // SDL_PollEvent(&event);
        // switch (event.type) {
        //     case SDL_QUIT : 
        //         isRunning = false;
        //         break;
        //     default:
        //         break;
        // }

        ui.clearRenderer();
        ui.update(frameDelay / 1000.f);
        ui.render();

        // See method-description
        //fpsCap(startingTick);
		if (frameDelay > delta) {
			SDL_Delay(frameDelay - delta);
		}
		
    }


    ui.clean();

    return 0;
}


// Could implement this?
/*
@  https://www.reddit.com/user/larso0/

Let me give you an example:

float time_seconds = SDL_GetTicks() / 1000.f;
while(1){
    float new_time = SDL_GetTicks() / 1000.f;
    float delta = new_time - time_seconds;
    time_seconds = new_time;
    updateGamePhysics(delta);
    SDL_RenderClear(renderer);
    renderGamebjects();
    SDL_RenderPresent(renderer); //Will wait here
}

So the game loop won't continue to the next iteration before SDL_RenderPresent is done presenting. 
So if VSync is enabled, SDL_RenderPresent will wait the correct amount of time for the framerate 
to stay at the monitors refreshrate. So what I recommend using the delta variable for is 
calculating the physics of your game. so if you have an object that should move on the x axis, 
instead of calculating it like x += xPerFrame; you should do x += delta*xSpeedPerSecond. 
That way your objects will move at the same rate, no matter what the frame rate is.

*/