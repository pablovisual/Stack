#include <iostream>
#include <string>
#include <ctime>
#include "Header.h"
using namespace std;

void testCopyConstructor(stackType<int> otherStack);
int main()
{
	clock_t const start = clock();

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
	stackType<int> copy_stack(50);
	stackType<int> dummy_stack(100);

	stack.initializeStack();
	stack.push(23);
	stack.push(45);
	stack.push(38);

	cout << "There are " << stack.size() << " elements in the stack\n";
	copy_stack = stack;

	cout << "The elements of copyStack:\n";

	while(!copy_stack.isEmptyStack())
	{
		cout << "Pushing: ";
		cout << copy_stack.top() << endl;
		cout << "Popped: ";
		cout << copy_stack.pop();
		cout << endl;
	}


	copy_stack = stack;
	testCopyConstructor(copy_stack);

	if (!stack.isEmptyStack())
		cout << "The original stack is not empty.\n" << "The top element of the original stack: "
		<< stack.top() << endl;

	dummy_stack = stack;

	cout << "The elements of dummyStack:\n";

	while(!dummy_stack.isEmptyStack())
	{
		cout << "Pushing: ";
		cout << dummy_stack.top() << endl;
		cout << "Popped: ";
		cout << dummy_stack.pop();
		cout << endl;
	}

	auto const duration = (clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
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