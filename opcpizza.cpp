#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int noOfPairs(vector<int> &arrAmnt, int target) {
    int pairs=0;
    vector<int>::iterator first,last;
    first=arrAmnt.begin();
    last=arrAmnt.end();
    sort(first, last);
    last--;
    while((first)<(last)) {
        if((*first)+(*last)==target){
            pairs++;
            first++;
            last--;
        }
        else if((*first)+(*last)<target)
                first++;
        else last--;
    }
    return pairs;

}


int main() {
    int t,n,m,tmpAmt;
    vector<int> amtPerPerson;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        amtPerPerson.clear();
        scanf("%d",&n);
        scanf("%d",&m);
        for(int j=0;j<n;j++) {
            scanf("%d",&tmpAmt);
            amtPerPerson.push_back(tmpAmt);
        }
        printf("%d\n",noOfPairs(amtPerPerson,m));
    }

    return 0;
}
