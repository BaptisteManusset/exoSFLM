#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
class GameObject
{
private:

	string nom;
	string url;
	sf::Texture texture;
public:
	sf::Sprite sprite;


	GameObject(string nom, string url);

	void setPosition(float x, float y);
	pair<float, float> getPosition();
	void move(float x, float y);
	string getNom() const;
	void setNom(string nom);
	string getUrl() const;
	sf::Texture getTexture() const;
	sf::Sprite getSprite() const;
};

