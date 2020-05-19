#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long int ll;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,a,b;
    char ch;
    cin>>n>>q;
    vector<int> v(n);
    ordered_set s;
    for(int i=0;i<n;i++)
    	cin>>v[i],s.insert(v[i]);
    while(q--){
    	cin>>ch>>a>>b;
    	if(ch=='!'){
    		s.erase(--s.lower_bound(v[a-1]));
    		v[a-1]=b;
    		s.insert(v[a-1]);
    	}
    	else
    		cout<<s.order_of_key(b+1)-s.order_of_key(a)<<endl;
    }
	return 0;
}