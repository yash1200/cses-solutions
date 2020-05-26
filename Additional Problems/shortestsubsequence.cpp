#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	string a,n="";
	cin>>a;
	set<char> s;
	for(char c:a){
		s.insert(c);
		if(s.size()==4)
			n+=c,s.clear();
	}
	if(!s.count('A'))n+='A';
	else if(!s.count('C'))n+='C';
	else if(!s.count('G'))n+='G';
	else if(!s.count('T'))n+='T';
	cout<<n<<endl;
	return 0;
}