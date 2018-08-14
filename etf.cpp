#include <iostream>
#include <math.h>

using namespace std;

int calEulerTotientFunction(int n) {
    if (n == 1) {
        return 1;
    }
    int result = n;
    for (int i = 2; i*i <= n; i++) {
       if (n % i == 0) result -= result / i;
       while ( n % i == 0) n /= i;
    }
    if (n > 1)
        result -= result/ n;
    return result;
}


int main () {
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n",calEulerTotientFunction(n));
    }
    return 0;
}
