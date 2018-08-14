#include <iostream>

using namespace std;

int main() {
    int noOfInputs;
    int inputNumber;
    int ans = 0;
    scanf("%d", &noOfInputs);

    for (int i = 0; i < noOfInputs; i++) {
        scanf("%d", &inputNumber);
        ans = ans ^ inputNumber;
    }
    printf("%d\n", ans);
    return 0;
}
