#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int n,x,sum=0,count=0,i=0,index=0;
	cin>>n>>x;
	vector<int> v(n);
	for(int j=0;j<n;j++)
		cin>>v[j];
	while(i<n){
		if(sum<x){
			if(index>=n)
				break;
			sum+=v[index++];
		}else if(sum>x)
			sum-=v[i++];
		else{
			sum-=v[i++];
			sum+=v[index++];
		}
		if(sum==x)
			count++;
	}
	cout<<count<<endl;
	return 0;
}