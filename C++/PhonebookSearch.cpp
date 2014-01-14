#include<iostream>
#include<string.h>
#include<fstream>
#include<stdio.h>

using namespace std;


ifstream data1 ("data", ios::in);
ifstream data2 ("Data", ios::in);

char ch=',';
string s;
class addressType{
    string address[4];

    public:
    void store_add(){


       if (data1.is_open())
            {

            int i=0;
            while(i<4){
                getline (data1,s,ch);
                address[i]=s;
                i++;


            }

  }

  else cout << "Unable to open file";
    }


    void print_add(){
    for(int i=0;i<4;i++){
    cout<<address[i]<<endl;
    }
    }
                    };

class personType{
    int i;
public:
   addressType sample;
   string personInfo[5];
   public:
   void load(){
       sample.store_add();
    if (data2.is_open())
            {

            for(i=0;i<5;i++)
            {
                getline (data2,s,ch);
                personInfo[i]=s;
            }
}
else cout << "Unable to open file";
    }

    void print(){

        for(i=0;i<5;i++){
        cout<<personInfo[i]<<endl;
        }
    }
};

class addressBookType{
                        int i,size;
                        public: personType *person;
                public:
                        addressBookType(int a){
                                            size=a;
                                            person=new personType[size];
                                            }

                        void load_data(){
                                for(i=0;i<size;i++)
                                {person[i].load();}
                                }

                        void search1(char* name){
                                for(i=0;i<size;i++){
                                        string ptr=person[i].personInfo[1];
                                        char *a=new char[ptr.size()+1];
                                        a[ptr.size()]=0;
                                        strcpy(a,ptr.c_str());

                                        if(strcmp(name,a)==0)
                                            {cout<<"DOB: "<<person[i].personInfo[2]<<endl<<"phone no: "<<person[i].personInfo[3]<<endl<<"Address:";
                                            person[i].sample.print_add();
                                            return ;
                                            }
                                        }
                        cout<<"not found"<<endl;
                        }

                    void search2(char* status){
                                            int flag=1;
                                            for(i=0;i<size;i++){
                                                string ptr1=person[i].personInfo[4];
                                                char *a=new char[ptr1.size()+1];
                                                a[ptr1.size()]=0;
                                                strcpy(a,ptr1.c_str());

                                                if(strcmp(status,a)==0)
                                                    {cout<<person[i].personInfo[1]<<endl;
                                                    flag=0;
                                                        }
                                                }
                                            if(flag!=0)
                                            cout<<"not found"<<endl;
                                            cout<<endl;
                                        }

                    };


int main(){

    int NoEntries;
    char choice;

    cout<<"enter total number of entries"<<endl;
    cin>>NoEntries;

    addressBookType book(NoEntries);
    book.load_data();

    char str[100];


cout<<"Enter your choice:\n 1. search entry by name \n 2.search people in particular status \n 3. To exit \n";
    cin>>choice;

    do{
    switch(choice)
    {
        case '1':
                cout<<"enter name\n";
                cin.ignore();
                gets(str);

                cout<<endl<<"search by name result:"<<endl<<endl;
                book.search1(str);
                break;

        case '2': cout<<"enter status to be searched\n";
                cin.ignore();
                gets(str);

                cout<<endl<<"person(s) in required status:"<<endl<<endl;
                book.search2(str);
                break;

        case '3': cout<<"have a nice day";
                return 0;

        default: cout<<"enter valid choice"<<endl;
    }
    cout<<endl;
    cout<<"Enter your choice:\n 1. search entry by name \n 2.search people in particular status \n 3. To exit \n";
    cin>>choice;

    }while(choice!='3');

return 0;
}
