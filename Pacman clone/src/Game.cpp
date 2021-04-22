#include "pch.h"
#include "Game.h"

Game::Game()
	: gameRunning(true), dt(), 
	  tiles{ {1, 3, 3, 3, 3, 3, 3, 3, 3, 5, 44, 44, 44, 11, 44, 13, 44, 44, 44, 1, 3, 3, 3, 3, 7, 9, 3, 3, 3, 3, 5},
	  {10, 45, 45, 47, 45, 45, 45, 45, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 45, 45, 47, 15, 20, 45, 45, 45, 45, 12},
	  {10, 45, 23, 25, 27, 45, 39, 27, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 23, 27, 45, 22, 26, 45, 23, 27, 45, 12},
	  {10, 45, 15, 44, 21, 45, 15, 20, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 15, 20, 45, 45, 45, 45, 15, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 15, 20, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 15, 35, 25, 25, 27, 45, 15, 20, 45, 12},
	  {10, 45, 22, 24, 26, 45, 38, 26, 45, 22, 3, 3, 3, 26, 44, 38, 3, 3, 3, 26, 45, 22, 24, 24, 24, 26, 45, 15, 20, 45, 12},
	  {10, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 15, 20, 45, 12},
	  {10, 45, 23, 25, 27, 45, 23, 25, 25, 25, 25, 25, 25, 27, 44, 39, 25, 25, 25, 27, 45, 39, 27, 45, 23, 25, 25, 37, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 22, 24, 24, 36, 23, 24, 24, 26, 44, 38, 24, 24, 24, 26, 45, 15, 20, 45, 22, 24, 24, 36, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 45, 45, 45, 15, 20, 44, 44, 44, 44, 44, 44, 44, 44, 44, 45, 15, 20, 45, 45, 45, 45, 15, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 39, 27, 45, 15, 20, 44, 29, 2, 2, 2, 31, 44, 23, 27, 45, 15, 20, 45, 23, 27, 45, 15, 20, 45, 12},
	  {10, 45, 22, 24, 26, 45, 15, 20, 45, 22, 26, 44, 13, 44, 44, 44, 11, 44, 15, 20, 45, 22, 26, 45, 15, 20, 45, 22, 26, 45, 12},
	  {10, 45, 45, 45, 45, 45, 15, 20, 45, 44, 44, 44, 33, 44, 44, 44, 11, 44, 15, 20, 45, 45, 45, 45, 15, 20, 45, 45, 45, 45, 12},
	  {43, 25, 25, 25, 27, 45, 15, 35, 25, 25, 27, 44, 44, 44, 44, 44, 11, 44, 15, 35, 25, 25, 27, 44, 15, 35, 25, 25, 27, 45, 12},
	  {42, 24, 24, 24, 26, 45, 15, 34, 24, 24, 26, 44, 44, 44, 44, 44, 11, 44, 15, 34, 24, 24, 26, 44, 15, 34, 24, 24, 26, 45, 12},
	  {10, 45, 45, 45, 45, 45, 15, 20, 45, 44, 44, 44, 32, 44, 44, 44, 11, 44, 15, 20, 45, 45, 45, 45, 15, 20, 45, 45, 45, 45, 12},
	  {10, 45, 23, 25, 27, 45, 15, 20, 45, 23, 27, 44, 13, 44, 44, 44, 11, 44, 15, 20, 45, 23, 27, 45, 15, 20, 45, 39, 27, 45, 12},
	  {10, 45, 15, 44, 21, 45, 38, 26, 45, 15, 20, 44, 28, 3, 3, 3, 30, 44, 22, 26, 45, 15, 21, 45, 22, 26, 45, 15, 21, 45, 12},
	  {10, 45, 15, 44, 21, 45, 45, 45, 45, 15, 20, 44, 44, 44, 44, 44, 44, 44, 44, 44, 45, 15, 20, 45, 45, 45, 45, 15, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 23, 25, 25, 37, 35, 25, 25, 27, 44, 39, 25, 25, 25, 27, 45, 15, 21, 45, 23, 25, 25, 37, 20, 45, 12},
	  {10, 45, 22, 24, 26, 45, 22, 24, 24, 24, 24, 24, 24, 26, 44, 38, 24, 24, 24, 26, 45, 38, 26, 45, 22, 24, 24, 36, 20, 45, 12},
	  {10, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 15, 20, 45, 12},
	  {10, 45, 23, 25, 27, 45, 39, 27, 45, 23, 2, 2, 2, 27, 44, 39, 2, 2, 2, 27, 45, 23, 25, 25, 25, 27, 45, 15, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 15, 20, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 15, 34, 24, 24, 26, 45, 15, 20, 45, 12},
	  {10, 45, 15, 44, 21, 45, 15, 20, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 15, 20, 45, 45, 45, 45, 15, 20, 45, 12},
	  {10, 45, 22, 24, 26, 45, 38, 26, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 22, 26, 45, 23, 27, 45, 38, 26, 45, 12},
	  {10, 45, 45, 47, 45, 45, 45, 45, 45, 13, 44, 44, 44, 11, 44, 13, 44, 44, 44, 11, 45, 45, 45, 47, 15, 20, 45, 45, 45, 45, 12},
	  {0, 2, 2, 2, 2, 2, 2, 2, 2, 4, 44, 44, 44, 11, 44, 13, 44, 44, 44, 0, 2, 2, 2, 2, 6, 8, 2, 2, 2, 2, 4}}
{
	//Window
	mWindow.create(sf::VideoMode(448, 496), "Pacman clone ", sf::Style::Close);
	mWindow.setFramerateLimit(144);
	std::cout << "[Game]: Window created" << "\n";

	//Tile map
	map.load("Textures/map.png", sf::Vector2u(16, 16), tiles, 28, 31);
}

Game::~Game()
{
	std::cout << "[Game]: Game is over" << "\n";
}

bool Game::isGameRunning()
{
	return gameRunning;
}

void Game::pollEvents()
{
	sf::Event ev;

	while (mWindow.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			gameRunning = false;
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			gameRunning = false;
	}
}

void Game::updateDt()
{
	dt = clock.restart().asSeconds();
}

void Game::updatePacmanMovement()
{
	int pacmanTileX = pacman.getTileX();
	int pacmanTileY = pacman.getTileY();

	if (pacman.getDirection() == Pacman_Directions::Directions::UP)
	{
		if (tiles[pacmanTileX][pacmanTileY - 1] == 44 || tiles[pacmanTileX][pacmanTileY - 1] == 45 || tiles[pacmanTileX][pacmanTileY - 1] == 47)
			pacman.move(0.f, -1.f, dt);
	}
	else if (pacman.getDirection() == Pacman_Directions::Directions::DOWN)
	{
		if (tiles[pacmanTileX][pacmanTileY + 1] == 44 || tiles[pacmanTileX][pacmanTileY + 1] == 45 || tiles[pacmanTileX][pacmanTileY + 1] == 47)
			pacman.move(0.f, 1.f, dt);
	}
	else if (pacman.getDirection() == Pacman_Directions::Directions::LEFT)
	{
		if (tiles[pacmanTileX - 1][pacmanTileY] == 44 || tiles[pacmanTileX - 1][pacmanTileY] == 45 || tiles[pacmanTileX - 1][pacmanTileY] == 47)
			pacman.move(-1.f, 0.f, dt);
	}
	else if (pacman.getDirection() == Pacman_Directions::Directions::RIGHT)
	{
		if (tiles[pacmanTileX + 1][pacmanTileY] == 44 || tiles[pacmanTileX + 1][pacmanTileY] == 45 || tiles[pacmanTileX + 1][pacmanTileY] == 47)
			pacman.move(1.f, 0.f, dt);
	}
}

void Game::update()
{
	pollEvents();

	//Pacman movement
	pacman.update(dt);
	updatePacmanMovement();
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(map);
	pacman.render(mWindow);
	mWindow.display();
}

void Game::run()
{
	while (isGameRunning())
	{
		updateDt();
		update();
		render();
	}
}
