#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <array>


#include"GameObject.h"
using namespace std;

int main()
{
#pragma region init
	sf::Clock clock;
	const pair<int, int> dim = { 1000,1000 };

	sf::RenderWindow window(sf::VideoMode(dim.first, dim.second), "SFML works!");

	const int tileSize = 64;

#pragma region level


	string level[25] = {
	"1111111111111111111111111",
	"1100000011100000000000001",
	"1010000011100000000000001",
	"1001000000000000000000001",
	"1000000100111010000000001",
	"1000000100101010000000001",
	"1000000110111011000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000001",
	"1000000000000000000000101",
	"1000000000000000000000011",
	"1111111111111111111111111",
	};

	for (size_t i = 0; i < sizeof(level) / sizeof(level[0]); i++)
	{
		cout << level[i] << endl;
	}
#pragma endregion



#pragma region assets
	GameObject wall("wall", "Asset/wall.png");
	wall.sprite.setScale(2, 2);

	GameObject ground("ground", "Asset/ground.png");

	GameObject player("player", "Asset/player.png");
	float playerSpeed = 150;
	player.setPosition(120, 280);
	player.sprite.setOrigin(93, 100);
#pragma endregion
#pragma endregion

	while (window.isOpen())
	{

#pragma region SFLM



		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
#pragma endregion
		window.clear();
		float deltaTime = clock.restart().asSeconds();

#pragma region background



		for (size_t i = 0; i < sizeof(level) / sizeof(level[0]); i++)
		{
			string str = level[i];
			for (std::string::size_type y = 0; y < str.size(); y++) {

				if (str[y] == '1') {
					wall.setPosition(y * tileSize, i * tileSize);
					window.draw(wall.getSprite());
				}
				else {
					ground.setPosition(y * tileSize, i * tileSize);
					window.draw(ground.getSprite());
				}
			}
		}
#pragma endregion






#pragma region player
#pragma region controls

		int vertical = 0;
		int horizontal = 0;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (player.sprite.getPosition().y > 0) {
				vertical = -1;
				//player.sprite.move(0.f, -playerSpeed * deltaTime);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (player.sprite.getPosition().y < dim.second) {
				vertical = 1;
				//player.sprite.move(0.f, playerSpeed * deltaTime);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (player.sprite.getPosition().x > 0) {
				horizontal = -1;
				//player.sprite.move(-playerSpeed * deltaTime, 0.f);
			}
			player.sprite.setScale(-1, 1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (player.sprite.getPosition().x < dim.first) {
				horizontal = 1;
				//player.sprite.move(playerSpeed * deltaTime, 0.f);
			}
			player.sprite.setScale(1, 1);
		}

		int player_x = player.sprite.getPosition().x;
		int player_y = player.sprite.getPosition().y;

		int playerNext_x = player_x + playerSpeed * horizontal * deltaTime;
		int playerNext_y = player_y + playerSpeed * vertical * deltaTime;


		string nextTile = "";
		int tile_y = (playerNext_y + vertical * 2) / tileSize;
		int tile_x = (playerNext_x + vertical * 2) / tileSize;
		nextTile = level[tile_y][tile_x];
		if (nextTile != "1") {
			player.sprite.move(
				playerSpeed * horizontal * deltaTime,
				playerSpeed * vertical * deltaTime
			);
		}

		sf::RectangleShape shape(sf::Vector2f(64 - 12, 64 - 12));
		shape.setOrigin(-6, -6);
		shape.setPosition(
			round(playerNext_x / tileSize) * tileSize,
			round(playerNext_y / tileSize) * tileSize
		);


		shape.setOutlineThickness(6);
		shape.setFillColor(sf::Color(0, 0, 0, 0));
		shape.setOutlineColor(sf::Color(0, 255, 0));


		/* debug
				cout << "[" << player_x << " << " << player_y << "]\t" << player_x / tileSize << " << " << player_y / tileSize;
				cout << "\tCase " << level[player_y / tileSize][player_x / tileSize] << " Next Case " << nextTile << endl;
		*/


#pragma endregion
		window.draw(player.getSprite());
		window.draw(shape);
#pragma endregion










		window.display();
	}

	return 0;
}