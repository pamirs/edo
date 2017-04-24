#include "s.h"
#include <math.h>


int multiply(int n1, int n2)
{
    int small  = n1 < n2 ? n1 : n2;
    int large  = small == n1 ? n2 : n1;

    return multiply2(small,large);

}


int multiply2(int n1, int n2)
{
    
    if(n1 == 0){
        return 0;
    }else if(n1 == 1){
        return n2;
    }

    int sum = multiply2(n1/2, n2);
    sum += sum;
    if (n1%2 == 1){
        sum += n2; 
    }
    return sum;
}


