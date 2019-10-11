#include "GameObject.h"
#include <iostream>

GameObject::GameObject(string nom, string url)
{
	this->nom = nom;
	this->url = url;
	if (!texture.loadFromFile(this->url)) cout << "erreur de chargement du fichier :" << this->url << endl;
	sprite.setTexture(this->texture);
}


void GameObject::setPosition(float x, float y)
{
	sprite.setPosition(x, y);

}

pair<float, float> GameObject::getPosition()
{
	return pair<float, float>(this->sprite.getPosition().x, this->sprite.getPosition().y);
}

void GameObject::move(float x, float y)
{
	sprite.setPosition(x, y);
}

string GameObject::getNom() const
{
	return nom;
}
void GameObject::setNom(string nom)
{
	this->nom = nom;
}
string GameObject::getUrl() const
{
	return url;
}
sf::Texture GameObject::getTexture() const
{
	return texture;
}
sf::Sprite GameObject::getSprite() const
{
	return sprite;
}


