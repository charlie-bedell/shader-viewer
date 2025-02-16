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
	
	int uTimeLoc = GetShaderLocation(shader, "uTime");
	int uMouseLoc = GetShaderLocation(shader, "uMouse");
	int uResolutionLoc = GetShaderLocation(shader, "uResolution");

	if (uTimeLoc == -1 || uResolutionLoc == -1) {printf("unable to find shader uniforms!\n");return 1;}

	float time = 0.0f;
	Rectangle rect = {25, 25, 750, 750};
	Vector2 resolution = {WINDOW_W, WINDOW_H};

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
