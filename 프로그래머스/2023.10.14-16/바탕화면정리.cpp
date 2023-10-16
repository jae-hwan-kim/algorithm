#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = {100, 100, -100, -100};
    bool init = false;
    int w = wallpaper.size();
    int h = wallpaper[0].size();

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (wallpaper[i][j] == '#') {
                // if ((answer[0] == 0 && answer[1] == 0) && !init) {
                //     answer[0] = i;
                //     answer[1] = j;
                //     answer[2] = i;
                //     answer[3] = j;
                //     init = true;
                // } else {
                    if (i <= answer[0]) {
                        answer[0] = i;
                    }
                    if (j <= answer[1]) {
                        answer[1] = j;
                    }
                    if (i >= answer[2]) {
                        answer[2] = i + 1;
                    }
                    if (j >= answer[3]) {
                        answer[3] = j + 1;
                    }
                // }
            }                
        }
    }
    // answer[2] += 1;
    // answer[3] += 1;
    cout << answer[0] << ' ' << answer[1] << ' ' << answer[2] << ' ' << answer[3] << '\n';
    return answer;
}

// .#...
// ..#..
// ...#.

// ..........
// .....#.... // 0, 1, 2, 3
// ......##.. // 2, 3 - 3
// ...##..... // 0
// ....#..... // 0

// .##...##. 
// #..#.#..# 
// #...#...# 
// .#.....#. 
// ..#...#.. 
// ...#.#... 
// ....#....

int main(void) {
    vector<string> wallpaper = {".#...", "..#..", "...#."}; // 0, 1, 3, 4
    // vector<string> wallpaper = {"..........", ".....#....", "......##..", "...##.....", "....#....."}; // 1, 3, 5, 8
    // vector<string> wallpaper = {".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...."}; // 0, 0, 7, 9
    
    solution(wallpaper);
    return (0);
}