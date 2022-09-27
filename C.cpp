#include <iostream>
#include <string.h>
#include <map>
#include <stack>
using namespace std;

int isNumber (int a) {
    if ('0' <= a && a <= '9' || a == '-') return 1;
    return 0;
}

const string ZERO = "0";

int main(){

    map<string, string> current;
    stack< map<string, string> > state;
    state.emplace();

    char delimeter = '=';
    string line;
    while (getline(cin, line))
    {
        if (line[0] == '{') {
            state.emplace();
        } else if (line[0] == '}') {
//            current = state.top();
            for (auto it: state.top()) {
                current[it.first] = it.second;
            }
            state.pop();
        } else {
            int point = line.find(delimeter);
            string key = line.substr(0, point);
            string val = line.substr(point + 1, line.size() - 1);
            if (isNumber(val[0])) {
                if(state.top()[key].empty()) {
                    state.top()[key] = current[key].empty() ? ZERO : current[key];
                }
                current[key] = val;

            } else {
                if(state.top()[key].empty()) {
                    state.top()[key] = current[key].empty() ? ZERO : current[key];
                }
                if (current[val].empty()) {
//                    current[val] = ZERO;
                    current[key] = ZERO;
                } else {
                    current[key] = current[val];
                }
                printf("%s\n", current[key].c_str());
            }
//            printf("%s: %s, val=%s\n", key.c_str(), current[key].c_str(), val.c_str());
//            printf("%s\n", current[key].c_str());
        }
    }
    return 0;
}
