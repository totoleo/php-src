#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

typedef int64_t zend_long;
typedef uint64_t zend_ulong;

typedef struct {
	char              val[1];
} zend_string_n;

int main(int argc, char const *argv[]) {
  const char *str = "hello world";
	int s_size = sizeof(zend_string_n)+strlen(str);
	s_size= s_size+s_size%
	zend_string_n *n = (zend_string_n *)malloc();
  memcpy(n->val,str,strlen(str));

	const char **s;
	int t1 = clock() * 1000 / CLOCKS_PER_SEC;
	s = malloc(1000000000*sizeof(const char *));
	for (size_t i = 0; i < 1000000000; i++) {
		s[i] = n->val;
	}
	int t2 = clock() * 1000 / CLOCKS_PER_SEC;

	printf("%s,%d\n", s[2],t2-t1);
	return 0;
}
