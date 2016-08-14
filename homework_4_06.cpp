#include <cstdio>
#include <cstring>

const size_t SIZE = 256;
char input[SIZE], stack[SIZE];
int head = 0;

void push(char c) {
	if (head >= SIZE) {
		printf("Stack overflow!!!\n");
	}
	stack[head] = c;
	++head;
	return;
}

char pop() {
	return stack[head-- - 1];
}

bool isPalindrome(char input[]) {
	size_t length = strlen(input);
	for (size_t i = 0; i < length / 2; ++i) {
		push(input[i]);
	}
	for (size_t i = length / 2 + length % 2; i < length; ++i) {
		if (pop() != input[i]) {
			return false;
		}
	}
	return true;
}


int main(int argc, char** argv) {
	printf("Enter a string: ");
	scanf("%s",input);
	
	if (isPalindrome(input)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}