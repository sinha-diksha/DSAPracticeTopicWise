#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

using namespace std;

/*int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for(int i=0; i<n; i++){
	        cin>>v[i];
	    }
	    long long count=0;
	    long long sum=0;
	    int i=0;
	    for(i=0; i<3; i++){
	       sum+=v[i];
	    }
	    if(sum%3!=0){
	        int x=sum%3;
	        int y=sum-x;
	        int z=y+3;
	        int r=z-sum;
	        count+=r;
	        v[2]=v[2]+r;
	        sum+=r;
	    }
	    for(; i<n; i++){
	        sum+=(v[i]-v[i-3]);
	        if(sum%3!=0){
	            int x=sum%3;
    	        int y=sum-x;
    	        int z=y+3;
    	        int r=z-sum;
    	        count+=r;
    	        v[i]=v[i]+r;
    	        sum+=r;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}*/


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
		int  maxProduct=v[0];
		int minProduct=v[0];
		for(int i=1; i<n; i++){
			if(v[i]<0){
				swap(maxProduct, minProduct);
			}
			maxProduct=max(maxProduct*v[i], v[i]);
			minProduct=min(minProduct*v[i], v[i]);
		}
		cout<<maxProduct<<endl;
	}
}
// Block swap algorithm



