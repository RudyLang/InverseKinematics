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
		ProcessInput();
		//UpdateGame();
		//GenerateOutput();
	}
}

void Game::ProcessInput()
{
	SDL_Event event;

	// While events are in the queue
	// SDL_PollEvent stores any information removed from the queue
	// Check the event type and handle it
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		// If user closes the window or hits 'x'
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}

	// Get state of keyboard (pointer to array)
	const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

	// End game loop if 'Escape' is pressed
	// Index using scancode value
	if (keyboardState[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}
}
