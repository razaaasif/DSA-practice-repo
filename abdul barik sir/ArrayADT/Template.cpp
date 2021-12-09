#include<bits/stdc++.h>
using namespace std;
class Array{
	private :
			int *A;
			int size;
			int length;
	public :
			Array(){
				size = 10;
				A = new int[size];
				length=0;
			}

			Array(int size){
				this->size= size;
				length =0;
				A= new int[this->size];
			}

			~Array(){
				delete []A;
			}


			void Display();

			void input(int bLength);
			void insert(int index,int val);
			int Delete(int index);
			int BinarySearch(int k);
			int RBinarySearch(int k,int l,int h);
			void Reverse();
			void RReverse();
			void ReverseBySwap();
			void sortedInsert(int k);
			void negativeLeftSide();
			void mergerArray(int *B,int bLength);
			void unionSet(int p[],int bLength);
			void interseactionSet(int p[],int bLength);
			void differenceSet(int p[],int bLength);
			void findMissing();
			void findDuplicate();
};

int Array::RBinarySearch(int k,int l,int h){
    int mid=(l+h)/2;
    if(l<=h){
    	if(k==A[mid])
			return mid;
		else{
			if(k < A[mid])
				return RBinarySearch(k,l,mid-1);
			else
				return RBinarySearch(k,mid+1,h);

	}
    }
	

	return -1;
}

void Array::input(int bLength){
	int i;
	for(i=0;i<bLength;i++)
		cin>>A[i];
	length = i;

}
void Array::Display(){
		for(int i = 0; i<length;i++)
		cout<<A[i]<<" ";
		cout<<endl;
	}


void Array::insert (int index, int n){
	if(index <=0 || index < size){
		for(int i = length ; i>index; i--)
			A[i]=A[i-1];
		A[index]=n;
		length++;
	}
}


int Array::Delete(int index){
	int temp = A[index];
	for(int i=index;i<length-1;i++){
		A[i]=A[i+1];
	}

	length--;
	return temp;
}


int Array::BinarySearch(int k){
	int mid,l=0,h=length-1;

	while(l<=h){
		mid = (l+h)/2;
		if(k==A[mid])
			break;
		else{
			if(k<A[mid])
				h=mid-1;
			else
				l=mid+1;
		}
	}
	if(l>h)
		return -1;


	return mid;
}

void Array::Reverse(){
	int *B = new int[length];
	for(int i = length-1,j=0;i>=0;i--,j++)
		B[j]=A[i];
	for(int i = 0;i<length;i++)
		A[i]=B[i];
	delete []B;
}

void Array::RReverse(){
	static int i = length-1;
	static int *B = new int [length];
	static int j =0;
    int temp;
	if(i>=0){
		B[j++] = A[i--];
		RReverse();
		A[++i]=B[i];
	}

}

void Array::ReverseBySwap(){
	int temp;
	for(int i = 0,j=length-1;i<=j;i++,j--){
		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
}


void Array::sortedInsert(int val){
	int i = length-1;
	while(A[i]>val){
		A[i+1] = A[i];
		i--;
	}
	A[i+1]=val;
	length++;
}

void Array::negativeLeftSide(){
	int i = 0;
	int temp;
	int j = length -1;
	while(i<j){
		while(A[i]<0){i++;}
		while(A[j]>0){j--;}
		if(i<j)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;

		}

	}
}

void Array::mergerArray(int p[],int bLength){
	int *C = new int[length + bLength];
	int k,i,j;
	i=j=k=0;
	while(i < length && j < bLength)
	{
		if(A[i]<p[j])
			C[k++] = A[i++];
		else
			C[k++] = p[j++];
	}


	for(;j<bLength;)
		C[k++] =p[j++];
	for(;i<length;)
		C[k++]  = A[i++];


	delete []A;
	A=C;
	length = length+bLength;
}

void Array::unionSet(int p[],int bLength){
	int *C =new int[length+bLength];
	int i =0,j=0,k=0;
	while(i<length && j<bLength){
		if(A[i]<p[j])
			C[k++]=A[i++];
		else
			if(A[i]>p[j])
				C[k++]=p[j++];
			else{
				C[k++]=A[i++];
				j++;
			}
	}

	for(;i<length;)
		C[k++]=A[i++];
	for(;j<bLength;)
		C[k++]=p[j++];

	delete []A;
	A=C;
	length = length+bLength;
}

void Array::interseactionSet(int p[],int bLength){
	int *C =new int[length];
	int i =0,j=0,k=0;
	while(i<length && j<bLength){
		if(A[i]<p[j])
			i++;
		else
			if(A[i]>p[j])
				j++;
			else{
				if(A[i]==p[j])
				{
					C[k++]=A[i++];
					j++;
				}

			}
	}

	
	delete []A;
	A=C;
	length=k;
}


void Array::differenceSet(int p[],int bLength){
	int *C =new int[length];
	int i =0,j=0,k=0;
	while(i<length && j<bLength){
		if(A[i]<p[j])
			C[k++]=A[i++];
		else{
			if(A[i]>p[j])
				j++;
			else{
			i++;j++;
		}

		}
		
			}

	for(;i<length;)
		C[k++]=A[i++];

	
	delete []A;
	A=C;
	length=k;
}

void Array::findMissing(){
	// int diff = A[0]-0;
	// for(int i =0;i<length;i++){
	// 	if(A[i]-i != diff){
	// 		while(diff<A[i]-i){
	// 			cout<<(i+diff)<<" ";
	// 			diff++;
	// 		}
	// 	} 
	// }
	int j=0;
	for (int i = A[0]; i < A[length-1]; i++){
		if (i == A[j])
			j++;
		else
			cout << i << endl;
	}
}

void Array::findDuplicate(){
	for(int i =0;i<length-1;i++){
		if(A[i] == A[i+1]){
			int j = i+1;
			while(A[j] == A[i])j++;
			printf("%d is %d times \n",A[i],j-i );
			i=j-1;
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Array arr;
	int length ;
	cin >> length;
	arr.input(length);
	// int bLength ;
	// cin >>bLength;
	// int B[] = {2,4,5,7,12};
	// arr.Display();
	// arr.unionSet(B,5);
	// arr.Display();
	// 
	// arr.differenceSet(B,5);
	// arr.Display();
	arr.findDuplicate();

	return 0;
	
}