/*First negative integer in every window of size k
EasyAccuracy: 48.61%Submissions: 121K+Points: 2
Join the most popular course on DSA. Master Skills & Become Employable by enrolling today! 
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function printFirstNegativeInteger() which takes the array A[], its size N and an integer K as inputs and returns the first negative number in every window of size K starting from the first till the end. If a window does not contain a negative integer , then return 0 for that window.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)

Constraints:
1 <= N <= 105
-105 <= A[i] <= 105
1 <= K <= N

*/

#include <bits/stdc++.h>
using namespace std;

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
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(i<k-1){
                if(v[i]<0){
                    dq.push_back(i);
                }
                continue;
            }
            if(i==k-1){
                if(v[i]<0){
                    dq.push_back(i);
                        
                }
                if(!dq.empty()){
                    ans.push_back(v[dq.front()]);
                }else{
                    ans.push_back(0);
                }
                continue;
            }
            if(!dq.empty() && i-k==dq.front()){
                dq.pop_front();
            }
            if(v[i]<0){
                dq.push_back(i);
            }
            if(!dq.empty()){
                ans.push_back(v[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

}