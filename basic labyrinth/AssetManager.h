#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <array>
#include <map>
#include <vector>

using namespace std;

class AssetManager
{
public:
	map<string, sf::Sprite> s;

	void addSprite(string name, string destination);
	sf::Sprite sget(string name);


};

