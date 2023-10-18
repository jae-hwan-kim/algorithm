#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> divided_today;
    vector<int> divided_privacies;
    vector<char> divided_privacies_type;
    map<int, char> divided;
    string tmp;

    // today 쪼개기
    today.push_back('.');
    for (auto c : today) {
        if (c == '.') {
            divided_today.push_back(stoi(tmp));
            tmp.clear();
            continue;
        }
        tmp.push_back(c);
    }

    // privacies 쪼개기
    for (auto str : privacies) {
        divided_privacies_type.push_back(str.back());
        // 10, end 지우고, back 을 .으로 바꿔
        str.erase(str.begin() + 10, str.end());
        str.push_back('.');
        for (auto c : str) {
            if (c == '.') {
                divided_privacies.push_back(stoi(tmp));
                tmp.clear();
                continue;
            }
            tmp.push_back(c);
        }
        divided.insert({divided_privacies.back(), divided_privacies_type.back()});
    }
    
    return answer;
}

int main(void) {
    string today = "2022.05.19";
    vector<string> terms = {"A 6", "B 12", "C 3"};
    vector<string> privacies = {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"};

    solution(today, terms, privacies);
    return (0);
}