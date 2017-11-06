#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int t;
    double r;
    double result;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>r;
        result=0.25;
        result+=4*r*r;
        cout<<"Case "<<i+1<<": ";
        cout<<fixed<<setprecision(2)<<result<<endl;
    }
    return 0;


}
