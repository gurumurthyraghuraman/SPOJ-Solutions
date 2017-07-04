#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n,input;
    bool isValid;
    vector<int> cars;
    stack<int> stackCars;
    scanf("%d",&n);

    while(n!=0){
        isValid=true;
        cars.clear();
        //stackCars.clear();
        for(int i=0;i<n;i++) {
            scanf("%d",&input);
            while(!stackCars.empty() && input>stackCars.top()) {
                    cars.push_back(stackCars.top());
                    stackCars.pop();
            }
            if(stackCars.empty() || input < stackCars.top())
                stackCars.push(input);


        }
        while(!stackCars.empty()) {
            cars.push_back(stackCars.top());
            stackCars.pop();
        }
        for(vector<int>::iterator it=cars.begin();it<cars.end()-1;it++) {
            if(*it>*(it+1))
                isValid=false;
        }
        if(isValid) printf("%s\n","yes");
        else printf("%s\n","no");
        cin>>n;
    }


    return 0;

}
