#include <stdint.h>
#include <stdio.h>

typedef int64_t zend_long;
typedef uint64_t zend_ulong;

typedef struct {
	char              val[1];
} zend_string_n;

typedef char** zend_string_o;

int main(int argc, char const *argv[]) {

	char* ns = "hello world";

	zend_string_o o = &ns;
	zend_string_n n = {
		(char)ns[0]
	};
	char* s;
	for (size_t i = 0; i < 1000000000; i++) {
		s= *o;
	}
	printf("%s\n", (char *)s);
	return 0;
}
