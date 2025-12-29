# Tipo Abstrato de Dados

## Define uma INTERFACE entre o TAD e as aplicações que o usam
- ENCAPSULA os detalhes da representação interna das suas instâncias e da implementação das suas funcionalidades
- Estão ocultos para os utilizadores do TAD !!
- Detalhes de representação / implementação podem ser alterados sem alterar a interface do TAD !
- Não é necessário alterar código que use o TAD !!


## Como fazer? 

Usar **struct** para definir / armazenar os atributos de cada instância de um TAD


## Invariantes da representação interna
- Os invariantes estabelecem condições para que os atributos
representem uma instância válida
- No caso da 1ª versão do TAD
- O comprimento de cada lado é um valor positivo
- Os comprimentos dos lados satisfazem a desigualdade triangular
- Estabelecer e documentar os invariantes !!


## Asserções / Condições verdadeiras
- Assegurar os invariantes sempre que se cria ou modifica uma
instância do TAD
- Usar asserções de entrada / pré-condições, sempre que
possível, para validar argumentos das funções
- Assegurar os invariantes à saída / pós-condições de cada
função que modifique uma instância
- Pode não ser necessário fazê-lo explicitamente !!


## Convenções habituais
- O utilizador de um TAD só opera com instâncias através da
interface do TAD
- I.e., as suas funções “públicas”
- O utilizador está, em geral, proibido de aceder diretamente
aos campos da representação interna de cada instância
- Esta convenção também é válida durante os testes do TAD
- Os testes avaliam o comportamento de um TAD e não a sua
implementação

## Organização em 2 ficheiros
- Ficheiro cabeçalho .h a ser incluído quando necessário
- Definição do tipo abstrato, de tipos de dados auxiliares e de
constantes
- Definição dos protótipos das funções (públicas) da interface
- Ficheiro de implementação .c
- Concretização da representação do tipo abstrato
- Implementação das funções da interface (públicas)
- Implementação de funções auxiliares (privadas)


## Ficheiro .c
- A implementação pode variar durante o desenvolvimento de
um projeto
- OU pode haver implementações diferentes para diferentes
aplicações
- Flexibilidade !!

## Como evitar múltiplas inclusões / definições ?
- Se o mesmo ficheiro .h for incluído em diferentes locais de
um programa, vai originar múltiplos erros de definição, em
tempo de compilação
- Necesário usar as diretivas de processamento #ifndef (if not
defined), #define e #endif no ficheiro .h
- Associar um identificador único a cada diretiva #ifndef
- Convenção: usar NOME-TAD_H_


## TAD = especificação + interface + implementação
- Encapsular detalhes da representação / implementação
- Flexibilizar manutenção / reutilização / portabilidade
- Ficheiro .h : operações públicas + ponteiro para instância
- Ficheiro .c : implementação + representação interna
