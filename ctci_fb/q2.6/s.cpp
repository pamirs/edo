#include <stack>

template<class T>
struct LinkedListNode{
    T data;
    LinkedListNode * Next;
};

// space O(n)
// time  O(n)
bool isPalindrome(LinkedListNode *head)
{
    LinkedListNode *mid = head;
    LinkedListNode *p = head;
    int  x = 0;
    stack <LinkedListNode>s;
    
    
    if (head == NULL)
    {
        return false;
    }
    while(p != NULL)
    {
        if(x){
            mid = mid->Next;
        }
        x = x^1;
        p = p->Next;
    }

    p = head;
    while(p != mid)
    {
        count++;
        s.push(mid);
    }

    if (x){
        mid = mid ->Next;
    }

    p = s.top;
    while (mid != NULL && p->Data == mid->Data){
        mid = mid->Next;
        s.pop;
        p = s.top();
    }

    if(mid == NULL)
        return true;

    return false;
}

template <class T>
LinkedListNode<T>* getKthLastElement(LinkedListNode<T>* head, int k)
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

// Elegent slow
// Space O(1)
// Time O(n2)
bool isPalindrome2(LinkedListNode *head)
{

    if (head == NULL) return false;
    LinkedListNode * p = head;
    int k = 0;
    while(p!=NULL){

        if (p->Data != getKthLastElement(head,k)->Data)
        {
            return false;
        }

        p = p->Next;
    }
    return true;
}


LinkedListNode* reverse(LinkedListNode* head)
{
    if (head ==NULL)
    {
        return NULL;
    }
    int i = 0;
    LinkedListNode* rHead = new LinkedListNode();
    rHead->Data = getKthLastElement(i++)->Data;
    LinkedListNode* rTail = rHead;
    LinkedListNode * p = getKthLastElement(i++)
    while( p != NULL){
        rTail->Next = new LinkedListNode();
        rTail = rTail->Next;
        rTail->Data = p->Data;
        p = getKthLastElement(i++);
    }
    rTail->Next = NULL;
    return rHead;
}

// reverse
// time O(n2)
// space O(1)

bool isPalindrome3(LinkedListNode *head)
{
    LinkedListNode * p1 = head;
    LinkedListNode * p2 = reverse(head);
    while(p1 !=NULL && p2 != NULL){
        if (p1->Data != p2->Data){
            return false;
        }
        p1 = p1->Next;
        p2 = p2->Next; 
    }
    return ;
}

struct Pair
{
    LinkedListNode* head;
    LinkedListNode* prev;
};

Pair reverse2(LinkedListNode* list)
{
    Pair ret;
    ret.head = NULL;
    ret.tail = NULL;
    if(list == NULL){
        return ret;
    }
    Pair p = reverse2(list->Next);
    LinkedListNode* n = new LinkedListNode();
    n->Data = list->Data;
    n->Next = NULL;
    if (p.head == NULL){
        ret.head = n;
        ret.tail = n;
    }else{
        ret.head = p.head;
        ret.tail = n;
        p.tail->Next = n;
    }
    return ret;
}


struct Result{
    LinkedListNode* node;
    bool result;
};


Result isPalindromeRecurse (LinkedListNode * list, int length)
{
    Result res;
    if (list == NULL || length == 0){
        res.result = true;
        r.node = list;
        return res;
    }else if (length == 1){
        res.result = true;
        res.node = list->Next;
        return res;
    }

     r = isPalindromeRecurse(list->Next, length - 2);

    if (!r.result || r.node == NULL) {
        return r;
    }

    r.result = (r.node->Data == list->Data);
    r.node   = r.node->Next; 

    return r;
}

bool isPalindrome3(LinkedListNode* list)
{
    LinkedListNode * tmp = list;
    int l = 0;
    while(tmp!=NULL)
    {
        i++;
        tmp=tmp->Next;
    }

    return isPalindromeRecurse(list->Next,i);
}
