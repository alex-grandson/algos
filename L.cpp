#include <cstdio>
#include <climits>
#include <algorithm>
#include <assert.h>

using namespace std;

int tree[450000];
int a[150000];

int solve(int l, int r, int v, int left, int right) {
//    assert(right < l || r < left); // INT_MAX;
    if (right < l || r < left)
        return INT_MAX;

    if (l <= left && right <= r)
        return tree[v];

    int middle = (left + right) / 2;
    return min(solve(l, r, v * 2, left, middle), // левая часть
               solve(l, r, v * 2 + 1, middle + 1, right)); // правая часть
}

void prepare(int a[], int v, int left, int right) {
    if (left == right)
        tree[v] = a[left];
    else {
        int middle = (left + right) / 2;
        prepare(a, v * 2, left, middle);
        prepare(a, v * 2 + 1, middle + 1, right);
        tree[v] = min(tree[v * 2],
                      tree[v * 2 + 1]);
//        printf("a[%d] = %d\n", v, a[v]);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    prepare(a, 1, 0, n - 1);

//    for (int i = 0; i < n; ++i) {
//        printf("%d ", tree[i]);
//    }
//    printf("\n");

    for (int i = 0, j = k - 1; j < n; i++, j++)
        printf("%d ", solve(i, j, 1, 0, n - 1));

    return 0;
}
