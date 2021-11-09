// Infix To Postfix
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include "InfixToPostfix.hpp"
using namespace std;
string InfixToPostfix(string infix){
    string postfix;
    stack<char> stack;
    int i,l = infix.size();
    for (i=0;i<l;i++){
        char current_token = infix[i];
        if (current_token != '(' and current_token != ')' and current_token != '^' and current_token != '*' and current_token != '/' and current_token != '+' and current_token != '-') postfix.push_back(current_token);
        else if (current_token == '(') stack.push(current_token);
        else if (current_token == ')'){
            while (1){
                if (stack.empty() == false and stack.top() == '('){
                    stack.pop();
                    break;
                }
                else{
                    if (stack.empty() == false){
                        postfix.push_back(stack.top());
                        stack.pop();
                    }
                }
            }
        }
        else if (current_token == '^') stack.push(current_token);
        else if (current_token == '*' or current_token == '/'){
            if (stack.empty()) stack.push(current_token);
            else if (stack.empty() == false and (stack.top() == '+' or stack.top() == '-' or stack.top() == '(')) stack.push(current_token);
            else if (stack.empty() == false and (stack.top() == '*' or stack.top() == '/' or stack.top() == '^')){
                while (1){
                    if (stack.empty()) break;
                    else {
                        if (stack.top() == '+' or stack.top() == '-' or stack.top() == '(') break;
                        else{
                            postfix.push_back(stack.top());
                            stack.pop();
                        }
                    }
                }
                stack.push(current_token);
            } 
        }
        else if (current_token == '+' or current_token == '-'){
            if (stack.empty()) stack.push(current_token);
            else if (stack.empty() == false and stack.top() == '(') stack.push(current_token);
            else if (stack.empty() == false and (stack.top() == '+' or stack.top() == '-' or stack.top() == '*' or stack.top() == '/' or stack.top() == '^')){
                while (1){
                    if (stack.empty()) break;
                    else {
                        if (stack.top() == '(') break;
                        else{
                            postfix.push_back(stack.top());
                            stack.pop();
                        }
                    }
                }
                stack.push(current_token);
            }
        }
    }
    while (stack.empty() == false){
        postfix.push_back(stack.top());
        stack.pop();
    }
    return postfix; 
}