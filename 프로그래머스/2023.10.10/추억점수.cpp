#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> table;
    
    for (int i = 0; i < name.size(); i++) {
        table[name[i]] = yearning[i];
    }
    for (int i = 0; i < photo.size(); i++) {
        int sum = 0;
        for (int j = 0; j < photo[i].size(); j++) {
            sum += table[photo[i][j]];
        }
        answer.push_back(sum);
    }
    return answer;
}

// #include <string>
// #include <vector>
// #include <map>
// using namespace std;

// vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
// {
//     vector<int> answer;
//     map<string, int> m;
//     for(int i=0;i<name.size();i++) m[name[i]] = yearning[i];// key 이름, value 추억 점수
//     for(int i=0;i<photo.size();i++)
//     {
//         int sum = 0;
//         for(int j=0;j<photo[i].size();j++) sum += m[photo[i][j]];// 점수가 있으면 총점에 추가
//         answer.push_back(sum);
//     }
//     return answer;
// }

int main() {
    vector<string> name = {"may", "kein", "kain", "radi"};
    vector<int> yearning = {5, 10, 1, 3};
    vector<vector<string>> photo = {{"may", "kein", "kain", "radi"},{"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"}};

    solution(name, yearning, photo);
    return (0);
}