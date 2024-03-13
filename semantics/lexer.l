%option noyywrap
%{
#include <cstdio>
#include <cstdlib>
#include "ast.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include <string.h>
%}
L [A-Za-z]
D [0-9]
H [0-9]|[A-Fa-f]

int lineno = 1;
%x COMMENT

%%
"and" {yylval.op = 'p';return T_and;}
"char" {return T_char;}
"div" {yylval.op = 'd';return T_div;}
"do" {return T_do;}
"else" {return T_else;}
"fun" {return T_fun;}
"if" {return T_if;}
"int" {return T_int;}
"mod" {yylval.op = 'm';return T_mod;}
"not" {return T_not;}
"nothing" {return T_nothing;}
"or" {yylval.op = 'o';return T_or;}
"ref" {return T_ref;}
"return" {return T_return;}
"then" {return T_then;}
"var" {return T_var;}
"while" {return T_while;}
"<-" {return T_arrow;}
"<=" {yylval.op = 's'; return T_smaller;}
">=" {yylval.op = 'g'; return T_greater;}
{L}({L}|{D}|_)* {yylval.RepString = strdup(yytext); return T_id;}

{D}+ {yylval.num = atoi(yytext); return T_const;}
\"[^"\n]*\" {yylval.RepString = strdup(yytext); return T_string;}


\'[^'^"^\\]\' {yylval.var=yytext[1];return T_charr;}
\'"\\t"\' {yylval.var='a';return T_charr;}
\'"\\0"\' {yylval.var='b'; return T_charr;}
\'"\\r"\' {yylval.var='c';return T_charr;}
\'"\\n"\' {yylval.var='d';return T_charr;}
\'"\\\\"\' {yylval.var='e';return T_charr;}
\'"\\\'"\' {yylval.var='f';return T_charr;}
\'"\\\""\' {yylval.var='j';return T_charr;}
\'"\\ "\' {yylval.var='i';return T_charr;}
\'\\(x{H}{H})\' {yylval.varr=strdup(yytext);return T_charra;}

[\(\)\[\]\{\}\,\;\:] {return yytext[0];}
[\=\+\-\*\#\<\>] {yylval.op=yytext[0];return yytext[0];}

"$$" {BEGIN(COMMENT);}
<COMMENT>"$$" {BEGIN(INITIAL);}                     //Energos kanonas mono sthn katastasi COMMENT
<COMMENT>\n {yylineno++;}
<COMMENT>"$" {/* nothing */;} 
<COMMENT>[^$\n]+ {/* nothing */;}

\$.+ {/* nothing */;}
[ \t]+ { /* nothing */;}
\n { yylineno++; }  

. {yyerror("lexical error");}
%%

void yyerror(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(1);
}	
