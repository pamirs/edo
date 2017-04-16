#include "../solution.h"

Node* addLists(Node* n1, Node* n2, int carry);

void addNumbers(Node* n1, Node* n2, Node** res)
{
	*res = addLists(n1, n2, 0);
}


Node* addLists(Node* n1, Node* n2, int carry)
{
   if(n1 == NULL && n2 == NULL && carry == 0){
      return NULL;
   }
   Node * result = new Node();
   int value = carry;
   if (n1 != NULL){
      value += n1->Number;
   }
   if (n2 != NULL){
      value += n2->Number;
   }
   
   result->Number = value % 10;
	
   result->Next = addLists(n1 == NULL ? NULL : n1->Next, n2 == NULL ? NULL : n2->Next, value >=10 ? 1: 0);
	
   return result;
}

