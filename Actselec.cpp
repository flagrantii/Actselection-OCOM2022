#include<bits/stdc++.h>
using namespace std;

struct sinka
{
	double v;
	double w;
	double vw;
};

bool cmp(sinka a,sinka b){
    return a.vw>b.vw;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int s,bp;
		double sumw=0,sumv=0;
		cin>>s>>bp;
		sinka b[s];
		for(int i=0;i<s;i++){
			cin>>b[i].v>>b[i].w;
			b[i].vw=b[i].v/b[i].w;
		}
		sort(b,b+s,cmp);
		for(int i=0;i<s;i++){
			if(sumw<bp){
				if(sumw+b[i].w<=bp){
					sumv+=b[i].v;
					sumw+=b[i].w;
				}else if(sumw+b[i].w>bp){
					sumv+=b[i].v*(bp-sumw)/b[i].w;
					sumw=bp;
				}
			}
		}
		cout<<fixed<<setprecision(2)<<sumv<<"\n";
	}	
	return 0;
}

