#include <cstdio>
#include <cstring>

int main(int argc, char** argv) {
  char string[256];
  printf("Enter a string: ");
  scanf("%s", string);
  size_t length = strlen(string);

  for (size_t i = 0; i < length / 2; ++i) {
    char tmp = string[length - i - 1];
    string[length - i - 1] = string[i];
    string[i] = tmp;
  }

  printf("%s\n", string);
  
  return 0;
}