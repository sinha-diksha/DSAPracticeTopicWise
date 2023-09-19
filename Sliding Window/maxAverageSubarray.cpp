/*Maximum Average Subarray I
Easy
2.7K
219
Companies
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cout<<fixed;
    cout<<setprecision(5);
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
        int sum=0;
        int i;
        for(i=0; i<k; i++){
            sum+=v[i];
        }
        double r=(double)sum/k;
        for(; i<n; i++){
            sum=sum+v[i]-v[i-k];
            double xyz=(double)sum/k;
            if(r<xyz){
                r=xyz;
            }
        }
        cout<<r<<endl;
    }
}