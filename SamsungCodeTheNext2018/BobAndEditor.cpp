    #include <bits/stdc++.h>
    using namespace std;
    vector<string> v;
    int main(){
    	int n;
    	cin>>n;
    	cin.ignore();
    	for(int i=0;i<n;i++){
    		string s1;
    		getline(cin,s1);
    		v.push_back(s1);
    	}
    	int q;
    	cin>>q;
    	cin.ignore();
    	int y=n-1,x=v[y].size();
    	string buff="";
    	for(int z1=0;z1<q;z1++){
    		string s1;
    		getline(cin,s1);
    		int n=v.size();
    		if(s1=="dd"){
    			if(y==n-1){
    				v.pop_back();
    				y--;
    				if(y==-1){
    					y++;
    				}
    			}else{
    				v.erase(v.begin()+y);
    			}
    			if(v.empty()){
    				y=0;
    				x=0;
    			}else{
    				x=v[y].size();
    			}
    		}else if(s1[0]==':'){
    			int idx=0;
    			for(int i=1;i<s1.size();i++){
    				idx = idx*10+s1[i]-'0';
    			}
    			y=idx-1;
    			if(!v.empty()){
    				x=v[y].size();
    			}else{
    				x=0;
    			}
    		}else if(s1[0]=='i'){
    			int num =0;
    			int st=1;
    			while(s1[st]<'0' || s1[st]>'9'){
    				st++;
    			}
    			for(int i=st;i<s1.size();i++){
    				num = num*10+s1[i]-'0';
    			}
    			
    			string s2;
    			int tmp=y;
    			for(int i=0;i<num;i++){
    				getline(cin,s2);
    				if(i==0){
    					string s3="";
    					if(!v.empty()){
    						s3=v[tmp];
    					}
    					string s4=s3;
    					s4+=s2;
    					if(v.empty()){
    						v.push_back(s4);
    					}else{	
    						v[tmp]=s4;
    					}
    					tmp++;
     
     
    				}else{
    					v.insert(v.begin()+tmp,s2);
    					tmp++;
    				}
    			}
    			y=tmp-1;
     
    		}else if(s1=="y"){
    			if(v.empty()){
    				buff="";
    			}else{
    				buff=v[y];
    			}
    		}else if(s1=="p"){
     
    			if(buff.size()==0){
    				x=v[y].size();
    				continue;
    			}
    			if(v.empty()){
    				v.push_back(buff);
    			}else{
    				v[y]+=buff;
    			}
    		x=v[y].size();
    		}else if(s1=="dy"){
    			if(y==n-1){
    				buff="";
    				buff=v[v.size()-1];
    				v.pop_back();
    				y--;
    				if(y==-1){
    					y++;
    				}
    			}else{
    				if(v.size()>0){
    					buff=v[y];
    					v.erase(v.begin()+y);
    				}else{
    					buff="";
    				}
    			}
    			if(!v.empty()){
    				x=v[y].size();
    			}else{
    				x=0,y=0;
    			}
    		}
    	}
    	for(auto x: v){
    		cout<<x<<endl;
    	}
    }
