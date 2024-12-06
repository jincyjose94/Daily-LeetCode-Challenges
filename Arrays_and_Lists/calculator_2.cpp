/*
227. Basic Calculator II
Given a string s which represents an expression, evaluate this expression and return its value. 

Input: s = "3+2*2"
Output: 7
s="42", o/p=42

This solution does not use stack.
Instead, it uses 2 additional variables to store previous 2 numbers.
Hence, addition take place while looping through string.
Time complexity: O(n)=>we traverse through length of string
Space complexity: O(1) => we used only additional variables
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
        int currentNum = 0;
        int prevNum = 0;
        int prevOp = '+';
        int secondPrevNum = 0;
        for (int sIndex = 0; sIndex < sLen; sIndex++){
            int currentChar = s.at(sIndex);
            if(isdigit(currentChar)){
                currentNum = currentNum*10 + (currentChar - '0');
            }
            if((!isdigit(currentChar)&&!isspace(currentChar))||sIndex == sLen-1){
                if(prevOp == '+'){
                    secondPrevNum+=prevNum;
                    prevNum = currentNum;
                }
                else if(prevOp == '-'){
                    secondPrevNum+=prevNum;
                    prevNum = currentNum * -1;
                }
                else if(prevOp == '*'){
                    prevNum= prevNum*currentNum;
                }
                else if(prevOp == '/'){
                    prevNum= prevNum/currentNum;
                }
                prevOp = currentChar;
                currentNum = 0;
            }
        }
        return secondPrevNum+prevNum;
    }
};