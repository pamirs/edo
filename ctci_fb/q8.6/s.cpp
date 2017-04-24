#include <stack>
#include <iostream>
#include <assert.h>

using namespace std;

struct Disk
{
    Disk(int sz) :size(sz){}
    int size;
};

int moveDisks(int n, stack<Disk*> &ti, stack<Disk*> &tf, stack<Disk*> &ts);
int main()
{

    //Tower1
    stack<Disk*> t1;
    stack<Disk*> t2;
    stack<Disk*> t3;

    t1.push(new Disk(5));
    t1.push(new Disk(4));
    t1.push(new Disk(3));
    t1.push(new Disk(2));
    t1.push(new Disk(1));

    int steps = moveDisks(t1.size(), t1,t3,t2);

    cout << endl << "Steps: " << steps << endl;
    while(!t3.empty()){
        cout << endl << t3.top()->size << endl;
        t3.pop();
    }
    return 0;
}

int moveDisks(int n, stack<Disk*> &ti, stack<Disk*> &tf, stack<Disk*> &ts)
{
int steps = 0;
    if (n==1){
        Disk* d = ti.top();
        ti.pop();
        assert(tf.empty() || tf.top()->size > d->size);
        tf.push(d);
        steps = 1;
    }else if (n==2){
        steps += moveDisks(1, ti,ts,tf);
        steps += moveDisks(1, ti,tf,ts);
        steps += moveDisks(1, ts,tf,ti);
    }else{
        steps += moveDisks(n-1, ti, ts, tf);
        steps += moveDisks(1, ti, tf, ts); 
        steps += moveDisks(n-1, ts, tf, ti); 
    }
    return steps;
}

