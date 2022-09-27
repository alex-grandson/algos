#include <cstdio>
#include <deque>

using namespace std;

deque<int> left;
deque<int> right;

int n;
int middle;
int current;
char operation;

void log(int i) {
    printf("\n%d: %c %d\n", i, operation, current);
    for (int i = 0; i < left.size(); ++i)
        printf("%d ", left[left.size() - i - 1]);
    printf("| ");
    for (int i = 0; i < right.size(); ++i)
        printf("%d ", right[right.size() - i - 1]);
    printf("\n");

}

// goblin --> back left front --> (middle) back right front --> shaman
// справа >= слева

// left = front

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %c", &operation);
        switch (operation) {
            case '+':
                scanf(" %d", &current);
                left.push_back(current);
                break;
            case '*':
                scanf(" %d", &current);
                right.push_back(current);
                break;
            case '-':
                current = * right.begin();
                right.pop_front();

                printf("%d\n", current);
                // printf("\nminus: %d\n", current);

                break;
        }

        if (right.size() != 0 && right.size() - 1 > left.size()) {
            middle = right.back();
            left.push_front(middle);
            right.pop_back();
        }
        if (left.size() != 0 && left.size() > right.size()) {
            middle = * left.begin();
            right.push_back(middle);
            left.pop_front();
        }

//        log(i);
    }
    return 0;
}
