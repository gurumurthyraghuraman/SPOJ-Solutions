#include <iostream>
#include <map>
using namespace std;

map<unsigned long long,unsigned long long> mapCalcCoins;

unsigned long long noOfDollars(unsigned long long coins){
	if(mapCalcCoins.find(coins)!=mapCalcCoins.end())
        return mapCalcCoins[coins];
	unsigned long long a= noOfDollars(coins/2);
	unsigned long long b= noOfDollars(coins/3);
	unsigned long long c= noOfDollars(coins/4);
	mapCalcCoins[coins]=max(a+b+c,coins);
	return mapCalcCoins[coins];

}


int main() {
	// your code goes here
	unsigned long long coins;
    mapCalcCoins[0]=0;
    while(cin>>coins){
		cout<<noOfDollars(coins)<<endl;
	}

	return 0;
}
