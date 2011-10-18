#ifndef SHAPE_GENERATOR
#define SHAPE_GENERATOR
#include <cstdlib>
#include <ctime>
#include "Shape.h"
//!\internal \brief Generates tetrominos at random
//!
struct Shape_Generator
{
	//!\internal \brief Seeds the pseudo-random number generator
	//!
	//!The generator uses the "time" function of ctime (in this case resulting in the current time) to initialize a PRNG with the "srand" function of cstdlib.
	static void init()
	{
		srand((unsigned)time(0));
	}
	//!\internal \brief Generates the next shape.
	//!
	//!Generates a random number using "rand()", does a mod 7, and then adds one to that. Uses a switch/case block to return the appropriate shape. Defaults to an "O" shape. 
	//!Note: Each case body is enclosed in brackets, because technically, everything inside the switch block is of the same scope, and the compiler freaks out when one of the shapes may not be instantiated.
	//!\return A pointer to a Shape object on the heap
	static Shape Next_Shape()
	{
		int random_integer = (rand() % 7) + 1;
		
		switch(random_integer)
		{
		case 1:
			{
			I i;
			return i;
			}
		case 2:
			{
			J j;
			return j;
			}
		case 3:
			{
			L l;
			return l;
			}
		case 4:
			{
			O o;
			return o;
			}
		case 5:
			{
			S s;
			return s;
			}
		case 6:
			{
			T t;
			return t;
			}
		case 7:
			{
			Z z;
			return z;
			}
		default:
			{
			O o;
			return o;
			}
			/*case 1: return new I();
			case 2: return new J();
			case 3: return new L();
			case 4: return new O();
			case 5: return new S();
			case 6: return new T();
			case 7: return new Z();
			default: return new O();*/
		}
	}
};
#endif