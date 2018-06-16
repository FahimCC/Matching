#include<stdio.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

int wrongSearchCounter = 1;
int flagg = 0, fflag = 0;
class student
{
private:
    char email[30];
    char password[30];
    char name[25];
    int age;
    char dateOfBirth[30];
    char bloodgroup[4];
    char mobileNo[15];
    char address[30];
    char fatherName[30];
    char motherName[30];
    char occupation[10];
    char religion[10];
    char married[15];
    char hscInstitute[30];
    char sscInstitute[30];
    double hscResult;
    double sscResult;
    int main;
    char gender[10];

public:
    ///constructor.
    student()
    {
        email[0] = '\0';
        password[0] = '\0';
        name[0] = '\0';
        religion[0] = '\0';
    }

    int matching(char* ,char* );
    int store_info();
    void search_info(char* , char* );
    int email_search(char *);
    int email_search_info(char* , char* );
    void main_search_info(int , char *, char *);
    void update_info(char* , char* );
    void delete_info(char* , char* );
    char* set_Capital_info(char *);
    void view_All_info(char *);

    int get_info()
    {
        nine:
        cout<<"\t\t\tEnter Your Email: ";
        cin.getline(email,29);

        char eemail[30];
        strcpy(eemail,email);
        int emaill = email_search(eemail);
        if(emaill == 5)
        {
            wrongSearchCounter++;
            cout<<endl<<"\t\t\tThis email id already in here please try any thing else."<<endl<<endl;
            goto nine;
        }

        strcpy(email,eemail);
        ///pattern matching.
        int index = matching(email,"@gmail.com");

        if(index == 0 || index == 1 || index == 2 || index == 3 || index == 4)
        {
            int length = strlen(email);
            for(int k=0;k<length;k++)
            {
                if(email[k] == ' ')
                {
                    wrongSearchCounter++;
                    cout<<endl<<"\t\t\tThis is not an email address.Please try again."<<endl<<endl;
                    goto nine;
                }
            }

            wrongSearchCounter++;
            if(wrongSearchCounter == 4)
            {
                cout<<endl<<"\t\t\tBujhchi tr Email nai .. age email khul tarpor aich akhon vag."<<endl<<endl;
                cout<<endl<<"\t\t\tPress any key to Exit."<<endl;
                getch();
                return 0;
            }
            cout<<endl<<"\t\t\tThis is not an email address.Please try again."<<endl<<endl;
            goto nine;
        }

        eight:
        cout<<"\t\t\tEnter Your Password: ";
        cin.getline(password,29);

        char passwor[30];
        cout<<"\t\t\tConfirm Password: ";
        cin.getline(passwor,29);

        if(strcmp(passwor,password))
        {
            cout<<endl<<"\t\t\tPassword Don't Match."<<endl<<endl;
            goto eight;
        }

        cout<<endl<<"\t\t\tEnter Your Name(Capital letter): ";
        cin.getline(name,24);

        ///funtion.
        strcpy(name,set_Capital_info(name));

        char w = name[0];
        int ll = strlen(name),count = 0;

        for(int k=0;k<ll;k++)
        {
            if(w == name[k])
                count++;
        }

        main = count;

        cout<<"\t\t\tEnter Your Age: ";
        cin>>age;
        cin.ignore();

        if(age > 25)
        {
            cout<<endl<<"\t\t\t25+ are not allowed for this application."<<endl<<endl;
            cout<<"\t\t\tPress any key to exit."<<endl;
            getch();
            exit(0);
        }

        cout<<"\t\t\tEnter Your Birth Date: ";
        cin.getline(dateOfBirth,29);

        cout<<"\t\t\tEnter Your Blood Group: ";
        cin.getline(bloodgroup,3);

        cout<<"\t\t\tEnter your gender: ";
        cin.getline(gender,9);

        strcpy(gender,set_Capital_info(gender));

        forteen:
        cout<<"\t\t\tEnter Your Mobile No.(+880): ";
        cin.getline(mobileNo,14);

        int l = strlen(mobileNo);

        if(l != 11)
        {
            cout<<endl<<"\t\t\tThis is not a Mobile number. Please enter correct number."<<endl<<endl;
            goto forteen;
        }

        cout<<"\t\t\tEnter Your Address: ";
        cin.getline(address,29);

        cout<<"\t\t\tEnter Your Father Name: ";
        cin.getline(fatherName,29);

        cout<<"\t\t\tEnter Your Mother Name: ";
        cin.getline(motherName,29);

        cout<<"\t\t\tEnter Your Occupation: ";
        cin.getline(occupation,9);

        cout<<"\t\t\tEnter Your Religion: ";
        cin.getline(religion,9);

        strcpy(religion,set_Capital_info(religion));

        cout<<"\t\t\tEnter Your Maritual Status: ";
        cin.getline(married,14);

        cout<<"\t\t\tEnter Your Alim/HSC Institute: ";
        cin.getline(hscInstitute,29);

        twenty_five:
        cout<<"\t\t\tEnter Your Alim/HSC Result: ";
        cin>>hscResult;
        cin.ignore();

        if(hscResult > 5.00)
        {
            cout<<"\t\t\tPlease! enter correct result."<<endl;
            goto twenty_five;
        }

        cout<<"\t\t\tEnter Your Dakhil/SSC Institute: ";
        cin.getline(sscInstitute,29);

        twenty_six:
        cout<<"\t\t\tEnter Your Dakhil/SSC Result: ";
        cin>>sscResult;
        cin.ignore();

        if(hscResult > 5.00)
        {
            cout<<"\t\t\tPlease! enter correct result."<<endl;
            goto twenty_six;
        }
        cout<<endl<<endl<<"\t\t\tThank you for creating account."<<endl;
        return 0;
    }

    int main_Part()
    {
        return main;
    }

    char* Gender()
    {
        return gender;
    }

    char* Religion()
    {
        return religion;
    }

    void show_info(int a = 0)
    {
        cout<<endl<<"\t\t\tName: "<<name<<endl;
        cout<<"\t\t\tAge: "<<age<<endl;
        cout<<"\t\t\tDate of Birth: "<<dateOfBirth<<endl;
        cout<<"\t\t\tBlood Group: "<<bloodgroup<<endl;
        cout<<"\t\t\tGender: "<<gender<<endl;
        cout<<"\t\t\tMobile No.(+880): "<<mobileNo<<endl;
        cout<<"\t\t\tEmail: "<<email<<endl;
        if(a == 1)
            cout<<"\t\t\tPassword: "<<password<<endl;
        cout<<"\t\t\tAddress: "<<address<<endl;
        cout<<"\t\t\tFather Name: "<<fatherName<<endl;
        cout<<"\t\t\tMother Name: "<<motherName<<endl;
        cout<<"\t\t\tOccupation: "<<occupation<<endl;
        cout<<"\t\t\tReligion: "<<religion<<endl;
        cout<<"\t\t\tMaritual Status: " <<married<<endl;
        cout<<"\t\t\tAlim/HSC Institute: "<<hscInstitute<<endl;
        cout<<"\t\t\tAlim/HSC Result: "<<hscResult<<endl;
        cout<<"\t\t\tDakhil/SSC Institute: "<<sscInstitute<<endl;
        cout<<"\t\t\tDakhil/SSC Result: "<<sscResult<<endl<<endl;
    }
};

void student::view_All_info(char *g)
{
    int flag = 1;
    ifstream fin;
    fin.open("Matching.txt",ios::in);

    if(!fin)
        cout<<"Data Base not open."<<endl;
    else
    {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(!strcmp(gender,g))
            {
                flag = 2;
                show_info(1);
            }
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
        if(flag == 1)
            cout<<endl<<"No information."<<endl;
    }
}

///set information
char* student::set_Capital_info(char *t)
{
    int length = strlen(t), flag = 1;
    int p;

    for(int k=0;k<length;k++)
    {
        p = t[k];
        if(p >= 97 && p <= 122)
        {
            t[k] = p-32;
        }
    }
    return t;
}

///match search
void student::main_search_info(int t, char *g, char *r)
{
    int flag = 1;
    ifstream fin;
    fin.open("Matching.txt",ios::in);

    if(!fin)
        cout<<endl<<"\t\t\tData Base not open."<<endl;
    else
    {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(main == t && strcmp(gender,g) && !strcmp(religion,r))
            {
                flagg = 3;
                flag = 2;
                show_info();
                cout<<endl<<"\t\t\t\tDo you want match again ?"<<endl<<endl;
                cout<<"\t\t\t\t1. Yes."<<endl;
                cout<<"\t\t\t\t2. No."<<endl;
                cout<<"\t\t\t\tEnter the number(1-2): ";
                int f;
                cin>>f;
                if(f == 1)
                {
                    flag = 1;
                    goto two;
                }
                else if(f == 2)
                    break;
                else
                    cout<<endl<<"Invalid Choice."<<endl;
            }
            two:
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
        if(flag == 1)
            cout<<endl<<"\t\t\tMatch not found."<<endl;

        flagg = flag;
    }
}

///update inormation.
void student::update_info(char* t, char* s)
{
    int flag = 1;
    fstream file;
    file.open("Matching.txt",ios::in | ios::out | ios::ate);
    file.seekg(0);
    if(!file)
        cout<<endl<<"\t\t\tData Base not open."<<endl;
    else
    {
        file.read((char*)this,sizeof(*this));
        while(!file.eof())
        {
            if(!strcmp(email,t) && !strcmp(password,s))
            {
                flag = 2;
                get_info();
                file.seekp(file.tellp()-sizeof(*this));
                file.write((char*)this,sizeof(*this));
                break;
            }
            file.read((char*)this,sizeof(*this));
        }
        file.close();
        if(flag == 1)
            cout<<"\t\t\tInformation not found."<<endl;
    }
}

///delete information.
void student::delete_info(char* t, char* s)
{
    int flag = 1;
    ifstream fin;
    ofstream fout;
    fin.open("Matching.txt",ios::in);

    if(!fin)
        cout<<endl<<"\t\t\tData Base not open."<<endl;
    else
    {
        fout.open("Temporary.txt",ios::out);
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(strcmp(email,t) && strcmp(password,s))
            {
                fout.write((char*)this,sizeof(*this));
            }
            else
                flag = 2;

            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
        fout.close();

        remove("Matching.txt");
        rename("Temporary.txt","Matching.txt");
        if(flag == 1)
            cout<<endl<<"\t\t\tInformation not found."<<endl;
    }
}

///email search information.
int student::email_search_info(char *t, char *s)
{
    int flag = 0;
    ifstream fin;
    fin.open("Matching.txt",ios::in);
    if(!fin)
        cout<<endl<<"\t\t\tData Base not open."<<endl;
    else
    {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(!strcmp(email,t) && !strcmp(password,s))
            {
                cout<<flag<<endl;
                flag = 1;
                break;
            }
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }
    return flag;
}

///email search.
int student::email_search(char *tt)
{
    int flag = 1;
    ifstream fin;
    fin.open("Matching.txt",ios::in);
    if(!fin)
        cout<<endl<<"\t\t\tData Base not open."<<endl;
    else
    {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(!strcmp(email,tt))
            {
                flag = 5;
                break;
            }
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }
    return flag;
}

///search information.
void student::search_info(char *t, char *s)
{
    int flag = 1;
    ifstream fin;
    fin.open("Matching.txt",ios::in);

    if(!fin)
        cout<<endl<<"\t\t\tData Base not open."<<endl;
    else
    {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if((!strcmp(email,t)) && (!strcmp(password,s)))
            {
                flag = 2;
                show_info();
                break;
            }
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
        if(flag == 1)
            cout<<endl<<"\t\tInformation not found."<<endl;
    }
}

///store information.
int student::store_info()
{
    if(email == '\0' && password == '\0')
    {
        cout<<endl<<"\t\tInformation are not initialized."<<endl;
        return 0;
    }
    else
    {
        ofstream fout;
        fout.open("Matching.txt",ios::app);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        return (1);
    }
}

///Pattern Matching.
int student::matching(char* T,char* P)
{
    int k=1,s=strlen(T),r=strlen(P),maxx = s - r + 1,index,l;
    while(k<=maxx)
    {
        for(l=0;l<r;l++)
        {
            if(P[l] != T[k+l-1])
            {
                goto step;
            }
        }
        index = k;
        goto inde;
        step:
        k = k + 1;

    }
    index = 0;
    inde:
    return index;
}

int main_menu()
{
    cout<<endl<<"**** Choice list ****"<<endl<<endl;
    cout<<"1. Sign Up."<<endl;
    cout<<"2. Sign In."<<endl;
    cout<<"3. Exit."<<endl<<endl;
    cout<<"Enter the Number(1-3): ";
    int a;
    cin>>a;
    cin.ignore();
    return a;
}

int second_main_menu()
{
    cout<<endl<<"\t\t**** Existing list ****"<<endl;
    cout<<endl<<"\t\t1. View Details."<<endl;
    cout<<"\t\t2. Update Information."<<endl;
    cout<<"\t\t3. Delete ID."<<endl;
    cout<<"\t\t4. Matching."<<endl;
    cout<<"\t\t5. Log out."<<endl<<endl;
    cout<<"\t\tEnter the number (1-5): ";
    int c;
    cin>>c;
    cin.ignore();
    return c;
}

int main()
{
    cout<<"\t\t\t\t\t   ~~ TEENEGERS MARRIGE POINT ~~\n\n\n"<<endl<<endl;

    ///Declaration.
    student B;
//    ofstream fout("Matching.txt");
//    fout.close();

    int emaill,e,mainM,n;
    char email[30], password[30], genderr[10], religion[10];

    while(1)
    {
        n = main_menu();
            ///sign in.
            if(n == 1)
            {
                B.get_info();
                B.store_info();

            }
            ///sign up.
            else if(n == 2)
            {
                e = 0;
                while(1)
                {
                    cout<<endl<<"\t\tEnter your email: ";
                    cin.getline(email,29);

                    cout<<endl<<"\t\tEnter your password: ";
                    cin.getline(password,29);

                    if(B.email_search_info(email,password))
                    {
                        while(1)
                        {
                            switch(second_main_menu())
                            {
                                ///view information.
                                case 1:
                                    B.search_info(email,password);
                                    break;

                                ///update information.
                                case 2:
                                    B.update_info(email,password);
                                    cout<<endl<<"\t\t\tNew information are inserted."<<endl;
                                    goto back;

                                ///delete information.
                                case 3:
                                    B.delete_info(email,password);
                                    cout<<endl<<"\t\t\tThis ID has been deleted."<<endl;
                                    goto back;

                                ///matching.
                                case 4:
                                    fflag = 3;
                                    mainM = B.main_Part();
                                    strcpy(genderr,B.Gender());
                                    strcpy(religion,B.Religion());

                                    B.main_search_info(mainM,genderr,religion);
                                    break;

                                ///back.
                                case 5:
                                    cout<<endl<<"\t\tPress any key to back."<<endl;
                                    getch();
                                    goto back;

                                default:
                                    cout<<endl<<"\t\tInvalid choice."<<endl;
                            }
                        }
                    }
                    else
                    {
                        cout<<endl<<"\t\tEmail and Password don't match.Please try again."<<endl;
                        e++;
                        if(e == 3)
                        {
                            cout<<endl<<"\t\tVua email password dech kn id thakle ko na thakle fut."<<endl;
                            exit(0);
                        }
                    }
                    back:
                    break;
                }
            }
            else if(n == 1436)
                B.view_All_info("MALE");

            else if(n == 1433)
                B.view_All_info("FEMALE");

            ///exit.
            else if(n == 3)
            {
                cout<<endl<<"\t\tPress any key to exit."<<endl;
                getch();
                cout<<endl<<endl<<endl<<"\t\t\t\t\tThank you for visiting this application."<<endl<<endl;

                if(flagg == 1)
                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n Ai application faltu mone korar kono karon nai. bohut kosto koira banaichi. Ar valo kotha ai j valo manush hou valo bou emnei paba.";
                else if(flagg == 3 && fflag == 3)
                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n Atto khushi howar kicchu nai ai matching matching ai application porjontoi. So, valo manush hou valo bou emnei paba.\n\n\n";
                cout<<endl<<endl;

                goto exit;
            }
            else
                cout<<endl<<"\t\tInvalid choice."<<endl;
    }
    exit:

    return 0;
}
