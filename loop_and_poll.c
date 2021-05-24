#include "terrain.h"

void loop_and_poll(sdl_utils *sdl)
{
	int quit = 0;
	SDL_Event e;
	while (!quit)
	{
		poll_events(&quit, &e);
		SDL_SetRenderDrawColor(sdl->renderer, 0x00, 0x00, 0x00, 0xFF);
		draw_line(sdl);
	}
}

void poll_events(int *quit, SDL_Event *e)
{
	while (SDL_PollEvent(e) != 0)
	{
		if (e->type == SDL_QUIT)
			*quit = 1;
		switch (e->key.keysym.sym)
		{
		case SDLK_ESCAPE:
			*quit = 1;
			break;
		default:
			break;
		}
	}
}