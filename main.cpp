#include <iostream> 
using namespace std;

void fun() {
	printf("hello word");
}

void fun(int x) {
	cout << x << endl;
}

void fun(char c) {
	if (c == ' ')
		cout << "\n" << endl;
}

int main() {
	printf("hello word");
	fun();
	fun(3);
	cout << "----------------" << endl;

	return 0;
}