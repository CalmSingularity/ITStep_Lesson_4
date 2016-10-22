#include <cstdio>
#include <cstring>

struct String {
  char str[64];
};

bool operator > (const String& A, const String& B) {
	// printf("%p %p\n", A.str, B.str); // печатаем адрес внутреннего объекта структуры для определения копирования структуры по значению
	if (strcmp(A.str, B.str) > 0) {
	  return true;
  } else {
    return false;
  }
}

template <typename T>
void insertionSort (T array[], size_t size) {
  for (size_t i = 1; i < size; ++i) {
    T key = array[i];
    int j = i - 1;
		// printf("%p %p\n", &array[j], &key); // печатаем адрес внешнего объекта структуры для определения копирования структуры по значению
    while (j >= 0 && array[j] > key) {
			// printf("%p %p\n", &array[j], &key); // печатаем адрес внешнего объекта структуры для определения копирования структуры по значению
      T temp = array[j];
      array[j] = key;
      array[j + 1] = temp;
      --j;
    }
  }
}

void printArray(String array[], size_t size) {
  for (int i = 0; i < size; ++i) {
    printf("%s\n", array[i].str);
  }
}


int main(int argc, char** argv) {
  size_t size;
  printf("Enter the size of array to sort: ");
  scanf("%i", &size);
  // String* array = new String[size];
  String array[size];

  printf("Enter %i strings: ", size);
  for (int i = 0; i < size; ++i) {
    scanf("%s", array[i].str);
  }
  
  insertionSort(array, size);

  printf("Sorted array of strings:\n");
  printArray(array, size);

  // delete[] array;
  return 0;
}
