#include <iostream>

using namespace std;

char endDirection(int rows, int columns) {
    if (columns < rows) {
        if (columns % 2 == 1)
            return 'D';
        return 'U';
    }
    else {
        if (rows % 2 == 0) {
            return 'L';
        }
        return 'R';
    }


}

int main() {
    int t;
    int rows,columns;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>rows>>columns;
        cout<<endDirection(rows, columns)<<endl;
    }
    return 0;
}
