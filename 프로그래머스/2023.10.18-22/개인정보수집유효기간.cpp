#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> policy;
    vector<int> priv;
    // 다 합해서 년월일을 하나의 숫자로 표현한다.
    // 개인정보 보호 기간도 합쳐서 하나의 숫자로 표현한다.
    // 현재 날짜와 보호 기간을 비교해서 보호 기간이 지났으면 파기한다.
    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5, 2));
    int day = stoi(today.substr(8, 2));
    int total = 12 * year * 28 + (month - 1) * 28 + day;

    for (int i = 0; i < terms.size(); i++) {
        stringstream ss(terms[i]);
        char type; int period;
        ss >> type >> period;
        policy[type] = period;
    }

    for (int i = 0; i < privacies.size(); i++) {
        int y = stoi(privacies[i].substr(0, 4));
        int m = stoi(privacies[i].substr(5, 2));
        int d = stoi(privacies[i].substr(8, 2));
        char p = privacies[i].back();
        int t = 12 * y * 28 + (m - 1) * 28 + (policy[p] * 28 - 1) + d;
        priv.push_back(t);
    }

    for (int i = 0; i < priv.size(); i++) {
        if (total > priv[i]) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main(void) {
    string today = "2022.05.19";
    vector<string> terms = {"A 6", "B 12", "C 3"};
    vector<string> privacies = {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"};

    vector<int> answer = solution(today, terms, privacies);
    vector<int>::iterator it = answer.begin();
    for (; it != answer.end(); it++)
        cout << *it << ' ';
    return (0);
}