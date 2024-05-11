/*Implement the Heap sort algorithm for demonstrating heap data structure with modularity 
of programming language (consider integer data)*/

#include<iostream>
using namespace std;

class Heap
{
	int* heap;
	int size;
	
	public:
		Heap()
		{
			cout<<"\nEnter the total number of elements : ";
			cin>>size;
			heap=new int[size+1];
			for(int i=1;i<=size;i++)
			{
				heap[i]=0;
			}
			heap[0]=size;
		}
		
		void showHeap()
		{
			cout<<"\nHeap : ";
			for(int i=1;i<=size;i++)
			{
				cout<<heap[i]<<" ";
			}
		}
		
		void createHeap()
		{
			for(int i=1;i<=size;i++)
			{
				cout<<"\n\nEnter element of heap : ";
				cin>>heap[i];
				upadjust(i);
				cout<<"\nAfter entering "<<heap[i]<<", heap : ";
				showHeap();
			}
		}
		
		
		void upadjust(int i)
		{
			while(i/2>=1)
			{
				if(heap[i]>heap[i/2])
				{
					int temp=heap[i];
					heap[i]=heap[i/2];
					heap[i/2]=temp;
					i=i/2;
				}
				else
				{
					break;
				}
			}
		}
		
		void create()
		{
			for(int i=1;i<=size;i++)
			{
				cout<<"\nEnter element of heap : ";
				cin>>heap[i];
			}
			
			for(int i=heap[0]/2;i>=1;i--)
			{
				downadjust(i);
			}
		}
		
		void heapSort()
		{
			while(heap[0]>1)
			{
				int last=heap[0];
				int temp=heap[1];
				heap[1]=heap[last];
				heap[last]=temp;
				heap[0]--;
				downadjust(1);
			}
			heap[0]=size;
		}
		
		void downadjust(int i)
		{
			int n=heap[0];
			while(2*i<=n)
			{
				int j=2*i;
				if(j+1<=n)
				{
					if(heap[j+1]>heap[j])
					{
						j=j+1;
					}
				}
				
				if(heap[i]<heap[j])
				{
					int temp=heap[i];
					heap[i]=heap[j];
					heap[j]=temp;
					i=j;
				}
				else
				{
					break;
				}
			}
		}
		
		
		//////////////////////////////////////////
		void createHeap_min()
		{
			for(int i=1;i<=size;i++)
			{
				cout<<"\n\nEnter element of heap : ";
				cin>>heap[i];
				upadjust_min(i);
				cout<<"\nAfter entering "<<heap[i]<<", heap : ";
				showHeap();
			}
		}		
		
		void upadjust_min(int i)
		{
			while(i/2>=1)
			{
				if(heap[i]<heap[i/2])
				{
					int temp=heap[i];
					heap[i]=heap[i/2];
					heap[i/2]=temp;
					i=i/2;
				}
				else
				{
					break;
				}
			}
		}
		
		void create_min()
		{
			for(int i=1;i<=size;i++)
			{
				cout<<"\nEnter element of heap : ";
				cin>>heap[i];
			}
			
			for(int i=heap[0]/2;i>=1;i--)
			{
				downadjust_min(i);
			}
		}		
		
		void downadjust_min(int i)
		{
			int n=heap[0];
			while(2*i<=n)
			{
				int j=2*i;
				if(j+1<=n)
				{
					if(heap[j+1]<heap[j])
					{
						j=j+1;
					}
				}
				
				if(heap[i]>heap[j])
				{
					int temp=heap[i];
					heap[i]=heap[j];
					heap[j]=temp;
					i=j;
				}
				else
				{
					break;
				}
			}
		}
		
		void heapSort_min()
		{
			while(heap[0]>1)
			{
				int last=heap[0];
				int temp=heap[1];
				heap[1]=heap[last];
				heap[last]=temp;
				heap[0]--;
				downadjust_min(1);
			}
			heap[0]=size;
		}				
};

int main()
{
	Heap h1;
	h1.createHeap();  //one by one
	h1.heapSort();	
	h1.showHeap();
	
	Heap h2;
	h2.create();         //input once
	h2.heapSort();
	h2.showHeap();
	
	Heap h3;
	h3.createHeap_min();  //one by one
	h3.heapSort_min();	
	h3.showHeap();
	
	Heap h4;
	h4.create_min();         //input once
	h4.heapSort_min();
	h4.showHeap();
	return 0;
}
/*#include<iostream>
using namespace std;

class Heap 
{
    int * data;
    int size;
public:
    Heap() 
	 {
        cout<<"Enter the No. of Elements of your Array: "<<endl;
        cin>>size;
        
        data = new int[size+1];
        for(int i=1; i<=size; i++) 
		  { 
            data[i] = 0;
        }
        data[0] = size;
    }
    
    void show() 
	 {
        for(int i=1; i<=size; i++) 
		  { 
            cout<<data[i]<<" ";
        }
    }
    
    void create() 
	 {
        for(int i=1; i<=size; i++) 
		  { 
            cout<<"\nEnter element of heap : ";
            cin>>data[i];
        }
        
        for(int i=size/2; i>=1; i--) 
		  { 
            downadjust(i);
        }
    }
    
    void downadjust(int i) 
	 {
        int n = data[0];
        while(2*i <= n) 
		  { 
            int j = 2*i;
            if(j+1 <= n && data[j+1] < data[j]) 
				{ 
                j = j+1;
            }
            if(data[i] > data[j])
				{
                swap(data[i], data[j]);
                i = j;
            }
            else 
				{
                break;
            }
        }
    }
    
    void sort() 
	 {
        while(data[0] > 1) 
		  {
            int last = data[0];
            swap(data[1], data[last]);
            data[0]--;
            downadjust(1);
        }
        data[0] = size;
    }
};

int main() 
{
    Heap obj;
    obj.create();
    cout<<"Before Sort: "<<endl;
    obj.show();
    obj.sort();
    cout<<"\n\nAfter sort: ";
    obj.show();
    
    return 0;
}
*/

