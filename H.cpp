#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	int k = 0;
	int sum = 0;
	scanf("%d %d ", &n, &k);
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a.begin(), a.end(), [](const int &a, const int &b) -> bool {
			return a > b;
		});
	if (k > n) {
		printf("%d", sum);
		return 0;
	}
	if (k == n) {
		printf("%d", sum - a[n - 1]);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (i % k == 0) {
			sum -= a[i - 1];
		}
	}
	printf("%d", sum);
	return 0;
}
