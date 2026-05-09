# Resumo MPECI inteira


# Aleatório 

"qualquer coisa" que não seja previsível com ceteza absuluta;


Evento cujo resultado não possa ser determinado com ceteza absoluta, caso contrário é **determinístico**;


# Probabilidade 

" Medida do **grau de certeza associado** a um resultado proveniente de um fenómeno de acaso" 


## Interesse 

Na maioria das aplicações existe algum tipo de regularidade que se manifesta se o númeor de observações/experiências for elevado 


# Experiência aleatória

- Procedimento que deve produzir um resultado;

- Mesmo que seja **repetido nas mesmas condições não garante que o resultado seja idêntico**;

- Resultado imprevisível;


### A uma experiência aleatória são associados:

- Espaço de amostragem (conjunto de resultados possíveis);

- Conjunto de acontecimentos (ou eventos);

- Lei de probabilidade;


### Espaço de amostragem

Conjunto S de todos os resultados possíveis de uma experiência aleatoória;

Resultados devem ser mutuamente exclusivos e não divisíveis;

- Discretos se for contável;
- Contínuos se não for contável;

Elementos de **S** são designados por **resultados elementares**

### Acontecimentos/ eventos

Acontecimento ou Evento, A, é um subconjunto de S


### Lei da probabilidade 

Atribui probabilidade aos vários eventos.

**Probabilidade**: número associado a um evento;

valor entre 0 e 1

## Cálculo de probabilidades

- Teoria clássica (de Laplace)

- Frequencista 

- Teoria matemática

“Pour étudiér un phénoméne, il faut réduire tous les evénements du
même type à un certain nombre de cas également possibles, et alors
la probabilité d’un événement donné est une fraction, dont le
numérateur représente le nombre de cas favorables à l’événement e
dont le dénominateur représente par contre le nombre des cas
possibles” - wow

Reduzir o fenómeno a um conjunto de resultados elementares, "casos", igualmente prováveis


$$ P(acontecimento) = \frac{número\ de\ casos\ favoráveis}{número\ de\ casos\ possíveis}$$

## Exemplo 

Lançamento de 1 DADO (Honesto)


Prob de obter face 5?

6 resultados ou eventos elementares {1,2,3,4,5,6}

$ P(face\ 5) = \frac{1}{6}$


# Regras básicas 

## Regra do complemento

$ P(A) = 1 - P(\neg A) $

## Interseção


$ P(A \cap B) =  P(A) × P(B) $



## Disjunção

$ P(A \vee B) = P(A) + P(B) - P(A \cap B) $ 

## Abordagem Frequencista
Usa-se esta frequência como uma medida empírica de probabilidade

### Definição
$ f(A) = \frac{\#\ ocorreências\ do\ evento\ A}{N} $ 



### Exemplo em MATLAB
Probabilidade de **sair 2 caras em 3 lançamentos**
```matlab
% simular 1 lançamento (de uma moeda)
lan= rand() < 0.5 % assumiremos que 1 = “cara”
% simular os 3 lançamentos
lan_3= rand (3, 1) < 0.5
% repetir N vezes
N= 1e6 % mas comecem com valor pequeno
lancamentos= rand(3,N)<0.5; % importante o “;”

% contar num ocorrências de “2 caras”
% contar num caras (1s) em cada experiência
% (que se encontra numa coluna da matriz lancamentos)
numCarasNaExperiencia= sum (lancamentos);

% contar vezes em que esse número de caras é 2
numOcorrencias = sum (numCarasNaExperiencia ==2)
% calcular freq relativa
fr = numOcorrencias / N
% usar como estimativa da probabilidade
pA= fr
```

# Teoria Axiomática de Probabilidade

Em determinado ponto da evolução de uma
teoria de pensamento matemático, torna-se
imperioso ordenar, sistematizar e relacionar
todos os conhecimentos entretanto nela
reconhecidos, isto é, proceder à sua
AXIOMATIZAÇÃO


---

## Probabilidade em espeços de amostragem não contáveis

$ P(A) = \frac{Área\ (A)}{ Área\ (S)} $

## Independência 

2 acontecimentos são independentes se e só se $ P(A \cap B) = P(A) × P(B) $

# Experiências de Bernoulli
Uma experiência de **Bernoulli** consiste em realizar uma experiência e registar se eum dado acontecimento se verifica ou não, sucesso ou falha.

### Exemplo 

k sucessos em n experiências

Face → sucesso

Verso → falha 
$P(FVVFFF) = {p}^{k}\ ×\ {(1-p)}^{n-k}  = {p}^{4}×{(1-p)}^{4-2} $


## Lei Binomial

$P_n(k) = C_k^n\ p^k\ {(1 - p)}^{n-k}$ 

# Probabilidade condicional

Probabilidade de A dado que B

$P(A|B) = \frac{P(A \cap B)}{P(B)}$



# Regra da Cadeia 

$ P(AB) = P(A|B) × P(B) $


$ P(A_1\ A_2\ ...\ A_n) = P(A_1|A_2\ ...\ A_n) × P(A_2\ ...\ A_n) $
$ P(A_1\ A_2\ ...\ A_n) = P(A_1|A_2\ ...\ A_n) × P(A_2|A_3\ ...\ A_n) × P(A_{n-1}|A_n) $


# Lei Probabilidade total
Partição do espaço de amostragem $A_1\ A_2\ A_3$
Ter $P(B|A_i)$, para todos os $i$

$ P(B) = P(B|A_1)P(A_1) + P(B|A_2)P(A_2) + P(B|A_3) $


Em geral: $ P(B) = \sum{j} P(B|A_j)P(A_j)$


# Regra de Bayes

$P(A_i|B) = \frac{P(B|A_i)P(A_i)}{\sum{j}P(B|A_j)P(A_j)}$


A Regra de Bayes, em consequência, pode ser
escrita da seguinte forma:

$$P(causa|efeito) = \frac{P(efeito|causa)P(causa)}{P(efeito)}$$



# Variável aleatória

Uma função que mapeia o espaço de
amostragem na recta real é designada de
VARIÁVEL ALEATÓRIA

Uma variável aleatória escalar 𝑋 é
formalmente definida como sendo um
mapeamento de um espaço amostral S para a
recta real



- Discretas - se os valores que a variável aleatória pode assumir forem finitos ou infinitos mas contáveis, exemplo: número de acessos por minuto a uma página web

- Contínuas – se os valores que pode assumir formarem um ou vários intervalos disjuntos, exemplo: Duração de uma aula no Zoom

- Mistas -  onde se verificam os atributos que definem os 2 tipos anteriores


# Esperança E[X]

| $x_1$| $p_x(x_i)$| $x_i p_X(x_i)$ |
| -- | --- | ---|
| -1 |  .1 | -.1|
| 0 |  .2 | .0|
| 1 |  .4 | .4|
| 2 |  .2 | .4|
| 3 |  .1 | .3|
| $E[X]$ |  | 1.0|



# Variância

$ Var(X) = E[ {(X - E(X))}^{2}]$


$ Var(X) = 𝜎² = \sum{i} [x_i - E(X)]²\ p(x_i)$

### Propriedades 

$var(X +c) = var(X)$

$var(c\ X) = c³\ var(X)$

# Desvio padrão
Raiz quadrada da variância é o desvio padrão representado por 𝜎.

---

# Distribruições

As funções de massa de probabilidade e de
densidade de probabilidade (para o caso
contínuo) podem assumir as mais variadas
formas.

Mas existe um conjunto de “formas”
(distribuições) que aparecem repetidamente em
muitos e variados problemas.

# Distribuições Discretas
# Distribuição de Bernoulli

$I_A(𝜔)\ =\ 1\ se\ 𝜔\ 𝜖\ A, 0\ caso\ contrário$

$E[X] = p$

$Var(I) = p(1-p)$

# Distribuição Binomial
Seja 𝑋 o número de vezes que um
acontecimento 𝐴 ocorre em 𝑛 experiências de
Bernoulli, isto é, 𝑋 representa o número de sucessos em 𝑛
experiências (observações)

$p_{X}(k) = Pr(X = k) = \binom{n}{k}\ p^k\ {(1-p)}^{n-k}$

$E[X] = n\ p$

$ Var(X) = n\ p\ (1-p)$


# Distribuição de Poisson

Função de massa de probabilidade da distribuição de Poisson

$p_X(k) = \frac{𝜆^k\ e^{-𝜆}}{k!}$

$E[X] = 𝜆$

$Var(X) = 𝜆$ 

# Distribuição Geométrica

Seja 𝑋 o número de vezes que é necessário
repetir uma experiência de Bernoulli até obter
um sucesso

$p_X(k) = p(1-p)^{k-1}, k = 1,2,3,\ ...$

$ E[X]  = \frac{1}{p}$

$ Var(X) = \frac{(1-p)}{p²}$



# Distribuições contínuas

# Distribuição uniforme

$E[X] = \frac{a+b}{2} $

$Var[X] = \frac{(b-a)²}{12} $
 
### Função rand() do Matlab

Para ter U(a,b) basta usar: 
```matlab
a+rand()*(b-a)
```
# Distribuição Normal (ou Gaussiana)

$f_X(x) = \frac{1}{\sqrt{2 \pi}𝜎}e^{-\frac{(x-m)²}{2𝜎²}}$

$E[X] = m$

$Var(X) = 𝜎²$
- É muito provavelmente a mais conhecida e utilizada de todas as distribuições (contínuas)

Adequa-se/ajusta-se a muitas características humanas

- Altura, peso, velocidade, resultados de testes de inteligência,
esperança de vida…

• Também se adequa a muitas outras coisas da natureza
- Árvores, animais etc têm muitas características que seguem a
distribuição normal

• Surge quando vários efeitos acumulados e independentes
se sobrepõem


# Distribuição exponencial

Surge frequentemente em problemas envolvendo
filas de espera e fiabilidade

$f_X(x) = 𝜆e^{−𝜆𝑥}$

$ E[X] = \frac{1}{𝜆}$

$Var(x) = \frac{1}{𝜆²}$



# Desigualdade de Markov

$P(X\ge a) \le \frac{E[X]}{a},\ qualquer\ a> 0  $

# Desigualdade de Chebyshev

$P(|X-E[X]| \ge a) \le \frac{Var(X)}{a²}$

# Teorema do Limite Central

$P(|M_n - f| \le 0.05) \ge 0.95 $
<br>
<br>
<br>
<br>
<br>

# Cadeias de Markov

Um processo de **Markov** é um processo
estocástico em que a probabilidade de o
sistema estar num estado específico num
determinado período de observação depende
apenas do seu estado no período de
observação imediatamente precedente


## Matriz de transição 

Seja $t_{ji}$, a probabilidade de transitar do estado i para o estado j.

$
\begin{bmatrix}
t_{11} & ... &  t_{1n}\\
 ... & ... &  ...  \\   
t_{n1} & ... & t_{nn}\\ 
\end{bmatrix}$

## Matriz T é estocástica

- Todas as entradas são não-negativas

- Os valores em cada COLUNA somados são sempre 1

Caso se verifiquem estas propriedades a matriz é denominada de matriz estocástica.

## Vetor estado 

$x^{(10)} = \binom{0.5}{0.5}$

$x^{(k+1)} = Tx^{(k)}$

# Cálculo do vector estado estacionário 

$Tu = u$

Ou de forma matricial, 
$ (T-I)u = 0$

Em matlab 

```matlab
M = [T - eye(length(T)); ones(1,length(T))];
x = [zeros(1,length(T)), 1];
% Vetor estacionário
u = M\x;
```
# PageRank

O pagerank (r) de uma página $P_j$ é por definição:

$r(P_j) = \sum{i} \frac{r(P_i)}{d_i}$ 


estado estacionário $r = Hr$


## Problemas 

### Dead ends
$
H = 
\begin{bmatrix}
 0 & 0.5 & 0& 0\\
1/3 & 0 & 0& 0.5\\
1/3 & 0 & 0& 0.5\\
1/3 & 0.5 & 0& 0\\
\end{bmatrix}$

### Solução:
$
H = 
\begin{bmatrix}
 0 & 0.5 & 1/4& 0\\
1/3 & 0 & 1/4& 0.5\\
1/3 & 0 & 1/4& 0.5\\
1/3 & 0.5 & 1/4& 0\\
\end{bmatrix}$


### Spider traps

$
H = 
\begin{bmatrix}
 0.5 & 0.5& 0\\
 0.5 & & 0\\
 0 & 0.5& 1\\
\end{bmatrix}$

### Solução:

$H_{new} = \beta * H + (1 - \beta) \times\frac{ones(length(H))}{length(H)}$

# Google Matix

$ A = \beta H + (1 - \beta)[\frac{1}{N}]_{N×N}$


## Alguns problemas do Page Rank
- Mede a importância genérica

Não tem em conta “autoridades” num tópico
específico

-  Solução: Topic-Specific PageRank
- Usa uma medida única de importância
- Solução: Hubs-and-Authorities
- Susceptível a spam de links, por exemplo “spam farms”: topografias artificiais de links criadas para aumentar o pagerank

- Solução: TrustRank


# Intervalos de Confiança

$ IC = estimativa ± valor\_critico × erro\_padrão$
### Exemplo 


$IC = M_n ± z_{σ/2}(σ / \sqrt{n})$

$M_n = 10.2, σ = 1.5, n= 25$

$IC = 10.2 ± 1.96 (1.5 / \sqrt{25}) = [9.61, 10.79]$ 

em Matlab **ztest()**

---

# Cadeias de Markov em tempo contínuo


## 1. Enunciado do Problema

Considere-se um Centro de Dados com:
* **2 servidores** idênticos e independentes.
* **1 técnico de manutenção** dedicado.

### Parâmetros de Tempo:
1. **Tempo de funcionamento** de cada servidor até falhar (tempo de vida útil): distribuído exponencialmente com uma média de **180 dias**.
2. **Tempo de reparação** de um servidor por parte do técnico: distribuído exponencialmente com uma média de **6 horas**.

**Objetivo:** Obter o diagrama de transição de estados, as taxas de transição, as probabilidades em regime estacionário (limite) de cada estado e analisar as métricas de desempenho associadas.

---

## 2. Definição dos Estados

O estado do sistema no instante $t$, denotado por $X(t)$, é definido pelo **número de servidores que estão avariados (ou em reparação)** no Centro de Dados:

* **Estado 0:** 2 servidores a funcionar (0 avariados).
* **Estado 1:** 1 servidor a funcionar e 1 servidor em reparação.
* **Estado 2:** 0 servidores a funcionar e 2 servidores em reparação/espera.

---

### Regra Fundamental: Sem Auto-Transição ($P_{ii} = 0$)

Numa CTMC, quando ocorre o evento de "salto", o sistema muda obrigatoriamente de estado. Por isso, no diagrama de taxas, não existem setas que saem de um estado e voltam para ele próprio.

---

## 3. Determinação das Taxas de Transição

Expressamos todas as taxas na mesma unidade de tempo: **dias**.

### 3.1. Taxa de Falha de um Servidor ($\lambda$)
O tempo médio até à falha é $MTTF = 180 \text{ dias}$.
$$\lambda = \frac{1}{180} \text{ falhas por dia}$$

### 3.2. Taxa de Reparação de um Servidor ($\mu$)
O tempo médio de reparação é $6 \text{ horas} = 0.25 \text{ dias}$.
$$\mu = \frac{1}{0.25} = 4 \text{ reparações por dia}$$

---

## 4. Diagrama de Transição de Estados
### 1. Gráfico (Diagrama) de Transição de Estados

No diagrama de uma CTMC (Cadeia de Markov em Tempo Contínuo), as setas representam as **taxas de transição** ($q_{ij}$) entre os estados. Os estados indicam o número de servidores avariados.



```text
       2/180 (λ0)       1/180 (λ1)
  ( 0 ) ----------> ( 1 ) ----------> ( 2 )
        <----------       <----------
           4 (μ1)            4 (μ2)
```

$
T = \begin{pmatrix}
0 & 4 & 0 \\
\frac{2}{180} & 0 & 4 \\
0 & \frac{1}{180} & 0
\end{pmatrix}
$

$
Q = \begin{pmatrix}
-\frac{2}{180} & 4 & 0 \\
\frac{2}{180} & -\left(4 + \frac{1}{180}\right) & 4 \\
0 & \frac{1}{180} & -4
\end{pmatrix}
$

Calculamos as taxas de transição $q_{ij}$ (taxa de passagem do estado $i$ para o estado $j$):

* **$q_{01} = 2 \lambda = \frac{2}{180}$**: Com 2 servidores ativos, a taxa de falha do sistema é o dobro.
* **$q_{12} = 1 \lambda = \frac{1}{180}$**: Com apenas 1 servidor ativo, a taxa de falha é $\lambda$.
* **$q_{10} = \mu = 4$**: 1 técnico a reparar 1 servidor.
* **$q_{21} = \mu = 4$**: 1 técnico a reparar o primeiro de 2 servidores avariados.



---

## 5. Equações de Balanço e Resolução

Aplicamos o princípio: **Fluxo que SAI = Fluxo que ENTRA**.

1. **Estado 0:** $\frac{2}{180} \pi_0 = 4 \pi_1$
2. **Estado 2:** $4 \pi_2 = \frac{1}{180} \pi_1$
3. **Normalização:** $\pi_0 + \pi_1 + \pi_2 = 1$

### Resultados:
* **$\pi_1 = \frac{1}{360} \pi_0$**
* **$\pi_2 = \frac{1}{720} \pi_1 = \frac{1}{259200} \pi_0$**

Resolvendo para $\pi_0$:
* **$\pi_0 \approx 0.997226$** ($99.72\%$)
* **$\pi_1 \approx 0.002770$** ($0.277\%$)
* **$\pi_2 \approx 0.000004$** ($0.0004\%$)

---

## 6. Métricas de Desempenho

* **N.º médio de servidores operacionais:** $2\pi_0 + 1\pi_1 + 0\pi_2 \approx \mathbf{1.997}$ servidores.
* **Ocupação do técnico:** $\pi_1 + \pi_2 \approx \mathbf{0.277\%}$ do tempo.
* **Disponibilidade do sistema:** $\pi_0 + \pi_1 \approx \mathbf{99.9996\%}$ do tempo.

# Processos de nascimento e morte

Seja o sistema cujo estado representa o número de clientes no sistema (n = 0,1,2,...) 

Sempre que o sistema tem n clientes
(1) chegam novos clientes ao sistema a tuma taxa exponencial $\lambda_n$
(2) partem clientes do sistema a uma taxa exponencial $µ_n$

Este sistema é designado por processo de **nascimento e morte**, $\lambda$ taxa de chegada ou nascimento  e taxa de partida ou morte, µ.

```      
        lambda_0   lambda_1      
        ----->      ----->
    (0)         (1)         (2) ....
        <-----      <-----
          µ_1         µ_2
        
```

### Taxa de entrada = taxa de saída

| Estado | entrada = saida |
| --- |-- |
| 0 | $µ_1 \pi _1 = \lambda_0 \pi_0$ |
| 1 | $µ_2 \pi _2 + \lambda_0 \pi_0 = (\lambda _ 1 + µ_1 ) \pi_1$ |
| 2 | $µ_3 \pi _3 + \lambda_1 \pi_1 = (\lambda _ 2 + µ_2 ) \pi_2$ |
| n | $µ_{n+1} \pi _{n+1} + \lambda_{n-1} \pi_{n-1} = (\lambda _ n + µ_n ) \pi_n$ |




<!-- 
                 Selo de certificação resumo LeitnerzinhoPVP  
                                                                         
       XXX                                                                
      XX                             XX                                   
     XX                               X       XXXXX                       
     X                               XXXXXXX                              
    X                        XXXXXXXXXXX                                  
   XX                                  X                                  
   X                       X           X                  XXXXXXX         
  X              XXXXXXX               X     X          XXX     X   X     
  X           XXXX     X   X           X    XXXXXXXXX   X  XXXXXX   XX    
 XX          XXXXX   XXX   X           X    XX       X  XXX          XXXXX
 X          XX   XXXX      X          XX   XXX       X  X            X   X
 X          X             XX         XX    X        XX  XX           X   X
XX           XXX          X         XX     X      XXX     XXXX      X     
X     XXXXXXX  XXXXX     XX       XXX     X      XX           XXXX  X     
XXXXXXX                 X       XX                                           

-->



