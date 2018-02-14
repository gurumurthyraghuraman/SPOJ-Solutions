#include <iostream>

using namespace std;

int minGenderRegularity(int g, int b) {
    if(g == 0)
        return b;
    if(b == 0)
        return g;
    if(b > g) {
        return (b - 1)/(g + 1) + 1;
    }
    else return (g - 1)/(b + 1) + 1;

}

int main() {
    int g,b;
    cin>>g>>b;
    while(g != -1 && b != -1) {
        cout<<minGenderRegularity(g,b)<<endl;
        cin>>g>>b;
    }
    return 0;
}
