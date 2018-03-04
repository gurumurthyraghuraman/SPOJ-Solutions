#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <queue>

using namespace std;

char blackWhiteArr[200][200];
int distArr[200][200];
bool visited[200][200];

void initialize() {
    for (int i = 0; i < 200; i++)
        for (int j = 0; j < 200; j++) {
            visited[i][j] = false;
            distArr[i][j] = 1000;
        }
}


void printNearestDistances(int n, int m) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", distArr[i][j]);
        }
        printf("\n");
    }
}

void bfs(pair<int,int> point, int n, int m) {
    queue<pair<int,int>> bfsQueue;
    bfsQueue.push(point);
    int dist,queueSize;
    int i,j;
    while(!bfsQueue.empty()) {
        queueSize = bfsQueue.size();
        for (int k = 0; k < queueSize; k++) {
            pair<int,int> currPoint = bfsQueue.front();
            i = currPoint.first;
            j = currPoint.second;
            dist = distArr[i][j];
            if (i+1 < n && distArr[i+1][j] > 1 + distArr[i][j]) {
                distArr[i+1][j] = 1 + distArr[i][j];
                bfsQueue.push(make_pair(i+1,j));
            }
            if (i-1 >= 0 && distArr[i-1][j] > 1 + distArr[i][j]) {
                distArr[i-1][j] = 1 + distArr[i][j];
                bfsQueue.push(make_pair(i-1,j));
            }
            if (j+1 < m && distArr[i][j+1] > 1 + distArr[i][j]) {
                distArr[i][j+1] = 1 + distArr[i][j];
                bfsQueue.push(make_pair(i,j+1));
            }
            if (j-1 >= 0 && distArr[i][j-1] > 1 + distArr[i][j]) {
                distArr[i][j-1] = 1 + distArr[i][j];
                bfsQueue.push(make_pair(i,j-1));
            }
            bfsQueue.pop();

        }

    }
}

/*vector<pair<int,int> > bfs(vector<pair<int, int> > points, int n, int m) {
    int p,q;
    vector<pair <int, int> > resultVect;
    for (int i = 0; i < points.size() ; i++) {
        p = points[i].first;
        q = points[i].second;

        if (blackWhiteArr[p][q] == '1') {
            distArr[p][q] = 0;
            visited[p][q] = true;
        }
        if (p + 1 < n && !visited[p + 1][q] && blackWhiteArr[p + 1][q] != '1') {
            distArr[p + 1][q] = distArr[p][q] + 1;
            visited[p + 1][q] = true;
            resultVect.push_back(make_pair(p + 1,q));
        }
        if (p - 1 >= 0 && !visited[p - 1][q] && blackWhiteArr[p - 1][q] != '1') {
            distArr[p - 1][q] = distArr[p][q] + 1;
            visited[p - 1][q] = true;
            resultVect.push_back(make_pair(p - 1,q));
        }
        if (q + 1 < m && !visited[p][q + 1] && blackWhiteArr[p][q + 1] != '1') {
            distArr[p][q + 1] = distArr[p][q] + 1;
            visited[p][q + 1] = true;
            resultVect.push_back(make_pair(p,q + 1));
        }
        if (q - 1 >= 0 && !visited[p][q - 1] && blackWhiteArr[p][q - 1] != '1') {
            distArr[p][q - 1] = distArr[p][q] + 1;
            visited[p][q - 1] = true;
            resultVect.push_back(make_pair(p,q - 1));
        }
    }
    return resultVect;

}*/


void calcWhitePixelDistance(vector<pair<int,int> > startPoints, int n, int m) {
    for (int i = 0; i < startPoints.size(); i++) {
        bfs(startPoints[i],n,m);
    }
}



int main() {
    vector<pair<int,int> > startPoints;
    int t;
    scanf("%d",&t);
    int n,m;
    char bwChar;
    string eachLine;
    for (int i = 0; i < t; i++) {
        initialize();
        scanf("%d %d",&n,&m);

        for (int j = 0; j < n ; j++) {
            cin>>eachLine;
            for (int k = 0; k < m ; k++) {
                blackWhiteArr[j][k] = eachLine[k];
                if (eachLine[k] == '1') {
                    distArr[j][k] = 0;
                    startPoints.push_back(make_pair(j,k));
                }
            }
        }
        calcWhitePixelDistance(startPoints,n,m);
        printNearestDistances(n,m);
    }


}
