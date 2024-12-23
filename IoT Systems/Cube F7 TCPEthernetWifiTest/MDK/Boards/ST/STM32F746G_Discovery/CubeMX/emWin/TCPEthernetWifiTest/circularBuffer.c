#include "settings.h"
#ifdef WIFI
#include "circularBuffer.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// This circular buffer expects sequences of characters, terminated with a '\n'. Ideal for processing AT commands.
// If you want to process regular strings, always ensure they end with a '\n'.

// Create global variables. These variables can also be used in other files in this project via the 'extern' keyword.
// The buffer must be marked as 'volatile' because it can change 'between two read operations' (e.g., in an interrupt).
volatile CircularBuffer circularBuffer;
enum CircularBufferActionResult circularBufferActionResult;

// This function properly initializes a newly created CircularBuffer. Always call it at the beginning of your code.
enum CircularBufferActionResult InitCircularBuffer(volatile CircularBuffer *buffer)
{
    // Initialize all bytes to zero.
    for (uint16_t index = 0; index < CIRCULAR_BUFFER_SIZE; index++)
        buffer->bufferData[index] = 0;

    // Reset read and write pointers.
    buffer->writeIndex = 0;
    buffer->readIndex = 0;

    // Indicate that no valid strings have been received yet.
    buffer->numberOfStringsInBuffer = 0;

    // Reset the start of the currently incoming string.
    buffer->startIndexOfCurrentlyArrivingString = 0;

    buffer->mutex = osMutexNew(NULL); // Mutex initialiseren
    if (buffer->mutex == NULL)
    {
        return INIT_FAILED; // Fout bij mutex-init
    }

    // Indicate that initialization succeeded.
    return INIT_SUCCEEDED;
}

// Retrieve a single character from the circular buffer via a pointer...
enum CircularBufferActionResult PopCharFromCircularBuffer(volatile CircularBuffer *buffer, char *data)
{
    osMutexAcquire(buffer->mutex, osWaitForever); // start critical section

    enum CircularBufferActionResult temp;
    // Note: (*ptr).a is equivalent to ptr->a.

    if (IsCircularBufferEmpty(buffer))
        temp = BUFFER_EMPTY;
    else
    {
        *data = buffer->bufferData[buffer->readIndex];
        buffer->readIndex++;

        if (buffer->readIndex >= CIRCULAR_BUFFER_SIZE)
            buffer->readIndex = 0;

        temp = READ_SUCCEEDED;
    }

    osMutexRelease(buffer->mutex); // end critical section
    return temp;
}

// Store a single character in the circular buffer.
enum CircularBufferActionResult PushCharToCircularBuffer(volatile CircularBuffer *buffer, char data)
{
    osMutexAcquire(buffer->mutex, osWaitForever); // start critical section

    enum CircularBufferActionResult temp;

    // If writeIndex is just before readIndex, or if writeIndex is at the very end while
    // readIndex is still at the very beginning => the buffer is full...
    // You always want to leave one slot unused to clearly distinguish between full and empty states.
    // Empty => when writeIndex and readIndex have the same value.
    // Full => when writeIndex is just before readIndex.

    if (IsCircularBufferFull(buffer))
    {
        osMutexRelease(buffer->mutex); // end critical section
        return BUFFER_FULL;
    }
    else
    {
        buffer->bufferData[buffer->writeIndex] = data;
        buffer->writeIndex++;

        if (buffer->writeIndex >= CIRCULAR_BUFFER_SIZE)
            buffer->writeIndex = 0;

        // A new line was received. Increment the counter indicating how many lines are present.
        if (data == '\n')
            buffer->numberOfStringsInBuffer++;

        osMutexRelease(buffer->mutex); // end critical section
        return WRITE_SUCCEEDED;
    }
}

// Retrieve a complete string from the circular buffer. A string MUST end with '\n'.
enum CircularBufferActionResult PopStringFromCircularBuffer(volatile CircularBuffer *buffer, char *string)
{
    enum CircularBufferActionResult result;
    char temp;
    uint8_t index = 0;

    if (IsCircularBufferEmpty(buffer))
        result = BUFFER_EMPTY;
    else
    {
        if (buffer->numberOfStringsInBuffer > 0)
        {
            PopCharFromCircularBuffer(buffer, &temp);
            string[index++] = temp;

            // TODO: To avoid unexpected infinite loops, add a timeout...
            while (temp != '\n') // Continue as long as no line feed is seen...
            {
                PopCharFromCircularBuffer(buffer, &temp);
                string[index++] = temp;
            }

            // Add end-of-string character.
            string[index] = 0;

            buffer->numberOfStringsInBuffer--;

            result = READ_STRING_SUCCEEDED;
        }
        else
            result = READ_STRING_FAILED;
    }

    return result;
}

// Add a string to the circular buffer.
enum CircularBufferActionResult PushStringToCircularBuffer(volatile CircularBuffer *buffer, char *string)
{
    uint8_t index = 0;
    enum CircularBufferActionResult temp;

    // TODO: Provide a timeout?
    // As long as no end-of-string character is encountered, push to the circular buffer.
    while (string[index] != 0)
        temp = PushCharToCircularBuffer(buffer, string[index++]);

    return temp;
}

// Check if the circular buffer is empty.
bool IsCircularBufferEmpty(volatile CircularBuffer *buffer)
{
    return buffer->readIndex == buffer->writeIndex;
}

// Check if the circular buffer is full.
bool IsCircularBufferFull(volatile CircularBuffer *buffer)
{
    return (buffer->writeIndex == (buffer->readIndex - 1)) ||
           ((buffer->writeIndex == (CIRCULAR_BUFFER_SIZE - 1)) && (buffer->readIndex == 0));
}

// Search for a specific string in the current buffer. After this function, the buffer is cleared.
bool LookForString1(volatile CircularBuffer *circularBuffer, char needle[])
{
    char haystack[CHAR_ARRAY_BUFFER_LENGTH];
    enum CircularBufferActionResult circularBufferActionResult;

    while (circularBuffer->numberOfStringsInBuffer > 0)
    {
        circularBufferActionResult = PopStringFromCircularBuffer(circularBuffer, haystack);
        if (circularBufferActionResult == READ_STRING_SUCCEEDED)
        {
            if (strcmp(haystack, needle) == 0)
                return true;
        }
    }

    return false;
}

// Search for one of two given strings in the current buffer. After this function, the buffer is cleared.
uint8_t LookForString2(volatile CircularBuffer *circularBuffer, char needle1[], char needle2[])
{
    char haystack[CHAR_ARRAY_BUFFER_LENGTH];
    enum CircularBufferActionResult circularBufferActionResult;

    while (circularBuffer->numberOfStringsInBuffer > 0)
    {
        circularBufferActionResult = PopStringFromCircularBuffer(circularBuffer, haystack);
        if (circularBufferActionResult == READ_STRING_SUCCEEDED)
        {
            if (strcmp(haystack, needle1) == 0)
                return 1;

            if (strcmp(haystack, needle2) == 0)
                return 2;
        }
    }

    return 0;
}

// Search for one of three given strings in the current buffer. After this function, the buffer is cleared.
uint8_t LookForString3(volatile CircularBuffer *circularBuffer, char needle1[], char needle2[], char needle3[])
{
    char haystack[CHAR_ARRAY_BUFFER_LENGTH];
    enum CircularBufferActionResult circularBufferActionResult;

    while (circularBuffer->numberOfStringsInBuffer > 0)
    {
        circularBufferActionResult = PopStringFromCircularBuffer(circularBuffer, haystack);
        if (circularBufferActionResult == READ_STRING_SUCCEEDED)
        {
            if (strcmp(haystack, needle1) == 0)
                return 1;

            if (strcmp(haystack, needle2) == 0)
                return 2;

            if (strcmp(haystack, needle3) == 0)
                return 3;
        }
    }

    return 0;
}
#endif