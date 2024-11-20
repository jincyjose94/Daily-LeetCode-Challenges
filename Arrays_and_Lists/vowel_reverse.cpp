/*
Reverse Vowels of a String
Input: s = "IceCreAm"
Output: "AceCreIm"

Complexity:
Time: O(n)
Space: O(1)
*/

class Solution {
public:
    bool isVowel (char vowel){
        return ((vowel == 'a')||(vowel == 'e')||(vowel == 'i')||(vowel == 'o')||(vowel == 'u')||
        (vowel == 'A')||(vowel == 'E')||(vowel == 'I')||(vowel == 'O')||(vowel == 'U'));
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length()-1;
        while (i<j){
            if(isVowel(s.at(i))&&(isVowel(s.at(j)))){
                char c = s.at(i);
                s.at(i) = s.at(j);
                s.at(j) = c;
                i++;
                j--;
            }
            else if(isVowel(s.at(i))) j--;
            else if(isVowel(s.at(j))) i++;
            else{
                i++;
                j--;
            }
        }
        return s;
    }
};