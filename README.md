# Projeto da Unidade 3 - Estruturas de Dados Básicas I

## Descrição do Projeto

Este projeto é uma implementação de uma tabela hash utilizando listas encadeadas para armazenar strings. É parte da disciplina de **Estruturas de Dados Básicas I (EDB)**. O objetivo principal é demonstrar a aplicação de conceitos de hashing e estruturas de dados para gerenciar e manipular strings de forma eficiente.

## Funcionalidades

O programa implementa uma tabela hash que oferece as seguintes funcionalidades:

- **Adicionar Palavras:** Permite adicionar novas palavras à tabela hash.
- **Remover Palavras:** Permite remover todas as ocorrências de uma palavra na tabela.
- **Atualizar Ocorrências:** Modifica a quantidade de ocorrências de uma palavra na tabela.
- **Contar Ocorrências de Palavras:** Conta o número de vezes que uma palavra específica aparece na tabela hash.
- **Imprimir a Tabela:** Exibe o conteúdo da tabela hash, mostrando as palavras armazenadas e suas respectivas ocorrências.

## Compilação

Para compilar o programa, utilize o comando `g++` com os arquivos de código-fonte `main.cpp` e `hashTable.cpp`. O comando de compilação é o seguinte:

```bash
g++ main.cpp hashTable.cpp -o Main
