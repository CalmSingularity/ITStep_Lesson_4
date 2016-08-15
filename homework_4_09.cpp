#include <cstdio>
#include <cstring>

bool isDelimiter(char key) {
  if (key == ' ' || key == '.' || key == ',') {
    return true;
  } else if (key == ';' || key == ':' || key == '-') {
    return true;
  } else if (key == '!' || key == '?') {
    return true;
  } else {
    return false;
  }
}


int main(int argc, char** argv) {
  char text[] = "-.---Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam eleifend condimentum magna imperdiet tristique. Pellentesque fringilla maximus mi vitae ullamcorper. Fusce mattis neque vel nisi fringilla, vel aliquet libero sagittis. Nullam fringilla at mi at accumsan. Suspendisse ullamcorper auctor enim, eu malesuada felis ornare eu. Morbi sodales nunc eget lacus sollicitudin semper. Donec tristique consequat tellus, ut porttitor felis maximus eget. Fusce consectetur iaculis pharetra. Donec congue volutpat arcu, eget sodales sapien tristique quis. Nullam ut posuere risus, sed pharetra lorem. Cras varius, est eu pulvinar scelerisque, ipsum nisi bibendum sapien, in scelerisque velit risus eget felis. Nam nec porttitor erat. Suspendisse dictum sit amet magna finibus lobortis. Phasellus non sem mollis, ultrices odio non, volutpat ligula. Aenean mollis eros ex, vitae lobortis quam gravida sed.";
  size_t length = strlen(text);
  bool last_was_delimiter = true;
  size_t count = 0;
  for (size_t i = 0; i < length; ++i) {
    if (isDelimiter(text[i])) {
      if (last_was_delimiter == false) {
        ++count;
        last_was_delimiter = true;
      } 
    } else {
      last_was_delimiter = false;
    }
  }
  if (last_was_delimiter == false) {
    ++count;
  }
  printf("Word count: %i\n", count);
  return 0;
}