//Title:Program to print the contents of a file in reverse order of lines
//Author: Avinash.A

#include <iostream>
#include <stdio.h>

using namespace std;

void revPrint(FILE *fp)
{
  char temp;
  fpos_t pos;	//stores   beginning of line
  
  
  //store start position of the current line in the file
  fgetpos(fp,&pos);
  
  
  //traverse to end of line
  temp = (char)fgetc(fp);
    
  if(temp == EOF)
    return;
  
  while(temp != EOF && temp != '\n')
  {
    temp = (char)fgetc(fp);
  }
 //EOF
 
  revPrint(fp);
  
  //Rewind the file-ptr to the beginning of the current line
  fsetpos(fp,&pos);
  
  //Display the current line
  temp = (char)fgetc(fp);
  while(temp != EOF && temp != '\n')
  {
    cout<<temp;
    temp = (char)fgetc(fp);
  }
    cout<<endl;
}

int main()
{

    FILE *fp;
    int i=0;
    //open the file pointer
    fp = fopen("test.txt","r");
    
    //function call which is reccursive 
    revPrint(fp);
    //close the file pointer
    fclose(fp);
    return 0;
} 
 
