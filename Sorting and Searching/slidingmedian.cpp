#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int mid=((k+1)/2)-1;
    vector<int> v(n);
    ordered_set s;
    for(int i=0;i<n;i++)
    	cin>>v[i];
    for(int i=0;i<k;i++)
    	s.insert(v[i]);
    cout<<*s.find_by_order(mid)<<" ";
    for(int i=0;i<n-k;i++){
    	s.erase(s.find_by_order(s.order_of_key(v[i])));
    	s.insert(v[i+k]);
    	cout<<*s.find_by_order(mid)<<" ";
    }
    cout<<endl;
	return 0;
}