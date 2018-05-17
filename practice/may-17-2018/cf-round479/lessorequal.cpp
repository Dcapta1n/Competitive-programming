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
ll a[N];
ll n,k;
ll f(ll x){
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a[i]<=x){
			cnt++;
		}
	}
	return cnt>=k;
}
int main(){
boost;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
 	ll lo = 1,hi =1e9;
 	while(lo<hi){
 		ll mid = (lo+hi)/2;
 		if(f(mid)){
 			hi = mid;
 		}else{
 			lo = mid+1;
 		}
 	}
 	int cnt = 0;
 	for(int i=0;i<n;i++){
 		if(a[i]<=lo){
 			cnt++;
 		}
 	}
 	if(cnt==k){
 		cout<<lo<<endl;
 	}else{
 		cout<<-1<<endl;
 	}


return 0;
}
 	
