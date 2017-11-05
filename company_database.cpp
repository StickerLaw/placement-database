/*
* Database of company profiles to be used for placement purposes.
* Currently the program isn't fully functional.
* It only gives the layout of the class structure
* and the flow of control between the member methods.
*
*---------------------------------CLASS STRUCTURE-------------------------------------
*       Users                           Company--------(friend)----------> Institute
*         |                       
*  --------------- 
*  |             |            
*  V             V             
* Admin        Guest    
*
*
*/


#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;


class company;
class institute;
std::vector<institute> v1;
std::vector<company> v2;

class users
{
    public: virtual void add_record_institute();
            virtual void delete_record_institute(string);
            virtual void read_file_institute();
            virtual void write_file_institute();
            virtual void search_record_institute(string);
            virtual void view_record_institute();
            virtual void add_record_company();
            virtual void delete_record_company(string);
            virtual void read_file_company();
            virtual void write_file_company();
            virtual void search_record_company(string);
            virtual void view_record_company();
            
            users(){}
};

class guest : public users
{
    protected: int choice;
               string e;

    public: friend void view_record_institute();
            friend void search_record_institute(string);
            friend void view_record_company();
            friend void search_record_company(string);
            guest(char type)
            {

                if(type=='I')
                {
                    cout<<"Press (1) to view existing records"<<endl;
                    cout<<"Press (2) to search an existing record"<<endl;
                    cout<<"Press (3) to exit"<<endl;
                    cin>>choice;
                    //system("clear");
    
                    switch(choice)
                    {
                        case 1: view_record_institute();
                                break;
    
                        case 2: cin>>e;
                                search_record_institute(e);
                                break;
                        case 3: //exit
                                break;
                    }
                }
                else
                {
                    cout<<"Press (1) to view existing records"<<endl;
                    cout<<"Press (2) to search an existing record"<<endl;
                    cout<<"Press (3) to exit"<<endl;
                    cin>>choice;
                    //system("clear");
    
                    switch(choice)
                    {
                        case 1: view_record_company();
                                break;
    
                        case 2: cin>>e;
                                search_record_company(e);
                                break;
                        case 3: //exit
                                break;
                    }
                }
            }
};

class admin : public users
{
    protected: int choice;
               string e;
               string password;

    public: friend void add_record_institute();
            friend void delete_record_institute(string);
            friend void read_file_institute();
            friend void write_file_institute();
            friend void search_record_institute(string);
            friend void view_record_institute();
            friend void add_record_company();
            friend void delete_record_company(string);
            friend void read_file_company();
            friend void write_file_company();
            friend void search_record_company(string);
            friend void view_record_company();
            friend void split(const std::string &s, std::vector<std::string> &elems,char); 

            admin(char type)
            {
                cout<<"Enter password"<<endl;
                cin>>password;

                if(type=='I')
                {
                    cout<<"Press (1) to add a new record"<<endl;
                    cout<<"Press (2) to search an existing record"<<endl;
                    cout<<"Press (3) to view existing records"<<endl;
                    cout<<"Press (4) to delete an existing record"<<endl;
                    cout<<"Press (5) to exit"<<endl;
                    cin>>choice;
                    // system("cls");
    
                    switch(choice)
                    {
                        case 1: add_record_institute();
                                //system("cls");
                                break;
                        case 2: cin>>e;
                                search_record_institute(e);
                                break;
                        
                        case 3: view_record_institute();
                                break;
    
                        case 4: cin>>e;
                                delete_record_institute(e);
                                break;
    
                        default: break;
                    }
                }
                    else
                    {
                        cout<<"Press (1) to add a new record"<<endl;
                        cout<<"Press (2) to search an existing record"<<endl;
                        cout<<"Press (3) to view existing records"<<endl;
                        cout<<"Press (4) to delete an existing record"<<endl;
                        cout<<"Press (5) to exit"<<endl;
                        cin>>choice;
                        // system("cls");
        
                        switch(choice)
                        {
                            case 1: add_record_company();
                                    //system("cls");
                                    break;
                            case 2: cin>>e;
                                    search_record_company(e);
                                    break;
                            
                            case 3: view_record_company();
                                    break;
        
                            case 4: cin>>e;
                                    delete_record_company(e);
                                    break;
        
                            default: break;
                        }
                    }
                }
};


class company
{

  friend class institute;

  public: string institute_name, company_name, contact_no, salary, domain, head_office;
            

  public: void add()
          {
              cout<<"Add institute name"<<endl;
              cin>>institute_name;
              cout<<"Add company name"<<endl;
              cin>>company_name;
              cout<<"Add contact number"<<endl;
              cin>>contact_no;
              cout<<"Add head_office"<<endl;
              cin>>head_office;
              cout<<"Add salary"<<endl;
              cin>>salary;
              cout<<"Add domains and technology"<<endl;
              cin>>domain;

           }

          void show()
          {
              cout<<institute_name<<'\t'<<company_name<<'\t'
              <<contact_no<<'\t'<<head_office<<'\t'<<salary<<'\t'<<domain<<endl;
          }


          void acceptData(vector<string> &v)
          {
              institute_name=v[0];
              company_name=v[1];
              contact_no=v[2];
              head_office=v[3];
              salary=v[4];
              domain=v[5];

          }

          void write(ofstream &x)
          {
              x<<institute_name<<','<<company_name<<','<<contact_no<<','
              <<head_office<<','<<salary<<','<<domain<<endl;                                   
          }

          friend void read_file_company();
          friend void write_file_company();
          friend void search_record_company(string);
          friend void delete_record_company(string);
          friend void add_record_company();
          friend void view_record_company();
}obc;


class institute
{
    friend class company; // now institute class has access to all members and attr. of company class

    public: string institute_name, company_name, contact_no, salary, domain, head_office;
      
    public: void add()
            {
                cout<<"Add institute name"<<endl;
                cin>>institute_name;
                cout<<"Add company name"<<endl;
                cin>>company_name;
                cout<<"Add contact number"<<endl;
                cin>>contact_no;
                cout<<"Add head_office"<<endl;
                cin>>head_office;
                cout<<"Add salary"<<endl;
                cin>>salary;
                cout<<"Add domains and technology"<<endl;
                cin>>domain;

                
            }

            void show()
            {
                cout<<institute_name<<'\t'<<company_name<<'\t'
                <<contact_no<<'\t'<<head_office<<'\t'<<salary<<'\t'<<domain<<endl;
            }

            void acceptData(vector<string> &v)
            {
                institute_name=v[0];
                company_name=v[1];
                contact_no=v[2];
                head_office=v[3];
                salary=v[4];
                domain=v[5];
  
            }

            void write(ofstream &x)
            {
                x<<institute_name<<','<<company_name<<','<<contact_no<<','
                <<head_office<<','<<salary<<','<<domain<<endl;                                   
            }

            friend void read_file_company();
            friend void write_file_company();
            friend void search_record_company(string);
            friend void delete_record_company(string);
            friend void add_record_company();
            friend void view_record_company();

// a global object of the class created right outside
}obi;



/* 
*makes a generic class which can be used to process 
*any kind of data in the split function
*/
template<class Out>
void split(const std::string &s, char delim, Out result)
{
    std::stringstream ss(s);
    std::string item;
    
    while (std::getline(ss, item, delim))
    {
        *(result++) = item;
    }
}
 

void split(const std::string &s, std::vector<std::string> &elems,char delim)
{
    split(s, delim, std::back_inserter(elems));
}




void users :: read_file_institute()
{
    ifstream x("institute.csv");
    char z[100]; // array to extract a single line from the csv file

    while(x.getline(z,100)) // csv data of one record
    {
        string s;

        for(int i=0;z[i]!='\0';i++)
            s.push_back(z[i]); // push back macro

        std::vector<string> v;
        split(s,v,',');                            
        obi.acceptData(v);//this vector contains all the memnber variables of the class institute.
        v1.push_back(obi);
    }
    
    x.close();
  
// Read all the remaining files in the same manner. Inside ifstream, change File name. Define acceptData in other classes which you want to read from the file, and send this vector to initialize.
}
 

void users :: write_file_institute()
{
    ofstream x("institute.csv");

    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++)
    {
        (*itr).write(x);
    }

    x.close();
}


void users :: add_record_institute()
{
    obi.add();
    v1.push_back(obi);
    write_file_institute(); 
}



void users :: delete_record_institute(string e)
{
    int c = 0;
    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++, c++)
    {
        if((*itr).institute_name == e)
        {
            v1.erase(v1.begin()+c);
            write_file_institute();
            break;
        }
    }
}


void users :: search_record_institute(string e)
{
    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++)
    {
        if((*itr).institute_name == e)
        {
            (*itr).show();
            break;
        }
    }
}


void users :: view_record_institute()
{
    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++)
    {
        (*itr).show();
    }
}



void users :: read_file_company()
{
    ifstream x("company.csv");
    char z[100]; // array

    while(x.getline(z,100)) // csv data of one record
    {
        string s;

        for(int i=0;z[i]!='\0';i++)
            s.push_back(z[i]); // push back macro

        std::vector<string> v;
        split(s,v,',');                            
        obc.acceptData(v);//this vector contains all the memnber variables of the class institute.
        v2.push_back(obc);
    }
    
    x.close();
  
// Read all the remaining files in the same manner. Inside ifstream, change File name. Define acceptData in other classes which you want to read from the file, and send this vector to initialize.
}
 

void users :: write_file_company()
{
    ofstream x("company.csv");

    for(std::vector<company>::iterator itr=v2.begin();itr!=v2.end();itr++)
    {
        (*itr).write(x);
    }

    x.close();
}


void users :: add_record_company()
{
    obc.add();
    v2.push_back(obc);
    write_file_company(); 
}



void users :: delete_record_company(string e)
{
    int c = 0;
    for(std::vector<company>::iterator itr=v2.begin();itr!=v2.end();itr++, c++)
    {
        if((*itr).company_name == e)
        {
            v2.erase(v2.begin()+c);
            write_file_company();
            break;
        }
    }
}


void users :: search_record_company(string e)
{
    for(std::vector<company>::iterator itr=v2.begin();itr!=v2.end();itr++)
    {
        if((*itr).company_name == e)
        {
            (*itr).show();
            break;
        }
    }
}


void users :: view_record_company()
{
    for(std::vector<company>::iterator itr=v2.begin();itr!=v2.end();itr++)
    {
        (*itr).show();
    }
}


// driver function to run the program
int main()
{
    char choice;
    char class_choice;
    users u;
    u.read_file_institute();
    u.write_file_institute();
    u.read_file_company();
    u.write_file_company();

    while(1)
    {
        cout<<"To save data in institute.csv press `I`"<<endl;
        cout<<"To save data in company.csv press `C`"<<endl;
        cout<<"To exit press any key"<<endl;
        cin>>class_choice;
        if(class_choice!='I'&&class_choice!='C')
            exit(0);

        cout<<"To login as admin press `A`"<<endl;
        cout<<"To login as a guest press 'G'"<<endl;
        cout<<"To exit press any key"<<endl;
        cin>>choice;

        if(choice=='A')
            admin a(class_choice);
        else if(choice=='G')
            guest g(class_choice);
        else
            exit(0);
    }
    
    return 0;
}