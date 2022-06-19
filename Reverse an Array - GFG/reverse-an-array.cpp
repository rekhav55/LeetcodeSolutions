#include <iostream>
using namespace std;

void func(int a[], int n){
    for(int i=0,j=n-1;i<j;i++,j--)
        swap(a[i], a[j]);
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    
	    func(a,n);
	    
	    for(int i=0;i<n;i++)
	        cout<<a[i]<<" ";
	    cout<<endl;   // this line was really necessary
	}
	return 0;
}