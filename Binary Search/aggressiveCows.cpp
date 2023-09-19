/*Aggressive Cows
Send Feedback
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.


You are also given an integer 'k' which denotes the number of aggressive cows.


You are given the task of assigning stalls to 'k' cows such that the minimum distance between 
any two of them is the maximum possible.


Print the maximum possible minimum distance.


Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
Input format :
The first line contains two integers ‘n’ and ‘k’ denoting the number of elements in the array and the number of aggressive cows.

The second line contains ‘n’ single space-separated integers denoting the position of the stalls.


Output format :
Return the largest possible minimum distance between cows.


Note :
You do not need to print anything; it has already been handled.
Sample Input 1 :
6 4
0 3 4 7 10 9


Sample Output 1 :
3


Explanation to Sample Input 1 :
The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here distance between cows are 3, 4 and 3 respectively.


Sample Input 2 :
5 2
4 2 1 3 6


Sample Output 2 :
5


Expected time complexity:
Can you solve this in O(n * log(n)) time complexity?


Constraints :
2 <= 'n' <= 10 ^ 5
2 <= 'k' <= n
0 <= 'arr[i]' <= 10 ^ 9
Time Limit: 1 sec.*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(int mid, vector<int>& barn, int k){
    int total=1;
    int last=0;
    for(int i=1; i<barn.size(); i++){
        if(barn[i]-barn[last]>=mid){
            total++;
            last=i;
        }
    }
    return total>=k;
}

int aggressiveCows(vector<int> &barn, int k){
    sort(barn.begin(), barn.end());
    int l=1;
    int r=1e9+5;
    int ans=1e9+5;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid,barn,k)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> barn(n);
        for(int i=0; i<n; i++){
            cin>>barn[i];
        }
        int k;
        cin>>k;
        cout<<aggressiveCows(barn,k)<<endl;
    }
}