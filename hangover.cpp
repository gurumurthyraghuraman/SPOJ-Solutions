#include <iostream>

using namespace std;

int noOfCards(float hang) {
    float i = 2;
    int c = 0;
    float hangLen = 0;
    while(hangLen < hang) {
        hangLen += 1/i;
        i++;
        c++;
    }
    return c;


}

int main() {
    float hang;
    cin>>hang;
    while(hang != 0.00) {
        cout<<noOfCards(hang)<<" card(s)"<<endl;
        cin>>hang;
    }
    return 0;
}
