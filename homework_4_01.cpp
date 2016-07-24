#include <cstdio>
#include <cstring>

const int SIZE = 10;
int stack[SIZE], max[SIZE];
int head = 0;

int top() {
	if (head <= 0) {
		printf("Stack underflow!!!\n");
	} else if (head > SIZE) {
		printf("Stack overflow!!!\n");
	} 
	return stack[head - 1];
}

void push(int x) {
	if (head >= SIZE) {
		printf("Stack overflow!!!\n");
		return;
	}
	stack[head] = x;
	if (x > max[head - 1]) {
		max[head] = x;
	} else {
		max[head] = max[head - 1];
	}
	++head;
}

void pop() {
	if (head <= 0) {
		printf("Stack underflow!!!\n");
		return;
	}
	--head;
}

void print() {
	for (int i = 0; i < head; ++i) {
		printf("%i ", stack[i]);
	}
	printf("\n");
}

int getMax() {
	if (head <= 0) {
		printf("Stack underflow!!!\n");
	} else if (head > SIZE) {
		printf("Stack overflow!!!\n");
	} 
	return max[head - 1];
}

enum Command {
	TOP = 0, PUSH = 1, POP = 2, PRINT = 3, EXIT = 4, GETMAX = 5, UNKNOWN = -1
};

int main(int argc, char** argv) {
	printf("Use the following commands: top, push, pop, print, max or exit.\n");

	while (true) {
		char input[7];
		scanf("%s", input);
		
		Command c;
		if (strcmp(input, "top") == 0) {
			c = TOP;
		} else if (strcmp(input, "push") == 0) {
			c = PUSH;
		} else if (strcmp(input, "pop") == 0) {
			c = POP;
		} else if (strcmp(input, "print") == 0) {
			c = PRINT;
		} else if (strcmp(input, "exit") == 0) {
			c = EXIT;
		} else if (strcmp(input, "max") == 0) {
			c = GETMAX;
		} else {
			c = UNKNOWN;
		}
		
		switch (c) {
			case TOP:
				printf("%i\n", top());
				break;
			case PUSH:
				int value;
				scanf("%i", &value);
				push(value);
				break;
			case POP:
				pop();
				break;
			case PRINT:
				print();
				break;
			case GETMAX:
				printf("%i\n", getMax());
				break;
			case EXIT:
				return 0;
			case UNKNOWN:
			default:
				printf("Wrong command!\n");
				break;
		}
	}
	
	return 0;
}