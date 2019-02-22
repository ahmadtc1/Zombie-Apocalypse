#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet {
private:
	//where is the bullet?
	Vector2f m_Position;

	//WHat each bullet looks like
	RectangleShape m_BulletShape;

	//Is the bullet currently whizzing thru the air?
	bool m_InFlight = false;

	//How fast does a bullet travel?
	float m_BulletSpeed = 1000;

	//What fraction of 1 pixel does the bullet travel vertically and horizontally each frame?
	//These values will be derived from m_BulletSpeed
	float m_BulletDistanceX;
	float m_BulletDistanceY;

	//Some boundaries so the bullet doesn't fly forever
	float m_MaxX;
	float m_MinX;
	float m_MaxY;
	float m_MinY;

	//Public function prototypes go here
public:
	//The constructor
	Bullet();

	//Stop the bullet
	void stop();

	//Returns the value of m_inFlight
	bool isInFlight();

	//Launch a new bullet
	void shoot(float startX, float startY, float xTarget, float yTarget);

	//Tell the calling code whre the bullet is in the woirld
	FloatRect getPosition();

	//Return the actual shape (for drawing)
	RectangleShape getShape();

	//Update the bullet each frame
	void update(float elapsedTime);
};