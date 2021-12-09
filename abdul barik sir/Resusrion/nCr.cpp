#include<iostream>
using namespace std;


int fact(int n){
	if(n==0 || n==1)
		return 1;
	else
		return n*fact(n-1);

}

	int nCr(int n,int r){
	int t1= fact(n);
	int t2 = fact(r);
	int t3 = fact(n-r);

	return t1/(t2*t3);
}

int pasacal(int n ,int r){
	if(r==0||n==r)
		return 1;
	else
		return pasacal(n-1,r-1)+pasacal(n-1,r);
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >>n>> m;
	cout << nCr(n,m)<<endl;
	cout << pasacal(n,m);

}