/*
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]

Complexity : Space => O(1)
             Time =>  O(n)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if (len>1){
            int nonZeroIndex = 0;
            for (int numsIndex=0; numsIndex<len; numsIndex++){
                if(nums.at(numsIndex)!=0){
                    nums.at(nonZeroIndex++) = nums.at(numsIndex);
                }
            }
            for (int zeroIndex=nonZeroIndex; zeroIndex<len; zeroIndex++){
                nums.at(zeroIndex) = 0;
            }
        }

    }
};    