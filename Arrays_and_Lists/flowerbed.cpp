/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true.

Time complexity: O(n) =>(loop through all elements in vector)
space complexity: O(1) =>storing only variable values
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        int len = flowerbed.size();
        if(len==1) return !(flowerbed.at(0));
        if((n>((len/2)+1))) return false;
        bool prev = false;
        for(int i=0; i<len-1; i++){
            if(!flowerbed.at(i) && !prev && !flowerbed.at(i+1)){
                flowerbed.at(i) = true;
                n--;
            }
            prev = flowerbed.at(i);
            if(n==0) break;
        }
        if((n!=0)&&!flowerbed.at(len-2)&&!flowerbed.at(len-1)){
            n--;
        }
        return (n<=0);
    }
};