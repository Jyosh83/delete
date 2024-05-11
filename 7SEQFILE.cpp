#include<fstream>
#include<iostream>
using namespace std;
class Student
{
	char name[30];
	char address[30];
	int div,rno;
	public:
		Student()
		{
			name[0] = '\0';
			address[0] = '\0';
			div = 0;
			rno = 0;
		}
		void scandata()
		{
			cin.ignore(1);
			cout<<"Enter Name of The Student: "<<endl;
			cin.getline(name,30);
			
			cout<<"Enter the Address of the Student: "<<endl;
			cin.getline(address,30);
			
			cout<<"Enter the Div of Student: "<<endl;
			cin>>div;
			
			cin.ignore(1);
			cout<<"Enter the Roll No. of Student:- "<<endl;
			cin>>rno;
			
		}
		void printdata()
		{
			cout<<"Name of Student ->  "<<name<<endl;
			cout<<"Roll No. :- "<<rno<<endl;
			cout<<"Div : -  "<<div<<endl;
			cout<<"Address :- "<<address<<endl;
		}
	friend class file;
};
class file
{
	public:
		
			void addstudent()
			{
				ofstream fout("D:\\second year\\ADSA PRACTICAL\\student.txt",ios::binary|ios::app);
				if(fout.fail())
				{
					cout<<"Not Connected "<<endl;
					return;
				}
				cout<<"Connected "<<endl;
				Student s;
				s.scandata();
				fout.write((char *)(&s),sizeof(s));
				fout.close();
			}
			void display_student(int rno)
			{
				ifstream fin("D:\\second year\\ADSA PRACTICAL\\student.txt",ios::binary);
				if(fin.fail())
				{
					cout<<"\nFile is Not Connected "<<endl;
					return;
				}
				cout<<"\nFile is Connected "<<endl;
				Student s;
				bool found = false;
				while(fin.read((char *)(&s),sizeof(s)))
				{
					if(s.rno == rno)
					{
						s.printdata();
						found = true;
					}
				}
				if(found == false)
				{
					cout<<"\nStudent is not Found "<<rno<<" with this roll no. "<<endl;
					
				}
			
			}
			void deleteStudent(int rno)
			{
				ifstream fin("D:\\second year\\ADSA PRACTICAL\\student.txt",ios::binary);
				if(fin.fail())
				{
					cout<<"NOT CONNECTED  error in opening the file"<<endl;
					return;
				}
				ofstream fout("D:\\second year\\ADSA PRACTICAL\\temp.txt",ios::binary|ios::app);
				if(fout.fail())
				{
					cout<<"NOT CONNECTED  error in opening the file"<<endl;
					return;
				}
				bool found = false;
				Student s;
				while(fin.read((char *)(&s),sizeof(s)))
				{
				
					if(s.rno == rno)
					{
						found = true;
						continue;
					}
					fout.write((char *)(&s),sizeof(s));
							
				}
				fin.close();
				fout.close();
				
				remove("D:\\second year\\ADSA PRACTICAL\\student.txt");
				rename("D:\\second year\\ADSA PRACTICAL\\temp.txt","D:\\second year\\ADSA PRACTICAL\\student.txt");
				if(found)
				{
					cout<<"Student is Successfully removed from the Data "<<endl;
					
				}
				else
				{
					cout<<"Student is not Present with that roll no in your data "<<" : "<<rno<<endl;
				}
				fin.close();
				fout.close();		
			}
		
};

int main()
{
	int choice;
	int rno;
	file obj;
	do
	{
		cout<<"\n1}Add Student \n2}Display Student \n3}Delete Student \n4}Exit \nEnter Your Choice: "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				obj.addstudent();
				break;
				
			case 2:
					cout<<"Enter the Roll Number: "<<endl;
					cin>>rno;
					obj.display_student(rno);
					break;
		
			case 3:
				cout<<"Enter the Roll Number of Student you want to Delete from Your File: "<<endl;
				cin>>rno;
				obj.deleteStudent(rno);
				break;
			case 4:
				cout<<":::::Exiting:::::"<<endl;
				break;
			default:
         		cout << "Invalid choice! Please try again." << endl;
			
			
		}	
	}while(choice!=4);
return 0;
}

