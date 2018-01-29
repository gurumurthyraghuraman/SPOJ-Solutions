#include <iostream>
#include <vector>
using namespace std;

bool visited[100001];
vector<int> adjListGraph[100001];
void initialize() {
    for(int i = 0; i < 100001; i++) {
        visited[i] = false;
        adjListGraph[i].clear();
    }
}

void dfs(int node, int *connectedComponentSize) {
    if (!visited[node]) {
        visited[node] = true;
        for(int i = 0; i < adjListGraph[node].size(); i++) {
            if (!visited[adjListGraph[node][i]]) {
                (*connectedComponentSize) += 1;
                dfs(adjListGraph[node][i], connectedComponentSize);
            }
        }
    }
}

vector<int> noOfConnectedComponents(int n) {
    vector<int> result;
    int connectedComponentSize;
    for(int i = 1; i <= n ; i++) {
        if (!visited[i]) {
            connectedComponentSize = 1;
            dfs(i, &connectedComponentSize);
            result.push_back(connectedComponentSize);
        }
    }
    return result;
}

long long waysToAddEdges(vector<int> componentSizeInfo, int n) {
    long long result = 1;
    int noOfComponents = componentSizeInfo.size();

    if(noOfComponents == 1) {
        return -1;
    }
    noOfComponents = noOfComponents - 2;
    if(noOfComponents == 0) {
        for(int i = 0; i < componentSizeInfo.size(); i++) {
            result *= (long long)componentSizeInfo[i];
            result = result % 1000000007;
        }
    }
    else {
        for(int i = 0; i < noOfComponents; i++) {
            result *= (long long)n;
            result =  result % 1000000007;

        }

        for(int j = 0; j < componentSizeInfo.size(); j++) {
            result *= (long long)componentSizeInfo[j];
            result = result % 1000000007;
        }
    }
    return result;

}

int main() {
    int t, n, m, v1, v2;
    vector<int> componentSizeInfo;
    cin>>t;
    for(int i = 0; i < t; i++) {
        initialize();
        componentSizeInfo.clear();
        cin>>n>>m;
        for(int j = 0; j < m; j++) {
            cin>>v1>>v2;
            adjListGraph[v1].push_back(v2);
            adjListGraph[v2].push_back(v1);
        }
        componentSizeInfo = noOfConnectedComponents(n);
        cout<<waysToAddEdges(componentSizeInfo,n)<<endl;

    }

    return 0;
}
