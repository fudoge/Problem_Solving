#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int getPrecedence(char op) {
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return 0;
}

string toPostfix(const string &exp) {
  stack<char> stk;
  string newExp = "";

  for (char ch : exp) {
    if (isalpha(ch)) {
      newExp += ch;
    } else if (ch == '(') {
      stk.push(ch);
    } else if (ch == ')') {
      while (stk.top() != '(') {
        newExp += stk.top();
        stk.pop();
      }
      stk.pop();
    } else {
      while (!stk.empty() && getPrecedence(stk.top()) >= getPrecedence(ch)) {
        newExp += stk.top();
        stk.pop();
      }
      stk.push(ch);
    }
  }

  while (!stk.empty()) {
    newExp += stk.top();
    stk.pop();
  }

  return newExp;
}

int main(int argc, char *argv[]) {
  string exp;
  cin >> exp;

  string newExp = toPostfix(exp);
  cout << newExp << "\n";
  return 0;
}