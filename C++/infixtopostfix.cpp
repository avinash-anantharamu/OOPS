
#include <iostream>

#include <stack>
#include <string>

using namespace std;

char prec[4];
int pre_val[4];

class I2P
{
    public:
	void Init();       
        void getexpr();
        void printexpr();
        void printpostexpr();
		// this function returns the precedence among the operators
		int precedence(char c); 
   
    protected:

    private:
		stack< char > Stack_expr;
		string infix;
		string postfix;
		char c;
};


int I2P::precedence(char c)
{
	   int i;
	   for(i=0;i<4;i++)
	   {
			if(prec[i]== c)
				return pre_val[i];
       }
	   return -1;
 }
void I2P::Init()
{
		Stack_expr.push( '(' );

}
void I2P::getexpr()
{
		cout << "Enter infix expression: " ;
		cin >> infix;                        				
}

void I2P::printexpr()
{
    cout << "The Infix expression entered: " << infix << endl;
}
	

void I2P::printpostexpr()
{
    for(int i=0; i <infix.size(); i++)
    {
        if ( (infix[i] >= '0' && infix[i] <='9') || (infix[i] >='a' && infix[i] <='z') ||(infix[i] >='A' && infix[i] <='B') )
		//Alpha numeric	variables or constants in postfix				        
{
            postfix = postfix + infix[i] + " " ;

        }
		else if ( infix[i] =='/' || infix[i] == '*' || infix[i] == '+' || infix[i] == '-' || infix[i] == '(' )
        {
                  c=infix[i];    
				  while(precedence(c)<precedence(Stack_expr.top()))
				  {	
						postfix = postfix + Stack_expr.top() + " "; 
						Stack_expr.pop();
				  }
				  Stack_expr.push( c );    //symbols on stack
        }
        else if( infix[i] == ')')
        {
				while( !Stack_expr.empty() && !(Stack_expr.top() == '(' ) )
				{
					postfix = postfix + Stack_expr.top() + " ";                       
					// pop if its a symbol
					Stack_expr.pop();
				}
				Stack_expr.pop();                                                         
		}
      else 
	  { 
				cout<<"Wrong input"<<endl;return;
	  }

      if ( i == (infix.size()-1) )
      {
            while( !Stack_expr.empty() && !(Stack_expr.top() == '(' ) )
            {
                postfix = postfix + Stack_expr.top() + " "; // end of expr.
                Stack_expr.pop();
                                                         
            }

       }
    }

    cout << endl << "Prefix: " << postfix << endl;

}
int main()
{
   
    pre_val[0]=4;pre_val[1]=3;pre_val[2]=2;pre_val[3]=1;
    prec[0]='/';prec[1]='*';prec[2]='+';prec[3]='-';
    I2P obj;
    obj.Init();
    obj.getexpr();
    obj.printexpr();
    obj.printpostexpr();
    return 0;
}
