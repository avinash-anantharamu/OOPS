#include <iostream>
#include <fstream>
#include <string.h>
#include<stdio.h>

using namespace std;
char ch='$';
string s;


class address
{
private:

    string addr,city,state,pincode;

public:
    void printAddress()
    {
        cout<< addr << endl << city <<endl<< state<<endl << pincode << endl;
    }

    void FileWrite(ofstream& stream)
    {
        stream << addr << '$'<< city << '$'<< state << '$'<< pincode << '$'<<endl;
    }

    char* convert(string s1)
    {

        char *a=new char[s1.size()+1];
        a[s1.size()]=0;
        strcpy(a,s1.c_str());
        return a;
    }

    void populateFromString(string ip[])
    {


        addr=ip[0];
        city=ip[1];
        state=ip[2];
        pincode=ip[3];

        if(strlen(convert(pincode))!= 6)
            pincode="invalid pin";
    }

};

class personType
{

    address addr;
    string phNo,dob,addrStr[4];
public:

    string name,reln;
    personType *next;

    personType()
    {
        strcpy(convert(name),"");
        strcpy(convert(reln),"");

        next = NULL;
    }


    void print()
    {

        printName();
        cout<< "The relation is : " << reln << endl;
        cout<<"Date Of Birth is : "<<dob;
        cout<< "Phone  Number is : " << phNo << endl;
        addr.printAddress();

    }

    void printName()
    {
        cout<< "Name is : " << name << endl;
    }

    void FileWrite(ofstream &str)
    {
        str<< name << '$';
        str<< phNo << '$';
        str<< reln << '$';
        str<< dob << '$';
        addr.FileWrite(str);

}

void nameFileWrite(ofstream &str)
{
    str<< "Name is : " << name << endl;
}



    char* convert(string s1)
    {

        char *a=new char[s1.size()+1];
        a[s1.size()]=0;
        strcpy(a,s1.c_str());
        return a;
    }
    void populateFromString(string ip[])
    {

        int i = 0;
        name=ip[0];
        phNo=ip[1];
        reln=ip[2];
        dob=ip[3];
        for(i=0; i<4; i++)
            addrStr[i]=ip[i+4];

        addr.populateFromString(addrStr);
    }

};

class AddressbType
{
    personType *Head;


public:

    AddressbType()
    {
        Head = NULL;}
    void initialise(){
        ifstream fs;
        fs.open("contacts");
        if(fs.is_open())
            cout<<"file opened";
        fs.unsetf(ios_base::skipws);
        char temp;
        int i ,end = 0;

        string record[8];
        while (!fs.eof())
        {
            for(i=0; i<8; i++)
            {
                getline(fs,s,ch);
                record[i]=s;

            }

            if(Head == NULL)
            {
                personType *temp = new personType();
                temp->populateFromString(record);
                Head = temp;
            }
            else
            {
                personType *temp = new personType();
                temp->populateFromString(record);
                temp->next = Head;
                Head = temp;
            }

           fs>>temp;
        }

    }

    char* convert(string s1)
    {

        char *a=new char[s1.size()+1];
        a[s1.size()]=0;
        strcpy(a,s1.c_str());
        return a;
    }

    void nameFind()
    {
        char find[100];
        int flg=0;

        cout<<"\nType name of person whom u r trying to find??\n";

        cin.ignore();
        gets(find);
        for(personType * cur = Head; cur!= NULL ; cur = cur->next)
        {

            if(strcmp(convert(cur->name),find) == 0)
            {
                cur->print();

                flg = 1;
            }
        }
        if(flg == 0)
            cout<<find<<" person cannot be found..";
    }

    void FindCategory()
    {
        int flg = 0;
        char find[100];
        ofstream opfs;

        opfs.open("results",ios_base::app);

        opfs.seekp(0,ios_base::end);

        cout<<"\nWhat category are you looking for??\n";

        cin>> find;
        cin.ignore();

        for(personType * cur = Head; cur!= NULL ; cur = cur->next)
            if(strcmp(convert(cur->reln),find) == 0)
            {
                cur->printName();
               cur->nameFileWrite(opfs);
                flg = 1;
            }

        if(flg == 0)
        {
            cout<<"No person under the entered category "<<find<<endl;
            opfs<<"No person under the entered category "<<find<<endl;
        }
        opfs.close();
    }



    void insert()
    {
        personType *temp = new personType();
        string record[8];
        string name,phno,reln,dob,street,city,state,pincode;
        char nam[100];
        cout<<"Enter details..\n ";
        cout<<"\nName of person:";
        cin.ignore();
        gets(nam);

        name.assign(nam);
        record[0]=name;

        cout<<"\nRelation  :";
        cin.ignore();
        gets(nam);
        reln.assign(nam);
        record[2]=reln;

        cout<<"\nPhone Number of the person :";
        cin.ignore();
        gets(nam);
        phno.assign(nam);
        record[1]=phno;

        cout<<"\nDate of Birth:";
        cin.ignore();
        gets(nam);
        dob.assign(nam);
        record[3]=dob;

        cout<<"\nStreet no.:";
        cin.ignore();
        gets(nam);
        street.assign(nam);
        record[4]=street;

       cout<<"\nEnter city name:";
        cin.ignore();
        gets(nam);
        city.assign(nam);
        record[5]=city;

        cout<<"\nState:";
        cin.ignore();
        gets(nam);
        state.assign(nam);
        record[6]=state;

        cout<<"\n Enter Pincode..It shoulb be of six digit:";
        cin>>pincode;

        record[7]=pincode;

        for(int k=0; k<8; k++)
            cout<<record[k]<<'$';
        cout<<endl;


        temp->populateFromString(record);
        ofstream ofs;
        ofs.open("contacts",ios_base::app);
        ofs.seekp(0,ios_base::end);
        temp->FileWrite(ofs);

        temp->next = Head;
        Head = temp;

        ofs.close();


    }

    void del()
    {
        char find[100];
        int flg = 0;
        personType *temp=Head;
        cout<<"\nEnter the Name that is to be deleted...\n\n";
        cin.ignore();
        gets(find);

        if(strcmp(convert(Head->name),find)==0)
        {
            personType * del = Head;
            Head = Head->next;
            delete del;
            flg++;

        }


        while( temp != NULL && temp->next != NULL)
        {

            if(strcmp(convert(temp->next->name),find)==0)
            {
                personType * del = temp->next;
                temp->next = temp->next->next;
                delete del;
                flg++;
            }
            temp=temp->next;
            cout<< endl << flg <<" All contacts with that name has been  deleted..\n";
        }

   }
};

int main()
{
    AddressbType b;

    char enterchoice;
    b.initialise();



        cout<<"\n__\n Enter:\n 1 > Enter name of a person to search \n 2 >Enter category to find related contacts\n 3 > Enter name to delete contacts\n 4 > Enter to insert contact\n 5 > Exit..\n";

        cin>> enterchoice;
    do
    {
        switch(enterchoice)
        {
        case '1':
            b.nameFind();
            break;

        case '2':
            b.FindCategory();
            break;

        case '3':
            b.del();
            break;

        case '4':
            b.insert();
            break;

        case '5':
            cout<<"";
            return 0;

        default:
            cout<<endl<<"Invalid option"<<endl;
        cout<<"\n__\n Enter:\n 1 > Enter name of a person to search \n 2 >Enter category to find related contacts\n 3 > Enter name to delete contacts\n 4 > Enter to insert contact\n 5 > Exit..\n";

        cin>> enterchoice;
        }
    }
    while(enterchoice!='5');
    return 0;
}
