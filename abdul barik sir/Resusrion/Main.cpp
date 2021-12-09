#include<bits/stdc++.h>
using namespace std;

int pow(int n , int m){
	if(m==0)
	return 1;
	
	if(m % 2 == 0)
		return pow(n*n,m/2);
	else
		return n*pow(n*n,(m-1)/2);
	}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n , m;
	cin >> n >> m;
	cout << pow(n, m);

}