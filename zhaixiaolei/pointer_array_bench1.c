#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct { char *val; } zend_string_o;

static inline zend_string_o *zend_string_o_init(const char *str) {
  size_t len = strlen(str);
  zend_string_o *zostrp = (zend_string_o *)malloc(sizeof(zend_string_o));

  char *n_str = (char *)malloc(sizeof(char) * len);

  memcpy(n_str, str, len);
  n_str[len] = '\0';
  zostrp->val = n_str;
  return zostrp;
}

int main(int argc, char const *argv[]) {
  char *str =
      "speed speed speed speed speed speed speed speed speed speed speed speed";

  int t2 = clock() * 1000 / CLOCKS_PER_SEC;

  zend_string_o *str2;
  for (long i = 0; i < 5000000; i++) {
    str2 = zend_string_o_init(str);
  }
  int t3 = clock() * 1000 / CLOCKS_PER_SEC;

  printf("%d\n", t3 - t2);
  return 0;
}
