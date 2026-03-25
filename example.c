#include "ring_buffer.h"
#include "ring_buffer.c"
#include <stdio.h>

#define BUFFER_SIZE 10

int main() {
    uint8_t buffer[BUFFER_SIZE];
    RingBuffer ringBuffer;

    // Initialize the buffer
    RingBuffer_Init(&ringBuffer, buffer, BUFFER_SIZE);

    // Add some data
    RingBuffer_PutChar(&ringBuffer, 'A');
    RingBuffer_PutChar(&ringBuffer, 'B');

    // Retrieve data
    char data;
    if (RingBuffer_GetChar(&ringBuffer, &data)) {
        printf("Retrieved data: %c\n", data);
    }

    return 0;
}