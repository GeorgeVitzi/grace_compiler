#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "symbol.hpp"
#include <string>
#include <cstdio>

inline std::ostream& operator<<(std::ostream &out,Type t){
   switch (t){
     case TYPE_int: out << "int"; break;
     case TYPE_char: out << "char"; break;
     case TYPE_nothing: out << "nothing"; break;
   }
   return out;
}

class AST {
public: 
  virtual void printOn(std::ostream &out) const = 0;
};

inline std::ostream& operator<< (std::ostream &out, const AST &t) {
  t.printOn(out);
  return out;
}

extern std::map<char, int> globals;




class Box:public AST{
public:
   Box(int n, Box *b=nullptr):number(n), box(b){}
   virtual void printOn(std::ostream &out) const override {
   out<<" ["<<number<<"]";
   if(box!=nullptr)out<<*box;
   }
private:
  int number;
  Box *box;
};



class Newdef : public AST{
public:
   Newdef(char* v,Newdef *n=nullptr):var(v),newd(n){}
   virtual void printOn(std::ostream &out) const override {
     out<<"," <<var;
     if(newd!=nullptr) out<<*newd;  
   }
private:
  char* var;
  Newdef *newd;
};

class Fpartype : public AST{
};

class Fpartype_1 : public Fpartype{
public:
   Fpartype_1(Type t,Box *b=nullptr): type(t), box(b){}
   virtual void printOn(std::ostream &out) const override {
     out<< type<<" []";
     if(box!=nullptr) out<<*box;
   }
private:
  Type type;
  Box *box;
};


class Fpartype_2 : public Fpartype{
public:
   Fpartype_2(Type t,Box *b=nullptr): type(t), box(b){}
   virtual void printOn(std::ostream &out) const override {
     out<< type;
     if(box!=nullptr) out<<*box;
   }
private:
  Type type;
  Box *box;
};

class Fpardef:public AST{
};

class Fpardef_1:public Fpardef{
public:
   Fpardef_1(char* v, Fpartype *f,Fpardef *fpar=nullptr): var(v),fparty(f),fpardef(fpar){}
   virtual void printOn(std::ostream &out) const override {
     out<< var<<":"<<*fparty;
     if(fpardef!=nullptr) out<<";"<<*fpardef;
  }
private:
  char* var;
  Fpartype *fparty;
  Fpardef *fpardef;
};


class Fpardef_2:public Fpardef{
public:
   Fpardef_2(char* v,  Newdef *n, Fpartype *f,Fpardef *fpar=nullptr ): var(v),newd(n),fparty(f),fpardef(fpar){}
   virtual void printOn(std::ostream &out) const override {
     out<< var<<*newd<<":"<<*fparty;
     if(fpardef!=nullptr) out<<";"<<*fpardef;
  }
private:
  char* var;
  Newdef *newd;
  Fpartype *fparty;
  Fpardef *fpardef;
};

class Fpardef_3:public Fpardef{
public:
   Fpardef_3(char* v, Fpartype *f,Fpardef *fpar=nullptr ): var(v),fparty(f),fpardef(fpar){}
   virtual void printOn(std::ostream &out) const override {
     out << " ref " << var<<":"<<*fparty;
     if(fpardef!=nullptr) out<<";"<<*fpardef;
  }
private:
  char* var;
  Fpartype *fparty;
  Fpardef *fpardef;
};

class Fpardef_4:public Fpardef{
public:
   Fpardef_4(char* v,  Newdef *n, Fpartype *f,Fpardef *fpar=nullptr ): var(v),newd(n),fparty(f),fpardef(fpar){}
   virtual void printOn(std::ostream &out) const override {
     out << " ref " << var<<*newd<<":"<<*fparty;
     if(fpardef!=nullptr) out<<";"<<*fpardef;
  }
private:
  char* var;
  Newdef *newd;
  Fpartype *fparty;
  Fpardef *fpardef;
};

class Head:public AST{
public:
   Head(char* v,Type t , Fpardef *f=nullptr):var(v), type(t),fpar(f){}
   virtual void printOn(std::ostream &out) const override {
    out <<" fun "<<var<<"(";
    if(fpar!=nullptr) out<<*fpar;
    out<<") :"<<type;
  }
private:
  char* var;
  Fpardef *fpar;
  Type type;
};

class Funcdef:public AST{
};
//classes funcdef ^--


class Declaration:public AST{
public:
   Declaration(Type t, Box *b=nullptr):type(t), box(b){}
   virtual void printOn(std::ostream &out) const override {
     out<< type;
     if(box!=nullptr) out<< *box;
   }
private:
  Type type;
  Box *box;
};

class Vardef:public AST{
public:
   Vardef(char* c, Declaration *d,Newdef *n=nullptr):var(c), decl(d), newdef(n){}
   virtual void printOn(std::ostream &out) const override {
   out<<" Decl(var "<<var;
   if(newdef!=nullptr)out<<*newdef;
   out<<":"<<*decl<<";)";
   }
private:
  char* var;
  Newdef *newdef;
  Declaration *decl;
};

class Funcdecl:public AST{
public:
   Funcdecl(Head *h):head(h){}
   virtual void printOn(std::ostream &out) const override {
     out<<*head<<";";
   }
private:
  Head *head;
};
class Localdef:public AST{
};
class Localdef_1:public Localdef{
public:
   Localdef_1(Funcdef *f):funcdef(f){}
   virtual void printOn(std::ostream &out) const override {
     out<<*funcdef;
   }
private:
  Funcdef *funcdef;
};

class Localdef_2:public Localdef{
public:
   Localdef_2(Funcdecl *f):funcdecl(f){}
   virtual void printOn(std::ostream &out) const override {
     out<<*funcdecl;
   }
private:
  Funcdecl *funcdecl;
};


class Localdef_3:public Localdef{
public:
   Localdef_3(Vardef *f):vardef(f){}
   virtual void printOn(std::ostream &out) const override {
     out<<*vardef;
   }
private:
  Vardef *vardef;
};

class Localdeff:public AST{
public:
  Localdeff(Localdef *l): lcl(l),blc_list() {}
  void append_blc(Localdef *l) { blc_list.push_back(l); }
  virtual void printOn(std::ostream &out) const override {
    out<< " Body(";
    out<<*lcl;
    bool first = true;
    for (Localdef *l : blc_list) {
      if (!first) out << ", ";
      first = false;
      out << *l;
    }
    out << ") ";
    out <<"\n";
   }
private:
  Localdef *lcl;
  std::vector<Localdef *> blc_list; 
};

// classes local-deff ^--
class Block:public AST{
};
class Lvalue :public AST{
};

class Expr: public AST{
};
class Funccall:public AST{
};

class Cond:public AST{
};

class Cond_st1:public Cond{
public:
  Cond_st1(Cond *c):cond(c){}
  virtual void printOn(std::ostream &out) const override {
    out<<" ("<<*cond<<") ";
  }
private:
  Cond *cond;
};

class Cond_st2:public Cond{
public:
  Cond_st2(Cond *c): cond(c){}
  virtual void printOn(std::ostream &out) const override {
  out<<"not"<<*cond;
  }
private:
  Cond *cond;
};

class BinOp_cond:public Cond{
public:
  BinOp_cond(Cond *l, char o, Cond *r): left(l), op(o), right(r) {}
  virtual void printOn(std::ostream &out) const override {
    if(op=='p') out <<"and";
    else out<<"or"; 
    out<< "(" << *left << ", " << *right << ")";
  }
private:
  Cond *left;
  char op;
  Cond *right;
};


class BinOp_expr :public Cond{
public:
  BinOp_expr(Expr *l, char o, Expr *r): left(l), op(o), right(r) {}
  virtual void printOn(std::ostream &out) const override {
    if(op=='s') out<<"<=";
    else if(op=='g') out<<">=";
    else out << op; 
    out<< "(" << *left << ", " << *right << ")";
  }
private:
  Expr *left;
  char op;
  Expr *right;
};


class Char :public Expr{
public:
  Char(char c):var(c){}
  virtual void printOn(std::ostream &out) const override {
    out<<"'";
    if(var=='d')out<<"\\n";
    else if(var=='a')out<<"\\t";
    else if(var=='b')out<<"\\0";
    else if(var=='c')out<<"\\r";
    else if(var=='e')out<<"\\\\";
    else if(var=='f')out<<"\\'";
    else if(var=='j')out<<"\\\"" ;
    else if(var=='i')out<<"\\ ";
    else out<<var;
    out<<"'";
  }
private:
  char var;
};

class Chara :public Expr{
public:
  Chara(char* c):var(c){}
  virtual void printOn(std::ostream &out) const override {
    out<<var;
  }
private:
  char* var;
};

class Const:public Expr{
public:
  Const(int n):number(n){}
  virtual void printOn(std::ostream &out) const override {
    out<<number;
  }
private:
  int number;
};


class Expr_lval:public Expr{
public:
  Expr_lval(Lvalue *lv):lvalue(lv){}
  virtual void printOn(std::ostream &out) const override {
    out<<*lvalue;
  }
private:
  Lvalue *lvalue;
};


class Exprpar:public Expr{
public:
  Exprpar(Expr *e):expr(e){}
  virtual void printOn(std::ostream &out) const override {
  out<<" ("<<*expr<<") ";
  }
private:
  Expr* expr;
};


class Exprplas :public Expr{
public:
  Exprplas(Expr *e):expr(e){}
  virtual void printOn(std::ostream &out) const override {
  out<<"+"<<*expr;
  }
private:
  Expr *expr;
};

class Exprsub :public Expr{
public:
  Exprsub(Expr *e):expr(e){}
  virtual void printOn(std::ostream &out) const override {
  out<<"-"<<*expr;
  }
private:
  Expr *expr;
};


class Expr_func:public Expr{
public:
  Expr_func(Funccall *fc):funccall(fc){}
  virtual void printOn(std::ostream &out) const override {
    out<<*funccall;
  }
private:
  Funccall *funccall;
};


class BinOp: public Expr {
public:
  BinOp(Expr *l, char o, Expr *r): left(l), op(o), right(r) {}
  virtual void printOn(std::ostream &out) const override {
    if(op=='d')out <<"div";
    else if(op=='m')out<<"mod";
    else out<<op; 
    out<< "(" << *left << ", " << *right << ")";
  }
private:
  Expr *left;
  char op;
  Expr *right;
};


class Comma: public AST{
public:
  Comma(Expr *e, Comma *c=nullptr):expr(e), comma(c){}
  virtual void printOn(std::ostream &out) const override {
    out<<","<<*expr;
    if(comma!=nullptr) out<<*comma;
  }
private:
  Expr *expr;
  Comma *comma;
};

class Funccall_default:public Funccall{
public:
  Funccall_default(char* c,Expr *e=nullptr, Comma *com=nullptr):var(c), expr(e), comma(com){}
  virtual void printOn(std::ostream &out) const override {
    out<<var<<" (";
    if(expr!=nullptr) out<<*expr;
    if(comma!= nullptr) out<< *comma;
    out<<") ";
  }
private:
  char* var;
  Expr *expr;
  Comma *comma;
};



class Id:public Lvalue{
public:
  Id(char* v):var(v){}
  virtual void printOn(std::ostream &out) const override {
    out<< " "<<var;
  }
private:
  char* var;
};


class String :public Lvalue{
public:
  String(char* v):var(v){}
  virtual void printOn(std::ostream &out) const override {
    out<<" "<<var;
  }
private:
  char* var;
};


class Lval_expr :public Lvalue{
public:
  Lval_expr(Lvalue *lv, Expr *e): lvalue(lv), expr(e){}
  virtual void printOn(std::ostream &out) const override {
    out<<*lvalue<<" ["<< *expr<<"] ";
  }
private:
  Lvalue *lvalue;
  Expr *expr;
};

class Stmt:public AST{

};

class Finish_1 :public Stmt{
public:
  virtual void printOn(std::ostream &out) const override {
    out<<";"; 
  }
private:
  bool val;
};

class Finish_2 :public Stmt{
public:
  virtual void printOn(std::ostream &out) const override {
    out<<" return ; "; 
  }
private:
  bool val;
};

class Stmt_lvalue :public Stmt{
public:
  Stmt_lvalue(Lvalue *lv, Expr *e):lvalue(lv), expr(e){}
  virtual void printOn(std::ostream &out) const override {
    out<<*lvalue<<" <- "<<*expr<<"; ";
  }
private:
  Lvalue *lvalue;
  Expr *expr;
};


class Stmt_block :public Stmt{
public:
  Stmt_block(Block *b): block(b){}
  virtual void printOn(std::ostream &out) const override {
    out<< *block;
  }
private:
  Block *block;
};



class Stmt_func :public Stmt{
public:
  Stmt_func(Funccall *f):funccall(f){}
  virtual void printOn(std::ostream &out) const override {
    out<< *funccall<<";";
  }
private:
  Funccall *funccall;
};


class If:public Stmt{
public:
  If(Cond *c, Stmt *s1, Stmt *s2=nullptr):cond(c), stmt1(s1), stmt2(s2){}  
  virtual void printOn(std::ostream &out) const override {
    out<<" if"<<*cond<<" then"<<*stmt1;
    if(stmt2!=nullptr) out<<" else"<<*stmt2;
  }
private:
  Cond *cond;
  Stmt *stmt1;
  Stmt *stmt2;
};


class While:public Stmt{
public:
  While(Cond *c, Stmt *s): cond(c), stmt(s){}
  virtual void printOn(std::ostream &out) const override {
    out<<" while"<<*cond<<" do "<<*stmt; 
  }
private:
  Cond *cond;
  Stmt *stmt;
};


class Stmt_expr :public Stmt{
public:
  Stmt_expr(Expr *e): expr(e){}
  virtual void printOn(std::ostream &out) const override {
    out<< " return" << *expr<<"; ";
  }
private:
  Expr *expr;
};

class Sol:public AST{
public:
   Sol(Stmt *s,Sol *sol=nullptr):stmt(s),sl(sol){}
   virtual void printOn(std::ostream &out) const override {
   if(sl!=nullptr) out<<*sl;
   out<<*stmt;
   }
private:
  Sol *sl;
  Stmt *stmt;
};

class Block_default:public Block{
public:
  Block_default(Sol *s=nullptr):sol(s){}
  virtual void printOn(std::ostream &out) const override {
    out <<" Block({" ;
    if(sol!=nullptr) out<<*sol;
    out<<"}) ";
  }
private:
  Sol *sol;
};

//classes block ^--
class Funcdef_default: public Funcdef{
public:
    Funcdef_default(Head *h,Block *b,Localdeff *l=nullptr): head(h), block(b),locald(l) {}
  virtual void printOn(std::ostream &out) const override {
    out <<"Body(";
    out << *head;
    if(locald!= nullptr) out << *locald;
    out << *block;
    out<<")";
  }
private:
  Head *head;
  Localdeff *locald;
  Block *block;
  
};

