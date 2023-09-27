#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int first = -1;
    int last = -1;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 2) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    if (first == -1)
        return vector<int>(1, -1);
    answer = vector<int>(arr.begin() + first, arr.begin() + last + 1);
    return answer;
}

int main(int ac, char **av) {
    vector<int> answer;
    vector<int> param;

    for (int i = 0; i < ac; i++) {
        param.push_back(atoi(av[i]));
    }
    answer = solution(param);
    for (int num : answer) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}