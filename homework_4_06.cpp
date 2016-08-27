#include <cstdio>
#include <cstring>

bool isPalindrome(char input[]) {
	size_t length = strlen(input);
	for (size_t i = 0; i < length / 2; ++i) {
		if (input[i] != input[length - i - 1]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char** argv) {
	char input[256];
	printf("Enter a string: ");
	scanf("%s",input);
	
	if (isPalindrome(input)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}