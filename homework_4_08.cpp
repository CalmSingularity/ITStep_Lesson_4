#include <cstdio>

const size_t SIZE = 5, N_LETTERS = 5;

// Check if there is no occurence of key 
// from the start of the string to position pos
bool noRepeat(char string[], char key, size_t pos) {
  if (pos == 0) {
    return true;
  }
  for (size_t i = 0; i < pos; ++i) {
    if (string[i] == key) {
      return false;
    } 
  }
  return true;
}

void printString(char string[SIZE]) {
  for (size_t i = 0; i < SIZE; ++i) {
    printf("%c", string[i]);
  }
  printf("\n");
}

// Fill in the rest of the string starting from pos position
// with all possible combinations of letters from alphabet 
// and print the resulting combinations
void iterateLetter(char string[SIZE], char alphabet[N_LETTERS], size_t pos) {
  for (size_t i = 0; i < N_LETTERS; ++i) {
    if (noRepeat(string, alphabet[i], pos)) {
      string[pos] = alphabet[i];
    } else {
      continue;
    }
    if (pos < SIZE - 1) {
      iterateLetter(string, alphabet, pos + 1);
    } else {
      printString(string);
    }
  }
}

int main(int argc, char** argv) {
  char alphabet[N_LETTERS], string[SIZE];
  scanf("%s",alphabet);
  iterateLetter(string, alphabet, 0);
  return 0;
}