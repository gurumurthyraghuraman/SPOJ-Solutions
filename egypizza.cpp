#include <iostream>

using namespace std;

int numberOfPizzas(int mapCount[3]) {
    int totalCount = 1;
    if (mapCount[0] >= mapCount[2]) {
        totalCount += mapCount[2];
        mapCount[0] -= mapCount[2];
        mapCount[2] = 0;

    }
    else {
        totalCount += mapCount[0];
        mapCount[2] -= mapCount[0];
        mapCount[0] = 0;
    }

    while(mapCount[1] > 0 && mapCount[0] > 1) {
        mapCount[1]--;
        mapCount[0] -= 2;
        totalCount++;
    }
    if (mapCount[1] && mapCount[0]) {
        totalCount++;
        mapCount[0]--;
        mapCount[1]--;
    }

    totalCount += mapCount[0] - mapCount[0]/4;

    totalCount += mapCount[1] - mapCount[1]/2;

    totalCount += mapCount[2];

    return totalCount;

}


int main() {
    int n;
    int totalCount = 0;
    int mapCount[3] = {0};
    string value;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>value;
        if (value == "1/4")
            mapCount[0]++;
        if (value == "1/2")
            mapCount[1]++;
        if (value == "3/4")
            mapCount[2]++;
    }
    cout<<numberOfPizzas(mapCount)<<endl;
    return 0;
}
