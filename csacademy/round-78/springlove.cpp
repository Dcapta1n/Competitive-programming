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
	ll a =0,sum=0;
	for(int i=0;i<n;i++){
		cin>>a;
		sum+=a;
		sum%=2;
	}
	sum%=2;
	cout<<sum<<endl;
 	



return 0;
}
 	
