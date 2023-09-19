#include <bits/stdc++.h>
using namespace std;

int fillCups(vector<int>& amount) {
        int n=amount.size();
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            if(amount[i]!=0){
                pq.push(amount[i]);
            }
        }
        int count=0;
        while(pq.size()>=2){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            count++;
            a--;
            b--;
            if(a>0){
                pq.push(a);
            }
            if(b>0){
                pq.push(b);
            }
        }
        if(!pq.empty()){
            count+=pq.top();
        }
        return count;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> amount(3);
        for(int i=0; i<3; i++){
            cin>>amount[i];
        }
        cout<<fillCups(amount)<<endl;
    }
}