#ifndef SHAPE
#define SHAPE
#include "utils.h"
//!\internal \brief This struct defines what a tetromino is. 
//!A Shape is described by four 2D arrays (one for each possible rotation of the tetromino)
struct Shape{
	//!\internal \brief Constructor ensures that R0 is the form that each shape spawns in.
	//!It does so by setting the rotationIndex to 0;
	Shape()
	{
		rotationIndex = 0;
	}
	//!\internal \brief The first of four possible states (arrays) of a tetromino.
	//!
	byte R0[5][5];
	//!\internal \brief The second of four possible states (arrays) of a tetromino.
	//!
	byte R1[5][5];
	//!\internal \brief The third of four possible states (arrays) of a tetromino.
	//!
	byte R2[5][5];
	//!\internal \brief The fourth of four possible states (arrays) of a tetromino.
	//!
	byte R3[5][5];
	//!\internal \brief Rotates a shape.
	//!\param clockwise Rotates clockwise if true, counter-clockwise if argument is false.
	//!Either increments or decrements (depending on argument) the rotationIndex, and sets currentRotation to equal the appropriate rotation array.
	void Rotate(bool clockwise)
	{
		if (clockwise)
		{
			if (rotationIndex == 3)
			{
				rotationIndex = 0;
			}
			else
			{
				rotationIndex++;
			}
		}
		else
		{
			if (rotationIndex == 0)
			{
				rotationIndex = 3;
			}
			else
			{
				rotationIndex--;
			}
		}
		switch (rotationIndex)
		{
		case 0:
			currentRotation = *R0;
			break;
		case 1:
			currentRotation = *R1;
			break;
		case 2:
			currentRotation = *R2;
			break;
		case 3:
			currentRotation = *R3;
			break;
		}
	}
	//!\internal \brief Points to the currently selected rotation array.
	//!byte pointer that points to the current rotation array.
	byte* currentRotation;
	//!\internal \brief Index of current rotation.
	//!Nothing more than an index used to refer to a corresponding rotation array.
	byte rotationIndex;
};
//!\internal \brief Struct describing an "I" tetromino.
//!
struct I : public Shape
{
	I()
	{
		Utils::initArray(*R0, 
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			1, 1, 1, 1, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R1, 
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 1, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R2, 
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			1, 1, 1, 1, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R3, 
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			1, 1, 1, 1, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);
	}
};
//!\internal \brief Struct describing a "J" tetromino.
//!
struct J : public Shape
{ 
	J()
	{
		Utils::initArray(*R0, 
			0, 0, 0, 0, 0,
			0, 2, 2, 2, 0,
			0, 0, 0, 2, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R1, 
			0, 0, 2, 2, 0,
			0, 0, 2, 0, 0,
			0, 0, 2, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R2, 
			0, 2, 0, 0, 0,
			0, 2, 2, 2, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R3, 
			0, 0, 2, 0, 0,
			0, 0, 2, 0, 0,
			0, 2, 2, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);
	}
};
//!\internal \brief Struct describing an "L" tetromino.
//!
struct L : public Shape
{
	L()
	{
		Utils::initArray(*R0, 
			0, 0, 0, 0, 0,
			0, 3, 3, 3, 0,
			0, 3, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R1, 
			0, 0, 3, 0, 0,
			0, 0, 3, 0, 0,
			0, 0, 3, 3, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R2, 
			0, 0, 0, 3, 0,
			0, 3, 3, 3, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R3, 
			0, 3, 3, 0, 0,
			0, 0, 3, 0, 0,
			0, 0, 3, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);
	}
};
//!\internal \brief Struct describing an "O" tetromino.
//!
struct O : public Shape
{
	O()
	{
		Utils::initArray(*R0, 
			0, 0, 0, 0, 0,
			0, 4, 4, 0, 0,
			0, 4, 4, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R1, 
			0, 0, 0, 0, 0,
			0, 4, 4, 0, 0,
			0, 4, 4, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R2, 
			0, 0, 0, 0, 0,
			0, 4, 4, 0, 0,
			0, 4, 4, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R3, 
			0, 0, 0, 0, 0,
			0, 4, 4, 0, 0,
			0, 4, 4, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);
	}
};
//!\internal \brief Struct describing an "S" tetromino.
//!
struct S : public Shape
{
	S()
	{
		Utils::initArray(*R0, 
			0, 0, 0, 0, 0,
			0, 0, 5, 5, 0,
			0, 5, 5, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R1, 
			0, 0, 5, 0, 0,
			0, 0, 5, 5, 0,
			0, 0, 0, 5, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R2, 
			0, 0, 0, 0, 0,
			0, 0, 5, 5, 0,
			0, 5, 5, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R3, 
			0, 0, 5, 0, 0,
			0, 0, 5, 5, 0,
			0, 0, 0, 5, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);
	}
};
//!\internal \brief Struct describing a "T" tetromino.
//!
struct T : public Shape
{
	T()
	{
		Utils::initArray(*R0, 
			0, 0, 0, 0, 0,
			0, 6, 6, 6, 0,
			0, 0, 6, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R1, 
			0, 0, 6, 0, 0,
			0, 0, 6, 6, 0,
			0, 0, 6, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R2, 
			0, 0, 6, 0, 0,
			0, 6, 6, 6, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R3, 
			0, 0, 6, 0, 0,
			0, 6, 6, 0, 0,
			0, 0, 6, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);
	}
};
//!\internal \brief Struct describing a "Z" tetromino.
//!
struct Z : public Shape
{ 
	Z()
	{
		Utils::initArray(*R0, 
			0, 0, 0, 0, 0,
			0, 7, 7, 0, 0,
			0, 0, 7, 7, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R1, 
			0, 0, 7, 0, 0,
			0, 7, 7, 0, 0,
			0, 7, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R2, 
			0, 0, 0, 0, 0,
			0, 7, 7, 0, 0,
			0, 0, 7, 7, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);

		Utils::initArray(*R3, 
			0, 0, 7, 0, 0,
			0, 7, 7, 0, 0,
			0, 7, 0, 0, 0,
			0, 0, 0, 0, 0,
			0, 0, 0, 0, 0);
	}
};
#endif