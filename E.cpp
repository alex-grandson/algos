#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count (vector<int> a, int x, int k) {
    int count = 1;
    int last = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i] - last >= x) {
            last = a[i];
            count++;
        }
    }
    return count >= k;
}

int bin_search(vector<int> a, int k) {
    int x_min = 0;
    int x_max = a[a.size() - 1] - a[0] + 1;
    while (x_max > x_min + 1) {
        int x = (x_min + x_max) / 2;
        if (count(a, x, k))
            x_min = x;
        else
            x_max = x;
    }
    return x_min;
}

int main() {
	int n = 0;
	int k = 0;
	cin >> n >> k;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
    cout << bin_search(a, k);
	return 0;
}
