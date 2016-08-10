#include <cstdio>
#include <cstring>

const size_t SIZE = 256;
char input[SIZE], stack[SIZE];
int head = 0;

// Returns True if pop operation was successful and False if not
bool push(char c) {
	if (head >= SIZE) {
		printf("Stack overflow!!!\n");
		return false;
	}
	stack[head] = c;
	++head;
	return true;
}

char pop() {
	if (head <= 0) {
		// printf("Stack underflow!!!\n");
		return ('e');
	}
	return stack[head-- - 1];
}

bool isEmpty() {
	// printf("Stack size: %i\n", head);
	if (head == 0) {
		return true;
	} else {
		return false;
	}
}


int main(int argc, char** argv) {
	
	scanf("%s",input);
	
	size_t i = 0;
	while (input[i] != '\0') {
		// printf("Checking char #%i: %c\n", i, input[i]);
		switch (input[i]) {
			case '(':
			case '[':
			case '{':
			case '<':
				if (!push(input[i])) {
					return 0;
				}
				break;

			case ')':
				if (pop() != '(') {
					printf("No\n");
					return 0;
				}
				break;

			case ']':
				if (pop() != '[') {
					printf("No\n");
					return 0;
				}
				break;

			case '}':
				if (pop() != '{') {
					printf("No\n");
					return 0;
				}
				break;

			case '>':
				if (pop() != '<') {
					printf("No\n");
					return 0;
				}
				break;

			default:
					printf("The string should contain brackets only!\n");
					return 0;			
				break;
		}
		++i;
	}

	// Print stack
	// printf("Stack: ");
	// for (size_t i = 0; i < head; ++i) {
	// 	printf("%c", stack[i]);
	// }
	// printf("\n");

	if (isEmpty()) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}