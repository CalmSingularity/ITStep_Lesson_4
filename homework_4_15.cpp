#include <cstdio>
#include <cstring>

const size_t STR_LEN = 64;

void insertionSort(char array[][STR_LEN], size_t size) {
  for (size_t i = 1; i < size; ++i) {
    char key[STR_LEN];
    strcpy(key, array[i]);
    int j = i - 1;
    while (j >= 0 && strcmp(array[j], key) > 0) {
      char temp[STR_LEN];
      strcpy(temp, array[j]);
      strcpy(array[j], key);
      strcpy(array[j + 1], temp);
      --j;
    }
  }
}

void printStrings(char array[][STR_LEN], size_t size) {
  for (int i = 0; i < size; ++i) {
    printf("%s\n", array[i]);
  }
}

int main(int argc, char** argv) {
  size_t size;
  printf("Enter the size of array to sort: ");
  scanf("%i", &size);
  char array[size][STR_LEN];
  printf("Enter %i strings: ", size);
  for (int i = 0; i < size; ++i) {
    scanf("%s", array[i]);
  }
  
  insertionSort(array, size);

  printf("Sorted array of strings:\n");
  printStrings(array, size);

  return 0;
}
