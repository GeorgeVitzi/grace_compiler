#ifndef __SYMBOL_HPP__
#define __SYMBOL_HPP__

void yyerror(const char *msg);

enum Type {TYPE_int,TYPE_char,TYPE_nothing,TYPE_bool};

struct SymbolEntry {
  Type type;
  SymbolEntry() {}
  SymbolEntry(Type t): type(t) {}

};

class Scope {
public:
  Scope() {}
  SymbolEntry *lookup(char c) {
    if (locals.find(c) == locals.end()) return nullptr;
    return &locals[c];
  }

  void insert(char c, Type t){
    if (locals.find(c) != locals.end()) yyerror("Duplicate variable");
    locals[c] = SymbolEntry(t);
  }
private:
  std::map<char, SymbolEntry> locals;

};


class SymbolTable{
public:
  SymbolEntry *lookup(char c) {
    for (auto i = scopes.rbegin(); i != scopes.rend(); ++i){
      SymbolEntry *e = i->lookup(c);
      if(e != nullptr) return e; 
    } 
    yyerror("Variable not found");
    return nullptr;
  }
  
  void insert(char c, Type t){
    scopes.back().insert(c,t);
    
  }
  void openScope(){
    scopes.push_back(Scope());
  }
  
  void closeScope(){
    scopes.pop_back();   
  }
private:
  std::vector<Scope> scopes;
};

extern SymbolTable st;
#endif
