#pragma once

#include "SDL.h"

class Game {
public:
	Game();

	bool Initialize(); // Initialize the game
	
	void RunLoop(); // Runs the game loop until over
	void Shutdown(); // Shutdown the game

private:
	// Helper Functions
	//void ProcessInput();
	//void UpdateGame();
	//void GenerateOutput();

	// SDL window object
	SDL_Window* mWindow;

	// Flag to check if window is open
	bool mIsRunning;
};
