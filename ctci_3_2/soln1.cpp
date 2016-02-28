#include "stack.hpp"

//using namespace ctci;


struct MinEntry
{

	MinEntry(int v = 0) : value(v)
	{

	}
	int value;
	int count;
};


MinStack::MinStack() : top_(-1)
{

}

MinStack::~MinStack()
{
}


T MinStack::pop()
{
	T val = Stack::pop();

	int min = min_stack_.top().value;

	if (min == val && min_stack_.top().count_-- == 1)
		min_stack_.pop();
 
	return val;
}



void Stack::push(T d)
{
	if (top_ == MAX_STACK_SIZE-1)
		throw "stack full";
 
	if(top_ < 0 || min_stack_.top().value > d)
		min_stack_.push(MinEntry(d));	
	else if(min_stack_.top().value == d)
		min_stack_.top().count_ ++;

	stack_array_[++top_] = d; 

}

int Stack::min()
{
	if(top < 0)
		throw "Stack empty";

	return  min_stack_.top().value_;
}




