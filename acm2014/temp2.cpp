#include <iostream>
#include <string>
#include <bitset>
using namespace std;
int main(){
	string str("123aa");
	string sss="oppp";
	const char* s;
	char c=str[2];
	c='u';
	int i=str.find("kkkk");
	cout<<(string::npos==i)<<endl;
}  
