//Direct Acccess File
#include<iostream>
#include<fstream>
#include<iomanip>
#define MAX 100
using namespace std;
class Student
{
	char name[30];
	char address[30];
	int roll;
	int div;
	public:
		friend class hash;
		friend class File;
		Student()
		{
			cin.ignore(1);
			name[0] = '\0';
			address[0] = '\0';
			roll = 0;
			div = 0;
		}
		void scan()
		{
			cout<<"Enter the Name of Student: "<<endl;
			cin.getline(name,30);
			cout<<"Enter the Address of Student: "<<endl;
			cin.getline(address,30);
			cout<<"Enter the Roll No. of Student: "<<endl;
			cin>>roll;
			cout<<"Enter the Division of Student: "<<endl;
			cin>>div;
			
		}
		void print()
		{
			cout<<"Name     : "<<name<<endl;
			cout<<"Address  : "<<address<<endl;
			cout<<"Roll no. : "<<roll<<endl;
			cout<<"Division : "<<div<<endl;
			
		}
		
};
class hash
{
	int rno[MAX];
	int loc[MAX];
	public:
		hash()
		{
			int i;
			for(i=0;i<MAX;i++)
			{
				rno[i] = -1;
				loc[i] = -1;
				
			}
			
		}
		int hashcode(int r)
		{
			return r%MAX;
		}
		void insert(int r,int l)
		{
			int key = hashcode(r);
			if(rno[key] == -1)
			{
				rno[key] = r;
				loc[key] = l;
				
			}
			else
			{
				//linear pro
				if((rno[key]%MAX) != key)
				{
					int temp;
					temp = rno[key];
					rno[key] = r;
					r = temp;
					
					temp = loc[key];
					loc[key] = l;
					l = temp;
					
				}
				int i = (key + 1)%MAX;
				while(rno[i] != -1)
				{
					if(key == i)
					{
						cout<<"Full";
						return;
					}
					i = (i+1)%MAX;
				}
				rno[i] = r;
				loc[i] = l;
			}
			
		}
		
		int search(int r)
		{
			int key = hashcode(r);
			if(rno[key] == r)
			{
				cout<<"Present "<<endl;
				return loc[key];
			}
			else
			{
				int i = (key+1);
				while(rno[i]!=r)
				{
					if(i == key)
					{
						cout<<"\nNot Found"<<endl;
						return -1;
					}
					i = (i+1)%MAX;
				}
				return loc[i];
			}
			
		}
		void display()
		{
			cout<<"\nHash Table: "<<endl;
			for(int i=0;i<MAX;i++)
			{
				cout<<"\nRoll no of "<<i<<" is "<<rno[i]<<setw(40)<<" Location of "<<i<<" = "<<loc[i];
				
			}
		}
		void delete_(int r)
		{
			int key = hashcode(r);
			if(rno[key] == r)
			{
				rno[key] = -1;
				loc[key] = -1;
				
			}
			else
			{
				int i = (key + 1)%MAX;
				while(rno[key] != r)
				{
					if(i == key)
					{
						cout<<"Not Present"<<endl;
						return;
					}
					i = (i+1)%MAX;
				}
				rno[key] = -1;
				loc[key] = -1;
			}
			
			
		}
		friend class File;
};
class File
{

	public:
		void add_student(hash &h)
		{
			fstream fout("D://second year//ADSA PRACTICAL//student.txt",ios::app|ios::binary);
			if(fout.fail())
			{
				cout<<"File is not Connected " <<endl;
				
			}
			cout<<"File is Connected"<<endl;
			Student s;
			s.scan();
			fout.seekg(0,ios::end);
			h.insert(s.roll,fout.tellg());
			fout.write((char *)(&s),sizeof(s));
			fout.close(); 
				
		}	
		void display_student(hash &h)
		{
			fstream fin("D://second year//ADSA PRACTICAL//student.txt",ios::in|ios::binary);
			if(fin.fail())
			{
				cout<<"\nFile not Connected";
				return;
			}
			cout<<"\nFile is connected ";
			Student s;
			while(fin.read((char * )&s,sizeof(s)))
			{
				s.print();
			}
			char ch;
			cout<<"Do you want to Display Hashtable : "<<endl;
			cin>>ch;
			if(ch == 'y')
			{
				h.display();
			}
			fin.close();
		}
		
		void search_student(int roll,hash &h)
		{
			fstream fin("D://second year//ADSA PRACTICAL//student.txt",ios::in|ios::binary);
			 if(fin.fail())
        {
            cout<<"\nFile not connected";
            return;
        }
        int l = h.search(roll);
        Student s;
        if(l!=-1)
        {
        	fin.seekg(l,ios::beg);
		  	fin.read((char *)&s,sizeof(s));
		  	s.print();
		  	
		  	
		  }
		  else
		  {
		  	cout<<"\nStudent not Found ";
		  	
		  }
		  fin.close();
		}
		void delete_student(int r,hash &h)
		{
			fstream fin("D:second year//ADSA PRACTICAL//student.txt",ios::in|ios::binary);
			 if(fin.fail())
        {
            cout<<"\nfile not connected";
            return;
        }
        fstream fout("D:second year//ADSA PRACTICAL//student_copy.txt",ios::binary|ios::out|ios::app);
			if(fout.fail())
        {
            cout<<"\nfile not connected";
            return;
        }
        Student s;
        int l=h.search(r);
        if(l==-1)
        {
            cout<<"\nstudent with roll no "<<r<<" not present";
        }
        while(fin.read((char*)&s,sizeof(s)))
        {
            if(s.roll==r)
            {
                h.delete_(r);
                cout<<"student deleted successfully";
                continue;
            }
            fout.write((char*)&s,sizeof(s));
            
        }
        fin.close();
        fout.close();
        remove("D:second year//ADSA PRACTICAL//student.txt");
        rename("D:second year//ADSA PRACTICAL//student_copy.txt","D:second year//ADSA PRACTICAL//student.txt");


		}
};

int main()
{
    hash h;
    Student s;
    File f;
    int rno;
    int choice;
    while(1)
    {
        cout<<"\nenter choice from user\n1:insertion\n2:display\n3:search\n4:delete\n5:exit";
        cin>>choice;
        switch(choice)
        {
            case 1:
                f.add_student(h);
                break;
            case 2:
                
                f.display_student(h);   
                break;
            case 3:    cout<<"\nenter roll no to search record";
                     cin>>rno;
                     f.search_student(rno,h);
                     break;
            case 4:cout<<"\nenter roll no to delete record";
                    cin>>rno;       
                    f.delete_student(rno,h);
                    break;
            case 5: exit(0);        





        }


    }
    


    return 0;
}
