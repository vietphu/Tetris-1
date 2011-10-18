#include "utils.h"
//!In any other implementation, another argument would be passed, giving the number of elements in that dynamic array. But to avoid having to put '25' in every call to this function, I'm just gonna be a bad programmer
//!and hard code a magic-number in here for maxIndex.
bool Utils::initArray(byte* pArray, ...)
{
	va_list plst;
	va_start(plst, pArray);

	byte maxIndex = 25;
	for (int i = 0; i < maxIndex; i++)
	{
		pArray[i] = va_arg(plst, byte);
	}
	va_end(plst);
	return true;
}