#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n, m, x, y;
bool res = true;

vector<vector<int>> g(100, vector<int>());
vector<int> color(100, 0);
queue<int> k;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf(" %d %d", &x, &y);
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            k.push(i);
            while (!k.empty()) {
                int v = k.front();
                k.pop();
                for (int j = 0; j < g[v].size(); j++) {
                    res &= !(color[g[v][j]] == 1 && color[v] == 1 || color[g[v][j]] == 2 && color[v] == 2);
                    if (color[g[v][j]] == 0) {
                        if (color[v] == 2)
                            color[g[v][j]] = 1;
                        if (color[v] == 1)
                            color[g[v][j]] = 2;
                        k.push(g[v][j]);
                    }
                }
            }
        }
    }

    if (res) printf("YES");
    else printf("NO");
}
