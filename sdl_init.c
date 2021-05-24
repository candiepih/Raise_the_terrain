#include "terrain.h"

/**
 * initialize_sdl - initializes sdl
 * Returns: (-1) on Failure (0) on Success
 */

int initialize_sdl()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		handle_errors();
		return (-1);
	}
	return (0);
}

/**
 * crete_window - creates sdl window instance
 * @sdl: data structure of sdl_utils
 * @title: string pointer to be used to window title
 * Return: window of SDL_Window or Null if window creation failed
 */

SDL_Window *create_window(sdl_utils *sdl, char *title)
{
	SDL_Window *window = NULL;
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		sdl->win_w, sdl->win_h, SDL_WINDOW_SHOWN);

	return window;
}

/**
 * initialize_and_create_window - initializes sdl and creates window
 * @sdl: data structure of sdl_utils
 * @window_title: string pointer to be given to window title
 * Return: nothing
 */

void initialize_and_create_window(sdl_utils *sdl, char *window_title)
{
	if (initialize_sdl() < 0)
		safe_close_sdl_instance(sdl);
	sdl->window = create_window(sdl, window_title);
	if (!sdl->window)
	{
		handle_errors();
		safe_close_sdl_instance(sdl);
	}
}

/**
 * handle_errors - handles output errors
 * Return: nothing
 */

void handle_errors()
{
	printf("Error: %s\n", SDL_GetError());
}

/**
 * safe_close_sdl_instance - frees and closes sdl
 * @sdl: data structure of sdl_utils
 * Return: nothing
 */

void safe_close_sdl_instance(sdl_utils *sdl)
{
	if (sdl->window != NULL)
		SDL_DestroyWindow(sdl->window);
	if (sdl->renderer != NULL)
		SDL_DestroyRenderer(sdl->renderer);
	SDL_Quit();
}