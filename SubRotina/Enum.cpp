#include <print>
#include <iostream>
#include <string>

enum class GameStatus{
    MainMenu,
    Playing,
    Pause,
    GameOver
};

void ShowStatus(GameStatus status){
    switch (status) {
    case GameStatus::MainMenu:
        std::println("=== Main Menu ===\n"); break;
    case GameStatus::Pause:
        std::println("=== Pause ===\n"); break;
    case GameStatus::Playing:
        std::println("=== Playing ===\n"); break;
    case GameStatus::GameOver:
        std::println("=== Game Over ===\n"); break;
    default:
        break;
    }
}

int main(void){

    GameStatus status = GameStatus::MainMenu;
    ShowStatus(status);

    status = GameStatus::Pause;
    ShowStatus(status);

    status = GameStatus::Playing;
    ShowStatus(status);

    status = GameStatus::GameOver;
    ShowStatus(status);

    return 0;
}