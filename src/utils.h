#ifndef UTILS
#define UTILS
#include "TYPEDEFS.h"
#include <cstdarg>
//!\internal \brief	Utility Struct
//!
//!A struct whose purpose is to contain functionality that is general-purpose and unrelated to Tetris (or games as a whole)
struct Utils{
	//!\internal \brief	Allows for C# style array initialization. This function is mainly here for aesthetic purposes.
	//!
	//!initArray takes a variable number of arguments after pArray, and adds them to pArray in sequence.
	//!
	//!\param pArray A pointer to a byte array
	//!
	//!\todo Prevent values of incorrect type from being passed to the variable length argument list.
	static bool initArray(byte* pArray, ...);
};
#endif