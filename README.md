Ring Buffer Implementation in C
Overview

This project provides a C-based implementation of a Ring Buffer (also known as a Circular Buffer). A Ring Buffer is a data structure that efficiently handles data in a fixed-size buffer by overwriting the oldest data when the buffer reaches its capacity. It is widely used in scenarios where data arrives at a fast rate and must be processed in a continuous loop.

Features
Efficient Circular Buffer: Data is written to the buffer, and when the buffer reaches its capacity, new data overwrites the oldest data in the buffer.
Thread-Safe Operations: All operations (read/write) are designed to be simple and efficient, suitable for embedded systems and real-time applications.
Basic Operations:
RingBuffer_Init(): Initializes the ring buffer.
RingBuffer_Clear(): Clears the buffer, resetting all positions.
RingBuffer_IsEmpty(): Checks if the buffer is empty.
RingBuffer_GetLength(): Returns the number of items stored in the buffer.
RingBuffer_GetCapacity(): Returns the buffer’s total capacity.
RingBuffer_PutChar(): Adds a character to the buffer.
RingBuffer_GetChar(): Retrieves a character from the buffer.

Functions
RingBuffer_Init(RingBuffer *ringBuffer, void *dataBuffer, size_t dataBufferSize)

Initializes the ring buffer with the given data buffer and size.

RingBuffer_Clear(RingBuffer *ringBuffer)

Clears the ring buffer, resetting the positions and count.

RingBuffer_IsEmpty(RingBuffer const *ringBuffer)

Checks if the buffer is empty. Returns true if empty, otherwise false.

RingBuffer_GetLength(RingBuffer const *ringBuffer)

Returns the current number of bytes in the buffer.

RingBuffer_GetCapacity(RingBuffer const *ringBuffer)

Returns the total capacity (size) of the buffer.

RingBuffer_PutChar(RingBuffer *ringBuffer, char c)

Adds a character to the buffer. Returns true if successful, otherwise false.

RingBuffer_GetChar(RingBuffer *ringBuffer, char *c)

Retrieves a character from the buffer. Returns true if successful, otherwise false.
