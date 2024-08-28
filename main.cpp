#include "hashTable.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Criando uma tabela de dispersão
  HashTable hashTable(100);

  // Adicionando 20 palavras na tabela de dispersão
  hashTable.addText("apple");
  hashTable.addText("orange");
  hashTable.addText("banana");
  hashTable.addText("grape");
  hashTable.addText("cherry");
  hashTable.addText("peach");
  hashTable.addText("mango");
  hashTable.addText("apricot");
  hashTable.addText("plum");
  hashTable.addText("date");
  hashTable.addText("fig");
  hashTable.addText("kiwi");
  hashTable.addText("melon");
  hashTable.addText("lime");
  hashTable.addText("nectarine");
  hashTable.addText("tangerine");
  hashTable.addText("pear");
  hashTable.addText("quince");
  hashTable.addText("raspberry");
  hashTable.addText("coconut");

  // Contando a quantidade de ocorrências das palavras
  cout << "Quantidade de ’apple’: " << hashTable.countWord("apple") << endl;
  cout << "Quantidade de ’orange’: " << hashTable.countWord("orange") << endl;
  cout << "Quantidade de ’banana’: " << hashTable.countWord("banana") << endl;
  cout << "Quantidade de ’grape’: " << hashTable.countWord("grape") << endl;
  cout << "Quantidade de ’cherry’: " << hashTable.countWord("cherry") << endl;

  // Verificando se uma palavra está na tabela
  if (hashTable.containsWord("peach")) {
    cout << "’peach’ esta presente na tabela." << endl;
  } else {
    cout << "’peach’ nao esta presente na tabela." << endl;
  }

  // Removendo uma palavra da tabela
  hashTable.removeWord("date");
  if (!hashTable.containsWord("date")) {
    cout << "’date’ foi removida da tabela." << endl;
  }

  // Atualizando a contagem de uma palavra na tabela
  hashTable.updateWord("orange", 2);

  // Imprimindo todo o conteúdo da tabela
  hashTable.printTable();
}