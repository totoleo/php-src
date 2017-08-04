#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

typedef int64_t zend_long;
typedef uint64_t zend_ulong;

typedef struct {
	char*   val;
} zend_string_o;

int main(int argc, char const *argv[]) {

	const char* str = "hello world";

  size_t len = strlen(str);
  zend_string_o *zostrp = (zend_string_o *)malloc(sizeof(zend_string_o));

   char *n_str = ( char *)malloc(sizeof(char) * len);

  memcpy(n_str, str, len);
  n_str[len] = '\0';
  zostrp->val = n_str;

	const char **s;
	s = malloc(1000000000*sizeof(const char *));
	int t1 = clock() * 1000 / CLOCKS_PER_SEC;
	for (size_t i = 0; i < 1000000000; i++) {
		s[i] = zostrp->val;
	}
	int t2 = clock() * 1000 / CLOCKS_PER_SEC;
	printf("%s,%d\n", *s,t2-t1);
	return 0;
}
