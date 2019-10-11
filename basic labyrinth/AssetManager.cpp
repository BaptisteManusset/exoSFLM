#include "AssetManager.h"

void AssetManager::addSprite(string name, string destination)
{

	sf::Texture text;
	if (!text.loadFromFile(destination)) cout << "erreur de chargement du fichier " << destination << endl;
	sf::Sprite sprite;
	sprite.setTexture(text);
	sprite.setScale(2, 2);
	this->s.insert(pair<string, sf::Sprite>(name, sprite));

}

sf::Sprite  AssetManager::sget(string name)
{
	if (this->s.find(name) != s.end()) { 
	return	this->s.find(name)->second; 
	}
	
}
