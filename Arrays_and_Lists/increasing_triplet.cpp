/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) 
such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
Input: nums = [2,1,5,0,4,6]
Output: true
Input: nums = [1,1,1]
Output: false
Complexity: O(n)time, O(1) space
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstNum = INT_MAX;
        int secondNum = INT_MAX;
        int len = nums.size();
        for (int i=0; i<len; i++){
            if(nums.at(i)<=firstNum){
                firstNum = nums.at(i);
            }
            else if(nums.at(i)<=secondNum){
                secondNum = nums.at(i);
            }
            else {
                return true;
            }
        }
        return false;
    }
};