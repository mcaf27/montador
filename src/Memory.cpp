#include "Memory.hpp"
#include <iostream>

using namespace std;

Memory::Memory() {}

void Memory::adicionar_instrucao(string com, string op) {
  vector<string> v;
  v.push_back(com);
  v.push_back(op);
  this->insts.push_back(v);
}

void Memory::adicionar_label(string nome, int posi) {
  this->labels.insert(pair<string, int>(nome, posi));
}

void Memory::print_insts() {
  for (auto & i : this->insts) {
    cout << i[0] << " " << i[1] << endl;
  }
}

void Memory::print_labels() {
  for (auto & i : this->labels) {
    cout << i.first << " " << i.second << endl;
  }
}