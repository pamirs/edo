#include <iostream>
#include <string>

using namespace std;

string & urlify(string & str, int length)
{
	int n = 0;
		
	if(length<=0){
		return str;
	}	

	for(int i=0; i< length; i++){
		if(str[i]==' '){
			n+=3;	
		}else{
			n+=1;
		}
	}
 
	if (n==length)	
		return str;

	str[n--] = '\0';     

	for(int i=length-1;i>=0;i--){
		if(str[i]==' '){
			str[n--] ='0';
			str[n--] ='2';
			str[n--] ='%';
		}else{
			str[n--] = str[i];
		}
	}
	return str;
}
