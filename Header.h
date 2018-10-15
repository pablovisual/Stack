#pragma once
///Header file : myStack.h
#include<iostream>
#include<string>
#include <type_traits>
#include <cassert>
#include "Header.h"
using namespace std;

template<class T>
class stackADT
{
public:
	virtual void initializeStack() = 0;
	///method to initialize the stack to an empty state
	///postcodition: Stack is empty

	virtual bool isEmptyStack() const = 0;
	///Function to determine whether the stack is empty
	///postcondtion: Return the true if the stack is empty
	///				 otherwise returns false

	virtual bool isFullStack() const = 0;
	///Function to determine whether the stack is full.
	///Postcondition: Returns true if the stack is full,
	///otherwise returns false.
	
	virtual void push(const T& newItem) = 0;
	///Function to add newItem to the stack.
	///Precondition: The stack exists and is not full.
	///Postcondition: The stack is changed and newItem
	///is added to the top of the stack.

	virtual T top() const = 0;
	///Function to return the top element of the stack.
	///Precondition: The stack exists and is not empty.
	///Postcondition: If the stack is empty, the program
	///terminates; otherwise, the top element
	///of the stack is returned.

	virtual void pop() = 0;
	///Function to remove the top element of the stack.
	///Precondition: The stack exists and is not empty.
	///Postcondition: The stack is changed and the top
};

template <class U>
class stackType : public stackADT<U>
{
public:
	const stackType<U>& operator=(const stackType<U>&);
	///Overload the assignment operator.

	void initializeStack();
	///Function to initialize the stack to an empty state.
	///Postcondition: stackTop = 0;

	bool isEmptyStack() const;
	///Function to determine whether the stack is empty.
	///Postcondition: Returns true if the stack is empty,
	///otherwise returns false.

	bool isFullStack() const;
	///Function to determine whether the stack is full.
	///Postcondition: Returns true if the stack is full,
	///otherwise returns false.

	void push(const U& newItem);
	///Function to add newItem to the stack.
	///Precondition: The stack exists and is not full.
	///Postcondition: The stack is changed and newItem
	///is added to the top of the stack.

	U top() const;
	///Function to return the top element of the stack.
	///Precondition: The stack exists and is not empty.
	///Postcondition: If the stack is empty, the program
	///terminates; otherwise, the top element
	///of the stack is returned.

	void pop();
	///Function to remove the top element of the stack.
	///Precondition: The stack exists and is not empty.
	///Postcondition: The stack is changed and the top
	///element is removed from the stack.

	stackType(int stackSize = 100);
	///Constructor
	///Create an array of the size stackSize to hold
	///the stack elements. The default stack size is 100.
	///Postcondition: The variable list contains the base
	///address of the array, stackTop = 0, and
	///maxStackSize = stackSize.

	stackType(const stackType<U>& otherStack);
	//Copy constructor

	~stackType();
	///Destructor
	///Remove all the elements from the stack.
	///Postcondition: The array (list) holding the stack
	///elements is deleted.

private:
	int maxStackSize; ///variable to store the maximum stack size
	int stackTop; ///variable to point to the top of the stack
	U *list; ///pointer to the array that holds the
			 ///stack elements
	void copyStack(const stackType<U>& otherStack);
	///Function to make a copy of otherStack.
	///Postcondition: A copy of otherStack is created and
	///assigned to this stack.
};

template <class U>
void stackType<U>::initializeStack() { stackTop = 0; } ///end of the stack


template <class U>
stackType<U>::stackType(int stackSize)
{
	if(stackSize <= 0)
	{
		cout << "Size of the array to hold the stack must ";
		cout << "be positive\nbhh";
		cout << "Creating an array of size 100hello there.\n";

		maxStackSize = 100;
	}

	else
		maxStackSize = stackSize; ///set max size of the stack to the stack size
	
	list = new U[stackSize]; ///the stack holds up to 100 items
	stackTop = 0; ///set stackTop to 0
}///end  of constructor

template <class U>
bool stackType<U>::isEmptyStack() const
{
	if (stackTop == 0) ///returns true if the stack is empty, otherwise
		return true;

	else
		return false;
}

template <class U>
bool stackType<U>::isFullStack() const
{
	if (stackTop == maxStackSize) ///if the stack is full returns true, otherwise
		return true;
	else
		return false;
}

template <class U>
void stackType<U>::push(const U& newItem)
{
	if (!isFullStack())
	{
		list[stackTop] = newItem; ///add newItem at the top
		++stackTop; ///increment stackTop
	}

	else
		cout << "Stack is full\n";
}

template <class U>
U stackType<U>::top() const
{
	if (stackTop != 0)
		return list[stackTop - 1];

	else
	{
		cout << "Stack is empty\n";
		return NULL;
	}
	///assert(stackTop != 0); this makes the program stop and opens up window to abort

}

template <class U>
void stackType<U>::pop()
{
	if(!isEmptyStack())
	{
		auto previous = list[stackTop - 1]; ///I'm setting U previous to be set to anything from the stacktop - 1
		stackTop--; ///decrementing stack, popping the stack
		cout << previous << endl; ///outputting what was popped
	}
}

template <class U>
void stackType<U>::copyStack(const stackType<U>& otherStack)
{
	delete[]list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;
	list = new U[maxStackSize];

	///copy otherStack into this stack
	for (int index = 0; index < stackTop; ++index)
		list[index] = otherStack.list[index];
	///end of copyStack
}

template <class U>
stackType<U>::~stackType()
{
	delete[]list; ///deallocate the memory occupied by the stack
}///end of deconstructor

template <class U>
stackType<U>::stackType(const stackType<U>& otherStack)
{
	list = nullptr;
	copyStack(otherStack);
}///end of copyStack

template <class U>
const stackType<U>& stackType<U>::operator=(const stackType<U>& otherStack)
{
	if (this != &otherStack) ///to avoid self copy
		copyStack(otherStack);

	return *this;
}///end of operator=
