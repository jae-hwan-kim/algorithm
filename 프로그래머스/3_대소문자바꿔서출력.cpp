#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) {
            char c = tolower(str[i]);
            putchar(c);
        } else if (islower(str[i])) {
            char c = toupper(str[i]);
            putchar(c);
        }
    }
    return 0;
}