#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    long long a = 0, b = 0, c = 0, d = 0, k = 0;
    scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &k);

    if (k == 1) {
        a = a * b - c;
        if (a <= 0) {
            printf("0");
        } else if (a >= d) {
            printf("%lld", d);
        } else {
            printf("%lld", a);
        }
        return 0;
//        printf("%lld", max(min(ans, d), 0LL));
    } else {
        for (long long i = 0; i < k; i++) {
            a = a * b - c;
            if (a <= 0) {
                printf("0");
                return 0;
            } else if (a >= d) {
                printf("%lld", d);
                return 0;
            }
            if (a == a * b - c) {
                printf("%lld", a);
                return 0;
            }
        }
    }
    printf("%lld", a);
    return 0;

}
