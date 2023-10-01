#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    std::unordered_map<std::string, int> um;

    for (int i = 0; i < players.size(); i++) {
        um.insert(std::pair<std::string, int>(players[i], i));
        // std::cout << players[i] << " => " << i << '\n';
    }
    for (std::string &s : callings) {
        int index = um[s];
        um[players[index - 1]]++;
        um[s]--;
        swap(players[index - 1], players[index]);
    }
    return players;
}

int main(void) {
    std::vector<std::string> players = {"mumu", "soe", "poe", "kai", "mine"};
    std::vector<std::string> callings = {"kai", "kai", "mine", "mine"};
    std::vector<std::string> answer = solution(players, callings);

    std::vector<std::string>::iterator it = answer.begin();
    for (; it != answer.end(); it++) {
        std::cout << *it << '\n';
    }
}

// std::unordered_map<std::string, int>::iterator it;
//     for (it=um.begin(); it!=um.end(); ++it) {
//         std::cout << it->first << " => " << it->second << '\n';
//     }