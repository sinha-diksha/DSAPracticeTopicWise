/*Longest subarray with sum divisible by K
MediumAccuracy: 33.72%Submissions: 46K+Points: 4
Join the most popular course on DSA. Master Skills & Become Employable by enrolling today! 
Given an array containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

Example 1:

Input:
A[] = {2, 7, 6, 1, 4, 5}
K = 3
Output: 4
Explanation:The subarray is {7, 6, 1, 4}
with sum 18, which is divisible by 3.
Example 2:

Input:
A[] = {-2, 2, -5, 12, -11, -1, 7}
K = 3
Output: 5
Explanation:
The subarray is {2,-5,12,-11,-1} with
sum -3, which is divisible by 3.
 

Your Task:
The input is already taken care of by the driver code. You only need to complete the function longSubarrWthSumDivByK() that takes an array (arr), sizeOfArray (n), positive integer K, and return the length of the longest subarray which has sum divisible by K. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=N,K<=106
-105<=A[i]<=105
 

*/

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumDivisibleByK(vector<int>& v, int k){
    int n=v.size();
    int mx=0;
    int sum=0;
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        sum+=v[i];
        int rem=(sum%k+k)%k;
        if(rem==0){
            mx=max(mx,i+1);
            continue;
        }
        if(mp.count(rem)==0){
            mp[rem]=i;
            continue;
        }else{
            mx=max(mx,i-mp[rem]);
        }

    }
    return mx;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        cout<<longestSubarrayWithSumDivisibleByK(v,k)<<endl;
    }
}