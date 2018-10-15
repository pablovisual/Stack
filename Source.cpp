#include <iostream>
#include <string>
#include <ctime>
#include "Header.h"
using namespace std;

int main()
{
	clock_t const start = clock();
	double const duration = (clock() - start) / static_cast<double>(CLOCKS_PER_SEC);

	cout << "hello\n";
	stackType<int> myStack;
	myStack.push(1);
	myStack.push(30);

	cout << myStack.top() << endl;
	cout << myStack.isEmptyStack() << endl;
	cout << myStack.isFullStack() << endl;
	myStack.pop();
	myStack.pop();
	cout << myStack.top() << endl;
	stackType<string> mystackT;
	mystackT.push("Hello");
	mystackT.push("there");
	cout << mystackT.top() << endl;
	stackType<char> charstack;
	charstack.push('m');
	charstack.push('e');
	charstack.push('h');
	cout <<charstack.top() << endl;
	charstack.pop();
	charstack.pop();
	cout << charstack.top() << endl;

	cout << "CLOCKS_PER_SEC: " << duration << '\n';
	return 0;
}