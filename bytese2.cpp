#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class TimeData {
    private:
        int time;
        bool isEntryTime;


    public:
        TimeData(int time, bool isEntryTime);
        int getTime();
        bool getIsEntryTime();
};

TimeData::TimeData(int time, bool isEntryTime) {
    (*this).time = time;
    (*this).isEntryTime = isEntryTime;
}

int TimeData::getTime(){
    return time;
}

bool TimeData:: getIsEntryTime() {
    return isEntryTime;
}

class CustomCompare {
    public:
        bool operator() (TimeData& time1, TimeData& time2) {
                return time1.getTime() > time2.getTime();
        }
};


int maxNumberOfPeople(priority_queue<TimeData, vector<TimeData>,CustomCompare> entryExitPriorityQueue, int noOfEntries) {
    int tempMaxPeople = 0;
    int maxPeople = 0;

    for (int i = 0; i < 2*noOfEntries; i++) {
        TimeData topTimeData = entryExitPriorityQueue.top();
        if (topTimeData.getIsEntryTime()) {
            tempMaxPeople++;
        } else {
            tempMaxPeople--;
        }
        entryExitPriorityQueue.pop();
        if (tempMaxPeople > maxPeople) {
            maxPeople = tempMaxPeople;
        }
    }
    return maxPeople;
}


int main() {
    int t, n, entryTime, exitTime;
    priority_queue<TimeData, vector<TimeData>, CustomCompare> entryExitPriorityQueue;
    scanf("%d",&t);
    for (int i = 0; i < t; i++) {
        entryExitPriorityQueue = priority_queue<TimeData, vector<TimeData>, CustomCompare>();
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d %d", &entryTime, &exitTime);
            TimeData entryData(entryTime, true);
            TimeData exitData(exitTime, false);
            entryExitPriorityQueue.push(entryData);
            entryExitPriorityQueue.push(exitData);
        }
        printf("%d\n",maxNumberOfPeople(entryExitPriorityQueue, n));
    }
    return 0;
}
