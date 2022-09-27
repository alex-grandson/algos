#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

struct Node {
    int i;
    int j;
    int weight;
    char from;
};

bool operator== (const Node &left, const Node &right) {
    return (right.i == left.i && right.j == left.j);
}

bool operator!= (const Node &left, const Node &right) {
    return (right.i != left.i || right.j != left.j);
}

bool operator>(const Node &left, const Node &right) {
    return true;
}

const int INF = 32000;
int n;
int m;
Node start;
Node finish;

int main() {
    scanf("%d %d %d %d %d %d",
          &n, &m, &start.i, &start.j, &finish.i, &finish.j);
    start.i--;
    start.j--;
    finish.i--;
    finish.j--;

    vector< vector<Node> > a(n, vector<Node>(m));
    vector<vector<int>> dists (n, vector<int>(m, INT32_MAX));
    dists[start.i][start.j] = 0;

    char type;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &type);
            if (type == '.') a[i][j].weight = 1;
            else if (type == 'W') a[i][j].weight = 2;
            else if (type == '#') a[i][j].weight = INF;
            a[i][j].i = i;
            a[i][j].j = j;
            a[i][j].from = '#';
        }
    }

    priority_queue<pair<int, Node*>> queue;
    queue.push({0, &start});

    Node * to;
    while (!queue.empty()) {

        int len = -queue.top().first;
        Node * current = queue.top().second;
        queue.pop();

        int dist = dists[current->i][current->j];

        if(len > dist) continue;

        if (current->i > 0) {
            to = &a[current->i - 1][current->j];
            if (to->weight != INF && dist + to->weight < dists[to->i][to->j]) {
                dists[to->i][to->j] = dist + to->weight;
                to->from = 'N';
                queue.push({-dists[to->i][to->j] , to});
            }
        }
        // берем нижнюю
        if (current->i < n - 1) {
            to = &a[current->i + 1][current->j];
            if (to->weight != INF && dist + to->weight < dists[to->i][to->j]) {
                dists[to->i][to->j] = dist + to->weight;
                to->from = 'S';
                queue.push({-dists[to->i][to->j] , to});
            }
        }
        // берем левую
        if (current->j > 0) {
            to = &a[current->i][current->j - 1];
            if (to->weight != INF && dist + to->weight < dists[to->i][to->j]) {
                dists[to->i][to->j] = dist + to->weight;
                to->from = 'W';
                queue.push({-dists[to->i][to->j] , to});
            }
        }
        // берем правую
        if (current->j < m - 1) {
            to = &a[current->i][current->j + 1];
            if (to->weight != INF && dist + to->weight < dists[to->i][to->j]) {
                dists[to->i][to->j] = dist + to->weight;
                to->from = 'E';
                queue.push({-dists[to->i][to->j] , to});
            }
        }
    }

    if (dists[finish.i][finish.j] == INT32_MAX) {
        printf("-1");
        return 0;
    }

    string ans = "";
    char symbol;
    int i = finish.i;
    int j = finish.j;
    while (i != start.i || j != start.j) {
        symbol = a[i][j].from;
        if (symbol == 'S') i--;
        if (symbol == 'N') i++;
        if (symbol == 'E') j--;

        if (symbol == 'W') j++;
        ans = symbol + ans;
    }

    printf("%d\n", dists[finish.i][finish.j]);
    printf("%s", ans.c_str());
    return 0;
}
