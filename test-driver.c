#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "klee/klee.h"
#include "slre.h" 
int main(void) {

  // create a regular expression that matches a URL
  const char * pattern = "^(http|https)://[a-z0-9-]+(.[a-z0-9-]+)+([/?].*)?$";
  char * text = (char *)malloc(20);
  klee_make_symbolic(text, 20, "text");
  klee_assume(text[19] == '\0');

  int a = slre_match(pattern, text, 20, NULL, 0, 0);
  printf("result = %d\n", a);
  
  return 0;
}