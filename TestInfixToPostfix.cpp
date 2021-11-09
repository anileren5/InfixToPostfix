#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include "InfixToPostfix.hpp"

using namespace std;

int main(void){
    string str;
    cout << "Infix Expression: ";
    getline(cin,str);
    cout << "Postfix Expression: " << InfixToPostfix(str) << endl;
    return 0;
}