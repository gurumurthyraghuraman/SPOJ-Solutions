#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


class node{
    public:
        string name;
        int topoNumber;
    void setNode(string a, int num){
        name=a;
        topoNumber=num;
    }

    bool operator < (const node& obj) const{
        return (topoNumber < obj.topoNumber);
    }

};



void topologicalSort(map<string,vector<string> > graphAdjList,map<string,bool>& visited, int *topoNum,string startStr, vector<node> &retVec){
        if(!visited[startStr]){
            visited[startStr]=true;
            for(int i=0;i<graphAdjList[startStr].size();i++){
                if(!visited[graphAdjList[startStr][i]])
                    topologicalSort(graphAdjList,visited,topoNum,graphAdjList[startStr][i],retVec);
            }
            node temp;
            temp.setNode(startStr,*topoNum);
            (*topoNum)=(*topoNum)-1;
            retVec.push_back(temp);

        }


}



int main(){
    int t,v;
    string strTemp1,strTemp2,startStr;
    map<string,vector<string> > graphAdjList;
    cin>>t;
    vector<string> lstString;
    map<string,bool> visited;
    vector<node> retVec;
    for(int i=0;i<t;i++){
        graphAdjList.clear();
        visited.clear();
        retVec.clear();
        cin>>v;
        for(int j=0;j<v-1;j++){
            cin>>strTemp1>>strTemp2;
            if(j==0)
                startStr=strTemp1;
            graphAdjList[strTemp1].push_back(strTemp2);
            visited[strTemp1]=false;
            visited[strTemp2]=false;
        }
        topologicalSort(graphAdjList,visited,&v,startStr,retVec);
        for(map<string,bool>::iterator it = visited.begin(); it != visited.end(); ++it) {
                if(!it->second)
                    topologicalSort(graphAdjList,visited,&v,it->first,retVec);
        }
        sort(retVec.begin(),retVec.end());
        cout<<"Scenario #"<<i+1<<":"<<endl;
        for(int i=0;i<retVec.size();i++){
            cout<<retVec[i].name<<endl;
        }
        cout<<endl;
    }

    return 0;
}
