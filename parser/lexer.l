%{
#include "lexer.hpp"	
#include "parser.hpp"	

#define T_eof 0
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

. {yyerror("illegal character");}
%%

