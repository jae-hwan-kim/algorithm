#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 이게 왜 안되는지 모르겠엄...
// int solution(int n, int m, vector<int> section) {
//     int answer = 0;
//     vector<bool> done(section.size(), false);

//     for (int i = 0; i < section.size(); i++) {
//         if (done[i]) continue;

//         answer += 1;
//         done[i] = true;
//         if (section[i + 1] && (section[i + 1] - section[i] < m)) {
//             done[i + 1] = true;
//             i += 1;
//             continue;
//         }
//     }
//     return answer;
// }

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int current = 0;

    for (int i = 0; i < section.size(); i++) {
        if (current > section[i]) continue;
        answer += 1;
        current = section[i] + m;
    }
    return answer;
}

// 1 2 3 4 5 6 7 8
// 8	4	[2, 3, 6] // 2
// 5	4	[1, 3]	// 1
// 4	1	[1, 2, 3, 4] // 4

int main(void) {
    // int n = 8;
    // int m = 4;
    // vector<int> section = {2, 3, 6};

    // int n = 5;
    // int m = 4;
    // vector<int> section = {1, 3};

    // int n = 4;
    // int m = 1;
    // vector<int> section = {1, 2, 3, 4};

    // int n = 4;
    // int m = 2;
    // vector<int> section = {3, 4};
    // int answer = solution(n, m, section);

    // int n = 5;
    // int m = 2;
    // vector<int> section = {1, 4, 5};

    int n = 5;
    int m = 5;
    vector<int> section = {1, 4};
    int answer = solution(n, m, section);
    cout << answer << '\n';
    return (0);
}