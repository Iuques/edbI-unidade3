#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <string>

using namespace std;

/*
  Definição da classe 'HashTable', que representa uma tabela hash.
*/

class HashTable {
private:
  // Constante que define o tamanho da tabela hash.
  const int TABLE_SIZE;
  // Struct de um node da lista encadeada.
  struct node {
    // Chave do node.
    string key;
    // Contagem de ocorrências da chave.
    int count;
    // Ponteiro para o próximo node.
    node *next;
  };
  // Ponteiro para o array que armazenará a tabela.
  node *table;
  // Node temporário para auxiliar na inserção de elementos.
  node *current;
  // Função de hash.
  int hashFunction(const string &word);

public:
  // Construtor padrão, recebe o tamanho da tabela (padrão 100)
  HashTable(int size = 100);
  // Destrutor padrão.
  ~HashTable();
  // Método para inserir uma palavra na tabela.
  void addText(string text);
  // Retorna a contagem de ocorrências de uma palavra.
  int countWord(string word);
  // Atualiza a contagem de ocorrências de uma palavra.
  void updateWord(string word, int newCount);
  // Remove uma palavra da tabela.
  void removeWord(string word);
  // Retorna true se a palavra existe na tabela.
  bool containsWord(string word);
  // Imprime a tabela hash.
  void printTable();
};

#endif