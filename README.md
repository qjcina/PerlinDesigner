# PerlinDesigner
Qt-based desktop application for "desigining" pseudo-random noise functions.
Periln Designer allows you to mix multiple "octaves" of noises or 2d functions into single one.
All octaves are discribed as JavaScript functions with additional Perlin Designer extenstion-functions.

## Screenshots:
<p align="center">
 <img src="https://github.com/qjcina/PerlinDesigner/blob/master/images/screenshot1.png" />
</p>

## Extension functions
All extension functions are added to `MathPD` object. They are written in C++ but are used by JavaScript in `NoiseEngine` class.
- `perlinNoise(x ,y)` - Generates perlin noise value for 2d point.
- `whiteNoise(x, y)` - Simple 2D white noise function.
- `randomNoise(x, y)` - Same as whiteNoise, but uses floating-point values instead of integers.

## TODO:
- Additional extenstion functions
- Different display methods
