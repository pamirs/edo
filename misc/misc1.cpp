#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int num)
{

if(num%2 == 0){
    return false;
}
       bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d));
        
        while (divisor <= upperLimit)
        {
            if (num % divisor == 0){
                prime = false;
                break;
            }
            divisor +=1;
        }
        return prime;
}

int main()
{
    int num = 40;

    for(int i = 3; i <= num; i++)
    {
        if( isPrime(i) )
        {
            cout << i << " is prime" << endl;
        }
    }
return 0;

}
