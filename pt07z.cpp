#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graphArr[10001];
bool visited[10001];

void initializeVisitedArray() {
    for (int i = 0; i < 10001; i++) {
        visited[i] = false;
    }
}

int bfsLastVisitedNode(int startNode) {
    queue<int> bfsQueue;
    int queueSize;
    int currentNode;
    int lastVisitedNode;
    int maxHeight = 0;
    bfsQueue.push(startNode);
    while (!bfsQueue.empty()) {
        queueSize = bfsQueue.size();
        for (int i = 0; i < queueSize; i++) {
            currentNode = bfsQueue.front();
            visited[currentNode] = true;
            for (int i = 0; i < graphArr[currentNode].size(); i++) {
                if (!visited[graphArr[currentNode][i]]) {
                        bfsQueue.push(graphArr[currentNode][i]);
                }
            }
            lastVisitedNode = currentNode;
            bfsQueue.pop();
        }
    }
    return lastVisitedNode;

}

int bfsLongestPath(int startNode) {
    queue<int> bfsQueue;
    int queueSize;
    int currentNode;
    int lastVisitedNode;
    int maxHeight = 0;
    bfsQueue.push(startNode);
    while (!bfsQueue.empty()) {
        queueSize = bfsQueue.size();
        for (int i = 0; i < queueSize; i++) {
            currentNode = bfsQueue.front();
            visited[currentNode] = true;
            for (int i = 0; i < graphArr[currentNode].size(); i++) {
                if (!visited[graphArr[currentNode][i]]) {
                        bfsQueue.push(graphArr[currentNode][i]);
                }
            }
            bfsQueue.pop();
        }
        maxHeight++;
    }
    return maxHeight - 1;

}



int main() {
    int noOfNodes, edgeStartNode, edgeEndNode, bfsStartNode, lastDepthNode;
    cin>>noOfNodes;
    initializeVisitedArray();
    for (int i = 0; i < noOfNodes - 1; i++) {
        cin>>edgeStartNode>>edgeEndNode;
        graphArr[edgeStartNode].push_back(edgeEndNode);
        graphArr[edgeEndNode].push_back(edgeStartNode);
        if (i == 0)
            bfsStartNode = edgeStartNode;
    }
    lastDepthNode = bfsLastVisitedNode(bfsStartNode);
    initializeVisitedArray();
    cout<<bfsLongestPath(lastDepthNode)<<endl;
    return 0;
}
