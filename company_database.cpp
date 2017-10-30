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
* Tasks remaining:
* Deciding the design of the delete function and implementing it.
* Deciding the design of the search function and implementing it.
* Testing this program.
* Define a macro pushback function as pb
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


class users
{
    public: void add_record();
            void delete_record(string);
            void read_file();
            void write_file();
            void search_record(string);
            void view_record();
            
            users(){}
            virtual ~users() {}
};

class guest : public users
{
    protected: int choice;

    public: friend void view_record();
            friend void search_record(string);
            guest()
            {

                cout<<"Press (1) to view existing records"<<endl;
                cout<<"Press (2) to search an existing record"<<endl;
                cout<<"Press (3) to exit"<<endl;
                cin>>choice;
                // system("cls");

                switch(choice)
                {
                    case 1: //view
                            break;
                    case 2: //search
                            break;
                    case 3: //exit
                            break;
                }
            }
};

class admin : public users
{
    protected: int choice;
               char type;
               string e;

    public: friend void add_record();
            friend void delete_record(string);
            friend void read_file();
            friend void write_file();
            friend void search_record(string);
            friend void view_record();
            friend void split(const std::string &s, std::vector<std::string> &elems,char); 

            admin()
            {
                cout<<"Press (1) to add a new record"<<endl;
                cout<<"Press (2) to delete an existing record"<<endl;
                cout<<"Press (3) to view existing records"<<endl;
                cout<<"Press (4) to search an existing record"<<endl;
                cout<<"Press (5) to exit"<<endl;
                cin>>choice;
                // system("cls");

                switch(choice)
                {
                    case 1: add_record();
                            //system("cls");
                            break;
                    case 2: cin>>e;
                            search_record(e);
                            break;
                    
                    case 3: view_record();
                            break;
                    case 4: cin>>e;
                            delete_record(e);
                            break;

                    default: break;
                }
            }
};


class company
{

  friend class institute;

  public: string company_name, contact_no, salary, domain, head_office;
            

  public: void add()
  		  {
                cout<<"Add company name"<<endl;
                cin>>company_name;
                cout<<"Add contact number"<<endl;
                cin>>contact_no;
                cout<<"Add salary"<<endl;
                cin>>contact_no;
                cout<<"Add head office"<<endl;
                cin>>contact_no;
                cout<<"Add domains and technologies"<<endl;
                cin>>contact_no;
          }
          
          // delete search and view methods to be added later
          // PRs are welcome

          friend void read_file();
          friend void write_file();
          friend void search_record(string);
          friend void view_record();
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
                cout<<institute_name<<endl;
                cout<<company_name<<endl;
                cout<<contact_no<<endl;
                cout<<head_office<<endl;
                cout<<salary<<endl;
                cout<<domain<<endl;
            }

            friend void add_record();
            friend void delete_record(string);
            friend void read_file();
            friend void write_file();
            friend void search_record(string);
            friend void view_record();
            

void acceptData(vector<string> &v)
{
  institute_name=v[0]; //If you have more member variables, initialize them like this
  company_name=v[1];
  contact_no=v[2];
  head_office=v[3];
  salary=v[4];
  domain=v[5];
  
}

void write(ofstream &x)
{
    //cout<<"Inside write()";
    x<<institute_name<<','<<company_name<<','<<contact_no<<','<<head_office<<','<<salary<<','<<domain<<endl;//If you have more variables, add them like this                                      
}

// a global object of the class created right outside
}obi;




template<typename Out>
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




void users :: read_file()
{
    ifstream x("institute.csv");
    char z[100]; // array

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
 

void users :: write_file()
{
    ofstream x("institute.csv");

    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++)
    {
        (*itr).write(x);
    }

    x.close();
}


void users :: add_record()
{
    obi.add();
    v1.push_back(obi);
    write_file(); 
}



void users :: delete_record(string e)
{
    int c = 0;
    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++, c++)
    {
        if((*itr).company_name == e)
        {
            v1.erase(v1.begin()+c);
            write_file();
            break;
        }
    }
}


void users :: search_record(string e)
{
    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++)
    {
        if((*itr).company_name == e)
        {
            (*itr).show();
            break;
        }
    }
}


void users :: view_record()
{
    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++)
    {
        (*itr).show();
    }
}



/* functionality to be extended later
** add a functionality to create new records in a loop
*/
int main()
{
    char user_type;
    users u;
    cout<<"If you are an admin press 'A'"<<endl;
    cout<<"If you are a guest press 'G'"<<endl;
    cin>>user_type;
    u.read_file();
    u.write_file();


    if(user_type=='A')
        admin a;
    else
        guest g;

    return 0;
}



