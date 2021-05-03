#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	/**
	 * initializing sdl
	 */

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable to initialize sdl: %s\n", SDL_GetError());
	}
	else
	{
		printf("Success while initializing sdl\n");
	}
	return (0);
}
