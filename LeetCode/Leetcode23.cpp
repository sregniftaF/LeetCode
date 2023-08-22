#include<iostream>
#include <string>
#include <vector>


// use a stack data structure, that inputs the opening brackets
using namespace std;

class Solution {
private:
    vector <char> Sstack; // opening brackets

public:
    bool comparewStack(char c) {
        //if (!Sstack.empty()) {
        //    return false;
        //}
        //else {
            char front = Sstack.back();
            if (c == ')' && front == '(')
                return true;
            else if (c == ']' && front == '[')
                return true;
            else if (c == '}' && front == '{')
                return true;
            else
                return false;
    //    }

   }
    void showStack() {
        for (int i = 0; i < Sstack.max_size(); i++) {
            cout << Sstack[i];
        }
    }
    bool isValid(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (Sstack.empty()) {
                if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                    return false;
                }
            }
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                AppendStack(s[i]);
            }
            else if (comparewStack(s[i])) {
                Sstack.pop_back();
            }
            else {
                return false;
            }

        }
        if (Sstack.empty()) {
            return true;
        }
        else return false;

        // check if the character is an opening bracket
        // if yes, throw into Sstack, else
        // if not return false
    }

    void AppendStack(char s) {
        Sstack.push_back(s);
    }
};
//
//int main() {
//
//    Solution sol;
//    string s;
//    cin >> s;
//    cout << (sol.isValid(s) ? "true":"false");
//}