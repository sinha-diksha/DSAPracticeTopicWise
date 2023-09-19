/*1. Two Sum
Easy
48.8K
1.6K
Companies
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> twoSum(vector<int>& nums, int target){
    ll n=nums.size();
    unordered_map<int,vector<int> > ourMap;
    for(int i=0; i<n; i++){
        ourMap[nums[i]].push_back(i);
    }
    unordered_map<int,vector<int> >:: iterator it=ourMap.begin();
    vector<int> v;
    while(it!=ourMap.end()){
        int x=it->first;
        int y=target-x;
        if(ourMap.count(y)>0){
            // v.push_back(it->second);
            // v.push_back(ourMap[y]);
            // break;
            if(x==y){
                if(it->second.size()>1){
                    v.push_back(it->second[0]);
                    v.push_back(it->second[1]);
                    break;
                }
            }else{
                v.push_back(it->second[0]);
                v.push_back(ourMap[y][0]);
                break;
            }
        }
        it++;
    }
    sort(v.begin(), v.end());
    return v;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int target;
        cin>>target;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        vector<int> output=twoSum(v,target);
        for(int i=0; i<2; i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
    }
}