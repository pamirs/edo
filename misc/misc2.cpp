#include <iostream>

using namespace std;

void addRestOfString(string s, string prefix);
void printPermutations(string s)
{
    cout << endl;

    addRestOfString(s, "");
}

void addRestOfString(string s, string prefix)
{
    if (s.size() == 0){
        cout << prefix << endl;
    }

//    cout << "* " << s.c_str() << " , " << prefix.c_str() << " *" << endl;

    //for (int i=0; i<s.size(); i++){
int i =0;
    for (char c : s){
        string tmp = prefix;
        tmp.push_back(c);
        string rest = s;
        rest.erase(i,1);
        i++;

        addRestOfString(rest,tmp);
    }


}

int main()
{
    printPermutations("123");
    cout << endl;
    cout << endl;
    printPermutations("abc");
    cout << endl;
    cout << endl;
    printPermutations("5678");

}
