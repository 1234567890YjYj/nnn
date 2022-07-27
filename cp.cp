prog1
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

class rev
{
	private:char a[10][20];
	public : void std_io();
	public : void file_io();
};

void rev::std_io()
{
	int n;
	cout<<"Enter number of names: ";
	cin>>n;
	cout<<"Enter names: ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++)
	{
		string s1 = a[i];
		reverse(s1.begin(),s1.end());
		cout<<s1<<endl;
	}
}


void rev::file_io()
{
	char ch;
	char ip[20],op[20];
	string stri;
	fstream fp1,fp2;
	cout<<"Enter source file: ";
	cin>>ip;
	cout<<"Enter dest file: ";
	cin>>op;
	
	fp1.open(ip,ios::in);
	fp2.open(op,ios::out);
	fp1.unsetf(ios::skipws);
	
	while(1)
	{
		if(fp1.fail())
			break;
		getline(fp1,stri);
		reverse(stri.begin(),stri.end());
		cout<<stri<<endl;
		fp2<<stri;
	}
}
int main()
{
	rev s1;
	//s1.std_io();
	int t=1;
	while(t)
	{
		cout<<"1. Read from keyboard \n2. Read from file \n3. Exit \nEnter your choice"<<endl;
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1: s1.std_io();
				break;
			case 2: s1.file_io();
				break;
			case 3: t =0;
				break;
			default: cout<<"Please enter a valid input: ";
		}
	}
}
==========================================================================================================
prog2
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
class student
{
	private:char name[20],sem[5],branch[5],buffer[45];
	public: void read()
		{
			cout<<"Enter the name\n";
			cin>>name;
			cout<<"Enter the sem\n";
			cin>>sem;
			cout<<"Enter the branch\n";
			cin>>branch;
		}
		void pack(fstream &ofile)
		{
			read();
			strcpy(buffer,name);
			strcat(buffer, "|");
			strcat(buffer,sem);
			strcat(buffer, "|");
			strcat(buffer,branch);
			strcat(buffer, "|");
			while(strlen(buffer)<45)
				strcat(buffer,"!");
			cout<<buffer<<endl;
			strcat(buffer, "\n");
			ofile<<buffer;
		}
		void unpack(fstream &ifile)
		{	
			char extra[45];
			while(!ifile.eof())
			{
				ifile.getline(name, 10, '|');
				ifile.getline(sem, 10, '|');
				ifile.getline(branch, 10, '|');
				ifile.getline(extra, 45, '\n');
				cout<<name<<" "<<sem<<" "<<branch<<endl;
			}
		}
		int search(fstream &ifile, char key[20])
		{
		 	char extra[45];
			while(!ifile.eof())
				{
					ifile.getline(name, 10, '|');
					ifile.getline(sem, 10, '|');
					ifile.getline(branch, 10, '|');
					ifile.getline(extra, 45, '\n');
					if(strcmp(name, key) == 0)
					{
						cout<<"-----Record found-----";
						return 1;
					}
				}
				return 0;
		}
		void modify(fstream &iofile, char key[20])
		{
			if(search(iofile,key))
			{
				cout<<"Enter modification details"<<endl;
				iofile.seekp(-46, ios::cur);
				pack(iofile);
			}
			else
				cout<<"Record not found";	
		}
};

int main()
{
	fstream ofile, ifile;
	int noofstudents, ch;
	char key[20];
	student s1;
	while(1)
	{
		cout<<"\n1.Pack\n2.Unpack\n3.Search\n4.Modify\n5.Exit\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: ofile.open("pro2_OP_file.txt",ios::out|ios::app);
				cout<<"How many students you want to enter ? ";
				cin>>noofstudents; 
				while(noofstudents--)
					s1.pack(ofile);
				ofile.close();
				break;
				
			case 2: ifile.open("pro2_OP_file.txt",ios::in);
				s1.unpack(ifile);
				ifile.close();
				break;
				
			case 3: ifile.open("pro2_OP_file.txt",ios::in);
				cout<<"Enter the name to search: ";
				cin>>key;
				if(s1.search(ifile, key) == 0)
					cout<<"-----Record not found-----"<<endl;
				break;
			
			case 4: ifile.open("pro2_OP_file.txt",ios::in|ios::out);
				cout<<"Enter the key(name) to modify: ";
				cin>>key;
				s1.modify(ifile, key);
				ifile.close();
				break;
							
			case 5:exit(0);
			
			default:cout<<"Invalid choice";
			
		}
	}	
}
=============================================================================================================
prog3
#include<iostream>
#include<fstream>
#include"string.h"
using namespace std;

class Student
{
	private: char name[20], sem[10], branch[10],buf[45];
	public: void read()
		{
			cout<<"Enter name, sem & branch"<<endl;
			cin>>name>>sem>>branch;
		}
		void pack(fstream &ofile)
		{
			read();
			strcpy(buf,"");
			strcat(buf,name);
			strcat(buf,"|");
			strcat(buf,sem);
			strcat(buf,"|");
			strcat(buf,branch);
			strcat(buf,"|");
			strcat(buf,"\n");
			ofile.write(buf,strlen(buf));
		}
		void unpack(fstream &ifile)
		{	
			char extra[45];
			while(!ifile.eof())
			{
				ifile.getline(name, 10, '|');
				ifile.getline(sem, 10, '|');
				ifile.getline(branch, 10, '|');
				ifile.getline(extra, 45, '\n');
				cout<<name<<" "<<sem<<" "<<branch<<endl;
			}
		}
		int search(fstream &ifile,char key[])
		{
			char extra[45];
			while(!ifile.eof())
			{
				ifile.getline(name,10,'|');
				ifile.getline(sem,10,'|');
				ifile.getline(branch,10,'|');
				ifile.getline(extra,45,'\n');
				
				if(strcmp(name,key)==0)
				{
					cout<<"Record found, details are: "<<endl;
					cout<<name<<" "<<sem<<" "<<branch<<endl;
					return 1;
				}
			}
			return 0;
		}
		void modify(fstream &ifile, char key[])
		{
			Student s2[10];
			char extra[20];
			int i=0;
			while(ifile.eof())
			{
				ifile.getline(s2[i].name,10,'|');
				ifile.getline(s2[i].sem,10,'|');
				ifile.getline(s2[i].branch,10,'|');
				ifile.getline(extra,20,'\n');
				i++;
			}
			ifile.close();
			int flag=0;
			
			for(int j=0;j<i;j++)
			{
				if(strcmp(s2[j].name,key)==0)
				{
					flag=1;
					cout<<"Found, Enter modification details"<<endl;
					cin>>s2[j].name>>s2[j].sem>>s2[j].branch;				
				}
			}
			if(flag==0)
			{
				cout<<"Record not found"<<endl;
				return;
			}
			ifile.open("lab3.txt",ios::trunc|ios::app);
			for(int k=0;k<i;k++)
			{
				strcpy(buf,"");
				strcat(buf,s2[k].name);
				strcat(buf,"|");
				strcat(buf,s2[k].sem);
				strcat(buf,"|");
				strcat(buf,s2[k].branch);
				strcat(buf,"|");
				strcat(buf,"\n");
				ifile.write(buf,strlen(buf));
			}
		}
				
};

int main()
{
	Student s1;
	char key[10];
	fstream f1,f2,f3,f4;
	int ch;
	while(1)
	{
		cout<<"1.Pack\n2.Unpack\n3.Search\n4.Modify\n5.Exit\n\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: f1.open("lab3.txt",ios::out|ios::app);
				s1.pack(f1);
				f1.close();
				break;
			case 2: f2.open("lab3.txt",ios::in);
				s1.unpack(f2);
				f2.close();
				break;
			case 3: f3.open("lab3.txt",ios::in);
				cout<<"Enter the key to search the record"<<endl;
				cin>>key;
				if(s1.search(f3,key)==0)
				{
					cout<<"Record not found"<<endl;
				}
				break;
			case 4: f4.open("lab3.txt",ios::in|ios::out);
				cout<<"enter the record name to be modified\n"<<endl;
				cin>>key;
				s1.modify(f4,key);
				f4.close();
				break;
			case 5: exit(0);
			default:cout<<"Invalid input"<<endl;
		}
	}
}
=========================================================================================================
prog4
#include<iostream>

#include<stdlib.h>

#include<string.h>

#include<fstream>

using namespace std;

class student

{

private:

    char buf[40], name[10], sem[10], branch[10], extra[40];

    

public:

    void read()

    {

    	//cout << "RRN: " << endl;

        //cin >> rrn;

        cout << "Name: " << endl;

        cin >> name;

        cout << "Semester: " << endl;

        cin >> sem;

        cout << "Branch: " << endl;

        cin >> branch;

    }



    void insert(fstream &ofile, char rrn[])

    {

        read();

        strcpy(buf, "");

        strcat(buf, rrn);

        strcat(buf, "|");

        strcat(buf, name);

        strcat(buf, "|");

        strcat(buf, sem);

        strcat(buf, "|");

        strcat(buf, branch);

        strcat(buf, "|");

        strcat(buf, "\n");

        ofile.write(buf, strlen(buf));

    }



    int search(fstream &ifile, char key[])

    {

        char rrn[10];

        while (!ifile.eof())

        {

            ifile.getline(rrn, 10, '|');

            ifile.getline(name, 10, '|');

            ifile.getline(sem, 10, '|');

            ifile.getline(branch, 10, '|');

            ifile.getline(extra, 40, '\n');

            if (strcmp(key, rrn) == 0)

            {

                cout << "Record found and details are:" << endl;

                cout << "Name: " <<name;

                cout << "\tSemester: " <<sem;

                cout << "\tBranch: " <<branch<<"\n";

                return 1;

            }

        }

        return 0;

    }

};



int main()

{

    int n, i, ch, k = 0;

    char key[10];

    student stu;

    fstream ofile, ifile;

    ofile.open("student2.txt", ios::trunc | ios::app);

    ofile.close();

   

    for (;;)

    {

        cout << "1.Insert\n2.Search\n3.Exit\n";

        cout << "Enter your choice: ";

        cin >> ch;

        switch (ch)

        {

        case 1:

            //fstream ofile;

            ofile.open("student2.txt", ios::out | ios::app);

            cout << "Enter the no. of students: ";

            cin >> n;

            for (i = 0; i < n; i++)

            {

                 k=sprintf(key, "%d" , ++k);

                //itoa(++k, key, 10);

                //std::string to_string(key);

                stu.insert(ofile, key);

            }

            ofile.close();

            break;

        case 2:

            cout << "Enter the RRN to search: ";

            cin >> key;

            //fstream ifile;

            ifile.open("student2.txt", ios::in);

            if (stu.search(ifile, key) == 0)

                cout << "Record not found\n";

            ifile.close();

            break;

        default:

            exit(0);

        }

    }

}
================================================================================================================
prog5
#include<iostream>

#include<string.h>

#include<fstream>

#include<stdlib.h>

using namespace std;

int n = 0;

int ind=0;

class student {

        public: char name[20], usn[20], branch[5];

        int sem;

        void insert(fstream & f1, fstream & f2) {

                cout << "Enter Name: ";

                cin >> name;

                cout << "Enter USN: ";

                cin >> usn;

                cout << "Enter Sem: ";

                cin >> sem;

                cout << "Enter Branch: ";

                cin >> branch;

                write(f1, f2);

        }



        void write(fstream & f1, fstream & f2) {

                f1 << ++ind << "\t" << usn << "\n";

                f2 << name << "\t" << usn << "\t" << sem << "\t" << branch << "\n";

        }



        void display(fstream & f2) {

                f2 >> name >> usn >> sem >> branch;

                cout << name << "\t" << usn << "\t" << sem << "\t" << branch << "\n";

        }



        int search(fstream & f1, char key[20]) {

                int i, x;

                for (i = 1; i <= n; i++) {

                        f1 >> x >> usn;

                        if (strcmp(usn, key) == 0)

                                return i;

                }

                cout << "Record not found\n";



                return 0;

        }



        int remove(fstream & f1, char key[20]) {

        	int i;

		i = search(f1, key);

		return i;

        }

};



int main()

{

        fstream f1, f2;

        student s[20], p;

        int ch, k = 0, i,j;

        char usn[20];

        //clrscr();

        f1.open("m1.txt", ios::trunc);

        f2.open("mn1.txt", ios::trunc);

        f1.close();

        f2.close();

        for (;;) {

                cout << "1.Insert 2.Display 3.Search 4.Delete 5.Exit\n";

                cout << "Enter choice: ";

                cin >> ch;

                switch (ch) {

                case 1:

                        f1.open("m1.txt", ios::app);

                        f2.open("mn1.txt", ios::app);

                        cout << "Enter no. of students: ";

                        cin >> k;

                        n = n + k;

                        for ( i = 1; i <= k; i++) s[i].insert(f1, f2);

                        f1.close();

                        f2.close();

                        break;

                case 2:

                        f2.open("mn1.txt", ios:: in );

                        for (i = 1; i <= n; i++)

                                s[i].display(f2);

                        f2.close();

                        break;

                case 3:

                        

                        cout << "Enter USN to search: ";

                        cin >> usn;

                        f1.open("m1.txt", ios:: in );

                        f2.open("mn1.txt", ios:: in );

                        j = p.search(f1, usn);



                        if (j != 0) {

                                cout << "Record found & Details are\n";

                                cout << "Name=" << s[j].name << "\n" << "USN=" << s[j].usn << "\n" <<

                                        "Sem=" << s[j].sem << "\n" << "Branch=" << s[j].branch << "\n";

                        }

                        f1.close();

                        f2.close();

                        break;

                case 4:

                        f1.open("m1.txt", ios:: in );

                        f2.open("mn1.txt", ios:: in );

                        cout << "Enter USN to delete: ";

                        cin >> usn;

                        j = p.remove(f1, usn);

                        if (j != 0) {

                                for (i = j; i < n; i++)

                                        s[i] = s[i + 1];

                                cout << "Deletion successfull\n";

                        }

                        n--;

                        ind--;

                        f1.close();

                        f2.close();

                        f1.open("m1.txt", ios::trunc | ios::app);

                        f2.open("mn1.txt", ios::trunc | ios::app);

                        ind = 0;

                        for (i = 1; i <= n; i++)

                                s[i].write(f1, f2);

                        f1.close();

                        f2.close();

                        break;

                default:

                        exit(0);

                }

        }

}
===============================================================================================================
prog6
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>

using namespace std;
int n = 0, ind = 0;
class student {
        public: char name[20], usn[20], branch[5];
        int sem;

        void insert(fstream & f1, fstream & f2) {
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter USN: ";
                cin >> usn;
                cout << "Enter Sem: ";
                cin >> sem;
                cout << "Enter Branch: ";
                cin >> branch;
                write(f1, f2);
        }

        void write(fstream & f1, fstream & f2) {
                f1 << ++ind << "\t" << name << "\n";
                f2 << name << "\t" << usn << "\t" << sem << "\t" << branch << "\n";
        }

        void display(fstream & f2) {
                f2 >> name >> usn >> sem >> branch;
                cout << name << "\t" << usn << "\t" << sem << "\t" << branch << "\n";
        }

        int search(fstream & f1, char key[20]) {
                int i, x;
                for (i = 1; i <= n; i++) {
                        f1 >> x >> name;
                        if (strcmp(name, key) == 0) return i;
                }
                cout << "Record not found\n";
                return 0;
        }

        int remove(fstream & f1, char key[20]) {
		int i;
		i = search(f1, key);
		return i;
        }
};

int main() {
        fstream f1, f2;
        student s[20], p;
        int ch, k = 0, i,j;
        //clrscr();
        f1.open("m.txt", ios::trunc);
        f2.open("mn.txt", ios::trunc);
        f1.close();
        f2.close();
        for (;;) {
                cout << "1.Insert 2.Display 3.Search 4.Delete 5.Exit\n";
                cout << "Enter choice: ";
                cin >> ch;
                switch (ch) {
                case 1:
                        f1.open("m.txt", ios::app);
                        f2.open("mn.txt", ios::app);
                        cout << "Enter no. of students: ";
                        cin >> k;
                        n = n + k;
                        for ( i = 1; i <= k; i++) s[i].insert(f1, f2);
                        f1.close();
                        f2.close();
                        break;
                case 2:
                        f2.open("mn.txt", ios:: in );
                        for (i = 1; i <= n; i++)
                                s[i].display(f2);
                        f2.close();
                        break;
                case 3:
                        char name[20];
                        cout << "Enter name to search: ";
                        cin >> name;
                        f1.open("m.txt", ios:: in );
                        f2.open("mn.txt", ios:: in );
                        j = p.search(f1, name);
                        if (j != 0) {
                                cout << "Record found & Details are\n";
                                cout << "Name=" << s[j].name << "\n" << "USN=" << s[j].usn << "\n" <<
                                        "Sem=" << s[j].sem << "\n" << "Branch=" << s[j].branch << "\n";
                        }
                        f1.close();
                        f2.close();
                        break;
                case 4:
                        f1.open("m.txt", ios:: in );
                        f2.open("mn.txt", ios:: in );
                        cout << "Enter name to delete: ";
                        cin >> name;
                        j = p.remove(f1, name);
                        if (j != 0) {
                                for (i = j; i < n; i++)
                                        s[i] = s[i + 1];
                                cout << "Deletion successfull\n";
                        }
                        n--;
                        ind--;
                        f1.close();
                        f2.close();
                        f1.open("m.txt", ios::trunc | ios::app);
                        f2.open("mn.txt", ios::trunc | ios::app);
                        ind = 0;
                        for (i = 1; i <= n; i++)
                                s[i].write(f1, f2);
                        f1.close();
                        f2.close();
                        break;
                default:
                        exit(0);
                }
        }
}
=======================================================================================================================
prog7


#include <fstream>

#include <iostream>

#include <string.h>

using namespace std;



void writeList()

{

    fstream f1, f2;

    int m;

    char name[10];

    f1.open("file1.txt", ios::out);

    f2.open("file2.txt", ios::out);



    cout << "Enter number of names for file1 : " << endl;

    cin >> m;

    for (int i = 0; i < m; i++)

    {

        cin >> name;

        f1 << name;

        f1 << "\n";

    }



    cout << "Enter number of names for file2 : " << endl;

    cin >> m;

    for (int j = 0; j < m; j++)

    {

        cin >> name;

        f2 << name;

        f2 << "\n";

    }

    f1.close();

    f2.close();

}



int main()

{

    char list1[10][10], list2[10][10];

    fstream f1, f2, f3;

    int i = 0, j = 0, m = 0, n = 0;

    writeList();

    f1.open("file1.txt", ios::in);

    f2.open("file2.txt", ios::in);

    f3.open("common.txt", ios::out);

    while (!f1.eof())

    {

        f1.getline(list1[i], 10, '\n');

        i++;

        m++;

    }



    while (!f2.eof())

    {

        f2.getline(list2[j], 10, '\n');

        j++;

        n++;

    }



    i = 0;

    j = 0;

    while (i < m && j < n)

    {

        if (strcmp(list1[i], list2[j]) == 0)

        {

            cout << "The common name is : " << list1[i] << endl;

            f3 << list1[i];

            i++;

            j++;

        }

       else if (strcmp(list1[i], list2[j]) < 0) // returns negative if not equal

            i++;

        else

            j++;

    }

    f1.close();

    f2.close();

    f3.close();

    return 0;

}

===================================================================================================================================
prog8
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
class record
{
public:
    char name[20];
    char usn[20];
} rec[20];

fstream file[8];
int no;
char fname[8][8] = {"1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "6.txt", "7.txt", "8.txt"};

void merge_file(char *file1, char *file2, char *filename)
{
    record recd[20];
    int i, k;
    k = 0;
    fstream f1, f2;
    f1.open(file1, ios::in);
    f2.open(file2, ios::in);
    while (!f1.eof())
    {
        f1.getline(recd[k].name, 20, '|');
        f1.getline(recd[k++].usn, 20, '\n');
    }
    while (!f2.eof())
    {
        f2.getline(recd[k].name, 20, '|');
        f2.getline(recd[k++].usn, 20, '\n');
    }
    int t, y;
    record temp;
    for (t = 0; t < k - 2; t++)
        for (y = 0; y < k - t - 2; y++)
            if (strcmp(recd[y].name, recd[y + 1].name) > 0)
            {
                temp = recd[y];
                recd[y] = recd[y + 1];
                recd[y + 1] = temp;
            }
    fstream temp1;

    temp1.open(filename, ios::out);
    for (t = 1; t < k - 1; t++)
        temp1 << recd[t].name << "|" << recd[t].usn << "\n";
    f1.close();
    f2.close();
    temp1.close();
    return;
}

void kwaymerge()
{
    int i, k;
    k = 0;
    char filename[7][20] = {"11.txt", "22.txt", "33.txt", "44.txt", "111.txt", "222.txt", "1111.txt"};
    for (i = 0; i < 8; i += 2)
    {
        merge_file(fname[i], fname[i + 1], filename[k++]);
    }
    k = 4;
    for (i = 0; i < 4; i += 2)
    {
        merge_file(filename[i], filename[i + 1], filename[k++]);
    }
    merge_file(filename[4], filename[5], filename[6]);
    return;
}

int main()
{
    int i;
    cout << "Enter no of records : ";
    cin >> no;
    cout << "\nEnter the details :\n";
    for (i = 0; i < 8; i++)
        file[i].open(fname[i], ios::out);
    for (i = 0; i < no; i++)
    {
        cout << "Name : ";
        cin >> rec[i].name;
        cout << "Usn : ";
        cin >> rec[i].usn;
        file[i % 8] << rec[i].name << "|" << rec[i].usn << "\n";
    }
    for (i = 0; i < 8; i++)
        file[i].close();
    kwaymerge();

    fstream result;
    result.open("1111.txt", ios::in);
    cout << "\nTHE SORTED RECORDS ARE : \n";
    char name[20], usn[20];
    for (i = 0; i < no; i++)
    {
        result.getline(name, 20, '|');
        result.getline(usn, 20, '\n');
        cout << "\nName : " << name << "\nUsn  : " << usn << "\n";
    }
    return 0;
}
=====================================================================================================
































