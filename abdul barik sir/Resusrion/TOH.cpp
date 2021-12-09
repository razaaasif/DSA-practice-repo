#include<bits/stdc++.h>
using namespace std;

int TOH(int disk,int a ,int b , int c){
	if(disk>0){
		TOH(disk-1,a,c,b);
		printf("(%d,%d)\n",a,c);
		TOH(disk-1,b,a,c);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout<<TOH(3,1,2,3);
}