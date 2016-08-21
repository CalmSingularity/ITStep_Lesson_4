#include <cstdio>
#include <cstring>

int main(int argc, char** argv) {
  const char* const dictionary[] = {"mathematics", "physics", "biology",
         "psychology", "geometry", "geography", "geology",
         "bioinformatics", "science", "scifi", "pharmacology",
         "musics", "analysis", "policy", "geopolicy",
         "politology", "demonology", "demonstations",
         "bioengineering", "modeling", "algebra", "literature",
         "liberation", "listing", "society", "scene", "lighting"};
  size_t length = sizeof(dictionary) / sizeof(dictionary[0]);

  char search_key[64];
  printf("Enter a word to look up in the dictionary: ");
  scanf("%s", search_key);

  const char* delimiter = "";
  for (size_t i = 0; i < length; ++i) {
    if (strstr(dictionary[i], search_key) == &dictionary[i][0]) {
      printf("%s%s", delimiter, dictionary[i]);
      delimiter = ", ";
    }
  }

  return 0;
}