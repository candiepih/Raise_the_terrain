# Raise_the_terrain
Demonstrates use of SDL2 in Graphics programming.
`Simple DirectMedia Layer` (SDL) is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. It is used by video playback software, emulators, and games. SDL is written in C, works natively with C++


Using the following coordinates

    {120, 60, 40, 60, 20, -20, -80, -120},
		{40, 20, 30, 30, -10, -40, -90, -110},
		{20, 30, 10, 06, -6, -20, -26, -90},
		{00, -6, 10, 10, -6, -20, -20, -40},
		{-20, -20, -18, -14, -40, -20, -20, -30},
		{-10, -10, -10, -10, -8, -20, -20, -30},
		{20, 10, 10, 10, 10, 04, 10, -10},
		{30, 24, 24, 22, 20, 18, 14, 16}

The value of z is 120 at position x = 0, y = 0
We can draw an isometric projection of a grid after translating 3D coordinates to 2D coordinates as follows:-

WX = inclination * X - inclination * Y;
WY = (1 - inclination) * X + (1 - inclination) * Y - Z;

where an `inclination` of 70% would have a value of `0.7` in this above equation.

The transformed grid would look like this:-

![terain](https://user-images.githubusercontent.com/44834632/119358650-8023df80-bcb1-11eb-8e2f-8b5e8fd2ba15.png)
