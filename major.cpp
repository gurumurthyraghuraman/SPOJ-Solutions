#include <stdio.h>
#include <set>
#include <map>

using namespace std;

int main(){
    int t,n,eachMsg;
    set<int> msgs;
    map<int,int> msgMap;
    set<int>::iterator setIt;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        msgs.clear();
        msgMap.clear();
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%d",&eachMsg);
            msgs.insert(eachMsg);
            if(msgMap.find(eachMsg)!=msgMap.end()){
                msgMap[eachMsg]+=1;
            }
            else{
                msgMap[eachMsg]=1;
            }

        }
        for(setIt=msgs.begin();setIt!=msgs.end();setIt++){
            if(msgMap[*setIt]>n/2){
                //cout<<"YES "<<*setIt<<endl;
                printf("YES %d\n",*setIt);
                break;

            }
        }
        if(setIt==msgs.end()){
            printf("NO\n");
        }

    }
    return 0;
}


