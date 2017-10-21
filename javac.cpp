#include <iostream>
#include <string>
using namespace std;

string convertName(string inputStr){
	string retString;
	bool underScore=false;
	bool capital=false;
	if(inputStr.length()==0)
		return inputStr;
	if((inputStr[0]>='A' && inputStr[0]<='Z') || inputStr[0]=='_')
		return "Error!";
	for(int i=0;i<inputStr.length();i++){
		if(inputStr[i]=='_'){
			if(i!=inputStr.length()-1){
				if(inputStr[i+1]>='a' && inputStr[i+1]<='z'){
					retString+='A'+(inputStr[i+1]-'a');
					i++;
				}
				else{
					return "Error!";
				}
			}
			else{
				return "Error!";
			}
			underScore=true;
		}
		else if(inputStr[i]>='A' && inputStr[i]<='Z'){
			capital=true;
			retString+='_';
			retString+='a'+(inputStr[i]-'A');
		}
		else{
			retString+=inputStr[i];

		}



	}
	if(capital && underScore)
		return "Error!";

	return retString;

}

int main() {
	string inputStr;
	while(cin>>inputStr){
		cout<<convertName(inputStr)<<endl;

	}
	return 0;
}
