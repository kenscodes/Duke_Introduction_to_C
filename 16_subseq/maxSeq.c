#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int * array, size_t n) {
  if (n == 0) {
    return 0;
  }
  int max = 1;
  int seq = 1;
  for (int i=1; i < n; ++i) {
    if (array[i] > array[i-1]) {
      seq += 1;
    } else {
      seq = 1;
    }
    if (seq > max) {
      max = seq;
    }
  }

  return max;
}
