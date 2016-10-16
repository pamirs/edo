
namespace ctci{

template <class T>
class Stack
{
public:
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

T & Stack::top()
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

 
	if(min_stack_.top_ < 0 || min_stack_.top().value > val)
		MinEntry m = {val, 1};
		min_stack_.push(m);	
	else if(min_stack_.top().value == val)
		min_stack_.top().count_ ++;

}

T pop(){
	T val = Stack<T>::pop();

	int min = min_stack_.top().value;

	if (min == val && min_stack_.top().count_-- == 1)
		min_stack_.pop();
 
	return val;

}

T min()
{
	return  min_stack_.top().value_;
};
private:

struct MinEntry
{
	int value;
	int count;
};

Stack<MinEntry> min_stack;

};

}







