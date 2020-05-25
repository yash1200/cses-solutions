#include<bits/stdc++.h>
using namespace std;
void findPrefix(string pattern,int m,int prefArray[]){
	int length=0;
	prefArray[0] = 0;
	for(int i = 1; i<m; i++) {
		if(pattern[i] == pattern[length]) {
			length++;
			prefArray[i] = length;    
		}else{
			if(length != 0) {
				length = prefArray[length - 1];
				i--;
			}else
				prefArray[i] = 0;
		}
	}
}
int kmpPattSearch(string mainString,string pattern){
	int n,m,i=0,j=0,loc=0;
	n=mainString.size();
	m=pattern.size();
	int prefixArray[m];
	findPrefix(pattern,m,prefixArray);
	while(i<n){
		if(mainString[i]==pattern[j])
			i++,j++;
		if(j==m){
			loc++;
			j=prefixArray[j-1];
		}else if(i<n&&pattern[j]!=mainString[i]){
			if(j != 0)
				j=prefixArray[j-1];
			else
				i++;
		}
	}
	return loc;
}
int main() {
	string str,patt;
	cin>>str>>patt;
	cout<<kmpPattSearch(str,patt)<<endl;
	return 0;
}