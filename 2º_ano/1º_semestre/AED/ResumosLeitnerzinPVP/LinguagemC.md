<!--Leitner-->
<div align="center">

# Resumos AED 
</div>

## Linguagem C 

### Links úteis:

<a href="cppreference.com">C reference</a>

<a href="tutorialspoint.com">Learn C by examples</a>

<a href="w3schools.com">C tutorials</a>

<a href="pythontutor.com">C coding tutor</a>

___ 

C não é uma linguagem OO, mas tem tipos estruturados: **struct** e **union**; 

Possível definir tipos auxiliares: **typedef**;

## Programa em C

```c
#include <stdio.h>
int main(void) {
	printf("Hello world\n");
	return 0;
}
 ```
___ 

## Tipos pré definidos 

### Valores inteiros

```c 
char c0 = 'A';		// by default is signed
int i0 = -13731231;   
short s0 = 1763;	


unsigned int i1 = 81231723U; 	// unsigned para ter a certeza que é unsigned
long l0 = 82312312313;				// long int
long long L0									// long long int
	
```
### Valores reais

```c
float f = 1.23e3f;			// igual a 1230.0 
double d = -1.23e6;			// -1230000.0
```

**float**: 4 bytes, aprox. 7 casas decimais significativas;

**double**: 8 bytes, aprox. 16 casas decimais significativas

___

## `stdio.h` printf 

	
```c
printf(formating_string, param1, param2, ...);

printf("I love C\n");
printf("I %s %c", "love", 'C');
```

### Alguns especificadores


```c
%%	// escreve um literal  
%c	// escreve um caracter
%s	// string 
%d	// inteiro com sinal 
%u	// inteiro sem sinal
%f	// converte um real na sua representação décimal: [-]ddd.ddd
%e	// converte um real na sua representação exponêncial
```

## `stdio.h` scanf


```c
scanf(formating_string, &param1, &param2, ...);
int my_num;
char my_char;

scanf("%d %c", &my_num, &my_char);


printf("O número lido: %d, e o char: %c", my_num, my_char);

char my_string[30];
scanf("%s", my_string);				// aqui não é necessário & porque o my_string é um ponteiro

```


## Arrays 


```c
double x_array[3];
int array[] = {1,2,3,4,5};
int 2d_array[3][3]; 

```

## `#include <math.h>`

Para compilar adicionar a flag **-lm**
```c
printf("%f\n", sqrt(16));
```

___

# Pointers 

**Ponteiro**: variável que contém o endereço de outra variável;


```c
int i;
int* ptr;

int* another_pointer = NULL;

```


## Operadores

`&` address operator: devolve o endereço de uma variável;
`*`	dereference operator: acede à variável apontada

```c
int i = 10;
int* ptr = &i;
int* another_pointer = ptr;

*ptr = 5;

```
## Arrays


```c
int array[3] = {1,2,3};

int* p_array = array;			// ponteiro para o primeiro elemento
```


### Aritmética de ponteiros


```c
int array[3] = {1,2,3};
*array = 100;				// muda array[0] = 100 
*(array + 1) = 200; // muda array[0+1] = 200
... 
```

### Iterar ao longo de um Array


```c
int *p = array;
for(int i = 0; i < 3; i++){
	printf("%d\n", *p);
	p = p + 1;
}
```
___

# Gestão de Memória

Em C, as estruturas de dados são alocadas dinamicamente ou de modo estático;

O tamanho de estruturas de dados estáticas é fixado em tempo de compilação e não sofre qualquer alteração durante a execução de um programa;

O espaço de memória de estruturas de dados dinâmicas é alocado e libertado durante a execução de um programa;

# Heap variables - Alocação dinâmica

Memória é alocada axplicitamente usando `malloc` ou `calloc`


```c
void* malloc( int )
void* calloc( int, int )

// Não há garbage collection como em Java logo:
void free (void*)
```


```c
int *ptr = NULL;
ptr = (int*)malloc(sizeof(int));
if(ptr == NULL) {

	exit(1);
}

*ptr = 99;
printf("%d\n", *ptr);
free(ptr);				
```

## Alocar espaço para um array


```c
int* a = NULL;
a = (int*)malloc(3 * sizeof(int)); // Try to allocate memory
if(a == NULL) {
	exit(1);
}						
a[0] = 99;
…
…
free(a);
```

___

# Funções

- Facilitar a implementação e depuração de erros

## Called-by-value vs. Called-by-pointer


```c
int sum(int a, int b){
	return a+b;
}

int sum(int* p_a, int* p_b) {
	return (*p_a) + (*p_b);
}

```

## Swap() 

Nestes casos é Called-by-pointer, caso contrário não alterava o valor que a ou b aponta

```c
void swap ( int* a, int* b) {
	int temp = *a;
	*a= *b;
	*b = temp;  
}

```
___ 

# Argc e Argv 

```c
int main(int argc, char **argv){

	for(int i = 0; i<argc; i++){

		print("%s\n", *argv);
		argv++;
	}	
}

```

___
# `enum` 

Por default o primeiro começa a 0;

```c
enum months {
	JANUARY = 1,
	FEBRUARY,
	MARCH
};
```
___

# `struct`

Syntax:	
```c
struct person {
	char* name;
	unsigned int yearBorn;
};

```

## Diferença entre **.** e **->**


```c
struct person p1 = {"leitner", "1870"}; 
char firstLetter = p1.name[0];

// pointer to struct
struct person *p_toPerson;
p_toPerson->name = "ANALEE";
p_toPerson->yearBorn = 1921;

```

<br>

# `typedef`

Syntax:
```c
//typedef ______   _____
//	      x+z+a      y    y substitui x+z+a por exemplo
//example
typedef struct { struct point c;
					unsigned int rad;
						} circle;
circle c1; //instancia uma variável circle

// um exemplo mais fácil de perceber
typedef int inteiro; 		// se eu escrever inteiro o compilador subsitui "inteiro" por "int"  
```
