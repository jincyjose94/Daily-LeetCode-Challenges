/*
There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.
Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.
Note that multiple kids can have the greatest number of candies.

Example 1:
Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 

total time complexity is: O(n)+O(n)=O(n)
Space Complexity
Result Vector: The res vector requires O(n) space.
Auxiliary Space: few extra variables maxCandy and len are used, which take O(1) space.
Thus, the total space complexity is: O(n)
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = 0;
        int len = candies.size();
        vector<bool> res;
        for (int candy: candies){
            maxCandy = max(maxCandy, candy);
        }
        for(int candy: candies){
            res.push_back((candy+extraCandies)>=maxCandy);
        }
        return res;
    }
};