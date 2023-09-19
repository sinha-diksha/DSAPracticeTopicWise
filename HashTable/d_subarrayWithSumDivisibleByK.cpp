/*Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
2 <= k <= 104*/

#include <bits/stdc++.h>
using namespace std;

int sumDivisibleByK(vector<int> v, int k){
    int count=0;
    int n=v.size();
    int sum=0;
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        sum+=v[i];
        int rem=(sum%k +k)%k;
        if(mp.count(rem)>0){
            mp[rem]++;
        }else{
            mp[rem]=1;
        }
    }
    unordered_map<int,int>:: iterator it=mp.begin();
    while(it!=mp.end()){
        int r=it->second;
        if(it->first==0){
            
            int l=(r*(r+1))/2;
            count+=l;
        }else{
            int x=(r*(r-1))/2;
            count+=x;
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
        int k;
        cin>>k;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        cout<<sumDivisibleByK(v,k)<<endl;
    }
}