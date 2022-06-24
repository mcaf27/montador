#include "../include/Memory.hpp"
#include <iostream>

using namespace std;

Memory::Memory() {}

void Memory::adicionar_instrucao(string com, string op) {
  vector<string> v;
  
  if(com == "LOAD") {v.push_back("1");}
  if(com == "STORE") {v.push_back("2");}
  if(com == "ADD") {v.push_back("3");}
  if(com == "SUB") {v.push_back("4");}
  if(com == "JMP") {v.push_back("5");}
  if(com == "JPG") {v.push_back("6");}
  if(com == "JPL") {v.push_back("7");}
  if(com == "JPE") {v.push_back("8");}
  if(com == "JPNE") {v.push_back("9");}
  if(com == "PUSH") {v.push_back("10");}
  if(com == "POP") {v.push_back("11");}
  if(com == "READ") {v.push_back("12");}
  if(com == "WRITE") {v.push_back("13");}
  if(com == "CALL") {v.push_back("14");}
  if(com == "RET") {v.push_back("15");}
  if(com == "HALT") {v.push_back("16");}
  if(com == "END") {v.push_back("");}
  if(com == "WORD") {v.push_back("WORD");}

  v.push_back(com);
  v.push_back(op);

  this->insts.push_back(v);

}

void Memory::adicionar_label(string nome, int posi) {
  this->labels.insert(pair<string, int>(nome, posi));
}

void Memory::print_insts() {
  for (auto & i : this->insts) {
    for (auto & j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}

void Memory::print_labels() {
  for (auto & i : this->labels) {
    cout << i.first << " " << i.second << endl;
  }
}

int Memory::tamanho() {
  int tam = 0;

  for (auto & i : this->insts) {
    if (i[1] != "END") {
      if (i[1] == "HALT" || i[1] == "RET" || i[1] == "WORD") {
        tam += 1;
      } else {
        tam += 2;
      }
    }
  }

  return tam;
}

void Memory::gera_saida(){


    string file("saida.txt");
    ofstream outfile;

    outfile.open(file);
    if (!outfile.is_open()) {
        cout << "Erro ao abrir arquivo " << file << '\n';
    } else {
        outfile << "MV1 0 999 ";

        outfile << this->tamanho() << " ";

        int ilc = 0;

        for (auto & i : this->insts) {

          if (i[0] == "") continue; //pseudoinstrução

          if (i[0] == "WORD") {
            outfile << i[2] << " ";
            
            continue;
          }

          if (i[0] == "15" || i[0] == "16") ilc += 1;
          else {
            ilc += 2;
          }

          outfile << i[0] << " ";
          

          if (i[0] != "15" && i[0] != "16") {
            outfile << this->labels.find(i[2])->second - ilc << " ";
            
          }
        }

        
    }
    outfile.close();
}