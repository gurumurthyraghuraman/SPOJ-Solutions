#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

bool isOffside(vector<int> def, vector<int> att){
    sort(def.begin(), def.end());
    sort(att.begin(), att.end());
    if(att[0]<def[1])
        return true;

    return false;


}


int main(){
    int noOfDef,noOfAtt,temp;
    vector<int> att;
    vector<int> def;

    scanf("%d",&noOfAtt);
    scanf("%d", &noOfDef);
    while(noOfDef!=0 || noOfAtt!=0){
            att.clear();
            def.clear();
            for(int j=0;j<noOfAtt;j++){
                scanf("%d",&temp);
                att.push_back(temp);
            }
            for(int i=0;i<noOfDef;i++){
                scanf("%d",&temp);
                def.push_back(temp);
            }

            if(isOffside(def,att))
                printf("Y\n");
            else printf("N\n");
            scanf("%d",&noOfAtt);
            scanf("%d", &noOfDef);
    }


    return 0;
}
