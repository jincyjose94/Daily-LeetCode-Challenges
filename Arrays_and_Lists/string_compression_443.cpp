/*
Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Example 2:
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.

Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".


Complexity: time=> O(n); we traverse the array.
            space=>O(1); no data structure created, only variables used.
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size();
        if(len == 1) return 1;
        int count = 1;
        int pos = 1;
        char prevChar = chars.at(0);
        for(int charsIndex = 1;charsIndex<len; charsIndex++){
            char currentChar = chars.at(charsIndex);
            if(currentChar == prevChar){
                count++;
                if(charsIndex==len-1){
                    string charCount = to_string(count);
                    for(auto c: charCount){
                        chars.at(pos++) = c;
                    }
                }
            }
            else{
                if(count>1){
                    string charCount = to_string(count);
                    for(auto c: charCount){
                        chars.at(pos++) = c;
                    }
                }
                count = 1;
                prevChar = currentChar;
                chars.at(pos++) = currentChar;
            }
        }
        cout<<"pos: "<<pos<<endl;
        chars.erase(chars.begin()+pos, chars.end());
        return pos;
    }
};