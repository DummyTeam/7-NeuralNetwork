#pragma once

#include <vector>
#include "Weight.h"
#include "Squishification.h"

class Layer;

class Neuron : public Visualizable
{
public:
	// Constructor with default ReLU squish
	Neuron(int id);

	// Constructor
	Neuron(Squishification* squishification);

	// Mutual init for all constructors
	void init();

	// Clear enough
	int getId();

	// Clear enough
	double getBias();

	// Returns activation value of neuron
	double getActivationValue();

	// Clear enough
	void setDelta(double);

	// Clear enough
	double getDelta();

	// Clear enough
	void setActivationValue(double);

	// Squishes sum of (weights*sourceActivation + b)
	double squish(double value);

	// Create weights, push_back to weights vector
	void initWeightsAndBias(std::vector<Neuron*> &neurons);

	// Calulates activation: a = f( weights * sourceActivation + b );
	void calculateActivation();

	// Calculate delta
	void calculatePreviousLayerNeuronDelta();

	// Updates weights and biases
	void updateWeightAndBias(double learningRate);

	// Calculates output layer delta
	void calculateOutputNeuronDelta(double);

	std::vector<Weight*> & getInconmingWeights();

	// Custom draw implementation
	void draw(sf::RenderWindow*, bool);

	sf::CircleShape* getShape();

	const sf::Vector2f& getInitPoint();
	sf::Vector2f getCenterPoint();

	sf::Text* getText();

private:
	int id;
	double bias;
	double activation;
	double delta;
	int type;
	Squishification* squishification;
	std::vector<Weight*> weights; // Incoming
	std::vector<Weight*> outgoingWeights; // Outgoing

	sf::CircleShape* shape;
	sf::Text* text;
	sf::Font* font;

	float shapeWidth;
	float shapeHeight;

	// Visualizable implementation
	void draw(sf::RenderWindow*);
};
