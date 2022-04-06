#pragma once
struct elem
{
	char value;
	elem* next = nullptr;
};
void push(elem*& stack, char value);
bool pop(elem*& stack, char& value);
bool pop(elem*& stack);
const char* peek(const elem* stack);
void clear(elem * &stack); 
