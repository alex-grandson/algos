#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Animal {
    char letter;
    int index;
};

int abs (int a) {
    if (a < 0) return -a;
    return a;
}

int isPair (int a, int b) {
    if ('a' <= a && a <= 'z' && 'A' <= b && b <= 'Z' ||
        'a' <= b && b <= 'z' && 'A' <= a && a <= 'Z')
        if (abs(a - b) == 'a' - 'A')
            return 1;
    return 0;
}

int isSmallLetter (int a) {
    if ('a' <= a && a <= 'z') return 1;
    return 0;
}

int main(){
    string s;
    cin >> s;


    Animal animal;
    int n = s.size() / 2;
    vector<Animal> zoo;
    vector<int> ans(n);
    int i = 0;
    int j = 0;
    int big = 0;
    int small = 1;
    while (j < 2 * n) {
        animal.letter = s[j];
        if (isSmallLetter(animal.letter)){
            animal.index = small;
            small++;
        }
        else {
            animal.index = big;
            big++;
        }
        zoo.push_back(animal);
//        cout << "i: " << i << ", j: " << j << ", s[j]: " << s[j] << " " << animal.index << endl;
        if (i > 0 && isPair(zoo[i - 1].letter, zoo[i].letter)) {
            if (isSmallLetter(zoo[i - 1].letter)) {
                ans[zoo[i].index] = zoo[i - 1].index;
            } else {
                ans[zoo[i - 1].index] = zoo[i].index;
            }
            zoo.pop_back();
            zoo.pop_back();
            i -= 2;
        }
        i += 1;
        j += 1;
    }

    if (zoo.empty()) {
//        sort(cages.begin(), cages.end(), [](const Animal &a, const Animal &b) -> bool {
//            return a.index < b.index;
//        });
        cout << "Possible" << endl;
        for (auto it: ans) cout << it << " ";
    } else {
        cout << "Impossible";
    }


    return 0;
}
