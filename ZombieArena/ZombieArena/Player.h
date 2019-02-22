#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;
	//Where is the player
	Vector2f m_Position;

	//Add a sprite
	Sprite m_Sprite; 

	//Add a texture
	Texture m_Texture;

	//What's the screen resolution
	Vector2f m_Resolution;

	//What size is the current arena
	IntRect  m_Arena;

	//How big is each tile of the arena
	int m_TileSize;

	//Which direction is the player currently moving in
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;

	//How much health has the player got?
	int m_Health;

	//What's the maximum health the player can have
	int m_MaxHealth;

	//When was the player last hit
	Time  m_LastHit;

	//Speed in pixels per second
	float m_Speed;

public:
	//Empty/Null constructor
	Player();

	void spawn(IntRect arena, Vector2f resolution, int tileSize);

	//Call this one at the end of each game
	void resetPlayerStats();

	//Handle the player getting hit by a zombie
	bool hit(Time timeHit);

	//How long ago was the player last hit
	Time getLastHitTime();

	//Where is the player
	FloatRect getPosition();

	//Where is the center of the player
	Vector2f getCenter();

	//Which angle is the player facing
	float getRotation();

	//Get the sprite
	Sprite getSprite();

	//Moving the player
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	//Stop the player moving in a certain direction
	void stopRight();
	void stopLeft();
	void stopUp();
	void stopDown();

	//We'll call this function once every frame to update the frame
	void update(float elapsedTime, Vector2i mousePosition);

	//Give the player a speed boost
	void upgradeSpeed();

	//Give the player some health
	void upgradeHealth();

	//Increase the player's max health
	void increaseHealthLevel(int amount);

	//How much health does the character currently have?
	int getHealth();
};