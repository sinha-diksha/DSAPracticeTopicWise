/*Magnetic Force Between Two Balls
Medium
1.9K
103
Companies
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls 
if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], 
Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any 
two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.

 

Example 1:


Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. 
The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.
 

Constraints:

n == position.length
2 <= n <= 105
1 <= position[i] <= 109
All integers in position are distinct.
2 <= m <= position.length*/

#include <bits/stdc++.h>
using namespace std;


bool check(int mid, vector<int>& position, int m){
    int total=1;
    int last=0;
    int n=position.size();
    for(int i=1; i<n; i++){
        if(position[i]-position[last]>=mid){
            total++;
            last=i;
        }
    }
    return total>=m;
}


int maxDistance(vector<int>& position, int m) {
    sort(position.begin(),position.end());
    int l=0;
    int r=1e9+5;
    int ans=1e9+5;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid,position,m)){
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
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        int m;
        cin>>m;
        cout<<maxDistance(v,m)<<endl;
    }

}