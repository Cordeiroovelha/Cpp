#include <raylib.h>
#include "Player.h"
using namespace std;

constexpr Color green = {173, 204, 96, 255};
constexpr Color darkGreen = {43, 51, 24, 255};

int main(void){
	constexpr int width{800}, height{600};
	InitWindow(width, height, "Janela");
	SetTargetFPS(60);
	InitAudioDevice();
	ChangeDirectory(GetApplicationDirectory());
	
	Player player;
	Music bgMusic = LoadMusicStream("Assets/music.mp3");
	float deltaTime = GetFrameTime();
	
	PlayMusicStream(bgMusic);
	
	while(!WindowShouldClose()){
		
		BeginDrawing();
		
		player.Update(deltaTime);
		player.CheckScreenLimits();
		
		ClearBackground(green);
		player.Draw();
		DrawFPS(width - 90, 0);
		// DrawCircle(width / 2, height / 2, 50, WHITE);
		
		EndDrawing();
	}
	
	UnloadMusicStream(bgMusic);
	CloseWindow();
	return 0;
}