#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef char ALIGN[16];

union header {
  struct header_t {
    size_t size;
    unsigned is_free;
    struct header_t *next;
  } s;
  ALIGN stub;
};

void *malloc(size_t size) {
  void *block;
  block = sbrk(size);
  if (block == (void *)-1) {
    return NULL;
  }
  return block;
}
