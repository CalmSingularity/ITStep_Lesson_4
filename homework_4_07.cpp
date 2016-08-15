#include <cstdio>

const size_t SIZE = 5, N_LETTERS = 5;
const char alphabet[N_LETTERS] = {'a', 'b', 'c', 'd', 'e'};

// Fill in the rest of the string starting from pos position
// with all possible combinations of letters from 'a' to 'e'
// and print the resulting combinations
void iterateLetter(char string[SIZE], size_t pos) {
  for (size_t i = 0; i < N_LETTERS; ++i) {
    string[pos] = alphabet[i];
    if (pos < SIZE - 1) {
      iterateLetter(string, pos + 1);
    } else {
      printf("%s\n", string);
    }
  }
}

int main(int argc, char** argv) {
  char string[SIZE];
  iterateLetter(string, 0);
  return 0;
}