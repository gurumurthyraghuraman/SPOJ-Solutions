#include <iostream>

using namespace std;

unsigned long long eights(unsigned long long k){
    unsigned long long res = 192;
    res+=(k-1)*250;
    return res;
}


int main(){
    int t;
    cin>>t;
    unsigned long long k;
    for(int i = 0; i < t; i++){
        cin>>k;
        cout<<eights(k)<<endl;
    }

    return 0;
}
