/*
Given an input string s, reverse the order of the words.
Input: s = "  hello world  "
Output: "world hello"
Input: s = "a good   example"
Output: "example good a"
*/

/*
Solution 1:
Complexity: O(n) for space and time
*/

class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = s.size()-1;
        string res;
        while(s.at(start)==' '){
            s.erase(0,1);
            end--;
        }
        while(s.at(end) == ' '){
            s.pop_back();
            end--;
        }
        int last_index = end;
        for(int i=end;i>=start;i--){
            if(s.at(i)==' ' || i==start){
                if(i==start){
                    res.append(s.substr(i, last_index-(i-1)));
                }
                else if(s.at(i+1)==' '){
                    last_index = i-1;
                }
                else{
                    res.append(s.substr(i+1, last_index-i));
                    last_index = i-1;
                    res.push_back(' ');
                }
            }
        }
        return res;
    }
};

/*
Solution 2:
Complexity: O(n) for both
iss>>word is like cin>>word
*/
class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string res, word;
        vector<string> words;
        while(iss>>word){
            words.push_back(word);
        }
        int word_count = words.size();
        for (int i=word_count-1; i>=0; i--){
            if(!res.empty()){
                res.append(" ");
            }
            res.append(words.at(i));
        }
        cout<<res;
        return res;
    }
};