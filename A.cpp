#include <iostream>

using namespace std;

class Segment {
public:
    int i;
    int j;
    Segment() {
        i = 0;
        j = 0;
    }
    void print() {
        cout << i + 1 << " " << j + 1<< "\n";
    }
};

int main() {
    int n = 0;
    int len = 0;
    int lenMax = 0;
    // текущий отрезок
    Segment current;
    // отрезок, содержащий ответ
    Segment answer;
    cin >> n;
    // "паровозик" трех подряд цветков
    int train[3] = {-1, -1, -1};
    for (int i = 0; i < n; i++) {
        cin >> train[i % 3];
        len++;
        if (train[0] == train[1] && train[1] == train[2]) {
            if (lenMax < len - 1) {
                lenMax = len - 1;
                answer.i = current.i;
                answer.j = i - 1;
            }
            current.i = i - 1;
            len = 2;
        }
        if (i == n - 1 && len > lenMax) {
            answer.i = current.i;
            answer.j = i;
        }
    }
    answer.print();
    return 0;
}
