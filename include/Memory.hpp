#ifndef MEMORY
#define MEMORY

#include <map>
#include <vector>
#include <string>

class Memory {

  private:
    std::map<std::string, int> labels;
    std::vector<std::vector<std::string>> insts;

  public:
    Memory();

    void adicionar_instrucao(std::string com, std::string op);
    void adicionar_label(std::string name, int posi);
    void print_insts();
    void print_labels();

    void ler_entrada(std::string e);
};

#endif