%{
#define T_eof 0
#define T_and 1001 
#define T_char 1002
#define T_div 1003
#define T_do 1004
#define T_else 1005
#define T_fun 1006
#define T_if 1007
#define T_int 1008
#define T_mod 1009
#define T_not 1010
#define T_nothing 1011
#define T_or 1012
#define T_ref 1013
#define T_return 1014
#define T_then 1015
#define T_var 1016
#define T_while 1017
#define T_id 1018
#define T_inter 1019
#define T_const 1020
#define T_charr 1021
#define T_string 1022
#define T_array 1023
#define T_arrow 1024
#define T_smaller 1025
#define T_greater 1026
%}

L [A-Za-z]
D [0-9]
H [0-9]|[A-Fa-f]
%option noyywrap
int lineno = 1;
%x COMMENT

%%
"and" {return T_and;}
"char" {return T_char;}
"div" {return T_div;}
"do" {return T_do;}
"else" {return T_else;}
"fun" {return T_fun;}
"if" {return T_if;}
"int" {return T_int;}
"mod" {return T_mod;}
"not" {return T_not;}
"nothing" {return T_nothing;}
"or" {return T_or;}
"ref" {return T_ref;}
"return" {return T_return;}
"then" {return T_then;}
"var" {return T_var;}
"while" {return T_while;}
"<-" {return T_arrow;}
"<=" {return T_smaller;}
">=" {return T_greater;}
{L}({L}|{D}|_)* {return T_id;}
{D}+ {return T_inter;}
{D}+(\.{D}*(e\-?{D}+)?)? { return T_const; }
\"[^"\n]*\" {return T_string;}

\'[^'^"^\\]\'  {return T_charr;}
\'"\\t"\' {return T_charr;}
\'"\\0"\' {return T_charr;}
\'"\\r"\' {return T_charr;}
\'"\\n"\' {return T_charr;}
\'"\\\\"\' {return T_charr;}
\'"\\\'"\' {return T_charr;}
\'"\\\""\' {return T_charr;}
\'"\\ "\' {return T_charr;}
\'\\(x{H}{H})\' {return T_charr;}
[\(\)\[\]\{\}\,\;\:] {return yytext[0];}
[\=\+\-\*\#\<\>] {return yytext[0];}

"$$" {BEGIN(COMMENT);}
<COMMENT>"$$" {BEGIN(INITIAL);}                     //Energos kanonas mono sthn katastasi COMMENT
<COMMENT>\n {yylineno++;}
<COMMENT>"$" {/* nothing */;} 
<COMMENT>[^$\n]+ {/* nothing */;}

\$.+ {/* nothing */;}
[ \t]+ { /* nothing */;}
\n { yylineno++; } 

. {fprintf(stderr, "illegal character'%c' (ASCII: %d), Error line %d \n",yytext[0],yytext[0],yylineno); exit(1);}
%%

int main(){
	int token;
	do{
		token= yylex();
		printf("token=%d,lexeme=\"%s\"\n",token,yytext);
	}while (token!= T_eof);
}
