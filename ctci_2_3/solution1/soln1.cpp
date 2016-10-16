#include <cstddef>


struct Node{
	int d;
	Node* next;
};

int deleteMiddle(Node* mid){

	if (mid == NULL || mid->next == NULL) return -1;

	mid->d = mid->next->d;
	mid->next = mid->next->next;
	delete mid->next;

	return 0;
}
