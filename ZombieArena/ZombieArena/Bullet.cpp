#include "pch.h"
#include "Bullet.h"


Bullet::Bullet()
{
	m_BulletShape.setSize(sf::Vector2f(2, 2));
}

void Bullet::stop()
{
	m_InFlight = false;
}

bool Bullet::isInFlight()
{
	return m_InFlight;
}

void Bullet::shoot(float startX, float startY, float xTarget, float yTarget)
{
	//Keep track of the bullet
	m_InFlight = true;
	m_Position.x = startX;
	m_Position.y = startY;

	//Calculate the gradient (slope) of the flight path
	float gradient = (startX = xTarget) / (startY - yTarget);
	
	//Any gradient less than 0 needs to be negative
	if (gradient < 0) {
		gradient *= -1;
	}

	//Calculate the ratio between x and t
	float ratioXY = (m_BulletSpeed / (1 + gradient));

	//Set the "speed" horizontallyl and vertically
	m_BulletDistanceX = ratioXY;
	m_BulletDistanceY = ratioXY * gradient;

	//Point the bullet in the right direction
	if (xTarget > startX) {
		m_BulletDistanceX *= -1;
	}

	if (yTarget < startY) {
		m_BulletDistanceY *= -1;
	}

	//Set a max range of 1000 pixels
	float range = 1000;
	m_MinX = startX - range;
	m_MaxX = startX + range;
	m_MinY = startY - range;
	m_MaxY = startY + range;
	
	//Position the bullet ready to be drawn
	m_BulletShape.setPosition(m_Position);

}

FloatRect Bullet::getPosition()
{
	return m_BulletShape.getLocalBounds();
}

RectangleShape Bullet::getShape()
{
	return m_BulletShape;
}

void Bullet::update(float elapsedTime)
{
	//Update the bullet position variables
	m_Position.x += m_BulletDistanceX * elapsedTime;
	m_Position.y += m_BulletDistanceY * elapsedTime;

	//Move the bullet
	m_BulletShape.setPosition(m_Position);

	//Has the bullet gone out of range?
	if (m_Position.x < m_MinX || m_Position.x > m_MaxX || m_Position.y < m_MinY || m_Position.y > m_MaxY) {
		m_InFlight = false;
	}
}
