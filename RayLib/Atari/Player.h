#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

class Player {
private:
	Texture2D texture;
	Vector2 position;
	int speed;
public:
	Player();
	
	~Player();
	
	void Draw() const;
	
	void Update(float deltaTime);
	
	void CheckScreenLimits();
	
};

#endif