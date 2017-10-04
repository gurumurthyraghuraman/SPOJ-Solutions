#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int noOfCorns(string strInput){
    string strTemp;
    int maxCorns;
    float r,s,h,pi,slHeight,dArea;
    pi=3.1415;
    int eCount=0;
    for(int i=0;i<strInput.length();i++){
        if(strInput[i]=='e'){
            if(eCount==0){
                r=stof(strTemp);
                strTemp="";
            }
            else{
                s=stof(strTemp);
                strTemp="";
            }
            eCount++;
        }
        else{
            strTemp+=strInput[i];
        }
    }
    h=stof(strTemp);
    strTemp="";
    slHeight=sqrt(r*r+h*h);
    dArea=pi*r*slHeight;
    maxCorns=ceil(dArea*s);

    return maxCorns;


}


int main(){
    int t;
    string strInput;
    cin>>t;
    for(int i=0;i<t;i++){
	cin>>strInput;
	cout<<noOfCorns(strInput)<<endl;
    }
    return 0;
}
