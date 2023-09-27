#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
        if (flag[i] == true) {
            int size = arr[i];
            // cout << "size : " << size << '\n';
            for (int j = 0; j < size * 2; j++) {
                // cout << "push_back " << size << " ";
                answer.push_back(size);
            }
            // cout << '\n';
        } else {
            int size = arr[i];
            // cout << "size : " << size << '\n';
            for (int j = 0; j < size; j++) {
                // cout << "pop_back " << size << " ";
                answer.pop_back();
            }
            // cout << '\n';
        }
    }
    return answer;
}

int main(int ac, char **av) {
    vector<int> answer;
    vector<int> arr;
    vector<bool> flag;

    for (int i = 0; i < ac; i++) {
        if (i != 0) {
            arr.push_back(atoi(av[i]));
        }
    }
    // for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
    //     std::cout << *it << " ";
    // }
    // flag = { true, false, true, false, false };
    flag = { true, false };
    answer = solution(arr, flag);
    for (int num : answer) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}