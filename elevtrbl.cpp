#include <iostream>
#include <queue>

using namespace std;

bool visited[1000001]={false};


int noOfPushes(int f, int s, int g, int u, int d) {
    if(g==s)
        return 0;

    int queueFront;
    int retValue=0;
    int queueSize;
    queue<int> bfsQueue;
    bfsQueue.push(s);
    while(!bfsQueue.empty()) {
        queueSize=bfsQueue.size();
        for(int i=0;i<queueSize;i++) {
            queueFront=bfsQueue.front();
            if(queueFront>f || queueFront<1){
                bfsQueue.pop();continue;
            }

            if(!visited[queueFront]) {
                visited[queueFront]=true;
                if(queueFront==g) {
                    return retValue;
                }

                bfsQueue.push(queueFront+u);


                bfsQueue.push(queueFront-d);



            }
            bfsQueue.pop();

        }
        retValue++;
    }
    return -1;
}


int main() {
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    int result=noOfPushes(f,s,g,u,d);
    if(result==-1){
        cout<<"use the stairs"<<endl;
    }
    else cout<<result<<endl;

    return 0;
}
