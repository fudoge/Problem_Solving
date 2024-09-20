#include <iostream>
#include <string>
#include <vector>

using namespace std;

int roman_to_integer(string &roman) {
    int i = 0;
    int len = roman.size();
    int res = 0;
    while (i < len)
    {
        switch(roman[i]) {
            case 'M': {
                res += 1000;
                break;
            }
            case 'D': {
                res += 500;
                break;
            }
            case 'C': {
                if(i < len-1 && (roman[i+1] == 'M' || roman[i+1] == 'D')) {
                    res -= 100;
                } else {
                    res += 100;
                }
                break;
            }
            case 'L': {
                res += 50;
                break;
            }
            case 'X': {
                if (i < len - 1 && (roman[i+1] == 'C' || roman[i+1] == 'L')) {
                    res -= 10;
                }
                else {
                    res += 10;
                }
                break;
            }
            case 'V': {
                res += 5;
                break;
            }
            case 'I': {
                if (i < len - 1 && (roman[i+1] == 'X' || roman[i+1] == 'V')) {
                    res -= 1;
                }
                else {
                    res += 1;
                }
                break;
            }
        }
        ++i;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<string> romans;
    string s;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        romans.push_back(s);
    }

    for(auto &roman : romans) {
        cout << roman_to_integer(roman) << "\n";
    }

    return 0;
}