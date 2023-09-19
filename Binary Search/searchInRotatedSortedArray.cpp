/*Search in Rotated Sorted Array
Medium
22.5K
1.3K
Companies
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1*/


// Here the elements are unique 

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> nums, int left, int right, int target){
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return -1; 
}

int search(vector<int>& nums, int target) {
    int pivot;
    int l=0;
    int r=nums.size()-1;
    int n=nums.size();
   
    while(l<=r){
        int mid=l+(r-l)/2;
        if(mid-1>=0 && mid+1<n && nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
            pivot=mid;
            break;
        }
        else if(mid==0 && nums[mid]>nums[mid+1]){
            pivot =mid;
            break;
        }
        else if(mid==n-1 && nums[mid-1]<nums[mid]){
            pivot=mid;
            break;
        }
        else if(nums[mid]>=nums[l]){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    int r1=binarySearch(nums,0,pivot,target);
    int s=binarySearch(nums,pivot+1,n-1, target);
    if(r1==-1 && s==-1){
        return -1;
    }
    else if (r1!=-1){
        return r1;
    }else{
        return s;
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++){
            cin>>nums[i];
        }
        int x;
        cin>>x;
        cout<<search(nums,x)<<endl;
    }

}