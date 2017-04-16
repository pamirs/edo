


#include <list>


using namespace std;


template <class T>
T getKthLastElement(list<T> l, int k)
{   
    int i = 0;
    auto kth = l.begin();
    for (auto it = l.begin(); it != l.end(); ++it, ++i){
        if(i == k){
            kth++; 
        }
    }

    if (i < k){
        throw "error";
    }
    return *kth; 
}


template<class T>
struct LinkedListNode{
    T data;
    LinkedListNode *Next;
}




template <class T>
LinkedListNode<T>* getKthLastElement2(LinkedListNode<T>* head, int k)
{   
    LinkedListNode<T> * kth = head;
    LInkedListNode<T> * p = head;
    for (int i=0; i < k; i++){
        if (p == NULL){
            return NULL;
        }
        p = p->Next;
    }

    while(p!=NULL){
        p = p->Next;
        kth = kth->Next;
    }

    return kth;
}
