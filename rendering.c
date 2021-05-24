#include "terrain.h"

void create_renderer(sdl_utils *sdl)
{
	sdl->renderer = SDL_CreateRenderer(sdl->window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (sdl->renderer == NULL)
	{
		handle_errors();
		safe_close_sdl_instance(sdl);
	}
}

void draw_line(sdl_utils *sdl)
{
	int arr[8][8] = {
		{120, 60, 40, 60, 20, -20, -80, -120},
		{40, 20, 30, 30, -10, -40, -90, -110},
		{20, 30, 10, 06, -6, -20, -26, -90},
		{00, -6, 10, 10, -6, -20, -20, -40},
		{-20, -20, -18, -14, -40, -20, -20, -30},
		{-10, -10, -10, -10, -8, -20, -20, -30},
		{20, 10, 10, 10, 10, 04, 10, -10},
		{30, 24, 24, 22, 20, 18, 14, 16}
	};
	SDL_Point points[8][8];

	SDL_SetRenderDrawColor(sdl->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	transform_data(sdl, arr, &points, 0);
	draw_grid(sdl, points);
	/*for (y = 0; y < 8; y++)
	{
		for (x = 0; x < 8; x++)
		{
			SDL_FPoint *point;
			point = convert_to_2D(x, y, arr[y][x]);
			points[y][x].x = point->x;
			points[y][x].y = point->y;
		}
	}*/

	SDL_RenderPresent(sdl->renderer);
}
void transform_data(sdl_utils *sdl, int data[8][8], SDL_Point(*data_points)[8][8], float angle)
{
	int margin = 20;
	int i = 0, j = 0, Rx = 0, Ry = 0, x = 0, y = 0, X = 0, Y = 0;
	int min_y = 0, min_x = 0, max_x = INT_MIN, max_y = INT_MIN;
	int min_dim = (sdl->win_h < sdl->win_w) ? sdl->win_h : sdl->win_w;
	int box_width = min_dim - 2 * margin;
	int box_height = min_dim - 2 * margin;
	int dy = (box_height / (8 - 1)), dx = (box_width / (8 - 1));
	int xOffset = (sdl->win_w - box_width) / 2 - 100;
	int yOffset = (sdl->win_h - box_height) / 2 + 100;

	(void)(angle), (void)(Rx), (void)(Ry);
	/*Transform the data from 3d space to into 2d*/
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			printf("dx: %d dy: %d\n", box_width, dy);
			x = j * dx;
			y = i * dy;
			to2D(x, y, data[i][j], &X, &Y);
			(*data_points)[i][j].x = X;
			(*data_points)[i][j].y = Y;
			if (X < min_x)
				min_x = X;
			if (Y < min_y)
				min_y = Y;
			j++;
		}
		i++;
	}

	/*Make the minimum value 0 and add the offsets*/
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			(*data_points)[i][j].x += -1 * min_x + xOffset;
			(*data_points)[i][j].y += -1 * min_y + yOffset;

			X = (*data_points)[i][j].x;
			Y = (*data_points)[i][j].y;
			if (max_x < X)
				max_x = X;
			if (max_y < Y)
				max_y = Y;

			j++;
		}
		i++;
	}
	printf("am printing points\n");
	print_points(*data_points);
}

void draw_grid(sdl_utils *sdl, SDL_Point(*data)[8][8])
{
	int i = 0, j = 0, Wy = 0, Wx = 0, X = 0, Y = 0;

	/*Draw rows first*/
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8 - 1)
		{

			X = (*data)[i][j].x;
			Y = (*data)[i][j].y;

			Wx = (*data)[i][j + 1].x;
			Wy = (*data)[i][j + 1].y;

			SDL_RenderDrawLine(sdl->renderer, X, Y, Wx, Wy);
			j++;
		}
		i++;

	}
	i = 0;
	/*Draw colsggregate value used where a float was expected first*/
	while (i < 8 - 1)
	{
		j = 0;
		while (j < 8)
		{

			X = (*data)[i][j].x, Y = (*data)[i][j].y;
			Wx = (*data)[i + 1][j].x, Wy = (*data)[i + 1][j].y;

			SDL_RenderDrawLine(sdl->renderer, X, Y, Wx, Wy);
			j++;
		}
		i++;

	}
	SDL_RenderPresent(sdl->renderer);
}

void to2D(int x, int y, int z, int* x1, int* y1)
{
	float inclination = 0.7;
	*x1 = inclination * x - inclination * y;
	*y1 = (1 - inclination) * x + (1 - inclination) * y - z;
}

void print_points(SDL_Point data[8][8])
{
	int i = 0, j = 0;

	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			printf("{%i, %i} ", data[i][j].x, data[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}

}