#include "pch.h"
#include "Game.h"

Game::Game() :mIsRunning(true)
{

}

bool Game::Initialize()
{
	
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);

	if (sdlResult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	mWindow = SDL_CreateWindow(
		"2D Inverse Kinematics", // Window Title
		100, // Top left x-coordinate of window
		100, // Top left y-coordinate of window
		1024, // Width of window
		768, // Height of window
		0 // Flags
	);

	if (!mWindow)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	return true;
}

void Game::Shutdown()
{
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::RunLoop()
{
	while (mIsRunning)
	{
		//ProcessInput();
		//UpdateGame();
		//GenerateOutput();
	}
}

