#include "main.h"
#include "imgui.h"
#include "rlImGui.h"

float ScaleToDPIF(float value)
{
	return GetWindowScaleDPI().x * value;
}

int ScaleToDPII(int value)
{
	return int(GetWindowScaleDPI().x * value);
}

void RunGame()
{
	int screenWidth = 1280;
	int screenHeight = 800;

	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(screenWidth, screenHeight, "raylib-Extras [ImGui] example - simple ImGui Demo");
	SetTargetFPS(144);
	rlImGuiSetup(true);

	Texture image = LoadTexture("resources/parrots.png");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		rlImGuiBegin();

		bool open = true;
		ImGui::ShowDemoWindow(&open);

		open = true;
		if (ImGui::Begin("Test Window", &open))
		{
			ImGui::TextUnformatted(ICON_FA_JEDI);
			rlImGuiImage(&image);
		}
		ImGui::End();

		rlImGuiEnd();

		EndDrawing();
	}

	rlImGuiShutdown();
	UnloadTexture(image);
	CloseWindow();
}

int main(int argc, char* argv[])
{
	RunGame();
	return 0;
}