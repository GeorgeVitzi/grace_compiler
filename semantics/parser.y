%{
#include <cstdio>
#include "ast.hpp"
#include "lexer.hpp"
#include <iostream>
#include <string>
SymbolTable st;
std::map<char, int> globals;

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
%token<num> T_const 
%token T_charra
%token<var> T_charr
%token T_string 

%left<op> "or" "and"
%nonassoc<op> '=' '#' '>' '<' "<=" ">=" "not"
%left<op> '+' '-'
%left<op> '*' "div" "mod"


%expect 1

%union {
  Funcdef *funcdef;
  Fpartype *fpartype;
  Head *head;
  Localdeff *localdeff;
  Localdef *localdef;
  Vardef *vardef;
  Declaration *decl;
  Funcdecl *funcdecl;
  Block *blocks;
  Lvalue *lvalue;
  Sol *soll;
  Stmt *stmts;
  Fpardef *fpardef;
  Newdef *newdef;
  Funccall *funccall;
  Comma *comma;
  Box *vox;
  Expr *exprs;
  Cond *conds;
  Type type;

  char* varr;
  char var;
  int num;
  char op;
  char*  RepString;       
}


%type<funcdef> func-def
%type<fpartype> fpar-type
%type<newdef> new-def
%type<head> header
%type<vardef> var-def
%type<localdeff> local-deff
%type<localdef> local-def
%type<decl> declaration
%type<funcdecl> func-decl
%type<blocks> block
%type<soll> sol
%type<stmts> stmt
%type<fpardef> fpar-def
%type<vox> box
%type<lvalue> l-value
%type<funccall> func-call
%type<comma> komma
%type<exprs> expr
%type<conds> cond
%type<type> data-type
%type<RepString> T_string T_id
%type<varr> T_charra

%%

program:    
  func-def{
  $1->sem(); 
  //std::cout << "AST: " << *$1 << std::endl;
  }
;
 
func-def:    
  header local-deff block { $$ = new Funcdef_default($1,$3,$2);}                                     
| header block { $$ = new Funcdef_default($1,$2); }
;

local-deff:  //block 
  local-def {$$=new Localdeff($1);}
| local-deff local-def {$1->append_blc($2); $$ = $1;}
;

local-def:
  func-def {$$= new Localdef_1($1);}
| func-decl {$$= new Localdef_2($1);}
| var-def {$$= new Localdef_3($1);}
;

header: //block     
  "fun" T_id '(' ')' ':' data-type {$$= new Head($2,$6);}
| "fun" T_id '(' fpar-def ')' ':' data-type {$$=new Head($2,$7,$4);}
;

fpar-def: 
  T_id ':' fpar-type ';' fpar-def {$$= new Fpardef_1($1, $3, $5);}
| T_id ':' fpar-type { $$= new Fpardef_1($1, $3); }
| T_id new-def ':' fpar-type ';' fpar-def {$$= new Fpardef_2($1, $2,$4,$6);}
| T_id new-def ':' fpar-type { $$= new Fpardef_2($1, $2,$4); }
| "ref" T_id ':' fpar-type ';' fpar-def {$$= new Fpardef_3($2, $4, $6);}
| "ref" T_id ':' fpar-type { $$= new Fpardef_3($2, $4); }
| "ref" T_id new-def ':' fpar-type ';' fpar-def {$$= new Fpardef_4($2, $3,$5, $7);}
| "ref" T_id new-def ':' fpar-type { $$= new Fpardef_4($2, $3,$5); }
;

new-def: 
  ',' T_id {$$= new Newdef($2);}
| ',' T_id new-def{$$=new Newdef($2,$3);} 
;

data-type: 
  "int"  {$$=TYPE_int;}
| "char" {$$=TYPE_char;}
| "nothing" {$$=TYPE_nothing;}
;

declaration: 
  data-type box {$$= new Declaration($1,$2);}
| data-type {$$= new Declaration($1);}
;

box: 
  '[' T_const ']' box {$$= new Box($2,$4);}
| '[' T_const ']' {$$= new Box($2);}
;

fpar-type: 
  data-type '[' ']' box {$$= new Fpartype_1($1,$4);}
| data-type '[' ']' {$$= new Fpartype_1($1);}
| data-type box {$$= new Fpartype_2($1,$2);}
| data-type  {$$= new Fpartype_2($1);}
;

func-decl: //block
  header ';' {$$=new Funcdecl($1);}
;

var-def: //block
  "var" T_id new-def ':' declaration ';' {$$=new Vardef($2,$5,$3);}
| "var" T_id ':' declaration ';' {$$=new Vardef($2,$4);}
;

stmt: 
  ';' {$$= new Finish_1();}
| l-value "<-" expr ';' {$$= new Stmt_lvalue($1,$3);}
| block {$$= new Stmt_block($1);}
| func-call ';' {$$=new Stmt_func($1);}
| "if" cond "then" stmt {$$= new If($2,$4);}
| "if" cond "then" stmt "else" stmt  {$$= new If($2,$4,$6);}
| "while" cond "do" stmt {$$= new While($2,$4);}
| "return" ';' {$$= new Finish_2();}
| "return" expr ';'{$$=new Finish_2($2);}
;

block: //block
 '{' sol '}' {$$= new Block_default($2);}
| '{' '}' {$$= new Block_default();}
;

sol: 
  stmt {$$=new Sol($1);}
| sol stmt {$$= new Sol($2,$1);}
;

func-call: 
  T_id '(' ')' {$$=new Funccall_default($1);}
| T_id '('expr komma ')' {$$=new Funccall_default($1,$3,$4);}
| T_id '(' expr ')' {$$=new Funccall_default($1,$3);}
;

komma:
 ',' expr {$$= new Comma($2);}
|',' expr komma {$$= new Comma($2,$3);} 
;

l-value: 
  T_id {$$= new Id($1);}
| T_string {$$= new String($1);}
| l-value '[' expr ']' {$$=new Lval_expr($1,$3);}
;

expr: 
  T_charr {$$= new Char($1);}
| T_charra {$$= new Chara($1);}
| T_const {$$= new Const($1);}
| l-value {$$= new Expr_lval($1);}
| '(' expr ')' {$$= $2;}
| '+' expr {$$= new Exprplas($2);}
| '-' expr {$$= new Exprsub($2);}
| func-call {$$= new Expr_func($1);}
| expr '+' expr {$$= new BinOp($1,$2,$3);}
| expr '-' expr {$$= new BinOp($1,$2,$3);}
| expr '*' expr {$$= new BinOp($1,$2,$3);}
| expr "div" expr {$$= new BinOp($1,$2,$3);}
| expr "mod" expr {$$= new BinOp($1,$2,$3);}
;

cond: 
  '(' cond ')'{$$=$2;}
| "not" cond {$$= new Cond_st1($2);}
| cond "and" cond {$$= new BinOp_cond($1,$2,$3);}
| cond "or" cond {$$= new BinOp_cond($1,$2,$3);}
| expr '=' expr {$$= new BinOp_expr($1,$2,$3);}
| expr '#' expr {$$= new BinOp_expr($1,$2,$3);}
| expr '<' expr {$$= new BinOp_expr($1,$2,$3);}
| expr '>' expr {$$= new BinOp_expr($1,$2,$3);}
| expr "<=" expr {$$= new BinOp_expr($1,$2,$3);}
| expr ">=" expr {$$= new BinOp_expr($1,$2,$3);}
;
%%

int main(){
	int result = yyparse();
	if (result == 0) printf("Success. \n");
	return result;
} 
