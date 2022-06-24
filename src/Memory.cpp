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
  if(com == "END") {v.push_back(" ");}

  v.push_back(com);
  v.push_back(op);

  this->insts.push_back(v);

}

void Memory::adicionar_label(string nome, int posi) {
  this->labels.insert(pair<string, int>(nome, posi));
}

void Memory::print_insts() {
  for (auto & i : this->insts) {
    cout << i[0] << " " << i[1] << " " << i[2] <<  endl;
  }
}

void Memory::print_labels() {
  for (auto & i : this->labels) {
    cout << i.first << " " << i.second << endl;
  }
}


void Memory::gera_saida(){


    string file("saida.txt");
    ofstream outfile;

    outfile.open(file);
    if (!outfile.is_open()) {
        cout << "Erro ao abrir arquivo " << file << '\n';
    } else {
        outfile << "MV1 0 999 ";
        for (auto & i : this->insts) {
          outfile << i[0] << " ";
        }
        
    }
    outfile.close();
}