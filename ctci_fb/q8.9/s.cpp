#include <iostream>
#include <string>

using namespace std;

void printParantheses(int);

int main()
{
    cout << "N: 2" <<endl;
    printParantheses(2);
    cout << "N: 3" <<endl;
    printParantheses(3);
    cout << "N: 5" <<endl;
    printParantheses(5);

    return 0;
}

void printParanthesesHelper(string p,  int left, int right);

void printParantheses(int n)
{
    printParanthesesHelper("",n,n);
}

void printParanthesesHelper(string p,  int left, int right)
{
    if(left){
        printParanthesesHelper(p + '(', left - 1, right);

        if(left < right){
            printParanthesesHelper(p + ')', left, right - 1);
        }
    }else{
        for(int i=0;i<right;i++){
            p+=')';
        }
        cout << p << endl;
    }
        

}
