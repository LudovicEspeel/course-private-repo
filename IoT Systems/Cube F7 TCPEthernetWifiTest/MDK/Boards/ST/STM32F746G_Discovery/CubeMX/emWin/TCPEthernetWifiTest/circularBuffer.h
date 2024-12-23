#include <stdint.h>
#include <stdbool.h>
#include "main.h"

#ifndef CIRCULAR_BUFFER_INCLUDED
#define CIRCULAR_BUFFER_INCLUDED

// Experimentally fill in the maximum size here to make optimal use of RAM (if desired).
#define CIRCULAR_BUFFER_SIZE 2001	 // Size of the buffer in bytes. One space is always left unused, so ... plus 1
#define CHAR_ARRAY_BUFFER_LENGTH 501 // Specify the maximum length of text chunks you want to process.
									 // Note: If the arrays are shorter (e.g., 101), issues can occur during reset.
									 // If many characters arrive without a single '\n', the arrays can overflow, causing
									 // unpredictable behavior in the code. The ideal length is probably not less than 350...
									 // This is because the "ready" signal, indicating that the module is ready for use,
									 // appears at approximately index 325. Therefore, the arrays must
									 // definitely be longer than this.
// Enumeration of all possible results that can be obtained after an operation with the circular buffer.
enum CircularBufferActionResult
{
	READ_SUCCEEDED,
	WRITE_SUCCEEDED,
	INIT_SUCCEEDED,
	INIT_FAILED,
	BUFFER_EMPTY,
	BUFFER_FULL,
	READ_STRING_SUCCEEDED,
	READ_STRING_FAILED
};

// Structure representing a circular buffer.
typedef struct
{
	uint16_t readIndex;
	uint16_t writeIndex;
	uint16_t numberOfStringsInBuffer;
	uint16_t startIndexOfCurrentlyArrivingString;
	char bufferData[CIRCULAR_BUFFER_SIZE];
	osMutexId_t mutex; // Mutex for threadsafe access
} CircularBuffer;

// Function prototypes.
enum CircularBufferActionResult InitCircularBuffer(volatile CircularBuffer *buffer);
enum CircularBufferActionResult PopCharFromCircularBuffer(volatile CircularBuffer *buffer, char *data);
enum CircularBufferActionResult PushCharToCircularBuffer(volatile CircularBuffer *buffer, char data);
enum CircularBufferActionResult PopStringFromCircularBuffer(volatile CircularBuffer *buffer, char *string);
enum CircularBufferActionResult PushStringToCircularBuffer(volatile CircularBuffer *buffer, char *string);
bool IsCircularBufferEmpty(volatile CircularBuffer *buffer);
bool IsCircularBufferFull(volatile CircularBuffer *buffer);

bool LookForString1(volatile CircularBuffer *circularBuffer, char needle[]);
uint8_t LookForString2(volatile CircularBuffer *circularBuffer, char needle1[], char needle2[]);
uint8_t LookForString3(volatile CircularBuffer *circularBuffer, char needle1[], char needle2[], char needle3[]);
#endif
