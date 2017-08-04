#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

/*
测试在 堆栈分配内存和堆上分配内存，那个更快
*/
int main(int argc, char const *argv[]) {

  clock_t t1 = clock();
  for (size_t i = 0; i < 1000000; i++) {
    char stack[4194304];
  }
  clock_t t2 = clock();
  for (size_t i = 0; i < 1000000; i++) {
    char * stack = (char *)malloc(4194304*sizeof(char));
  }
  clock_t t3 = clock();

  printf("heap:%lu,stack:%lu\n", (t3-t2),(t2-t1));
  return 0;
}
