#include <cstdio>
#include <cstring>

void insertionSort (int array[], size_t size) {
  for (size_t i = 1; i < size; ++i) {
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      int temp = array[j];
      array[j] = key;
      array[j + 1] = temp;
      --j;
    }
  }
}

bool binarySearch(int array[], size_t size, int search_key) {
  int average_index = 0, 
      first_index = 0, 
      last_index = size - 1;
  
  while (first_index < last_index) {
    average_index = first_index + (last_index - first_index) / 2; 
    if (search_key <= array[average_index]) {
      last_index = average_index;
    } else {
      first_index = average_index + 1;
    } 
  }
  
  if (array[last_index] == search_key) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char** argv) {
  const size_t SIZE = 16;
  int array[SIZE], search_key;
  printf("Enter 16 integers: ");
  for (int i = 0; i < SIZE; ++i) {
    scanf("%i", &array[i]);
  }
  
  printf("Enter a number to search in the array: ");
  scanf("%i", &search_key);

  insertionSort(array, SIZE);

  if (binarySearch(array, SIZE, search_key)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
