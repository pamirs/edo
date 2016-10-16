#include <unordered_map>

struct Node{
	int d;
	Node* next;
};

using namespace std;

void remDuplicates(Node** list)
{
	Node* current = *list;
	Node* prev = NULL;

	while(current!=NULL){	
		prev = current;
		Node* current2 = current->next;
		while(current2!=NULL){
			if(current2->d == current->d){
				prev->next = current2->next;
				delete current2;
				current2 = prev->next;
			}else
				current2 = current2->next;
		}
		current = current->next;
	}		
}
