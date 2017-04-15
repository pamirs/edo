#include "../solution.h"

Node* addLists(Node* n1, Node* n2, int carry);

void addNumbers(Node* n1, Node* n2, Node** res)
{
   *res = NULL;
   int carry = 0;
   Node *sum = addLists(n1, n2, &carry);

   if(carry){
      *res = new Node();
      *res->Next = sum;
      *res->Number = carry;
   }else{
      *res = sum;
   }

}


Node* addLists(Node* n1, Node* n2, int* carry)
{
   if(n1 == NULL && n2 == NULL && carry == 0){
      *carry = 0;
      return NULL;
   }

   Node * result = new Node();
   result->Next = addLists(n1 == NULL ? NULL : n1->Next, n2 == NULL ? NULL : n2->Next, carry);
   
   int value = *carry;
   if (n1 != NULL){
      value += n1->Number;
   }
   if (n2 != NULL){
      value += n2->Number;
   }
   
   result->Number = value % 10;
  
   *carry = value >= 10 ? 1 : 0;  
   return result;
}

