#include <stdio.h>

typedef unsigned int uint32_t;
typedef int int32_t;

int main(int argc, char const *argv[]) {
  printf("%d\n", ((uint32_t)-(int32_t)(-12800000000)));
  printf("%zu\n", ((size_t)(uint32_t)-(int32_t)(-12800000000)));
  printf("%lu,%lu\n", sizeof(size_t),sizeof(int));
  printf("%d\n", (7|-8));
  return 0;
}
