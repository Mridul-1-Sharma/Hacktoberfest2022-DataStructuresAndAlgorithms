#include<iostream>
#define max 5
using namespace std;

class sort
{
	public:
		int population[max];
		string town[max];
		int low,high;
		
		sort()
		{
			low = 0;
			high = max-1;
			
		}
		
		void get_data();
		void quick_sort(int low,int high);
		int partition(int low,int high);
		void insersion_sort();
		void display();
		
};

void sort::get_data()
{
	for(int i=0;i<max;i++)
	{
		cout<<"Enter town name : ";
		cin>>town[i];
		cout<<"Enter population of town : ";
		cin>>population[i];
		cout<<"\n\n";
		
	}
	
}

void sort::display()
{
	cout<<"\nTown\tPopulation\n";
	cout<<"\n______________________\n\n";
	for(int i=0;i<max;i++)
	{
		cout<<town[i]<<"\t"<<population[i]<<"\n";
		
	}
}

void sort::insersion_sort()
{
	for(int i=1;i<max;i++)
	{
		int temp = population[i];
		string store = town[i];
		int j = i-1;
		
		while(j>=0 && population[j]>temp)
		{
			population[j+1] = population[j];
			
			town[j+1] = town[j];
			
			j--;
			
		}
		
		population[j+1] = temp;
		town[j+1] = store;
		
	}
	
}

void sort::quick_sort(int low,int high)
{
	if(low>high)
    {
        return;
    }
    
    int pivot=partition(low,high);
    quick_sort(low,pivot-1);
    quick_sort(pivot+1,high);
	
	
}

int sort::partition(int low,int high)
{
	int pivot = population[low];
	
	int i = low;
	int j = high;
	
	while(i<j)
	{
		while(population[i]<=pivot)
		{
			i++;
			
		}
		
	    while(population[j]>pivot)
	    {
	 	    j--;
		
	    }
	
	    if(i<j)
	    {
		    int temp = population[i];
		    population[i] = population[j];
		    population[j] = temp;
		    
		    string store = town[i];
		    town[i] = town[j];
		    town[j] = store;
		
	    }
	    
	}
	
	int t = population[j];
	population[j] = population[low];
	population[low] = t;
	
	
	
	string store = town[i];
	town[i] = town[j];
	town[j] = store;
	
	return j;
	
}


int main()
{
	sort s;
	int choice,start=1;
	
	while(start==1)
	{
		cout<<"\n------------------- Sorting of Population -------------------\n\n";
		cout<<"1)Insertion sort \n2)Quick sort \n\n";
		cout<<"Enter your choice your option : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				s.get_data();
				s.insersion_sort();
				s.display();
				break;
				
			case 2:
				s.get_data();
				s.partition(0,4);
				s.quick_sort(0,4);
		        s.display();
				break;
				
			default:
				cout<<"You have entered wrong choice !!!\n\n ";
				
		}
		cout<<"Press 1 to again sort : ";
		cin>>start;
		
	}

	
	return 0;
	
}
