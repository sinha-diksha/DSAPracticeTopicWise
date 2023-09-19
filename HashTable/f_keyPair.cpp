/*Key Pair
Easy
Join the most popular course on DSA. Master Skills & Become Employable by enrolling today! 
Given an array Arr of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly X.

Example 1:

Input:
N = 6, X = 16
Arr[] = {1, 4, 45, 6, 10, 8}
Output: Yes
Explanation: Arr[3] + Arr[4] = 6 + 10 = 16
Example 2:

Input:
N = 5, X = 10
Arr[] = {1, 2, 4, 3, 6}
Output: Yes
Explanation: Arr[2] + Arr[4] = 4 + 6 = 10
Your Task:
You don't need to read input or print anything. Your task is to complete the function hasArrayTwoCandidates() which takes the array of integers arr, n and x as parameters and returns a boolean denoting the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 105*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(n) for(int i=0; i<n; i++)

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x;
        cin>>x;
        vector<int> v(n);
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            cin>>v[i];
            mp[v[i]]++;
        }
        bool isFound=false;
        unordered_map<int,int>:: iterator it=mp.begin();
        while(it!=mp.end()){
            int y=x-it->first;
            if(mp.count(y)>0){
                cout<<"YES"<<endl;
                isFound=true;
                break;
            }
            it++;
        }
        if(!isFound){
            cout<<"No"<<endl;
        }
    }
}