#include <raylib.h>
#include "Player.h"

Player::Player(){
	texture = LoadTexture("Assets/player.png");
	position.x = ((GetScreenWidth() - texture.width) / 2);
	position.y = ((GetScreenHeight() - texture.height) / 2);
	speed = 15.0f;
}
	
Player::~Player(){
	UnloadTexture(texture);
}
	
void Player::Draw() const{
	DrawTexture(texture, position.x, position.y, RAYWHITE);
}
	
void Player::Update(float deltaTime){
	
	if(IsKeyDown(KEY_DOWN))
		position.y += speed * deltaTime;
	if(IsKeyDown(KEY_UP))
		position.y -= speed * deltaTime;
	if(IsKeyDown(KEY_LEFT))
		position.x -= speed * deltaTime;
	if(IsKeyDown(KEY_RIGHT))
		position.x += speed * deltaTime;
	
	CheckScreenLimits();
}
	
void Player::CheckScreenLimits(){
	if(position.y + texture.height >= GetScreenHeight()){
		position.y = GetScreenHeight() - texture.height;
	}
	if(position.y <= 0){
		position.y = 0;
	}
	if (position.x + texture.width >= GetScreenWidth()){
		position.x = GetScreenWidth() - texture.width;
	}
	if (position.x <= 0){
		position.x = 0;
	}
}