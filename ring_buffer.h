#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Structure describing the ring buffer. */
typedef struct {
  uint8_t *buffer;          // pointer to the byte array for data storage
  size_t dataBufferSize;    // capacity of the buffer (number of bytes)
  size_t head;              // write position index
  size_t tail;              // read position index
  size_t count;             // current number of bytes stored in the buffer
  // TODO: implement the structure members
} RingBuffer;

/**
 * Initializes the given ring buffer structure.
 *
 * @param ringBuffer pointer to a \ref RingBuffer structure
 * @param dataBuffer pointer to a location in memory, where the ring buffer data will be stored
 * @param dataBufferSize size in bytes of the dataBuffer
 *
 * The program should terminate if any of the arguments is invalid (i.e. null pointer or zero size).
 */
void RingBuffer_Init(RingBuffer *ringBuffer, void *dataBuffer, size_t dataBufferSize);

/**
 * Clears contents of the given ring buffer.
 *
 * @param ringBuffer pointer to a \ref RingBuffer structure
 * @return true if the ring buffer is cleared successfully, false otherwise
 */
bool RingBuffer_Clear(RingBuffer *ringBuffer);

/**
 * Checks if the given ring buffer is empty.
 *
 * @param ringBuffer pointer to a \ref RingBuffer structure
 * @return true if the ring buffer holds no data, false otherwise
 */
bool RingBuffer_IsEmpty(RingBuffer const *ringBuffer);

/**
 * Gets the length (in bytes) of the data stored in the given ring buffer.
 *
 * @param ringBuffer pointer to a \ref RingBuffer structure
 * @return length (in bytes) of the data stored in the ring buffer
 */
size_t RingBuffer_GetLength(RingBuffer const *ringBuffer);

/**
 * Returns the capacity (in bytes) of the given buffer.
 *
 * @param ringBuffer pointer to a \ref RingBuffer structure
 * @return capacity (in bytes) of the ring buffer (how much characters can it store)
 */
size_t RingBuffer_GetCapacity(RingBuffer const *ringBuffer);

/**
 * Appends a single character to the ring buffer. The stored data length will be
 * increased by 1.
 *
 * @param ringBuffer pointer to a \ref RingBuffer structure
 * @return true if the character was added successfully, false otherwise
 */
bool RingBuffer_PutChar(RingBuffer *ringBuffer, char c);

/**
 * Pulls out a single character from the ring buffer. The stored data length will be
 * decreased by 1.
 *
 * @param ringBuffer pointer to a \ref RingBuffer structure
 * @return true if the character was pulled out successfully, false otherwise
 */
bool RingBuffer_GetChar(RingBuffer *ringBuffer, char *c);

#ifdef __cplusplus
}
#endif

#endif
