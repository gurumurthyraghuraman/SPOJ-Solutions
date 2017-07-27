#include <iostream>
#include <string>
using namespace std;

bool checkPalin(string s, int start, int last) {
	while(start<=last){
		if(s[start]==s[last]){
			start++;
			last--;
		}
		else {
			return false;
		}
	}
	return true;

}


int main() {
	// your code goes here
	int k;
	string inputStr;
	cin>>k;
	cin>>inputStr;
	int start=0;
	int last=k-1;
	int len=inputStr.length();
	int count=0;
	while(last<=len){
		if(checkPalin(inputStr,start,last))
			count++;
		start++;
		last++;
	}
	cout<<count<<endl;
	return 0;
}
