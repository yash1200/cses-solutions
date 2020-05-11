#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n;
	cin>>n;
	while(n--){
		int x,count=0;
		cin>>x;
		for(int i=1;i<=sqrt(x);i++){
			if(x%i==0){
				if(i*i==x)
					count++;
				else
					count+=2;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}