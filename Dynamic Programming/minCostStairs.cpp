/*Min Cost Climbing Stairs
Easy
9.8K
1.5K
Companies
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    int* arr=new int[n+1];
    if(n==2){
        return min(cost[0], cost[1]);
    }
    arr[0]=0;
    arr[1]=0;
    arr[2]=(cost[1]<=cost[0]+cost[2])?cost[1]:cost[0];
    for(int i=3; i<n+1; i++){
        arr[i]=min(arr[i-1]+cost[i-1], arr[i-2]+cost[i-2]);
    }
    return arr[n];
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
        cout<<minCostClimbingStairs(v)<<endl;
    }
}