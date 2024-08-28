#include "hashTable.h"

// Construtor e destrutor da tabela de dispersão
HashTable::HashTable(int size) : TABLE_SIZE(size) {
  // Inicializa a tabela
  table = new node[TABLE_SIZE];
  
  // Inicializa os elementos de cada índice com valores nulos
  for (int i = 0; i < TABLE_SIZE; i++) {
    table[i].key = "";
    table[i].count = 0;
    table[i].next = nullptr;
  }
  current = nullptr;
}
HashTable::~HashTable() { delete[] table; }

// Método de adicionar texto
void HashTable::addText(string text) {
  // Recebe o índice através da função hash
  int index = hashFunction(text);

  // Checa se o índice está vazio
  if (table[index].key == "") {
    // Caso esteja vazio, adiciona o texto e incrementa o contador
    table[index].key = text;
    table[index].count = 1;
    cout << "Texto adicionado no índice " << index
         << ". Contagem de palavras atualizada." << endl;

  } else {
    current = &table[index];
    // Caso não esteja vazio, checa se a palavra já existe na lista
    if (current->key == text) {
      current->count++;
      cout << "Contagem atualizada no índice " << index << endl;
      return;
    }
    while (current->next != NULL) {
      current = current->next;
      if (current->key == text) {
        current->count++;
        cout << "Contagem de palavras atualizada no índice " << index << endl;
        return;
      }
    }

    // Caso a palavra não exista na lista, adiciona-a e incrementa o contador
    node *newNode = new node;
    newNode->key = text;
    newNode->count = 1;
    newNode->next = nullptr;

    current->next = newNode;

    cout << "Novo texto adicionado no índice " << index
         << ". Contagem de palavras atualizada." << endl;
  }
}

// Método de contar a quantidade de ocorrências de uma palavra
int HashTable::countWord(string word) {
  // Recebe o índice através da função hash
  int index = hashFunction(word);

  // Busca a palavra na lista encadeada
  current = &table[index];
  while (current != nullptr) {
    if (current->key == word) {
      // Retorna a contagem da palavra
      return current->count;
    }
    current = current->next;
  }
  // Caso não ache a palavra, retorna 0
  return 0;
}

// Método de atualizar a contagem de uma palavra
void HashTable::updateWord(string word, int newCount) {
  // Recebe o índice através da função hash
  int index = hashFunction(word);

  // Busca a palavra na lista encadeada
  current = &table[index];
  while (current != nullptr) {
    if (current->key == word) {
      // Atualiza a contagem da palavra
      current->count = newCount;
      cout << "Contagem de `" << word << "` atualizada para " << newCount
           << endl;
      return;
    }
    current = current->next;
  }
  // Caso não ache a palavra, imprime uma mensagem
  cout << "Palavra não encontrada na tabela." << endl;
}

// Método de remover uma palavra da tabela
void HashTable::removeWord(string word) {
  // Recebe o índice através da função hash
  int index = hashFunction(word);

  current = &table[index];
  // Inicializa um novo node temporário para armazenar o node anterior na busca
  node *previous = nullptr;

  // Busca a palavra na lista encadeada
  while (current != nullptr) {
    if (current->key == word) {
      // Checa se o node a ser removido é o primeiro da lista
      if (previous == nullptr) {
        // Caso seja retorna os valores aos de inicialização do construtor
        table[index].key = "";
        table[index].count = 0;
        table[index].next = nullptr;
        return;
      }
      // Caso não seja, atualiza o ponteiro next do node anterior
      previous->next = nullptr;
      return;
    }
    previous = current;
    current = current->next;
  }
  // Caso não ache a palavra, imprime uma mensagem
  cout << "Palavra não encontrada na tabela." << endl;
}

// Método de verificar se uma palavra está na tabela
bool HashTable::containsWord(string word) {
  // Recebe o índice através da função hash
  int index = hashFunction(word);

  // Busca a palavra na lista encadeada
  current = &table[index];
  while (current != nullptr) {
    if (current->key == word) {
      // Retorna true se a palavra for encontrada
      return true;
    }
    current = current->next;
  }
  // Retorna false se a palavra não for encontrada
  return false;
}

// Método de imprimir todo o conteúdo da tabela
void HashTable::printTable() {
  // Inicializa uma variável para checar se a linha anterior foi impressa
  bool previousWasEmpty = false;

  for (int i = 0; i < TABLE_SIZE; i++) {
    // Checa se o índice está vazio
    if (table[i].key == "") {
      // Caso esteja vazio, imprime "..." (se a linha anterior foi impressa)
      if (!previousWasEmpty) {
        cout << "..." << endl;
        previousWasEmpty = true;
      }
    } else {
      // Caso não esteja vazio, imprime a palavra e a contagem
      cout << "Índice " << i << ": ";
      cout << "\"" << table[i].key << "\" (" << table[i].count
           << " ocorrência(s))";
      current = &table[i];
      // Imprime os nodes sequentes da lista encadeada
      while (current->next != NULL) {
        current = current->next;
        cout << " -> \"" << current->key << "\" (" << current->count
             << " ocorrência(s))";
      }
      cout << endl;
      previousWasEmpty = false;
    }
  }
}

// Função hash
int HashTable::hashFunction(const string &word) {
  unsigned long hash = 5381;
  for (char c : word) {
    // hash ∗ 33 + c
    hash = ((hash << 5) + hash) + static_cast<unsigned long>(c);
  }
  return hash % TABLE_SIZE;
}
