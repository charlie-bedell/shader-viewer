#include <stdio.h>
#include "raylib.h"

int main(void) {
	printf("hello, world!");
	
	InitWindow(500, 500, "noyabai window");
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);
		DrawText("Hello, world!", 50, 100, 20, BLACK);
		EndDrawing();
	}
	CloseWindow();
}
