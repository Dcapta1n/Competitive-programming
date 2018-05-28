#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long int
#define pi pair<ll,ll> 
vector<pi> v;
ll dp[18][1<<18];
#define F first
#define S second
 
int line(pi x,pi y,pi z){
	ll x1 = x.F,y1=x.S;
	ll x2=y.F,y2=y.S;
	ll x3=z.F,y3=z.S;
	
	ll a = (y3-y1)*(x2-x1);
	ll b = (y2-y1)*(x3-x1);
	if(b==a){
		return 1;
	}else{
		return 0;
	}
}
double dis(pi x,pi y){
	double x1 = x.F,y1=x.S;
	double x2=y.F,y2=y.S;
	double dis = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	return sqrtl(dis);
}
int chk(pi a,pi b,pi c){
	if(line(a,b,c)){
		double dis1=dis(a,b),dis2=dis(b,c),dis3=dis(a,c);
		if(dis1+dis2-dis3<0.0000000001){
		 	return 1;
		}else {
			return 0;
		}
	}else{
		return 0;
	}
}
ll f(ll pos ,ll  mask){
	if(dp[pos][mask]!=-1){
		return dp[pos][mask];
	}
	ll cnt=0;
	for(int i=0;i<32;i++){
		if((mask&(1<<i))){
			cnt++;
		}	
	}
	ll ans1 = 0;
	ans1+= (cnt>1);
	for(int i=0;i<v.size();i++){
		if((mask&(1<<i))){
			continue;
		}
		int flag=1;
		for(int j=0;j<v.size();j++){
			if(j==i){continue;}
			if(mask&(1ll<<j)){continue;}
			int z1 =chk(v[pos],v[j],v[i]);
			if(z1==1){
				flag=0;
				break;
			}
		}
		if(flag){
			ll newmask = mask|(1<<i);
			ans1 += f(i,newmask);
		}
 
	}
	return dp[pos][mask]=ans1;
}
int main(){
 
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		
		v.pb(mp(x,y));
	}
	memset(dp,-1,sizeof dp);
	ll ans =0;
	for(int i=0;i<n;i++){
		ll mask = 1<<i;
		ans+=f(i,mask);
	}
	cout<<ans<<endl;
 
 
return 0;
}
