#include <stdio.h>
#include <stdlib.h>

int main() {
  void* ptr = malloc(0);
  printf("%p\n",ptr);
  ptr = realloc(ptr, 0);
  printf("%p\n", ptr);
return 0;
}
