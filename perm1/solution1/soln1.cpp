#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> perm(string s, string prefix);

vector<string> perm(string s)
{
	return perm(s,"");
}

vector<string> perm(string s, string prefix)
{
	vector<string> all;
	
	if(s.length() <= 1){
		all.push_back(prefix+s);
	}else 
	{
		for(int i=0; i<s.length(); ++i){
			vector<string> tmp = perm(s.substr(0,i) + s.substr(i+1,s.length()-i-1), prefix+s.at(i) );

			all.insert(all.end(),tmp.begin(), tmp.end());
		}
	}
	
	return all;
}
