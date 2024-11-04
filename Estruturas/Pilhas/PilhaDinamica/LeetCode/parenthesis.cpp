#include <bits/stdc++.h>

using namespace std;

bool is_valid(string);

int main(){

    string expressao;
    cin >> expressao;

    if (is_valid(expressao)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

bool is_valid(string expressao) {

    stack<char> pilha;

    for (unsigned int i = 0; i < expressao.length(); i++) {

        switch (expressao[i]){
            case '{':
                pilha.push('{');
                break;

            case '[':
                pilha.push('[');
                break;
            
            case '(':
                pilha.push('(');
                break;

            case '}':
                if (pilha.empty()) {
                    return false;
                } else if (pilha.top() == '{') {
                    pilha.pop();
                } else {
                    return false;
                }
                break;
            
            case ']':
                if (pilha.empty()) {
                    return false;
                } else if (pilha.top() == '['){
                    pilha.pop();
                } else {
                    return false;
                }
                break;
            
            case ')':
                if (pilha.empty()) {
                    return false;
                } else if (pilha.top() == '('){
                    pilha.pop();
                } else {
                    return false;
                }
                break;
        }
    }

    if (pilha.empty()) return true;
    return false;
}