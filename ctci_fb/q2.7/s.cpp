

LinkedListNode * findTailAndLength(LinkedListNode * list, int & length)
{
    int l = 0;
    LinkedListNode *tail = NULL;
    while(list!=NULL){
        tail = list;
        list = list->Next;
        l++;
    }
    length = l;
    return tail;
}


Node * getKthNode(LinkedListNode * list, int k)
{
    int i = 0;
    LinkedListNode *node = list;
    while(node!=NULL && i++ < k){
        node = node->Next;
    }
    return node;
}

LinkedListNode* isIntersecting(LinkedListNode * l1, LinkedListNode *l2)
{
    if (l1 == NULL || l2 == NULL){
        return NULL;
    }

    int length1,length2;

    LinkedListNode * tail1 = findTailAndLength(l1, length1);
    LinkedListNode * tail2 = findTailAndLength(l1, length2);

    if (tail1 != tail2){
        return NULL;
    }

    int len;
    LinkedListNode *shortList, *longList;

    if( length1 < length2)
    {
        len = length2 - length1;
        shortList = l1;
        longList = l2;
    }else{
        len = length1 - length2;
        shortList = l2;
        longList = l1;
    }

    LinkedListNode* n = getKthElement(longList, len);

    while(n!=shortList){
        n = n->Next;
        shortList = shortList->Next;
    }
        
    return n;
}
