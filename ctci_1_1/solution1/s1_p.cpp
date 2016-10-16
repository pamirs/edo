#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

bool isUnique(const std::string & str)
{
    unsigned char charcount[256];

    memset(charcount,0,256);
    
    for (int i=0;i<str.size();i++){
        
        if(charcount[str.at(i)]++ > 0){
            return false;
        }

    }

    return true;

}






