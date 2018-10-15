#include <iostream>
#include <string>
#include <ctime>
#include "Header.h"
using namespace std;

void testCopyConstructor(stackType<int> otherStack);
int main()
{
	clock_t const start = clock();
	double const duration = (clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
	

	/*cout << "hello\n";
	stackType<int> myStack;
	myStack.initializeStack();
	myStack.push(1);
	myStack.push(30);

	cout << myStack.top() << endl;
	cout << myStack.isEmptyStack() << endl;
	cout << myStack.isFullStack() << endl;
	cout << myStack.pop();
	cout << myStack.pop();
	cout << myStack.top() << endl;

	stackType<string> mystackT;
	mystackT.push("Hello");
	mystackT.push("there");
	cout << mystackT.top() << endl;

	stackType<char> charstack;
	charstack.push('m');
	charstack.push('e');
	cout <<charstack.top() << endl;
	cout << charstack.pop();
	cout << charstack.pop();
	cout << charstack.top() << endl;*/

	stackType<int> stack(50);
	stackType<int> copyStack(50);
	stackType<int> dummyStack(100);

	stack.initializeStack();
	stack.push(23);
	stack.push(45);
	stack.push(38);

	cout << "THere are " << stack.size() << " elements in the stack\n";
	copyStack = stack;

	cout << "The elements of copyStack:\n";

	while(!copyStack.isEmptyStack())
	{
		cout << copyStack.top() << endl;
		cout << "Popped: ";
		cout << copyStack.pop();
		cout << endl;
	}


	copyStack = stack;
	testCopyConstructor(copyStack);

	if (!stack.isEmptyStack())
		cout << "The original stack is not empty.\n" << "The top element of the original stack: "
		<< stack.top() << endl;

	dummyStack = stack;

	cout << "The elements of dummyStack:\n";

	while(!dummyStack.isEmptyStack())
	{
		cout << dummyStack.top() << endl;
		cout << "Popped: ";
		cout << dummyStack.pop();
		cout << endl;
	}

	cout << "CLOCKS_PER_SEC: " << duration << '\n';
	return 0;
}

void testCopyConstructor(stackType<int> otherStack)
{
	if(!otherStack.isEmptyStack())
	{
		cout << "The original stack is not empty.\n";
		cout << "The top element of otherStack: " << otherStack.top() << endl;
	}
}