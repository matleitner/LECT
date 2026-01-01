# Dicionários

- Usar uma chave para aceder a um item / valor
- Chaves e itens / valores podem ser de qualquer tipo
- Chaves são comparáveis
- MAS, não há duas chaves iguais !!
- Idealmente, sem limite de tamanho / do número de pares (chave, valor)
- Chaves não existentes são associadas a um VALOR_NULO
- API simples / Código cliente simples


## HASH table 

- Estrutura de dados para armazenar pares (**chave**, **valor**)

- Sem chaves duplicadas

- Sem uma ordem implícita 

Objetivo: O(1) 

## Funções de HASHING 

Requesito : se x == y, então hash(x) == hash(y)

Desejável : se x != y, então hash(x) != hash(y)



# Hash Tables 
## Endereçamento calculado 
## Open Addressing

### Colisões

Quando há uma colisão, procurar o espaço vago seguinte e armazenar o item 


## Linear Probing 

(i+1)%M, (i+2)%M, ...


Problema clustering 

Novas chaves são indexadas no meio de "grandes" clusters

E os itens colocados no final dos clusters

## Quadratic Probing 

(i+1)% M, (i + 4) % M, ( i + 9 ) %M, ...

## Análise

Fator de carga λ=N/M 
Nº de tentativas para encontrar um item 

1/2 * ( 1 + 1 (1 - λ))  -> 1.5 se λ = 50%  -> 3 se λ=80%

Nº médio de tentativas para **inserir**

1/2 * (1 + 1 (1-λ)²)    -> 2.5 se λ = 50%  -> 13 se λ=80%





M muito grande -> demasiados espaços vagos

M pequeno -> tempo de procura aumenta

Solução : Resizing + Rehashing 

## Resising + Rehashing 

- Objetivo fator de carga < 1/2
- Duplicar tamanho quando F >= 1/2

- Reduzir para metade quando F <= 1/8



# Hash Table <String, String>

 
```c
struct _HashTableBin {
	char* key;
	char* value;
	unsigned int isDeleted;
	unsigned int isFree;
};

struct _HashTableHeader {
	unsigned int size;
	unsigned int numActive;
	unsigned int numUsed;
	hashFunction hashF;
	probeFunction probeF;
	unsigned int resizeIsEnabled;
	struct _HashTableBin* table; 
};

// Exemplos Hashing Probing
unsigned int hash1(const char* key) {
	assert(strlen(key) > 0);
	return key[0];
}

unsigned int hash2 (const char* key) {
	assert(strlen(key) > 0);
	if(strlen(key == 1) return key[0];
	return key[0] + key[1];
}

unsigned int linearProbing(unsinged int index, unsigned int i, unsinged int size) {
	return (index + i) %  size;
}

unsigned int quadraticProbing(unsinged int index, unsigned int i, unsinged int size) {
	return (index + (i * i)) %  size;
}
```

# Separate Chaining
- Desempenho não se degrada
abruptamente
- Pouco sensível a funções de hashing
menos boas
# Open Addressing + Linear Probing

- Menos espaço de memória
“desperdiçado
