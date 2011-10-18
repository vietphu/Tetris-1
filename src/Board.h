#ifndef BOARD
#define BOARD
#include <map>
#include <string.h>
#include <vector>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "Shape_Generator.h"

using namespace std;
using namespace boost::asio;
//!\brief Represents the "playing field" or "board" of the game, and handles gameplay.
//!
struct Board
{
	//!\brief Initializes a Board object for gameplay
	//!\param boardWidth The number of units of width of the board.
	//!\param boardHeight The number of units of height of the board. Note: If you want 10 units of height, enter '11', because the first row is not displayed. It's used for spawning shapes, detecting endgame, etc...
	//!\param Levels A vector of pairs of int and byte. Each pair represents information about a particular level. The int represents the time (in milliseconds) it takes for a shape to drop by one unit. The byte represents the number of lines to be cleared until the next level. Note: The last element in the vector is the first level to be read in.
	Board(uint boardWidth, uint boardHeight, vector<pair<int, byte>> Levels);
#pragma region GET
	//!\brief Copies the current board array to board_copy.
	//!\param board_copy a pointer to a uint array that the current board array will be copied to.
	void Get_Board(uint* board_copy);

	//!
	//!\return An object that represents the currently falling shape.
	byte* Get_CurrentShape();

	//!\return The board width in block units.
	//!
	uint Get_BoardWidth();

	//!\return The board height in block units.
	//!
	uint Get_BoardHeight();

	//!\return The current X coordinate value.
	//!
	uint Get_X();

	//!\return The current Y coordinate value.
	//!
	uint Get_Y();

	//!\return An object representing the next shape to fall.
	//!
	byte* Get_NextShape();
#pragma endregion MEMBERS THAT ALLOW READ-ACCESS TO PRIVATE/PUBLIC VARIABLES
#pragma region USE
	//!\brief Begins the Update loop.
	//!
	//!Starts the game, or resumes it from a paused state.
	void StartGame();
	//!\brief Pauses the game from the update loop.
	void PauseGame();
#pragma endregion MEMBERS THAT USERS MUST UTILIZE TO SUCCESSFULLY SET UP A GAME
#pragma region INPUT

	//!\brief Moves the current shape to the left by one unit.
	void MoveLeft();

	//!\brief Moves the current shape to the right by one unit.
	void MoveRight();

	//!\brief Moves the current shape down by one unit.
	void MoveDown();

	//!\brief Rotates the current shape clockwise.
	void Rotate_Clockwise();

	//!\brief Rotates the current shape counter-clockwise.
	void Rotate_CounterClockwise();

#pragma endregion MEMBERS FOR CLASSES CONTROLLING INPUT
#pragma region PRIVATE
private:
	//!\internal \brief Points to the current board array.
	int* board;
	//!\internal \brief Contains the board width in block units.
	uint boardWidth;
	//!\internal \brief Contains the board height in block units.
	uint boardHeight;
	//!\internal \brief Stores the current (falling) shape.
	Shape currentShape;
	//!\internal \brief Contains the next shape to fall.
	Shape nextShape;
	//!\internal \brief Generates the next shape to fall, and stores it in "nextShape".
	void NextShape();
	//!\internal \brief Contains the number of lines until the next level.
	uint lines_toNextLevel;
	//!\internal \brief Contains the current level.
	byte level;
	//!\internal \brief Contains the speed that the tetrominos fall at.
	double speed;
	//!\internal \brief Reports on whether the game is over or not.
	bool IsGameOver;
	//!\internal \brief Checks the status of the game. True if over, false if still going.
	bool isGameOver();
	//!\internal \brief Saves a tetromino to the board at its resting position.
	//!\param currentShape A copy of the current shape that will be saved to the board array.
	//!\param x The x-coordinate at which to save the shape.
	//!\param y The y-coordinate at which to save the shape.
	void SaveToBoard(Shape currentShape, uint x, uint y);
	//!\internal \brief Clears a line from the board when it is filled as per standard Tetris-style play.
	void LineClear();
	//!\internal \brief Reports on whether there has been a collision or not.
	bool IsCollision();
	//!\internal \brief Stores the current game score.
	int score;
	//!\internal \brief Holds the total area (number of units) of the board array.
	uint dim;
	//!\internal \brief Contains the current x position of the current tetronimo
	uint x;
	//!\internal \brief Contains the current y position of the current tetronimo
	uint y;
	//!\internal \brief Contains the speed of each level and the lines between each level. Read in backwards. Last element is the first level.
	vector<pair<int, byte>> lines_info;
	//!\internal \brief Updates the board at intervals specified by the user in lines_info
	void Update();
	//!\internal \brief When true, game is paused.
	bool paused;
#pragma endregion PRIVATE MEMBERS THAT USERS DO NOT NEED ACCESS TO
};
#endif