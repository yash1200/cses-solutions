#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
set<string> s;
void get(string a,int l,int r){
    if (l == r)  
        s.insert(a);  
    else
        for(int i = l; i <= r; i++){
            swap(a[l], a[i]);
            get(a, l+1, r);
            swap(a[l], a[i]);
        }
}
int main(){
	string str;
	cin>>str;
	sort(str.begin(),str.end());
	string str1="";
	get(str,0,str.length()-1);
	cout<<s.size()<<endl;
	for(auto itr=s.begin();itr!=s.end();++itr)
		cout<<*itr<<endl;
	return 0;
}