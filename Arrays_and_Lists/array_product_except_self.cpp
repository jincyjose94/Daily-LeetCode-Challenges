/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Complexity analysis:
Time: O(n)
Space: O(1) not considering result vector
The output array does not count as extra space for space complexity analysis.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(len, 1);
        for (int left_i=1;left_i<len;left_i++){
            result.at(left_i)=result.at(left_i-1)*nums.at(left_i-1);
        }
        int rightProduct = 1;
        for (int i=len-2;i>=0;i--){
            rightProduct*=nums.at(i+1);
            result.at(i)*=rightProduct;
        }
        return result;
    }    
};