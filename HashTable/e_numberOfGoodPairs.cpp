/*Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:

Input: nums = [1,2,3]
Output: 0
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(n) for(int i=0; i<n; i++)


int numIdenticalPairs(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int,int> mp;
    f(n){
        if(mp.count(nums[i])>0){
            mp[nums[i]]++;
            continue;
        }else{
            mp[nums[i]]=1;
        }
    }
    int count=0;
    unordered_map<int,int>:: iterator it=mp.begin();
    while(it!=mp.end()){
        if(it->second>=2){
            int l=it->second;
            int r=(l*(l-1))/2;
            count+=r;
        }
        it++;
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        f(n){
            cin>>v[i];
        }
        cout<<numIdenticalPairs(v)<<endl;
    }
}