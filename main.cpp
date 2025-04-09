#include <iostream> 

void fun() {
	printf("hello word");
}

void fun(char c) {
	if (c == ' ')
		cout << "\n" << endl;
}

int main() {
	printf("hello word");
	fun();

	return 0;
}