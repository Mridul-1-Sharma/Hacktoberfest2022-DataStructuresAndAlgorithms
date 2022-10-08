// Codechef - LTIME112D -Permutation Creation(PERMCREATE)

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;  //TEST CASES
	cin>>t; 
	while(t--)
	{
	    int n;
	    cin>>n; // INPUT
	    if(n==2 || n==3)
	    {
	        cout<<"-1";
	    }
	    else if(n==4){
	        cout << "3 1 4 2";
	    }
        // CREATING PERMUTATION
	    else if(n%2==0)
	    {
	        int j=(n/2)+1;
	        for(int i=1;i<=n/2;i++)
	        {
	            cout<<i<<" "<<j<<" ";
	            j++;
	        }
	    }
	    else
	    {
	        int j=((n+1)/2)+1;
	        for(int i=1;i<=(n-1)/2;i++)
	        {
	            cout<<i<<" "<<j<<" ";
	            j++;
	        }
	        cout<<(n+1)/2;
	    }
	    cout<<"\n";
	}
	return 0;
}
