// Program: Scrabble Game
// Author:  Name: Yousef Osama    Section: not determined   ID: 20230591
// Version: 1.0
// Date: 03-03-2023

#include <iostream>

using namespace std;

int main() {
    int nums = 9;
    bool valid[10];
    for (int i = 1; i <= 9; i++) {
        valid[i] = true;
    }
    int sum[2] = {0, 0};
    int turn = 1;
    bool winner = false;
    while (nums) {
        cout << "valid numbers are [";
        bool flag = false;
        for (int i = 1; i <= 9; i++) {
            if (valid[i]) {
                if (flag)
                    cout << ", ";
                flag = true;
                cout << i;
            }
        }
        cout << "]\n";
        cout << "player 1: " << sum[0] << "   player 2: " << sum[1] << "\n";
        try {
            int select;
            cout << "player " << turn << ", enter a valid number: ";
            while (!(cin >> select) || select < 1 || select > 9 || !valid[select]) {
                throw exception();
            }
            sum[turn - 1] += select;
            valid[select] = false;
            nums--;
            if (sum[turn - 1] == 15) {
                cout << "player " << turn << " wins!\n";
                winner = true;
                break;
            }
            turn = 3 - turn;
        } catch (int x) {
            cout << "invalid input\n";
            cin.clear();
            cin.ignore();
        }
    }
    if (!winner) {
        cout << "it's a draw!\n";
    }
}
