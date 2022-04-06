#include "Stack.h"

void push(elem*& top, char value)
{
	auto* newel = new elem;
	newel->value = value;
	if (top) {
		newel->next = top;
	}
	top = newel;
}

bool pop(elem*& top, char& value)
{
	if (top)
	{
		value = top->value;
		auto* rem = top;
		top = top->next;
		delete rem;
		return true;
	}
	else {
		return false;
	}
}

bool pop(elem*& top)
{
	if (top)
	{
		auto* rem = top;
		top = top->next;
		delete rem;
		return true;
	}
	else {
		return false;
	}
}
const char* peek(const elem* top)
{
	if (top)
	{
		return &top->value;
	}
	return nullptr;
}

void clear(elem*& top)
{
	/*
	int val;
	while (pop(top, val));
	*/
	while (top)
	{
		auto* rem = top;
		top = top->next;
		delete rem;
	}
}
