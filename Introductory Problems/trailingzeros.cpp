#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int fi(int n){
    int count = 0;
    for(int i=5;n/i>=1;i*=5) 
        count+=n/i;
    return count;
}
int main(){
	int n;
	cin>>n;
	cout<<fi(n)<<endl;
	return 0;
}