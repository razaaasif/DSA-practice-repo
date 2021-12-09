#include<bits/stdc++.h>
using namespace std;

int fib(int n){
	if(n<=1){
		return n;
	}
	else{
		return fib(n-2)+fib(n-1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int  m;
	cin >> m;
	cout << fib(m);

}