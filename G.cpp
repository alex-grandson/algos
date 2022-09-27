#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

map<char, int> weight;

int main() {

    string s;
    cin >> s;
    map<char, int> count;
    for (char c : s) count[c] += 1;
    for (int i = 0; i < 26; i++)
        cin >> weight[i + 'a'];
    string ans = "";
    string mid = "";
    for (auto c: s) {
        if (count[c] > 1 && ans.find(c) == -1)
            ans.push_back(c);
        else
            mid.push_back(c);
    }

    for (char i : ans)
        mid.erase(mid.find(i), 1);

    sort(ans.begin(), ans.end(), [](const char a, const char b) -> bool {
        return weight[a] > weight[b];
    });

    cout << ans << mid;
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}
