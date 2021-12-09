#include<bits/stdc++.h>
using namespace std;

double exp(int x, int n){
	static double f=1,p=1;
	if(n==0)
		return 1;
	else{
		double r = exp(x,n-1);
		p=p*x;
		f=f*n;
		return r+p/f;
	}
}
 
double eHomers(int x,int n){
	double S=1;
	for(; n>0; n--){
		S=1+x*S/n;
	}
	return S;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n , m;
	cin >> n >> m;
	cout << exp(n, m);
	cout<<endl<<eHomers(n,m);

}