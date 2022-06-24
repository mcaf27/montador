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

  while (getline(arq, in)) {
    in = in.substr(0, in.find(';'));

    if (in.find(':') == -1) {
      
      string com;
      istringstream ss(in);
      ss >> com;
      ilc++;
      string op;

      if (com != "HALT" && com != "RET") {
        ss >> op;
        ilc++;
      }

      mem->adicionar_instrucao(com, op);
      
    } else {

      string label = in.substr(0, in.find(':'));
      mem->adicionar_label(label, ilc);

      ilc++;

    }
  }

  mem->print_insts();
  cout << "---" << endl;
  mem->print_labels();
  mem->gera_saida();
  delete mem;
  arq.close();

  return 0;

}