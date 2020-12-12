#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "SeparateChainingHashTable.h"
#include "QuadraticProbingHashTable.h"
#include "Aluno.h"

enum FATOR_CARGA { CARGA_0_25 = 9431, 
                   CARGA_0_50 = 4703,
                   CARGA_1    = 2357,
                   CARGA_5    = 1151,
                   CARGA_10   = 233
                };
                
using namespace std;
      
int main(int argc, char** argv) { 
    SeparateChainingHashTable<Aluno> hashTable=SeparateChainingHashTable<Aluno>(CARGA_0_25);
    ifstream arquivo("listadealunos.csv", std::ifstream::in); 
    string nome, matricula;
    
    // Le arquivo CSV e cria instancias na tabela hash
    while (arquivo.good()) {
        getline(arquivo, matricula, ';');
        getline(arquivo, nome, '\n'); 

        hashTable.insert(Aluno(nome, matricula));
    }
    
    // Testes de mesa
    hashTable.insert(Aluno("Yuri de Sousa Tiano Gonçalves", "144151014"));
    hashTable.insert(Aluno("Felipe Sacramento de Lima", "216171003"));
    hashTable.insert(Aluno("Gabriel Pereira Melhor dos Santos", "205171009"));
    
    hashTable.remove(Aluno("Felipe Sacramento de Lima", "216171003"));
    hashTable.print();
   
    return EXIT_SUCCESS;
}
