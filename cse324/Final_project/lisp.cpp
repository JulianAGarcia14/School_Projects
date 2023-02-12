#include<iostream>
#include<sstream>
#include<stdio.h>
#include<list>
#include<string>
#include<cmath>
using namespace std;



inline bool ischar(char c)
{
    return c>='A' && c<='z';
}

inline bool isint(char c)
{
    return c>='0' && c<='9';
}

std::string vars[20][2] = {
  { "a", "20"},
  { "b", "40"}
};

class Lisp
{
private:
    enum tok { TOK_STOP,TOK_BRKSTART,TOK_BRKSTOP,TOK_NUM,TOK_OPERATOR,TOK_FUNCTION, TOK_CHAR};//the token types
    struct Token
    {
        tok tokentype;
        double value;
        string name;
        Token(tok toktype,double val=0, string nam=""):tokentype(toktype),value(val),name(nam)
        {}
    };

    //functions with one or two parameters
    typedef double(*oneparamfunc)(double);
    typedef double(*twoparamfunc)(double,double);

    struct function
    {
        oneparamfunc func;
        int params;
        string name;
    };
    static function funcs[]; //contains all the functions

    static int nofuncs;//the total number of function

    stringstream expression;//where we store the expression to be parsed
    Token GetNextToken();
    void Skipspace()
    {
        while(expression.peek() == ' ')
            expression.get();
    }
    double applyoper(double val1,double val2,char oper)
    {
        switch(oper)
        {
        case '+':
            return val1+val2;
        case'-':
            return val1-val2;
        case '*':
            return val1*val2;
        case '/':
            return val1/val2;
        case '<':
            if(val1 < val2) {
                    return 1;
            } else{
                return 0;
            }

        case '>':
            if(val1 > val2) {
                return 1;
            } else{
                return 0;
            }

        case '=':
            if(val1 == val2) {
                return 1;
            } else{
                return 0;
            }
        case '!':
            if(val1 != val2) {
                return 1;
            } else{
                return 0;
            }


        }
        return 0;

    }
public:
    struct Error{
        string error;
        int pos;
        Error(const string& err,int position):error(err),pos(position){}
    };
    struct Literal{
        string literal;
        int pos;
        Literal(const string& lit,int position):literal(lit),pos(position){}
    };
    //Passes an expression which is written to the stringstream expression by stringstream write function
    void SetExpression(const string& Expression)
    {
        expression.write(Expression.c_str(),Expression.size());
    }
    double Parse();
};

double mod(double a,double b)
{
    return long(a)%long(b);
}

//stringstream define(sringstream a, stringstream b)
//{
//    return long(a)%long(b);
//}

Lisp::function Lisp::funcs[]={
    {sqrt,1,"sqrt"},
    //{lisp_list,1," "},
    //{(oneparamfunc)((twoparamfunc)mod),2,"car"},
    //{(oneparamfunc)((twoparamfunc)mod),2,"cdr"},
    //{(oneparamfunc)((twoparamfunc)mod),2,"cons"},

    //{(oneparamfunc)((twoparamfunc)define),2,"define"}, // to define variables

    //{(oneparamfunc)((twoparamfunc)mod),2,"conditional"}, //not sure if this matters
    //{(oneparamfunc)((twoparamfunc)mod),2,"setassign"}, // to set variables to expressions
    {(oneparamfunc)((twoparamfunc)pow),2,"pow"}

};

int Lisp::nofuncs=24;

Lisp::Token Lisp::GetNextToken()
{
    Skipspace();
    if(expression.peek()== EOF)
        return Token(TOK_STOP);
    if(expression.peek()=='(')
    {
        expression.get();
        return Token(TOK_BRKSTART);
    }
    if(expression.peek()==')')
    {
        expression.get();
        return Token(TOK_BRKSTOP);
    }
    if(string("+-*/<>=!").find(expression.peek()) != string::npos)
    {
        int opid=expression.get();
        //check to see if it is really an operator
        if(expression.peek() != ' ')//since there is no space after the operator, it can be a unary negation sign
            expression.unget();
        else
            return Token(TOK_OPERATOR,opid);
    }

    if(isint(expression.peek()) || expression.peek() == '-')
    {
        double val;
        //shift to see whats next
        expression>>val;
        //the number MUST be followed by space or closing bracket
        //if(expression.peek() != ' ' && expression::ws.peek() != ')')
            //throw Error("Invalid character after number ",expression.tellg());
            //throw Literal("T\n", expression.tellg());
            //cout<<"T";
        return Token(TOK_NUM,val);
    }

    if( expression.peek() == 'T') {
        double val;
        string nam;
        //shift to see whats next
        expression>>val;
        expression>>nam;
        return Token(TOK_CHAR,val, nam);
    }

    if( ischar(expression.peek()) )
    {
        double val;
        string nam;
        //shift to see whats next

        expression>>nam;
        //cout<<nam;
        expression>>val;

        return Token(TOK_CHAR,val, nam);
    }


    int curpos=expression.tellg();
    string fname;//name of the expression
    expression>>fname;
    for(int i=0;i<nofuncs;i++)
    {
        if(funcs[i].name == fname)
        {
            return Token(TOK_FUNCTION,i);
        }
    }
    throw Error("Invalid character",expression.tellg());
}


//template <typename T>
double Lisp::Parse()
{
    int curpos=expression.tellg();
    Token tok=GetNextToken();
    if(tok.tokentype == TOK_NUM)
    {
        return tok.value;
    }

    if(tok.tokentype == TOK_CHAR)
    {
        for (int i = 0; i < 20; i++) {
                if(tok.name == vars[i][0]) {
                        return stod(vars[i][1]);
                }
        }
        for (int i = 0; i < 20; i++) {
                if(vars[i][0] == "") {
                        vars[i][0] = tok.name;
                        Token tok1=GetNextToken();
                        std::cout<<tok1.value;
                        vars[i][1] = to_string(tok1.value);
                        throw Literal("", expression.tellg());
                }
        }
    }
    //if not a number then we expect an expression
    if(tok.tokentype != TOK_BRKSTART)
        throw Error("Expected ( ",curpos);

    Token tokop=GetNextToken();
    if(tokop.tokentype !=TOK_OPERATOR && tokop.tokentype !=TOK_FUNCTION)
    {
        throw Error("Expected operator or function ",curpos);
    }
    //case when the token parses to a function
    if(tokop.tokentype ==TOK_FUNCTION)
    {
        //set function id to the function value
        int fid=tokop.value;

        //find how many parameters we need
        double* params=new double[funcs[fid].params];

        for(int j=0;j<funcs[fid].params;j++)
        {
            params[j]=Parse();
        }

        //apply the function
        double Ret;
        if(funcs[fid].params == 1)
            Ret= (* reinterpret_cast<oneparamfunc>(funcs[fid].func))(params[0]);
        else
            Ret= (* reinterpret_cast<twoparamfunc>(funcs[fid].func))(params[0],params[1]);
        delete []params;

        int curpos=expression.tellg();
        Token end=GetNextToken();
        if(end.tokentype != TOK_BRKSTOP)
            throw Error("Expected ) ",curpos);
        return Ret;
    }
    //else
    //get the number
    double num1,num2;//num1 is the result
    num1=Parse();
    while(1)
    {
        num2=Parse();
        num1=applyoper(num1,num2,tokop.value);
        int curpos=expression.tellg();
        Token nexttoken=GetNextToken();
        if(nexttoken.tokentype == TOK_BRKSTOP)
        {
            return num1;
        }
        if(nexttoken.tokentype == TOK_STOP)
            throw Error("Unexpected end of line ",expression.tellg());
        //restore the position
        expression.seekg(curpos);
    }

}
int main()
{
    cout<<"Welcome to the incomplete lisp interpreter\n";
    for(;;)
    {
        cout<<">>> ";
        string s;
        getline(cin,s);
        Lisp environ;
        environ.SetExpression(s);
        if(s.size()==0)
            return 0;
        try
        {
            cout<<environ.Parse()<<endl;
        }
        catch(const Lisp::Error& error)
        {
            cout<<"Error: "<<error.error<<" at position "<<error.pos+1<<endl;
        }
        catch(const Lisp::Literal& literal)
        {
            cout<<literal.literal;
        }
    }
    return 0;
}
