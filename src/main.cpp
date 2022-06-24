#include "../include/Memory.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int main(int argc, char * argv []) {

  ifstream arq;
  arq.open(argv[1]);

  string line;

  Memory * mem;
  mem = new Memory();

  string in;
  int ilc = 0;

  // primeira passada
  while (getline(arq, in)) {
    in = in.substr(0, in.find(';'));

    if (in.find(':') == -1) {
      
      string com;
      istringstream ss(in);
      ss >> com;
      ilc++;
      string op;

      if (com != "HALT" && com != "RET" && com != "WORD") {
        ss >> op;
        ilc++;
      } else if (com == "WORD") ss >> op;

      mem->adicionar_instrucao(com, op);
      
    } else {

      string label = in.substr(0, in.find(':'));
      mem->adicionar_label(label, ilc);

      // ilc++;

      string com = "";
      string op = "";

      istringstream ss(in.substr(in.find(':') + 1));
      ss >> com;
      ilc++;
      if (com != "HALT" && com != "RET" && com != "WORD") {
        ss >> op;
        ilc++;
      } else if (com == "WORD") {
        // cout << "word" << endl;
        ss >> op;
      }

      
      mem->adicionar_instrucao(com, op);
    }
  }


  arq.clear();


  // mem->print_insts();
  // cout << "---" << endl;
  // mem->print_labels();
  mem->gera_saida();

  delete mem;
  arq.close();

  return 0;

}