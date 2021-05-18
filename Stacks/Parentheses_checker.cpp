#include<string.h>
#include<conio.h>
#include<iostream>
#define MAX 10
using namespace std;
int top=-1, stack[MAX];
//Function declaration
void push(char);
char pop();
int main()
{
    char exp[MAX],temp;
    int i,flag=1;
    cout<<"Enter the Expression: ";
    gets(exp);
    for(i=0;i<strlen(exp);i++)
    {
        //checks for opening bracket and push it into stack
        if(exp[i]=='('||exp[i]=='['|| exp[i]=='{')
        {
            push(exp[i]);
        }
        //checks for closing brackets
        if(exp[i]==')'||exp[i]==']'|| exp[i]=='}')
        {
            if(top==-1)
            {
                flag=0;
            }
            else
            {
                temp=pop();
                if((exp[i]==')')&&(temp=='{'||temp=='['))
                {
                    flag=0;
                }
                if((exp[i]=='}')&&(temp=='('||temp=='['))
                {
                    flag=0;
                }
                if((exp[i]==']')&&(temp=='('||temp=='{'))
                {
                    flag=0;
                }
            }
        }
    }
    if(top>=0)
    {
        flag=0;
    }
    if(flag==1)
    {
        cout<<"\nValid Expression!";
    }
    else
    {
        cout<<"\nInvalid Expression!";
    }
} //main function terminates
void push(char c)
{
    if (top==(MAX-1))
    {
        printf("\nStack Overflow!");
    }
    else
    {
        top++;
        stack[top]=c;
    }
}
char pop()
{
    if(top==-1)
    {
        cout<<"\nStack Underflow!";
    }
    else
    {
        return(stack[top--]);
    }
}
