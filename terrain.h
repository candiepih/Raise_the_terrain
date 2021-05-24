#ifndef TERRAIN_H
#define TERRAIN_H

#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef struct sdl_args
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int win_h;
	int win_w;
} sdl_utils;

// sdl initializations. Declarations in sdl_init.c
int initialize_sdl();
SDL_Window *create_window(sdl_utils *sdl, char* title);
void initialize_and_create_window(sdl_utils *sdl, char *window_title);
void handle_errors();
void safe_close_sdl_instance(sdl_utils *sdl);

// function prototypes responsible for rendering. Declarations in rendering.c
void create_renderer(sdl_utils* sdl);
void draw_line(sdl_utils *sdl);
void transform_data(sdl_utils* sdl, int data[8][8], SDL_Point(*data_points)[8][8], float angle);
void draw_grid(sdl_utils* sdl, SDL_Point(*data)[8][8]);
void print_points(SDL_Point data[8][8]);
void to2D(int x, int y, int z, int* x1, int* y1);

// handling program lopp and poll events. Declarations in loop_and_poll.c
void loop_and_poll(sdl_utils *sdl);
void poll_events(int *quit, SDL_Event *e);

#endif