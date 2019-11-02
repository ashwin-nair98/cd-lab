%{
#include<stdio.h>
#include "lex.yy.c"
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%%
st: exp {printf("Result: %d",$$);}
    ;
exp: exp '+' exp {$$ = $1 + $3;}
    |exp '-' exp {$$ = $1 - $3;}
    |exp '*' exp {$$ = $1 * $3;}
    |exp '/' exp {$$ = $1 / $3;}
    |'('exp')' {$$ = $2;}                                   
    |NUMBER {$$ = $1;}
    ;
%%
int main()
{	
	printf("Enter expression: ");
        yyparse();
        return 0;
}
yyerror(char *s)
{
        printf("error:%s",s);
}
