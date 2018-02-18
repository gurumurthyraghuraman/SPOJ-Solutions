#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10001];
bool visited[10001] = {false};


bool dfs(int startNode) {
    if (!visited[startNode]) {
        visited[startNode] = true;
        if (graph[startNode].empty())
            return true;
        for(int i = 0; i < graph[startNode].size(); i++) {
                if (!dfs(graph[startNode][i]))
                    return false;
        }
        return true;
    } else {
        return false;
    }

}

bool isTree(int n, int startNode) {
    if (dfs(startNode)) {
        for(int i = 1; i <= n; i++) {
            if(!visited[i])
                return false;
        }
    }
    else {
        return false;
    }
    return true;
}


int main() {
    int n, m, startNode;
    int edgeStart,edgeEnd;
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        cin>>edgeStart>>edgeEnd;
        if (i == 0) {
            startNode = edgeStart;
        }
        graph[edgeStart].push_back(edgeEnd);
    }
    if (isTree(n,startNode))
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
