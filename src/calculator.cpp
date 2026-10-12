using namespace std;
#include "calculator.hpp"
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <cmath>

double Calculator::evaluate(string expression) {

   vector<string> postfix = InfixtoPOSTfix(expression);
   return evaluatePostfix(postfix);
   }
   vector<string> Calculator::InfixtoPOSTfix(string expression){
      vector<string> output;
      stack<string> operators;

      if(expression.empty()) {

      cout << "Error: Empty expression" << endl;
      return output;
    }

   for (int i = 0; i < expression.length(); i++) {
      char num = expression[i];

      if (isdigit(num)){
         output.push_back(string(1, num));
      }
      else if (expression[i] == '(') {
         operators.push(string(1, expression[i]));
      }
      else if (expression[i] == ')') {
         
         while (!operators.empty() && operators.top() != "("){
            output.push_back(operators.top());
            operators.pop();
         }
         operators.pop();
      }
   else if 
      (expression[i] == '*'|| 
      expression[i] == '/' || 
      expression[i] == '+' || 
      expression[i] == '-') {

      while (!operators.empty() && operators.top() != "(" && 
         ((operators.top() == "*" || 
         operators.top() == "/") ||
         operators.top() == "+" || 
         operators.top() == "-")) {
         output.push_back(operators.top());
         operators.pop();
      }
      operators.push(string(1, expression[i]));
   }

   while (!operators.empty()) {
      output.push_back(operators.top());
      operators.pop();
   }
   return output;
   }
