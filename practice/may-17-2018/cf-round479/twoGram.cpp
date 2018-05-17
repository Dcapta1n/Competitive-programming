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
	int n;
	cin>>n;
	string s;
	cin>>s;
	map<string,int> m;
	for(int i=0;i<n;i++){
		if(i+1<n){
			string s1="";
			s1+=s[i];
			s1+=s[i+1];
			//cout<<s1<<endl;
			m[s1]++;
		}
	}
	auto it = m.begin();
	string ans ="";
	int c=0;
	while(it!=m.end()){
		int cnt = it->S;
		if(cnt>c){
			c=cnt;
			ans=it->F;

		}
		it++;
	}
 		cout<<ans<<endl;



return 0;
}
 	
