/*Find K Closest Elements
Medium
7.3K
584
Companies
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int diffSum=0;
    int n=arr.size();
    int index=0;
    int i;
    for(i=0; i<k; i++){
        diffSum+=(abs(arr[i]-x));
        index=i;
    }
    int mindiff=diffSum;
    for(; i<n; i++){
        diffSum-=(abs(arr[i-k]-x));
        diffSum+=(abs(arr[i]-x));
        if(mindiff>diffSum){
            mindiff=diffSum;
            index=i;
        }
    }
    vector<int> output;
    for(int i=index; i>index-k; i--){
        output.push_back(arr[i]);
    }
    reverse(output.begin(), output.end());
    return output;
    
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
        int k,x;
        cin>>k>>x;
        vector<int> output=findClosestElements(v,k,x);
        for(int i=0; i<output.size(); i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
    }
}