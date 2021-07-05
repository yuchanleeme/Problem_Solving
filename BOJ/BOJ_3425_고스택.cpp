#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/3425

/*
<고스택>
주요: 구현
1. Gostk이라는 클래스를 아예 새로 구현한다.
2. 각 명령어와 예외 조건에 맞게 구현한다.
3. 해당 입력에 맞게 결과값을 출력한다.
=========
* 예외가 너무도 많은 문제
// input  :  https://contest.felk.cvut.cz/11cerc/solved/execute.in.gz
// output :  https://contest.felk.cvut.cz/11cerc/solved/execute.out.gz

*/

class Gostk {
   public:
    vector<long long> arr;
    bool isError;

    Gostk() {
        isError = false;
    }

    long long top() {
        return arr.back();
    }

    void num(long long x) {
        arr.push_back(x);
    }

    void pop() {
        if (arr.empty()) {
            isError = true;
        } else {
            arr.pop_back();
        }
    }

    void inv() {
        if (arr.empty()) {
            isError = true;
        } else {
            long long temp = top();
            temp *= -1;
            pop();
            num(temp);
        }
    }

    void dup() {
        if (arr.empty()) {
            isError = true;
        } else {
            num(top());
        }
    }

    void swp() {
        if (arr.size() < 2) isError = true;
        else {
            long long one = top();
            pop();
            long long two = top();
            pop();
            num(one);
            num(two);
        }
    }

    void add() {
        if (arr.size() < 2) isError = true;
        else {
            long long one = top();
            pop();
            long long two = top();
            pop();
            if (abs(one + two) > 1e9) isError = true;
            else
                num(one + two);
        }
    }
    void sub() {
        if (arr.size() < 2) isError = true;
        else {
            long long one = top();
            pop();
            long long two = top();
            pop();
            if (abs(two - one) > 1e9) isError = true;
            else
                num(two - one);
        }
    }
    void mul() {
        if (arr.size() < 2) isError = true;
        else {
            long long one = top();
            pop();
            long long two = top();
            pop();
            if (abs(two * one) > 1e9) isError = true;
            else
                num(one * two);
        }
    }
    void div() {
        if (arr.size() < 2) isError = true;
        else {
            long long one = top();
            pop();
            long long two = top();
            pop();
            if (one == 0) {
                isError = true;
            } else {
                long long res = abs(two) / abs(one);
                if (one * two < 0) {
                    num(-res);
                } else {
                    num(res);
                }
            }
        }
    }
    void mod() {
        if (arr.size() < 2) isError = true;
        else {
            long long one = top();
            pop();
            long long two = top();
            pop();
            if (one == 0) {
                isError = true;
            } else {
                long long res = abs(two) % abs(one);
                if (two < 0) {
                    num(-res);
                } else {
                    num(res);
                }
            }
        }
    }
};

void cal(long long num, vector<string> &ops) {
    Gostk stk;
    stk.num(num);

    for (string op : ops) {
        if (op.length() > 3) {
            // num
            stk.num(atoi(&op[4]));
        } else {
            if (op == "POP") stk.pop();
            else if (op == "INV")
                stk.inv();
            else if (op == "DUP")
                stk.dup();
            else if (op == "SWP")
                stk.swp();
            else if (op == "ADD")
                stk.add();
            else if (op == "SUB")
                stk.sub();
            else if (op == "MUL")
                stk.mul();
            else if (op == "DIV")
                stk.div();
            else if (op == "MOD")
                stk.mod();
        }

        if (stk.isError) {
            cout << "ERROR\n";
            return;
        }
    }

    if (stk.arr.size() != 1) {
        cout << "ERROR\n";
    } else {
        cout << stk.top() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        vector<string> ops;
        while (true) {
            string line;
            cin >> line;
            if (line == "NUM") {
                string temp;
                cin >> temp;
                line += " ";
                line += temp;
            }
            if (line == "QUIT") return 0;
            if (line == "END") break;
            ops.push_back(line);
        }

        int T;
        cin >> T;
        while (T--) {
            long long num;
            cin >> num;
            if (num > 1e9) cout << "ERROR\n";
            else {
                cal(num, ops);
            }
        }

        cout << "\n";
    }

    return 0;
}