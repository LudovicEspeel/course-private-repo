#include "functions.h"

string getString(int *arrayPtr, int length)
{
    string result = "";

    for (const int* element = arrayPtr; element < arrayPtr + length; element++)
	{
		result += to_string(*element);
        if(element < arrayPtr + length-1)
        {
		    result += " ";
        }
	}
	return result;
}

void remove(int number, int *arrayPtr, int length)
{
    int* p = arrayPtr; //arrayPtr points to array pointer (zeroth element of the array)

	while (p < arrayPtr + length)
	{
		if (*p == number)
		{
			int *q = p; //q points to p (x-th element of the array)
			while (q < arrayPtr + length - 1) //"move" the other elements of the array
			{
				*q = *(q + 1); //take the next element and write it in the current element
				q++;
			}

			//actually this should be done once (next time, the 0 will be "shifted"/duplicated):
			*(arrayPtr + length - 1) = 0; //set the last element to 0
		}
		else
		{
			//only step up the pointer if there are no duplicate values nearby 
			//like 3 in ..., 2, 3, 3, 17, ...
			p++;
		}
	}
}