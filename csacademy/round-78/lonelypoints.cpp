/******************
*	Subham kumar  *
*				  *	
*******************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned ll
#define vi vector<ll>
#define  F first 
#define  S second
#define ii pair<ll,ll>
#define boost ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define pb push_back
#define mp make_pair
#define all(c) c.begin(),c.end()
#define PI 3.14159265359
#define N 4000000
#define mod 1000000007
#define vii vector<ii> 
#define debug1 cout<<"debug1"<<endl;
#define debug(x) cout<<"this is "<<x<<endl;
/***************************************************************/



int main(){
boost;
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll en = a[n-1]-a[n-2];
	ll st = a[1]-a[0];
	vi v;
	if(en>st){
		for(int i=1;i<n-1;i++){
			v.pb(a[i]-a[i-1]);
		}
		sort(all(v));
	}else{
		for(int i=2;i<n;i++){
			v.pb(a[i]-a[i-1]);
		}
		sort(all(v));

	}
	 if(n==3){

	 }else{
	 	ll mx = v[v.size()-1];
	 	if(mx%2){
	 		mx/=2;
	 		mx++;
	 	}else{
	 		mx/=2;
	 	}
	 	mx = max(mx,v[v.size()-2]);
	 	cout<<mx<<endl;
	 }



return 0;
}
 	
