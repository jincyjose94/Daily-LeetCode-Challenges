/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49  
Input: height = [1,1]
Output: 1

Complexiy: space=> O(1)
            time=> O(n)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = INT_MIN;
        while(left<right){
            maxArea = max((min(height.at(left),height.at(right))*(right-left)), maxArea);
            if(height.at(left)>height.at(right)){
                right--;
            }
            else{
                left++;
            }
        }
        return maxArea;

    }
};