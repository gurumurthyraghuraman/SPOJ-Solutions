#include <iostream>

using namespace std;

int main() {
    int t,n,p;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &p);
        if (p == 0) {
            printf("Airborne wins.\n");
        } else {
            printf("Pagfloyd wins.\n");
        }
    }
    return 0;
}
