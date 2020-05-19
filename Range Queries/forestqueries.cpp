#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int n,q,x1,y1,x2,y2;
	string s;
	cin>>n>>q;
	int ar[n][n],pre[n][n+1]={};
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<n;j++){
			if(s[j]=='.')
				ar[i][j]=0;
			else
				ar[i][j]=1;
			pre[i][j+1]=pre[i][j]+ar[i][j];
		}
	}
	while(q--){
		cin>>y1>>x1>>y2>>x2;
		int count=0;
		for(int i=y1-1;i<y2;i++)
			count+=pre[i][x2]-pre[i][x1-1];
		cout<<count<<endl;
	}
	return 0;
}