// Codechef staters 58 -Division 4 - Break The Element(ArrayBreak)
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t; // number of test case
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n; // size of input
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i]; // input of array
	    }
	    int even=0;
	    int odd=0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]%2==0)
	        {
	            even++; //checking number of even numbers
	        }
	        else
	        {
	            odd++; // checking number of odd numbers
	        }
	    }
        //number of element that need to be remove
	    if(even==0 || odd==0)
	    {
	        cout<<"0"<<"\n";
	    }
	    else
	    {
	        cout<<even<<"\n";
	        }
	    
	    
	}
	return 0;
}