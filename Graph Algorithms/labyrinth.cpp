#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int n,m,xa,ya,xb,yb,a,b,c;
	cin>>n>>m;
	vector<string> v(n);
	vector<vector<int>> vis(n,vector<int>(m,-1));
	for(int i=0;i<n;i++){
		cin>>v[i];
		for(int j=0;j<m;j++)
			if(v[i][j]=='A')
				xa=i,ya=j;
			else if(v[i][j]=='B')
				xb=i,yb=j;
	}
	queue<tuple<int,int,int>> q;
	q.push({xa,ya,0});
	while(!q.empty()){
		tie(a,b,c)=q.front();
		q.pop();
		if(vis[a][b]!=-1)
			continue;
		vis[a][b]=c;
		if(a==xb&&b==yb){
			string ans="";
			cout<<"YES\n"<<vis[a][b]<<endl;
			while(a!=xa||b!=ya){
				if(a>0&&vis[a-1][b]==c-1)
					ans+='D',a--;
				else if(a<n-1&&vis[a+1][b]==c-1)
					ans+='U',a++;
				else if(b>0&&vis[a][b-1]==c-1)
					ans+='R',b--;
				else
					ans+='L',b++;
				c--;
			}
			reverse(ans.begin(),ans.end());
			cout<<ans<<endl;
			return 0;
		}
		if(a>0&&v[a-1][b]!='#'&&vis[a-1][b]==-1)
			q.push({a-1,b,c+1});
		if(a<n-1&&v[a+1][b]!='#'&&vis[a+1][b]==-1)
			q.push({a+1,b,c+1});
		if(b>0&&v[a][b-1]!='#'&&vis[a][b-1]==-1)
			q.push({a,b-1,c+1});
		if(b<m-1&&v[a][b+1]!='#'&&vis[a][b+1]==-1)
			q.push({a,b+1,c+1});
	}
	cout<<"NO\n";
	return 0;
}