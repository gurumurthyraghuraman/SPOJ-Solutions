#include <iostream>
#include <vector>
using namespace std;

vector<int> ingridients(int e1, int f1, int s1, int m1, int e2, int f2, int s2, int m2){
	vector<int> result;
	int maxCakes=0;
	if(e1%e2==0 && e1/e2>maxCakes){
		maxCakes=e1/e2;
	}
	else{
		if(e1%e2!=0 && (e1/e2) + 1>maxCakes)
			maxCakes=(e1/e2) +1;
	}
	if(f1%f2==0 && f1/f2>maxCakes){
		maxCakes=f1/f2;
	}
	else{
		if(f1%f2!=0 && (f1/f2) + 1>maxCakes)
			maxCakes=(f1/f2) +1;
	}
	if(s1%s2==0 && s1/s2>maxCakes){
		maxCakes=s1/s2;
	}
	else{
		if(s1%s2!=0 && (s1/s2) + 1>maxCakes)
			maxCakes=(s1/s2) +1;
	}
	if(m1%m2==0 && m1/m2>maxCakes){
		maxCakes=m1/m2;
	}
	else{
		if(m1%m2!=0 && (m1/m2) + 1>maxCakes)
			maxCakes=(m1/m2) +1;
	}
	//cout<<"Max Cakes:"<<maxCakes<<endl;
	result.push_back(e2*maxCakes - e1);
	result.push_back(f2*maxCakes - f1);
	result.push_back(s2*maxCakes - s1);
	result.push_back(m2*maxCakes - m1);

	return result;


}

int main() {
	// your code goes here
	int e1,e2,f1,f2,m1,m2,s1,s2;
	bool allCasesDone=true;
	while(allCasesDone){
		cin>>e1>>f1>>s1>>m1>>e2>>f2>>s2>>m2;
		if(e1==-1 && f1==-1 && s1==-1 && m1==-1 && e2==-1 && f2==-1 && s2==-1 && m2==-1){
			allCasesDone=false;
		}
		else{
			vector<int> result=ingridients(e1,f1,s1,m1,e2,f2,s2,m2);
			for(int i=0;i<result.size();i++){
				cout<<result[i]<<" ";
			}
			cout<<endl;
		}


	}
	return 0;
}
