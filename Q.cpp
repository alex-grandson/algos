#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int> > a;

/*

1 * * | * * 2
  * * | * *
  - - - - -
3 * * | * * 4
  * * | * *

    i, j | i, m - j
n - i, j | n - i, m - j

    Для того, чтобы понять, сколько нужно изменить
    Досточно пройтись по одной четверти и узнать насколько она симметрична относительно остальных
 */


vector<int> b(4, 0);

int ans = 0;

void crossCheck() {
    int vertical = 0, horizontal = 0;
    vector<int> v;
    vector<int> h;
    v.reserve(m);
    h.reserve(n);
    if (n % 2 == 1) {
        for (int i = 0; i < m; ++i)
            h.push_back(a[n / 2][i]);
        for (int i = 0; i < m / 2; ++i)
            if (h[i] != h[m - i - 1])
                horizontal++;
    }
    if (m % 2 == 1) {
        for (int i = 0; i < n; ++i)
            v.push_back(a[i][m / 2]);
        for (int i = 0; i < n / 2; ++i)
            if (v[i] != v[n - i - 1])
                vertical++;
    }
//    printf("ans:%d h=%d v=%d ans2: ", ans, vertical, horizontal);
    ans += vertical + horizontal;
}

int main() {
    scanf("%d %d", &n, &m);
    a.reserve(n);
    for (int i = 0; i < n; ++i) {
        a[i].reserve(m);
        for (int j = 0; j < m; ++j) {
            scanf(" %d", &a[i][j]);
        }
    }
    int temp;
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            temp = 0;
            b[0] = a[i][j];
            b[1] = a[n - i - 1][j];
            b[2] = a[i][m - j - 1];
            b[3] = a[n - i - 1][m - j - 1];
            sort(b.begin(), b.end());
            if (b[0] == b[1] && b[1] != b[2] && b[2] == b[3]) {
                ans += 2;
                continue;
            }
            for (int k = 1; k < 4; ++k) {
                if (b[k] != b[k - 1]) {
                    temp++;
//                    printf("%d %d\n", b[k], b[(k + 1) % 4]);
                }
            }
            ans += min(3, temp);
        }

    }
    crossCheck();
    printf("%d", ans);
    return 0;
}
