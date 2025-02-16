#include <stdio.h>
#include "raylib.h"
#include "rlgl.h"

#if defined(PLATFORM_DESKTOP)
  #define GLSL_VERSION 330
#else // PLATFORM_ANDROID, PLATFORM_WEB
  #define GLSL_VERSION 100
#endif

#define WINDOW_W 800
#define WINDOW_H 800


int main(void) {

	InitWindow(WINDOW_W, WINDOW_H, "noyabai window");

	Shader shader = LoadShader(0, "shaders/template.fs");
	if (shader.id == 0) {printf("shader failed to load!\n"); return 1;}
	
	int uTimeLoc = GetShaderLocation(shader, "uTime"); // not currently used
	int uMouseLoc = GetShaderLocation(shader, "uMouse"); // not currently used
	int uResolutionLoc = GetShaderLocation(shader, "uResolution");

	if (uTimeLoc == -1 || uResolutionLoc == -1) {printf("unable to find shader uniforms!\n");return 1;}
	// i guess these fail if you don't use them in the shader
	// let raylib handle this issue itself for the time being
	// if (uTimeLoc == -1 || uResolutionLoc == -1 || uMouseLoc == -1) {printf("unable to find shader uniforms!\n");return 1;}
	// TODO: need to work on figuring out the resolution, its relation to the window, and its mapping to the rectangle
	float time = 0.0f;
	Rectangle rect = {0, 0, WINDOW_W, WINDOW_H};
	Vector2 resolution = {1600.0f, 1600.0f};

	SetShaderValue(shader, uTimeLoc, &time, SHADER_UNIFORM_FLOAT);
	SetShaderValue(shader, uResolutionLoc, &resolution, SHADER_UNIFORM_VEC2);

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		// UPDATE
		time = (float)GetTime();
		SetShaderValue(shader, uTimeLoc, &time, SHADER_UNIFORM_FLOAT);
		SetShaderValue(shader, uResolutionLoc, &resolution, SHADER_UNIFORM_VEC2);
		// END UPDATE

		// DRAW
		BeginDrawing();

		ClearBackground(BLACK);
		BeginShaderMode(shader);
		DrawRectangleRec(rect, WHITE);
		EndShaderMode();

		EndDrawing();
		// END DRAW
	}
	UnloadShader(shader);
	CloseWindow();

	return 0;
}
