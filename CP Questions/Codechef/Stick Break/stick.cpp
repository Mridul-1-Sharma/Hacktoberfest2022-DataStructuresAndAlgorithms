//Codechef LTIME 112 -DIVISION 4 - STICK BREAK
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t; // test case
	while(t--)
	{
	    int k,l;
	    cin>>l>>k; // input
	    if(l%k==0)
	    {
	        cout<<"0"<<"\n"; //output
	    }
	    else
	    {
	        cout<<"1"<<"\n"; //outout
	    }
	}
	return 0;
}
