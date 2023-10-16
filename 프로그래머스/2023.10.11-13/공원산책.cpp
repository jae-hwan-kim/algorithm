#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int w = park[0].size();
    int h = park.size();
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (park[i][j] == 'S') {
                answer.push_back(i);
                answer.push_back(j);
            }
        }
    }
    for (int i = 0; i < routes.size(); i++) {
        int move = 0;
        int dest = atoi(&routes[i][2]);
        char dir = routes[i][0];
        if (dir == 'E') {
            if (answer[1] + dest >= w) {
                ;
            } else {
                for (int j = 1; j <= dest; j++) {
                    if (park[answer[0]][answer[1] + j] == 'X') {
                        move = 0;
                        break;
                    }
                    move += 1;
                }
                answer[1] += move;
            }
        } else if (dir == 'W') {
            if (answer[1] - dest < 0) {
                ;
            } else {
                for (int j = 1; j <= dest; j++) {
                    if (park[answer[0]][answer[1] - j] == 'X') {
                        move = 0;
                        break;
                    }
                    move += 1;
                }
                answer[1] -= move;
            }
        } else if (dir == 'S') {
            if (answer[0] + dest >= w) {
                ;
            } else {
                for (int j = 1; j <= dest; j++) {
                    if (park[answer[0] + j][answer[1]] == 'X') {
                        move = 0;
                        break;
                    }
                    move += 1;
                }
                answer[0] += move;
            }
        } else if (dir == 'N') {
            if (answer[0] - dest < 0) {
                ;
            } else {
                for (int j = 1; j <= dest; j++) {
                    if (park[answer[0] - j][answer[1]] == 'X') {
                        move = 0;
                        break;
                    }
                    move += 1;
                }
                answer[0] -= move;
            }
        } 
    }
    return answer;
}
    // cout << answer[0] << ", " << answer[1] << '\n';

int main(void) {
    // vector<string> park = {"SOO", "OOO", "OOO"};
    // vector<string> routes = {"E 2", "S 2","N 1"};
    vector<string> park = {"SOO", "OXX", "OOO"};
    vector<string> routes = {"E 2","S 2","W 1"};
    // vector<string> park = {"OSO","OOO","OXO","OOO"};
    // vector<string> routes = {"E 2","S 3","W 1"}; // 1, 1
    // vector<string> park = {"OXXO", "XSXO", "XXXX"};
    // vector<string> routes = {"E 1", "S 1"};
    solution(park, routes);
    return (0);
    // [2, 1]
    // ["SOO","OXX","OOO"]	["E 2","S 2","W 1"]	[0,1]
    // ["OSO","OOO","OXO","OOO"]	["E 2","S 3","W 1"]	[0,0]
}