#include "Board.h"
//Public
Board::Board(uint boardWidth, uint boardHeight, vector<pair<int, byte>> Levels)
{
	Board::boardHeight = boardHeight;
	Board::boardWidth = boardWidth; 
	dim = boardWidth * boardHeight;
	board = new int[boardWidth * boardHeight];
	paused = false;
	Shape_Generator::init();
	nextShape = Shape_Generator::Next_Shape();
	NextShape();
	lines_info = Levels;
	lines_toNextLevel = lines_info.back().second;
	speed = lines_info.back().first;
	level = 0;
}
#pragma region GET
void Board::Get_Board(uint* board_copy)
{
	memcpy(board_copy, board, dim);
}

byte* Board::Get_CurrentShape()
{
	return currentShape.currentRotation;
}

uint Board::Get_BoardWidth()
{
	return Board::boardWidth;
}

uint Board::Get_BoardHeight()
{
	return Board::boardHeight;
}

uint Board::Get_X()
{
	return x;
}

uint Board::Get_Y()
{
	return y;
}

byte* Board::Get_NextShape()
{
	return nextShape.currentRotation;
}
#pragma endregion
#pragma region USE
void Board::StartGame()
{
	paused = false;
	while (true)
	{
		if ((isGameOver() == false) || (paused == false))
		{
			Update();
		}
		else
		{
			break;
		}
	}
}

void Board::PauseGame()
{
	paused = true;
}
#pragma endregion
#pragma region INPUT
void Board::MoveLeft()
{
	x--;
	if (IsCollision())
	{
		x++;
	}
}

void Board::MoveRight()
{
	x++;
	if (IsCollision())
	{
		x--;
	}
}

void Board::MoveDown()
{
	y++;
	if (IsCollision())
	{
		y--;
	}
}

void Board::Rotate_Clockwise()
{
	currentShape.Rotate(true);
	if (IsCollision())
	{
		Rotate_CounterClockwise();
	}
}

void Board::Rotate_CounterClockwise()
{
	currentShape.Rotate(false);
	if (IsCollision())
	{
		Rotate_Clockwise();
	}
}
#pragma endregion
#pragma region PRIVATE
void Board::Update()
{
	io_service io;
	deadline_timer t(io, boost::posix_time::milliseconds(lines_info.back().first));
	t.wait();

	y++;

	if (IsCollision())
	{
		y--;
		SaveToBoard(currentShape, x, y);
		NextShape();
	}
	LineClear();
	if(lines_toNextLevel == 0)
	{
		lines_info.pop_back();
		level++;
		lines_toNextLevel = lines_info.back().second;
		speed = lines_info.back().first;
	}
}

void Board::SaveToBoard(Shape currentShape, uint x, uint y)
{
	for (uint p_x = 0; p_x < 5; p_x++)
	{
		for (uint p_y = 0; p_y < 5; p_y++)
		{
			if (currentShape.currentRotation[p_x, p_y] != 0)
			{
				board[x + p_x, y + p_y] = currentShape.currentRotation[p_x, p_y];
			}
		}
	}
}

void Board::LineClear()
{
	vector<int> lines;
	int j;
	for(uint q = 0; q < boardHeight; q++)
	{j = 0;
		for(uint z = 0; z < boardWidth; z++)
		{
			if(board[q, z] >= 1)
			{
				j++;
				if (j == boardWidth)
				{
					lines.push_back(q);
					if (lines_toNextLevel != 0)
					{
						lines_toNextLevel--;
					}
				}
			}
		}
	}

	for (uint q = 0; q < lines.size(); q++)
	{
		for(uint z = 0; z < boardWidth; z++)
		{
			for (uint k = lines[q]; k > 0; k--)
			{
				board[lines[q] - k, z] = board[lines[q] - k - 1, z];
			}
		}
	}
}

bool Board::IsCollision()
{
	for (uint p_y = 0; p_y < 5; p_y++)
	{
		for (uint p_x = 0; p_x < 5; p_x++)
		{
			if (currentShape.currentRotation[p_y, p_x] != 0)
			{
				if (board[y + p_y, x + p_x] >= 1)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool Board::isGameOver()
{
	for(uint q = 0; q < boardWidth; q++)
	{
		if(board[0, q] >= 1)
		{
			return true;
		}
	}
	return false;
}

void Board::NextShape()
{
	currentShape = nextShape;
	nextShape = Shape_Generator::Next_Shape();
	//Shape* temp = Shape_Generator::Next_Shape();
	//nextShape = *temp;
	//delete temp;
	y = 0;
	x = boardWidth / 2;
}
#pragma endregion