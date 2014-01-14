#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class address
{
  private:
 char addr[100], city[100], state[100], pincode[7];

public:
    address()
    {
     strcpy(addr,"");
     strcpy(city,"");
     strcpy(state,"");
     strcpy(pincode,"");
    }

    void printAddress()
    {
     cout<< addr << endl << city <<endl<< state<<endl << pincode << endl;
    }

    void FileWrite(ostream& stream)
    {
        stream << addr << ','<< city << ','<< state << ','<< pincode << ',';
    }

    void populateFromString(char ip[])
    {

        int i = 0,j = 0;

        while (ip[i]!=',')
        {
            addr[j++] = ip[i++];
        }
		addr[j]='\0';
        j=0;
        i++;

        while (ip[i]!=',')
        {
            city[j++] = ip[i++];
        }
	city[j] ='\0';
        j=0;
        i++;

        while (ip[i]!=',')
        {
            state[j++] = ip[i++];
        }
	state[j] ='\0';
        j=0;
        i++;

        while (ip[i]!=',')
        {
            pincode[j++] = ip[i++];
        }
        if(strlen(pincode)!= 6)
	{
	  cout<<"A record has suffered corruption..\n The Pin code field data will be dropped..\n";
	  printAddress();
	  pincode[0] ='\0';
	}
	else
        pincode[j] ='\0';

    }

};

class personType
{
    char phNo[12],dd[3],mm[3],yy[3], addrStr[100];
    address addr;

public:
    char name[100],reln[100];
    personType *next;

    personType()
    {
        strcpy(name,"");
        strcpy(reln,"");
        strcpy(phNo,"");
        strcpy(addrStr,"");
        strcpy(dd,"");
        strcpy(mm,"");
        strcpy(yy,"");
	next = NULL;
    }

    void print(){
    cout<< "Name is : " << name << endl;
    cout<< "The relation is : " << reln << endl;
    cout<<"Date Of Birth is : "<<dd<<" / "<<mm<<" / "<<yy<<endl;
    cout<< "Phone  Number is : " << phNo << endl;
    addr.printAddress();

    }

    void printName()
    {
      cout<< "Name is : " << name << endl;
    }

    void writeNameToFile(ofstream &str)
    {
      str<< "Name is: " << name << endl;
    }

    void FileWrite(ofstream &str)
    {
      str<< name << ',';
      str<< phNo << ',';
      str<< reln << ',';
      str<< dd << ',';
      str<< mm << ',';
      str<< yy << ',';
      addr.FileWrite(str);
      str<<"|";

    }

    void printRelation()
    {
      cout<< "The relation is : " << reln << endl;
    }

    void printPhoneNo()
    {
      cout<< "Phone  Number is : " << phNo << endl;
    }

    void printDOB()
    {
      cout<<"Date Of Birth is : "<<dd<<" / "<<mm<<" / "<<yy<<endl;
    }

    void printAddress()
    {
      addr.printAddress();
    }

    void printPerson()
    {
      cout<<endl;
        printName();
	printPhoneNo();
	printRelation();
	printDOB();
        addr.printAddress();
    }

    void populateFromString(char ip[])
    {

        int i = 0,j = 0;

        while (ip[i] != ',')
        {
            name[j++] = ip[i++];
        }
	name[j] ='\0';
        j=0;
        i++;

        while (ip[i] != ',')
        {
            phNo[j++] = ip[i++];
        }
	phNo[j] ='\0';
        j=0;
        i++;

        while (ip[i] != ',')
        {
            reln[j++] = ip[i++];
        }
	reln[j] ='\0';
        j=0;
        i++;

        while (ip[i] != ',')
        {
            dd[j++] = ip[i++];
        }
	dd[j] = '\0';
        j=0;
        i++;

        while (ip[i] != ',')
        {
            mm[j++] = ip[i++];
        }
	mm[j] = '\0';
        j=0;
        i++;

        while (ip[i] != ',')
        {
            yy[j++] = ip[i++];
        }
	yy[j] = '\0';
        j=0;
        i++;

        while (ip[i] != '|')
        {
            addrStr[j++] = ip[i++];
        }

        addrStr[j] = '\0';
        addr.populateFromString(addrStr);
    }

};

class AddressbType
{
  personType *Head;
  char fn[100];

public:

  AddressbType()
  {
    Head = NULL;

    cout<<endl<<"Enter the name of the file to be processed??"<<endl;
    cin>> fn;
    cin.ignore();

    readFromFile(fn);
  }

  ~AddressbType()
  {
    ofstream ofs;
    ofs.open(fn,ios_base::out);

    for(personType *cur = Head; cur != NULL ;cur=cur->next)
    {
      cur->FileWrite(ofs);
      if(cur->next != NULL)
	ofs<<"\n";
    }

    ofs.close();

  }

  void nameFind()
  {
    char find[100];
    int flg=0;

    cout<<"\nType name of person you are searching\n";

    cin.ignore();
    gets(find);

    for(personType * cur = Head; cur!= NULL ; cur = cur->next)
      if(strcmp(cur->name,find) == 0)
      {
          cur->print();
            flg = 1;
      }
      if(flg == 0)
      cout<<find<<" person not found..";
  }

  void FindCategory()
  {
    int flg = 0;
    char find[100];
    ofstream opfs;

    opfs.open("results",ios_base::app);

    cout<<"\nWhat category are you looking for??\n";

    cin>> find;
    cin.ignore();

    for(personType * cur = Head; cur!= NULL ; cur = cur->next)
      if(strcmp(cur->reln,find) == 0)
      {
	cur->printName();
	cur->writeNameToFile(opfs);
	flg = 1;
      }

      if(flg == 0)
      {
	cout<<"No person under the entered category "<<find<<endl;
	opfs<<"No person under the entered category "<<find<<endl;
      }
      opfs.close();
  }

    void readFromFile(char fileName[])
    {
        ifstream fs;
        fs.open(fileName);
	fs.unsetf(ios_base::skipws);	//unset flag to allow reading the white space
        char temp;
	int i = 0,end = 0;

        char record[1000] = "";

        while (!fs.eof())
        {
	  end = 0;
            fs>>temp;
            while (temp != '|')
            {
	      record[end++] = temp;
	      fs>>temp;
            }
            record[end] = '|';

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

	    for(int l=0;l<1000;l++) record[l] = '\0';

	    fs>>temp;
        }
        fs.close();
    }


    void insert()
    {
      personType *temp = new personType();
      char record[1000] = "";
      char name[100],phno[100],reln[100],dd[3],mm[3],yy[3],street[100],city[100],state[100],pincode[7] = "";

      cout<<"Enter details..\n ";
      cout<<"\nName of person";
      cin.ignore();
      gets(name);
      strcat(record,name);
      strcat(record,",");

       cout<<"\nRelation  : ";
      cin>>reln;
      strcat(record,reln);
      strcat(record,",");

      cout<<"\nPhone Number of the person : ";
      cin>>phno;
      strcat(record,phno);
      strcat(record,",");


      cout<<"\nDate of Birth: ";
      cin>>dd;
      strcat(record,dd);
      strcat(record,",");

      cout<<"\nEnter month : ";
      cin>>mm;
      strcat(record,mm);
      strcat(record,",");

      cout<<"\nYear of Birth: ";
      cin>>yy;
      strcat(record,yy);
      strcat(record,",");

      cout<<"\nStreet no.: ";
      cin.ignore();
      gets(street);
      strcat(record,street);
      strcat(record,",");

      cout<<"\nEnter city name: ";
      cin.ignore();
      gets(city);
      strcat(record,city);
      strcat(record,",");

      cout<<"\nState: ";
      cin.ignore();
      gets(state);
      strcat(record,state);
      strcat(record,",");

      cout<<"\n Enter Pincode..It shoulb be of six digit: ";
      cin>>pincode;

      while(strlen(pincode)!=6)
      {
      cout<<"\nPlease enter a valid Pincode: ";
      cin>>pincode;
      }

      strcat(record,pincode);
      strcat(record,",|\n");

      cout<<record;

      temp->populateFromString(record);

      temp->next = Head;
      Head = temp;

    }

    void del()
    {
      char find[100];
      int flg = 0;
      personType *temp=Head;
      cout<<"\nEnter the Name that is to be deleted...\n\n";
      cin.ignore();
      gets(find);

      if(strcmp(Head->name,find)==0)
      {
	personType * del = Head;
	Head = Head->next;
	delete del;
	flg++;//for(personType *temp = Head; temp != NULL && temp->next != NULL ;temp = temp->next)
      }


while( temp != NULL && temp->next != NULL)
	{

          if(strcmp(temp->next->name,find)==0)
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

  int enterchoice;

  do
  {
    cout<<"\n__\n Enter:\n 1 > Enter name of a person to search \n 2 >Enter category to find related contacts\n 3 > Enter name to delete contacts\n 4 > Enter to insert contact\n 5 > Exit..\n";

    cin>> enterchoice;
   //cin.ignore();

    switch(enterchoice)
    {
      case 1: b.nameFind();
	      break;

      case 2:b.FindCategory();
	      break;

      case 3:b.del();
	      break;

      case 4:b.insert();
	      break;

      case 5:
	cout<<"";
	return 0;

      default: cout<<endl<<"Invalid option"<<endl;
    }
  }while(1);
    return 0;
}
