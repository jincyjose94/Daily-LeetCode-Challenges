#include <vector>
#include <iostream>

/*
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array is not returned, but instead be stored inside the array nums1. 
nums1 has a length of m + n, nums2 has a length of n.
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

time complexity: O(m+n)
space complexity: O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums_index = 0;
        while(!nums2.empty()&&m>0){
            if(nums2.at(0)<=nums1.at(nums_index)){
                nums1.insert(nums1.begin()+nums_index, nums2.at(0));
                nums2.erase(nums2.begin(), nums2.begin()+1);
            }
            else  
            {
                m--;
            }
            nums_index++;
           
        }
        while(!nums2.empty()){
            nums1.insert(nums1.begin()+nums_index, nums2.at(0));
            nums2.erase(nums2.begin());
            nums_index++;
        }
        while(n>0){
            nums1.pop_back();
            n--;
        }
    }
};