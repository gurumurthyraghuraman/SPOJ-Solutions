#include <iostream>
#include <utility>
#include <queue>

using namespace std;


bool isValid(pair<int,int> cSquare) {
    if(cSquare.first>=8 || cSquare.first<0 || cSquare.second>=8 || cSquare.second<0)
        return false;
    return true;

}

int noOfSteps(pair<int,int> startPoint, pair<int,int> endPoint) {
    bool visited[8][8]={false};
    queue<pair<int,int> > bfsQueue;
    pair<int,int> queueFront;
    int steps=0;
    int queueSize;
    bfsQueue.push(startPoint);

    while(!bfsQueue.empty()) {
        queueSize=bfsQueue.size();
        for(int i=0;i<queueSize;i++) {
            queueFront=bfsQueue.front();
            if(queueFront.first==endPoint.first && queueFront.second==endPoint.second){
                return steps;
            }
            if(isValid(queueFront) && !visited[queueFront.first][queueFront.second]) {
                bfsQueue.push(make_pair(queueFront.first+1, queueFront.second+2));
                bfsQueue.push(make_pair(queueFront.first-1, queueFront.second+2));
                bfsQueue.push(make_pair(queueFront.first+1, queueFront.second-2));
                bfsQueue.push(make_pair(queueFront.first-1, queueFront.second-2));
                bfsQueue.push(make_pair(queueFront.first+2, queueFront.second+1));
                bfsQueue.push(make_pair(queueFront.first+2, queueFront.second-1));
                bfsQueue.push(make_pair(queueFront.first-2, queueFront.second+1));
                bfsQueue.push(make_pair(queueFront.first-2, queueFront.second-1));
            }
            if(isValid(queueFront))
                visited[queueFront.first][queueFront.second]=true;
            bfsQueue.pop();

        }
        steps++;

    }
    return -1;




}



int main(){
    int t;
    char in1,in2,in3,in4;
    pair<int,int> startPoint, endPoint;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>in1>>in2;
        cin>>in3>>in4;
        startPoint=make_pair(in1-'a',in2-'1');
        endPoint=make_pair(in3-'a',in4-'1');
        cout<<noOfSteps(startPoint, endPoint)<<endl;
    }
    return 0;

}
