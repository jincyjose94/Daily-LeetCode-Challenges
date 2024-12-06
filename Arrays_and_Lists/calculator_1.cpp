/*
227. Basic Calculator II
Given a string s which represents an expression, evaluate this expression and return its value. 

Input: s = "3+2*2"
Output: 7
s="42", o/p=42

This solution use stack.
Time complexity: O(n)=>we traverse through length of string
Space complexity: O(n) => we used a stack
*/

class Solution {
public:
    int calculate(string s) {
        int sLen = s.size();
        if (sLen == 0){
            return 0;
        }
        else if (sLen == 1){
            return (s.at(0) - '0');
        }
        else if (sLen == 2){
            return (((s.at(0) - '0') * 10) + (s.at(1) - '0'));
        }
        stack<int> numberStack;
        int prevOp = '+';
        int number = 0;
        int result = 0;
        for (int sIndex = 0; sIndex < sLen; sIndex++) {
            int currentChar = s.at(sIndex);
            if (isdigit(currentChar)) {
                number = number * 10 + (currentChar - '0');
            }
            if ((!isdigit(currentChar) && !isspace(currentChar)) ||
                sIndex == sLen - 1) {
                if (prevOp == '+') {
                    numberStack.push(number);
                } else if (prevOp == '-') {
                    numberStack.push(number * -1);
                } else if (prevOp == '/') {
                    int prevNumber = numberStack.top();
                    numberStack.pop();
                    numberStack.push(prevNumber / number);
                } else if (prevOp == '*') {
                    int prevNumber = numberStack.top();
                    numberStack.pop();
                    numberStack.push(prevNumber * number);
                }
                prevOp = currentChar;
                number = 0;
            }
        }
        while (!numberStack.empty()) {
            result += numberStack.top();
            numberStack.pop();
        }
        return result;
    }
};