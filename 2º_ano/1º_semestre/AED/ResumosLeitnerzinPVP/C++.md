# Linguagem C++


## C vs C++

C++ é OO 

Suporta programação genérica: templates

permite o tratamento de exceções: try - throw - catch 

Bibliotecas poderosas

Strings library + Containers library + Algorithms library + ...


```cpp 
#include <iostream>

using namespace std;

int main(void) {

	cout << "Hello World!" << endl;
	return 0;
}


```

# Name spaces

A **visibilidade** de variáveis e de funções pode ser controlada e definida em diferentes name spaces

```cpp
namespace NEW {
	static int t_bytes;
	int f(int x) { return 2 * x; }
}

namespace OLD {
	static int t_bytes;
	int f(int x) { return 3 * x; }
}

NEW::t_bytes;
OLD::f

// ou atribuindo-lhes visibilidade
using namespace OLD;
```

# Funções passagem de argumentos 
## Call-by-Value

```cpp
double ChangeItByValue(double it) {
	it += 10;
	std::cout << "Within function, i = " << it << std::endl;
	return it;

}

std::cout << "Before function execution, it = " << it << std::endl;
double result = ChangeItByValue(it);
std::cout << "After : it =  " << it << "\nResult returned: " << result << std::endl;

```

## Call-by-Pointer

```cpp
double ChangeItByPointer(double* p) {
	*p +=10;
	std::cout << "Within function, *p = " << *p << std::endl;
	return *p;
}
```

## Call-by-Reference

```cpp
double ChangeItByReference(double& it) {
	it += 10;
	std::cout << "Within function, it = " << it << std::endl;
	return it;
}

```

# Argumentos por Omissão

```cpp
int f(int x, int y = 2, int z = 3);

...

int f(int x, int y, int z) {}
	
	return x + 2 * y + 3 * z;
}

```
# Overloading 

Funções com o mesmo nome e diferentes listas de argumentos pode coexistir e ser invocadas de acordo com os tipos dos seus argumentos

Mas não é permitido que duas funçoẽs se distingam apenas pelo tipo do seu resultado: 
```cpp
int square( int x ) { return x * x; }

double square ( double x) { return x * x; }
```

# Template Functions

Uma função genérica é definida sem que sejam especificados os tipos de todos os seus argumentos ou do seu resultado

Ficando definida uma família de funções

Tal permite a sua invocação para diferentes tipos de dados

```cpp
template <typename T> T f(T x) {
	return T(7) * x;
} 
int i = f<int>(3);
double d = f<double>(5.0);
int i = f(1);
double d = f(2.6);
```

# Auto 

- O tipo de uma variável declarada é automaticamente deduzido a partir do seu valor inicial;

- O tipo do resultado deu uma função é automaticamente deduzido a partir das suas instruções de return;

```cpp
template<typename T, typeName U>
auto add(T t, U u){ return t + u;}
// return type is the type of operator+(T,U)

auto a = 1 + 2; //int
auto b = 1 + 1.2; // double
```  

# Gestão da memória 

- A alocação de memória é feita usando o operador **new**
- A libertação usando **delete**
- Em arrays é usado operador **delete[]**

```cpp
int *p_i = new int;
*p_i = 3;

dekete p_i;
p_i = new int[10];
double *p_d = new double[100];
delete[] p_d;

```

# Tratamento de exceções

- Um modo habitual de lidar com ocorrências excecionais é terminar a
execução do programa
- Em aplicações críticas, tal não é desejável, sendo necessário gerir a
ocorrência sem terminar a execução
- Para tal, o código que se pretende “proteger” é colocado num bloco
try {…} e o código de gestão de cada tipo de ocorrência é colocado
em um ou mais blocos catch(…) {…}
- As ocorrências (excecionais) são assinaladas lançando uma exceção,
usando a instrução throw

```cpp
double sqrt(double x) {
	if(x<0.0) throw 0;
	return sqrt(x);
}

...

try {
	cout << sqrt(-1.0) << endl;

}

catch(int i) {
	cout << "Integer exception number " << i << "caught" << endl;
	exit(1);
}
```

# Classes e Objetos
- Atributos de instância vs Atributos de classe (static)
- Métodos de instância vs Métodos de classe (static)
- Visibilidade: private, protected, public
- O ponteiro this – referência para o objeto que invoca o método
- O qualificador const
- O qualificador friend
- Construtores
- Destrutor – quando é necessário ?
- Construtor de Cópia (Copy Constructor) – quando é necessário ?
- Operador de Atribuição (operator =) – quando é necessário ?
- Getters e Setters
- Overloaded operators : operator ==, operator <, etc.
- Output : friend operator <<

## Exemplo de uma classe **Fraction.h**

```cpp
class Fraction {
	public:
		Fraction(void);
		Fraction(int numerator, int denominator = 1);
	
		int GetNumerator(void) const;		// qualificar como const os argumentos e métodos que não alterem atributos
		void SetNumerator(int n);
		
		int GetDenominator(void) constM
		void SetDenominator(int n);
		

		// Comparison operators 	
		bool operator==(const Fraction& frac) const;			// passar por referência objetos que são argumentos

		bool operator!=(const Fraction& frac) const;
		bool operator<(const Fraction& frac) const;
		
		Fraction operator-(void) const;
		
		Fraction operator+(const Fraction& frac) const;
		Fraction operator-(const Fraction& frac) const;
		Fraction operator*(const Fraction& frac) const;
		Fraction operator/(const Fraction& frac) const;
		
		double ToDouble(void) const;
	
		friend std::osstream& operator<<(std::ostream& out, const Fraction& frac);


		private:

			void Reduce(void);

			int numerator_;
			int denominator_;

};
```
# Fraction.cpp

```cpp
Fraction::Fraction(void) : numerator_(0), denominator_(1) {}

Fraction::Fraction(int numerator, int denominator) {
	assert(denominator > 0);
	numerator_ = numerator;
	denominator_ = denominator;
	Reduce();
}

int Fraction::GetNumerator(void) const { return numerator_; }
int Fraction::SetNumerator(int n) { 
	numerator_ = n; 
	Reduce();
}

bool Fraction::operator==(const Fraction& frac) const{
	return (numerator_ == frac.numerator_) && (denominator_ == frac.denominator_);
}

...

Fraction Fraction::operator-(void) const {
	Fraction res(-numerator_, denominator_);
	return res;
}


```

# STL Standard Template Library

- Objetivo : facilitar o desenvolvimento de código eficiente
- Conjunto de classes genéricas (template classes) que disponibilizam estruturas de dados (containers) e funcionalidades (algoritmos e
iteradores)
- Containers : array, vector, deque, map, set, …
- Algoritmos : searching, sorting, …
- Eficiência : estruturas de dados e funcionalidades baseadas em
algoritmos otimizados

- Algoritmos eficientes : funcionalidades e estruturas de dados
implementadas usando algoritmos rápidos e otimizados
- Legibilidade e manutenção : API consistente torna o código fácil de
compreender, desenvolver e manter
- Reutilização : escrita de código genérico e reutilizável, aplicável a
diferentes classes e tipos de dados

## Sequence Containers 

- Implementam estruturas de dados que podem ser acedidas de modo
sequencial
- array : elementos contíguos e tamanho fixo
- vector : elementos contíguos e tamanho variável
- deque : double-ended queue
- forward_list : lista simplesmente ligada
- list : lista duplamente ligada

## Array

```cpp
#include <array>
std::array<some_type, array_size>;
std::array<int,4> elems = {1,2,3,4};
```
- Tamanho fixo
- Obter o tamanho do array : .size()
- Elementos contíguos e com acesso aleatório
- Aceder ao elemento numa dada posição : .at( ) ou [ ]
- Aceder ao primeiro elemento (índice = 0) : .front()
- Aceder ao último elemento (índice = size – 1) : .back(

Iterar sobre todos os elementos




```cpp
for( const auto& e : a) {
	cout << " " << e;

}
cout << endl;
```

## Vector
 
```cpp
#include <vector>

std::vector<some_type>
```
Generalização do array container
- Elementos contíguos + Acesso aleatório + Tamanho variável
- Aumenta ou diminui de tamanho, quando se inserem ou apagam elementos
- Métodos eficientes para realizar operações na cauda de um vector
- A escolha preferencial, na maioria dos casos. When in doubt, use a vector !
```cpp
vector<unsigned int> v = {0,1,2,3,4};

```
- v.push_back(6);
- Inserir elemento na cauda do vector
- v.pop_back();
- Remover elemento da cauda do vector
- v.insert(v.begin(),99);
- Inserir elemento antes do primeiro elemento do vector
- v.erase(v.begin());
- Remover o primeiro elemento do vector
- v.begin()é um iterador


## Deque

```cpp
#include <deque>
std::deque<some_type>

```
- d.push_back(6);
- Inserir elemento na cauda do deque
- d.pop_back();
- Remover elemento da cauda do deque
- d.push_front(99);
- Inserir elemento antes do primeiro elemento do deque
- d.pop_front();
- Remover o primeiro elemento do deque
- d.empty();
- Devolve true, se o deque não tiver elementos; false, no caso contrário

# Container Adaptors 

Fornecem uma API mais restrita, para um sequence container, apenas
com algumas funcionalidades

O sequence container de base está instanciado por omissão (default)

- stack
- queue
- priority_queue

## Stack LIFO

```cpp
#include <stack>

std::stack<some_type>;
```

- s.push(6);
 
	Adicionar elemento no topo da pilha
- s.top();
 
	Devolve uma referência para o elemento no topo da pilha
- s.pop();
 
	Remover o elemento do topo da pilha
- s.size();
 
	Devolver o número de elementos da pilha
- s.empty();
 	
	Devolve true, se a pilha não tiver elementos; false, no caso contrário


## Queue FIFO

```cpp
#include <queue>
std::queue<some_type>
```

- q.front();
- Devolve uma referência para o primeiro elemento, na frente da fila
- q.back();
- Devolve uma referência para o último elemento, na cauda da fila
- q.pop();
- Remover o elemento na frente da fila
- q.push(10);
- Juntar um elemento à cauda da fila
- q.size();
- q.empty();


# STL associative COntainers

Implementam estruturas de dados ordenadas, de tamanho variável,
e que suportam uma procura eficiente – O(log n)
- map : coleção (dicionário) de pares (chave, valor), sem chaves repetidas, e ordenados de acordo com as chaves
- multimap : possíveis chaves repetidas
- set : coleção (conjunto) de elementos ordenados, e sem repetições
- multiset : possíveis elementos repetidos

O tipo das chaves deve suportar o operador de comparação <, para
permitir a procura e assegurar a ordem dos itens de um dicionário
- O mesmo se passa para o tipo dos elementos de um conjunto
- Esse operador é implícito para os tipos pré-definidos: int, double, etc.
- Sempre que as chaves ou elementos sejam instâncias de uma classe,
essa classe deve suportar o operador de comparação <
- Assegurar implementando, se necessário, o overloaded operator <
para essa classe
- A igualdade (==) é habitualmente inferida usando o operador <
- P.ex., !(a < b) && !(b < a)

## Map 
```cpp
#include <map>
std::map<key_type, value_type>

```
- m.insert({key, value})
- Adicionar o elemento (key, value) ao dicionário
- m.erase(key)
- Remover do dicionário o elemento com a chave dada, caso exista
- m.count(key)
- Devolve o número de itens cuja chave é igual à chave dada (0 ou 1)
- m.at(key)
- Consulta o elemento com a chave dada, caso exista
- m[key]
- Consultar / adicionar um elemento com a chave dada
### Iterar sobre maps

```cpp
for ( const auto& e : m) {
	cout << "key = " << e.first << " value = " << e.second << endl;
}

```
## Set 

```cpp
#include <set>
std::set<some_type>
```

- s.insert(element)
- Adicionar um elemento ao conjunto
- s.erase(element)
- Remover um elemento do conjunto
- s.count(element)
- Devolve o número de elementos iguais ao element procurado (0 ou 1)


# Iteradores
- Permitem aceder a elementos individuais de uma estrutura de dados (container) usando o operador *
- Usados habitualmente para percorrer sequencialmente todos os
elementos
- São incrementados ou decrementados usando os operadores ++ e --,
passando a referenciar o elemento seguinte ou anterior, caso exista

- Classes de iteradores : forward iterator, bidirectional iterator, random
access iterator
- Forward iterator : avançar ao longo de uma estrutura de dados, um
elemento de cada vez, usando o operador ++
- Biderectional iterator : avançar ou recuar, um elemento de cada vez,
usando o operador ++ ou o operador --
- Random access iterator : aceder a uma posição arbitrária

Exemplo:
```cpp
#include <iterator>

...
std::vector<int> v = { 3 , 1, 4 };
std::vector<int>::iterator it;
it = v.begin();

while(!it != v.end()) {

	std::cout << *it << "-";
	it++;
}

```
```cpp
std::vector<int> elems = {1,2,3,4};

for(auto it = elems.begin(); it!=elems.end(); it++) {
	std::cout << *it << '\n';
}

for (auto e : elems) {
	std::cout << e << '\n';
	
}

```

# Lambda expression

Pequena função anónima, escrita diretamente num bloco de código ou como argumento de outra função

### sintax  [capture] (parameters) {code}

```cpp
int main(void) {
	auto message = [] () { cout << "Hello World!\n";} 
	message();

	return 0;
}

```
