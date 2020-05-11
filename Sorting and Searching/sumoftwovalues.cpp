#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main(){
	int n,x;
	cin>>n>>x;
	int ar[n];
	map<int,vector<int>> m;
	for(int i=0;i<n;i++){
		cin>>ar[i];
		m[ar[i]].push_back(i);
	}
	bool flag=true;
	for(int i=0;i<n;i++){
		if(m.find(x-ar[i])!=m.end()){
			if(x-ar[i]==ar[i]&&m[x-ar[i]].size()==1)
				continue;
			if(x-ar[i]==ar[i])
				cout<<m[ar[i]][0]+1<<" "<<m[ar[i]][1]+1<<endl,flag=false;
			else
				cout<<m[ar[i]][0]+1<<" "<<m[x-ar[i]][0]+1<<endl,flag=false;
			break;
		}
	}
	if(flag)
		cout<<"IMPOSSIBLE\n";
	return 0;
}