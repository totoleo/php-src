#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct { char val[1]; } zend_string;

static inline zend_string *zend_string_init(const char *str) {
  size_t len = strlen(str);

  zend_string *ret = (zend_string *)malloc(sizeof(zend_string) + len + 1);

  memcpy(ret->val, str, len);
  ret->val[len] = '\0';
  return ret;
}

int main(int argc, char const *argv[]) {
  char *str =
      "speed speed speed speed speed speed speed speed speed speed speed speed";

  int t1 = clock() * 1000 / CLOCKS_PER_SEC;

  zend_string *str1;
  for (long i = 0; i < 5000000; i++) {

    str1 = zend_string_init(str);
  }

  int t2 = clock() * 1000 / CLOCKS_PER_SEC;

  printf("%d\n", t2 - t1);
  return 0;
}
