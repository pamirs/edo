#include <iostream>

namespace ctci{

template <class T>
class Stack
{
public:

Stack() : top_(-1)
{

}
void push(T val){
	if (top_ == MAX_STACK_SIZE-1)
		throw "stack full";
 
	stack_array_[++top_] = val; 
}

T pop(){
	if(top_ < 0)
		throw "Stack empty";
	T val = stack_array_[top_--];
	return val;
}

bool empty()
{
	return top_ < 0;
}

T & top()
{
	if(top_ < 0)
		throw "Stack empty";
	return stack_array_[top_];
}
private:
enum{
MAX_STACK_SIZE = 100
};

T stack_array_[MAX_STACK_SIZE];
int top_;
};


template<class T>
class StackWithMin : public Stack<T>
{
public:

void push(T val){
	Stack<T>::push(val);

 
	if(min_stack_.empty() || min_stack_.top().value > val){
		MinEntry m = {val, 1};
		
		std::cout << "adding min " << val << std::endl;
		min_stack_.push(m);	
        }else if(min_stack_.top().value == val){
		min_stack_.top().count ++;
	
		std::cout << "incrementing  min " << val << std::endl;
	}

}

T pop(){
	T val = Stack<T>::pop();

	T min = min_stack_.top().value;

	if (min == val && min_stack_.top().count-- == 1)
		min_stack_.pop();
 
	return val;

}

T min()
{
	return  min_stack_.top().value;
};
private:

struct MinEntry
{
	T value;
	int count;
};

Stack<MinEntry> min_stack_;

};

}







