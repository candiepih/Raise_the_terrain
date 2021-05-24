#include "terrain.h"

int main(int argc, char** argv)
{
	sdl_utils sdl = {NULL, NULL, 700, 1200};

	initialize_and_create_window(&sdl, "SDL ISOMETRIC PROJECTION");
	create_renderer(&sdl);
	if (sdl.window && sdl.renderer)
		loop_and_poll(&sdl);
	safe_close_sdl_instance(&sdl);

	return (0);
}