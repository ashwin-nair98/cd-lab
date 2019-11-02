%{
	#include <string.h>
	int COMMENT=0;
	char keywords[18][20], identifiers[50][50], operators[20][3];
	int keyWordCount = 0, identifierCount = 0, operatorCount=0;
	int checkKeyword(char *word){
		int i = 0, fl =1;
		for(i=0;i<keyWordCount;i++)
			if(strcmp(keywords[i], word) == 0){
				fl = 0;
				break;
			}
		if(fl){
			strcpy( keywords[keyWordCount++], word);
		}
		return fl;
	}
	
	int checkIdentifier(char *word){
		int i = 0, fl =1;
		for(i=0;i<identifierCount;i++)
			if(strcmp(identifiers[i], word) == 0){
				fl = 0;
				break;
			}
		if(fl){
			strcpy(identifiers[identifierCount++], word);
		}
		return fl;
	}
	int checkOperator(char *word){
		int i = 0, fl = 1;
		for(i=0; i<operatorCount;i++)
			if(strcmp(operators[i], word)==0)
			{	fl = 0;
				break;
			}
		if(fl){
			strcpy(operators[operatorCount++], word);
		}
		return fl;
	} 
	
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%
#.* {
	printf("\n%s is a preprocessor directive",yytext);
	}
int |
float |
char |
double |
while |
for |
struct |
typedef |
do |
if |
break |
continue |
void |
switch |
return |
else |
goto {if(checkKeyword(yytext)) printf("\n%s is a KEYWORD",yytext);}
"/*" {COMMENT=1;}{printf("\n %s is a COMMENT",yytext);}
\+ |
\- |
\/ |
\% {printf("\n %s is an OPERATOR", yytext);}
{identifier}\( {if(!COMMENT)printf("\nFUNCTION \n%s",yytext);}
\{  {if(!COMMENT)printf("\n BLOCK BEGINS");}
\}  {if(!COMMENT)printf("BLOCK ENDS ");}
{identifier}(\[[0-9]*\])? {if(!COMMENT) if(checkKeyword(yytext)) printf("\n %s is an IDENTIFIER",yytext); }
\".*\" {if(!COMMENT)printf("\n %s is a STRING",yytext);}
[0-9]+ {if(!COMMENT) printf("\n %s is a NUMBER ",yytext);}
\)(\:)? {if(!COMMENT)printf("\n");ECHO;printf("\n");}
\( ECHO;
= {if(!COMMENT) if(checkOperator(yytext)) printf("\n %s is an ASSIGNMENT OPERATOR",yytext);}
\<= |
\>= |
\< |
== |
\> {if(!COMMENT) if(checkOperator(yytext)) printf("\n%s is a RELATIONAL OPERATOR",yytext);}
%%
int main(int argc, char **argv)
{
FILE *file;
file=fopen("var.c","r");
if(!file)
{
printf("could not open the file");
exit(0);
}
yyin=file;
yylex();
printf("\n");
return(0);
}
int yywrap()
{
return(1);
}
