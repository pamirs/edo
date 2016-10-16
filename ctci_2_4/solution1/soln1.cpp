#include <cstddef>

struct Node{
	int d;
	Node* next;
};


int partitionList(Node** list, int pval)
{
	if (list == NULL)
	{
		return -1;	
	}
	
	if(*list == NULL){
		return 0;
	}
	Node *last = *list; 
	while(last->next!=NULL){
		last = last->next;
	}
	
	Node * current = *list;
	Node * prev = NULL;
	while(current!=last){
		if(current->d >= pval){
			if(prev == NULL)
				*list = current->next;
			else
				prev->next = current->next;
			Node* tmp = current->next;
			current->next = last->next;
			last->next = current;
			current = tmp;
		}else{
			prev = current;
			current = current->next;
		}
	}
	return 0;
}

