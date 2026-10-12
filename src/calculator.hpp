#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;


class Calculator {
public:
    double evaluate(string expression);

    private:
    vector<string> InfixtoPOSTfix(string expression);
    double evaluatePostfix(vector<string> postfix);
};

#endif
