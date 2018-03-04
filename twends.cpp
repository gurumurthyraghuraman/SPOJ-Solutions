#include <iostream>

using namespace std;

int pointsArr[1000];

int dpArr[1000][1000];

void initializeDpArr() {
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++)
            dpArr[i][j] = -1;
    }

}


int twends(int first, int last, int index) {
    if (first > last)
        return 0;

    if (dpArr[first][last] == -1) {
        if (index % 2 == 0) {
            if (pointsArr[first] >= pointsArr[last]) {
                dpArr[first][last] = twends(first + 1, last, index + 1) - pointsArr[first];
            } else {
                dpArr[first][last] = twends(first, last - 1, index + 1) - pointsArr[last];
            }
        }
        else {
            dpArr[first][last] = max(pointsArr[first] + twends(first + 1, last, index + 1), pointsArr[last] + twends(first, last - 1, index + 1));
        }
    }
    return dpArr[first][last];
}

int main() {
    int n;
    int gameNumber = 1;
    cin>>n;
    while (n != 0) {
        initializeDpArr();
        for (int i = 0; i < n; i++) {
            cin>>pointsArr[i];
        }
        cout<<"In game "<<gameNumber<<", the greedy strategy might lose by as many as "<<twends(0, n-1, 1)<<" points."<<endl;
        gameNumber++;
        cin>>n;
    }
    return 0;
}
