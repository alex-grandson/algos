#include <cstring>
#include <cstdio>
#include <climits>

using namespace std;

const int MAX = 1001;
int n;
int graph[MAX][MAX];
bool link_table[MAX][MAX];
bool used[MAX];

// binary search bounds
int left = 0;
int right = INT_MAX;

void DFS (int v, int type) {
    used[v] = 1;
    for (int i = 0; i < n; i++)
        if (!used[i] && (type ? link_table[i][v] : link_table[v][i]))
            DFS(i, type);
}

int visited_all () {
    for (int i = 0; i < n; ++i)
        if (!used[i]) return 0;
    return 1;
}

void clear_used() {
    for (bool & i : used) i = false;
}

bool linked_graph(int *middle) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            link_table[i][j] = graph[i][j] <= *middle;
        // link_table - флаги. связаны ли i и j аэропорты.
        // связаны при текущем значении middle.
        // middle - размер бака. тот вес ребер, который еще удовлетворяет

    clear_used(); // подготовка перед DFS.
    DFS(0, 0);
    if (visited_all()) {
        clear_used();
        DFS(0, 1);
        if (visited_all())
            return true;
        else
            return false;
    } else
        return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf(" %d", &graph[i][j]);

    while (left < right) {
        int middle = (left + right) / 2;
        if (linked_graph(&middle))
            right = middle;
        else
            left = middle + 1;
    }
    printf("%d", left);
    return 0;
}
