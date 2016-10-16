#include <string>
#include <unordered_map>
bool isUnique(const std::string & str)
{
    std::unordered_map<char,int> lookup;

    for (int i=0; i<str.size(); i++){
        
        if (lookup[str.at(i)]++ > 0){
            return false;
        }
    }
    return true;
}

