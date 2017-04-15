#include "../solution.h"


void addNumbers(Node* n1, Node* n2, Node** sum)
{
  Node* tmp1 = n1;
  Node* tmp2 = n2;
  Node* tmp3 = NULL;
  int carry = 0;
  int t1,t2;
  *sum = NULL;
  while(tmp1 != NULL || tmp2 != NULL){
	
	if( tmp3 == NULL){
		*sum = tmp3 = (Node*) malloc(sizeof(Node));
	}else{
		tmp3->Next = (Node*) malloc(sizeof(Node));
		tmp3 = tmp3->Next;
	}
	
        if(tmp1 != NULL){
		t1 = tmp1->Number;
		tmp1 = tmp1->Next;
	} else{
		t1 = 0;
	}
	if(tmp2 != NULL){
		t2 = tmp2->Number;
		tmp2 = tmp2->Next;
	}else{
		t2 = 0;
	}

	if(carry + t1 + t2 > 9){
		tmp3->Number =  t1 + t2 + carry - 10;
		carry = 1;
	}else{
		tmp3->Number =  t1 + t2 + carry;
		carry = 0;
	}
  }

  if(tmp3 != NULL){
	if(carry){
		tmp3 = tmp3->Next = (Node*)malloc(sizeof(Node));
		tmp3->Number = carry;
	}
	tmp3->Next = NULL;
  } 

}
