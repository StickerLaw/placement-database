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


#include <bits/stdc++.h>
using namespace std;

class company;
class institute;
std::vector<institute> v1;
std::vector<company> v2;

class users
{
    public: virtual void add_record_institute();
            virtual void delete_record_institute(string,string);
            virtual void read_file_institute();
            virtual void write_file_institute();
            virtual void search_record_institute(string);
            virtual void view_record_institute();
            virtual void add_record_company();
            virtual void delete_record_company(string,string);
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
                    q:
                    cout<<"\n\nPress (1) to view existing records"<<endl;
                    cout<<"Press (2) to search an existing record"<<endl;
                    cout<<"Press (3) to exit"<<endl;
                    cin>>choice;
                    //system("clear");

                    switch(choice)
                    {
                        case 1: view_record_institute();
                                break;

                        case 2: cout<<"Enter institute name to search: ";
                                cin>>e;
                                search_record_institute(e);
                                break;
                        case 3: exit(0);
                                break;
                        default: cout<<"Wrong Input.";
                                 goto q;
                    }
                }
                else if(type=='C')
                {
                    y:
                    cout<<"\n\nPress (1) to view existing records"<<endl;
                    cout<<"Press (2) to search an existing record"<<endl;
                    cout<<"Press (3) to exit"<<endl;
                    cin>>choice;
                    //system("clear");

                    switch(choice)
                    {
                        case 1: view_record_company();
                                break;

                        case 2: cout<<"Enter Company Name to search: ";
                                cin>>e;
                                search_record_company(e);
                                break;
                        case 3: exit(0);
                                break;
                        default: cout<<"Wrong Input.";
                                 goto y;
                    }
                }
            }
};

class admin : public users
{
    protected: int choice;
               string e;
               string f;

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
                if(type=='I')
                {
                    z:
                    cout<<"\n\nPress (1) to add a new record"<<endl;
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
                        case 2: cout<<"Enter institute name to search: ";
                                cin>>e;
                                search_record_institute(e);
                                break;

                        case 3: view_record_institute();
                                break;

                        case 4:
                                cout<<"Enter institute name to delete record: ";
                                cin>>e;
                                cout<<"Enter company name to delete record: ";
                                cin>>f;
                                delete_record_institute(e,f);
                                break;
                        case 5: exit(0);

                        default: cout<<"Wrong Input."<<endl;
                                 goto z;
                    }
                }
                else if(type=='C')
                {
                    x:
                    cout<<"\n\nPress (1) to add a new record"<<endl;
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
                        case 2: cout<<"Enter company name to search: ";
                                cin>>e;
                                search_record_company(e);
                                break;

                        case 3: view_record_company();
                                break;

                        case 4: cout<<"Enter company name to delete record: ";
                                cin>>e;
                                cout<<"Enter Institute name to delete record: ";
                                cin>>f;
                                delete_record_company(e,f);
                                break;
                        case 5: exit(0);

                        default: cout<<"Wrong Input."<<endl;
                                 goto x;
                    }
                }
            }
};


class company
{

    friend class institute;

    public: string institute_name, company_name, contact_no, salary, domain, head_office;


    public:
        void add()
        {
            int i;

            cout<<"\n\nAdd institute name: ";
            cin>>institute_name;
            cout<<"Add company name: ";
            cin>>company_name;
            cout<<"Add contact number: ";
            cin>>contact_no;
                if(isalpha(contact_no[i]))
                {
                    cout<<"Invlid input try again"<<endl;
                    exit(0);
                }
            cout<<"Add head_office: ";
            cin>>head_office;
            cout<<"Add salary: ";
            cin>>salary;
            if(isalpha(salary[0]))
            {
                cout<<"Invlid input try again"<<endl;
                exit(0);
            }
            cout<<"Add domains and technology: ";
            cin>>domain;
        }

        void show()
        {
            cout<<"\n\n---------------------------------------------------------------------------------"<<endl;
            cout<<"Company Name: "<<company_name<<'\n'<<"Institute Name: "<<institute_name<<'\n'<<"Contact Number: "<<contact_no<<'\n'<<"Head Office: "<<head_office<<'\n'<<"Salaray in Lakhs: "<<salary<<'\n'<<"Domains and technology: "<<domain<<endl;
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
            x<<institute_name<<','<<company_name<<','<<contact_no<<','<<head_office<<','<<salary<<','<<domain<<endl;
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

    public:
        void add()
        {
            cout<<"\n\nAdd institute name: ";
            cin>>institute_name;
            cout<<"Add company name: ";
            cin>>company_name;
            cout<<"Add contact number: ";
            cin>>contact_no;
            if(isalpha(contact_no[0]))
            {
                cout<<"Invlid input try again"<<endl;
                exit(0);
            }
            cout<<"Add head_office: ";
            cin>>head_office;
            cout<<"Add salary: ";
            cin>>salary;
            if(isalpha(salary[0]))
            {
                cout<<"Invlid input try again"<<endl;
                exit(0);
            }
            cout<<"Add domains and technology: ";
            cin>>domain;
        }
        void show()
        {
            cout<<"\n\n---------------------------------------------------------------------------------"<<endl;
            cout<<"Institute name: "<<institute_name<<'\n'<<"Company Name: "<<company_name<<'\n'<<"Contact Number: "<<contact_no<<'\n'<<"Head Office: "<<head_office<<'\n'<<"Salary in Lakhs: "<<salary<<'\n'<<"Domains and technology: "<<domain<<endl;
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
            x<<institute_name<<','<<company_name<<','<<contact_no<<','<<head_office<<','<<salary<<','<<domain<<endl;
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


void users :: delete_record_institute(string e, string f)
{
    int c = 0,flag=0;
    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++, c++)
    {
        if((*itr).institute_name == e && (*itr).company_name == f)
        {
            flag = 1;
            v1.erase(v1.begin()+c);
            write_file_institute();
            break;
        }
    }
    if(flag = 0)
        cout<<"No such Institute found."<<endl;
}


void users :: search_record_institute(string e)
{
    int flag = 0;
    for(std::vector<institute>::iterator itr=v1.begin();itr!=v1.end();itr++)
    {
        if((*itr).institute_name == e)
        {
            flag = 1;
            (*itr).show();
        }
    }
    if(flag == 0)
        cout<<"No such Institute found."<<endl;
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


void users :: delete_record_company(string e,string f)
{
    int c = 0,flag = 0;
    for(std::vector<company>::iterator itr=v2.begin();itr!=v2.end();itr++, c++)
    {
        if((*itr).company_name == e && (*itr).institute_name == f)
        {
            flag = 1;
            v2.erase(v2.begin()+c);
            write_file_company();
            break;
        }
    }
    if(flag == 0)
        cout<<"No such company found."<<endl;
}


void users :: search_record_company(string e)
{
    int flag=0;
    for(std::vector<company>::iterator itr=v2.begin();itr!=v2.end();itr++)
    {
        if((*itr).company_name == e)
        {
            flag = 1;
            (*itr).show();
        }
    }
    if(flag==0)
        cout<<"No such company found."<<endl;
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
    string s1,s2;
    char choice;
    char class_choice;
    users u;
    u.read_file_institute();
    u.write_file_institute();
    u.read_file_company();
    u.write_file_company();
    l:
    cout<<"\nPress `I` to get interface on the basis of institute."<<endl;
    cout<<"Press `C` to get interface on the basis of company."<<endl;
    cout<<"To exit press any key"<<endl;
    cin>>class_choice;
    if(class_choice!='I' && class_choice!='C')
        exit(0);
    while(1)
    {
        cout<<"\n\nTo login as admin press A."<<endl;
        cout<<"To login as a guest press G."<<endl;
        cout<<"To Change interface press C.\n";
        cout<<"To exit press any key"<<endl;
        cin>>choice;

        if(choice =='A' || choice == 'a')
        {
            cout<<"Enter user name: ";
            cin>>s1;
            cout<<"Enter password: ";
            cin>>s2;
            if(s1 == "admin" && s2 == "password")
                admin a(class_choice);
            else if(s1 != "admin" && s2 == "password")
            {
                cout<<"Wrong username."<<endl;
                continue;
            }
            else if(s1 == "admin" && s2 != "password")
            {
                cout<<"Wrong password."<<endl;
                continue;
            }
            else if(s1 != "admin" && s2 != "password")
            {
                cout<<"Wrong username and password."<<endl;
                continue;
            }
        }
        else if(choice == 'G' || choice == 'g')
            guest g(class_choice);
        else if(choice == 'C' || choice == 'c')
            goto l;
        else
            exit(0);
    }

    return 0;
}
