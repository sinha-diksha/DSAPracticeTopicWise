//bubble sort

#include <bits/stdc++.h>
using namespace std;

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
        for(int i=0; i<n-1; i++){
        
            for(int j=0; j<n-i-1; j++){
                if(v[j]>v[j+1]){
                    v[j]=v[j]+v[j+1];
                    v[j+1]=v[j]-v[j+1];
                    v[j]=v[j]-v[j+1];
                }
                
            }
        }
        for(int i=0; i<n; i++){
            cout<<v[i]<<endl;
        }
    }
}