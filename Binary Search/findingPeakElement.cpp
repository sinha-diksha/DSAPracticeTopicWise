/*A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an 
element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 



// O(n) Time complexity
int findPeakElement1(vector<int>& nums) {
    int n=nums.size();
    for(int i=0; i<n; i++){
        if(i==0){
            if(nums[i]>nums[i+1]){
                return i;
            }
        }
        else if(i==n-1){
            if(nums[i]>nums[i-1]){
                return i;
            }
        }
        else if(nums[i]>nums[i+1] && nums[i]>nums[i-1]){
            return i;
        }
    }
    return -1;
}


// O(log n) Time Complexity
int findPeakElement(vector<int>& nums){
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        cout<<findPeakElement1(v);
    }
}