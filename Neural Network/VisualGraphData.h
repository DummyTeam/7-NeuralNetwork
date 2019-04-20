#pragma once
#include "Visualizable.h"

class VisualGraphData : public Visualizable
{
public:
	VisualGraphData(double data);
	void draw(sf::RenderWindow*);
	void setPosition(float x, float y);
	const sf::Vector2f& getPosition();
	void setData(double data);

private:
	sf::CircleShape* shape;
	double data;
};

