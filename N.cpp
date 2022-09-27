// свинки копилки

/*
 * нужно последовательно вывести все циклы
 * циклы могут быть с ответвлениями (в одной свинке много ключей
 *
 * 1. составить граф из свинок
 * 2. берем точку и проходимся во все стороны (вниз и вверх_
 * сначала нужно закрыть все циклы с деревьями
 * это делается так
 * берем итую свинку копилку и начинаем как в листе проходимся по всем эелементам
 * пока не
 * движение наверх отдельный метод цикл вайл
 */

#include <cstdio>
#include <vector>

using namespace std;

vector<int> pigs;
vector<int> temp;
int num = 0, ans = 0, n = 0, pig;

void DFS(int v) {
    if (pigs[v] != -1) {
        if (pigs[v] == num)
            ans++;
        return;
    }
    pigs[v] = num;
    DFS(temp[v]);
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        pigs.push_back(-1);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &pig);
        temp.push_back(--pig);
    }
    for (int i = 0; i < n; i++) {
        num = i;
        DFS(i);
    }
    printf("%d", ans);
    return 0;
}
