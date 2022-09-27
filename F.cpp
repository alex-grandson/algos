#include <iostream>
#include <vector>
#include <string>

struct {
    bool operator()(std::string  a, std::string  b) const { return a + b > b + a; }
} sorting;

int main()
{
    std::vector<std::string> vct;
    std::string input;
    while (std::cin >> input) {
        vct.push_back(input);
    }
    // clang 11 proved
    std::sort(vct.begin(), vct.end(), sorting);
    for (auto & i : vct){
        std::cout << i;
    }
    std::cout <<  std::endl;
    return 0;
}
