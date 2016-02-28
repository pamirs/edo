#include <unordered_map>

struct Node{
	int d;
	Node* next;
};

using namespace std;

void remDuplicates(Node** list)
{
	unordered_map<int,int> value_map;	
	unordered_map<int,int>::iterator it;

	Node* current = *list;
	Node* prev = NULL;
	
	while(current!=NULL){
		
		it = value_map.find(current->d);
		
		if(it == value_map.end()){
			value_map[current->d] = 1;
			prev = current;
			current = current->next;
		}else{
			if(prev == NULL){
				current = current->next;
				delete *list;
				*list = current;
			}else{
				prev->next = current->next;
				delete current;
				current = prev->next;
			}
		}

	}
}
