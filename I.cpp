#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
typedef int pos;

int n, k, p;
int result = 0;

pos posNextCar;
int current;

int main() {
    scanf("%d %d %d", &n, &k, &p);
    if (k >= n) {
        printf("%d", n);
        return 0;
    }
    if (k >= p) {
        printf("%d", p);
        return 0;
    }

    vector<int> cars(p);
    vector< vector<int> > order(n);
    vector<int> iterOfOrder(n, 0);

    for (int i = 0; i < p; ++i) {
        scanf(" %d", &current);
        order[current - 1].push_back(i);
        cars[i] = current;
    }

    // (position; car)
    map<pos, int, greater<pos> > cars_on_floor_ordered;
    unordered_map<int, pos> cars_on_floor;

    int diff = 0;

    for (int i = 0; i < p; ++i) {
        int current = cars[i];

        auto current_car = cars_on_floor.find(current);

        if (current_car == cars_on_floor.end()) {
            result += 1;
            if (cars_on_floor_ordered.size() == k) {

                auto pair = cars_on_floor_ordered.begin();

                cars_on_floor_ordered.erase(pair->first);
                cars_on_floor.erase(pair->second);
            }
        } else
            cars_on_floor_ordered.erase(current_car->second);

        iterOfOrder[current - 1] += 1;
        int index = iterOfOrder[current - 1];

        if (index >= order[current - 1].size()) {
            posNextCar = (p + (diff++));
        } else {
            posNextCar = order[current - 1][index];
        }

        cars_on_floor_ordered[posNextCar] = current;
        cars_on_floor[current] = posNextCar;
    }
    printf("%d", result);
    return 0;
}
