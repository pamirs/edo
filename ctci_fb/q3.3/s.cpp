#include <stack>

using namespace std;

template <class T>
class SetOfStacks
{

    public:
        SetOfStacks(int capacity) : capacity_(capacity)
        {
            stack<T> s; 
            stacks.push_back(move(s))
            currentStack_ = &stacks.back();
        }
    
        void push(T val)
        {
            if(currentStack_->size() >= capacity){
                stack<T> s;
                stacks<stack<T>>.push_back(move(s));
                currentStack_ = &stacks.back();
            }

            currentStack_->push(val);
        }

        void pop()
        {
            currentStack_->pop();
            
            if(!currentStack_->size() && stacks_.size() > 1){
                stacks_.pop_back();
                currentStack_ = &stacks_.back(); 
            }
        }

    private:
        deque<Stack<T>> stacks;
        int capacity_;
        stack* currentStack;
};


