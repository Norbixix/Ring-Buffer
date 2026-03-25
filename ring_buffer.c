#include "ring_buffer.h"
#include <assert.h>

void RingBuffer_Init(RingBuffer *ringBuffer, void *dataBuffer, size_t dataBufferSize) {
  assert(ringBuffer != NULL);
  assert(dataBuffer != NULL);
  assert(dataBufferSize > 0);

  ringBuffer->buffer = (uint8_t *)dataBuffer;
  ringBuffer->dataBufferSize = dataBufferSize;
  ringBuffer->head = 0;
  ringBuffer->tail = 0;
  ringBuffer->count = 0;
  
  // todo - done
}

bool RingBuffer_Clear(RingBuffer *ringBuffer) {
  if(ringBuffer == NULL)
  {
    return false;
  }

  ringBuffer->head = 0;
  ringBuffer->tail = 0;
  ringBuffer->count = 0;

  return true; // todo - done
}

bool RingBuffer_IsEmpty(RingBuffer const *ringBuffer) {
  return (ringBuffer != NULL) && (ringBuffer->count == 0);  // todo - done
}

size_t RingBuffer_GetLength(RingBuffer const *ringBuffer) {
  if(ringBuffer == NULL)
  {
    return 0;
  }

  return ringBuffer->count; // todo - done
}

size_t RingBuffer_GetCapacity(RingBuffer const *ringBuffer) {
  if(ringBuffer == NULL)
  {
    return 0;
  }

  return ringBuffer->dataBufferSize; // todo - done
}

bool RingBuffer_PutChar(RingBuffer *ringBuffer, char c) {
  if(ringBuffer == NULL || ringBuffer->count >= ringBuffer->dataBufferSize)
  {
    return false;
  }

  ringBuffer->buffer[ringBuffer->head] = (uint8_t)c;
  ringBuffer->head = (ringBuffer->head + 1) % ringBuffer->dataBufferSize; // handle wrap-around
  ringBuffer->count++;
  return true; // todo - done
}

bool RingBuffer_GetChar(RingBuffer *ringBuffer, char *c) {
  if(ringBuffer == NULL || c == NULL || ringBuffer->count == 0)
  {
    return false;
  }

  *c = (char)ringBuffer->buffer[ringBuffer->tail];
  ringBuffer->tail = (ringBuffer->tail + 1) % ringBuffer->dataBufferSize; // handle wrap-around
  ringBuffer->count--;
  return true; // todo - done
}
