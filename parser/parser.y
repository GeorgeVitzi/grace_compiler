%{
#include "lexer.hpp"
#include <cstdio>
#include <cstdlib>
%}

%token T_and "and"
%token T_char "char"
%token T_div "div"
%token T_do "do"
%token T_else "else"
%token T_fun "fun"
%token T_if "if"
%token T_int "int"
%token T_mod "mod"
%token T_not "not"
%token T_nothing "nothing"
%token T_or "or"
%token T_ref "ref"
%token T_return "return"
%token T_then "then"
%token T_var "var"
%token T_while "while"
%token T_arrow "<-"
%token T_smaller "<="
%token T_greater ">="
%token T_id 
%token T_inter 
%token T_const 
%token T_charr 
%token T_string 

%left "or" "and"
%nonassoc '=' '#' '>' '<' "<=" ">=" "not"
%left '+' '-'
%left '*' "div" "mod"


%expect 1
%%

program:
  /*nothing*/
  |func-def
;
 
func-def:
  header local-deff block                                       
| header block
;

local-deff:
  local-def
| local-deff local-def
;

header:
  "fun" T_id '(' ')' ':' ret-type
| "fun" T_id '(' fpar-def ')' ':' ret-type
;

fpar-def:
  T_id ':' fpar-type
| T_id ':' fpar-type ';' fpar-def
| T_id fapar-def ':' fpar-type
| T_id fapar-def ':' fpar-type ';' fpar-def
| "ref" T_id ':' fpar-type
| "ref" T_id ':' fpar-type ';' fpar-def
| "ref" T_id fapar-def':' fpar-type
| "ref" T_id fapar-def':' fpar-type ';' fpar-def
;

fapar-def:
  ',' T_id 
| ',' T_id fapar-def
;

data-type:
  "int"
| "char"
;

type:
  data-type typee
| data-type
;

typee:
  '[' T_inter ']' typee
| '[' T_inter ']'
;

ret-type:
  data-type
| "nothing"
;

fpar-type:
  data-type '[' ']' typee
| data-type '[' ']'
| data-type typee
| data-type 
;

local-def:  
  func-def
| func-decl
| var-def
;

func-decl:
  header ';'
;

var-def:
  "var" T_id fapar-def ':' type ';'
| "var" T_id ':' type ';'
;

stmt:
  ';'
| l-value "<-" expr ';'
| block
| func-call ';'
| "if" cond "then" stmt
| "if" cond "then" stmt "else" stmt
| "while" cond "do" stmt 
| "return" ';'
| "return" expr ';'
;

block:
 '{' sol '}' 
| '{' '}'
;

sol:
  stmt
| sol stmt
;

func-call:
  T_id '(' ')' 
| T_id '('expr vitzilante ')' 
| T_id '(' expr ')' 
;

vitzilante:
 ',' expr
|',' expr vitzilante
;

l-value:
  T_id 
| T_string
| l-value '[' expr ']'
;

expr:
  T_inter
| T_charr
| T_const
| l-value
| '(' expr ')'
| '+' expr
| '-' expr
| func-call
| expr '+' expr
| expr '-' expr
| expr '*' expr
| expr "div" expr
| expr "mod" expr
;

cond:
  '(' cond ')' 
| "not" cond
| cond "and" cond
| cond "or" cond
| expr '=' expr
| expr '#' expr
| expr '<' expr
| expr '>' expr
| expr "<=" expr
| expr ">=" expr
;

%%
void yyerror(const char *msg){
	fprintf(stderr, "Error:%s\n",msg);
	exit(1);
}
int main(){
	int result = yyparse();
	if (result == 0) printf("Success. \n");
	return result;
} 
