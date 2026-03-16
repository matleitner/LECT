%%  TASK 1  %%
%1. a)
N = 10000;
% Gera uma matriz 3 linhas e 10000 colunas de números
% aleatórios entre 0 e 1 

experiments = rand(3, N);


% Gera uma matriz em que é 1 cara quando < 0.5 e 
% 0 >= 0.5 simulando coroa

tosses = experiments < 0.5;


% Gera um vetor linha com 10000 elementos 
% em que 1 é quando ha 2 caras 
sucesso = sum(tosses)== 2;

% Determinar a probabilidade 

probSimulation = sum(sucesso)/N;

%% 
% 2.
% a)
N = 1e5;
p = 0.5;
n = 15;

tosses = rand(n, N) < p;
successes_a = sum(tosses) == 6;
prob_a = sum(successes_a) / N;

% b) 

successes_b = sum(tosses) >= 6;
prob_b = sum(successes_b) / N;

prob_a 
prob_b


%%
% 3. a) = HeadTailsProb.m
% 3. b) 
N = 1e4;

p = 0.5;

n = 100;

function Y = create(n, N, p)

    Y = zeros(1, n+1);
    for k = 0:n
        Y(k+1) = HeadTailsProb(p,n,k,N);
    end
end
Y100 = create(100, N,p);
Y40  = create(40, N,p);
Y20  = create(20, N,p);
figure(3)
subplot(2,2,[3 4]);
stem(Y100);
xlabel("Nº de Caras");
ylabel("Probabilidade");
title("100 Moedas");
grid on;

subplot(2,2,2)
stem(Y40);
xlabel("Nº de Caras");
ylabel("Probabilidade");
title("40 Moedas");
grid on;

subplot(2,2,1)
stem(Y20);
xlabel("Nº de Caras");
ylabel("Probabilidade");
title("20 Moedas");
grid on;


%%
% 4.
p = 0.5;
k = 2;
n = 3;
% exercicio 1 
function prob = prob(p,n,k)
    prob = nchoosek(n,k) * p^k*(1-p)^(n-k);
end

% exercicio 2
% a)
prob(p,n,k)
p = 0.5;
k = 6;
n = 15;
prob(p,n,k)

% b) P(X>=6) = 1 - P(X<6) = 1 - (P(0) + P(1) + ... + P(5))

somador = 0;

for i = 0:1:5
    somador = somador + prob(p,n,i);
end

1 - somador 

%% 
% 5.
BER = 1e-5;
size = 100 * 8; % bytes * bits;
% a)
probabilidade_a = prob(BER, size, 0)

% b) 
size = 1000 * 8;

probabilidade_b = 1 - prob(BER,size,0) - prob(BER,size,1)




%% 6. (OPCIONAL)
fprintf("\n6.\n")
% a)
fprintf("a)\n")
N = 1e4;
p = 0.1;    % probabilidade de ser defeituoso
n = 5;      % sample of 5 

function prob = AnalyticsCalc(n,p,k)
    prob = nchoosek(n,k) * p^k * (1-p)^(n-k);
end

k = 3;
probabilidade_5_defeituosos = AnalyticsCalc(n,p,k);
fprintf("A probabilidade de 3 de 5 sairem defeituosos: %.4f\n", probabilidade_5_defeituosos);
experiments = rand(n,N) < p;
success = sum(experiments) == 3;
P = sum(success) / N;
fprintf("A probabilidade de 3 de 5 sairem defeituosos por simulação: %.4f\n", P);

% b)
fprintf("b)\n")
X = 2;      %P(X<=2) = P(0) + P(1) + P(2)
Prob = AnalyticsCalc(n,p,0) + AnalyticsCalc(n,p,1) + AnalyticsCalc(n,p,2);

fprintf("Valor teórico da probabilidade de P(X<=2) = %.4f\n", Prob)

experiments = rand(n,N) < p;
success = sum(experiments) <= 2;
Prob_Sim = sum(success) / N;

fprintf("Valor por simulação da probabilidade de P(X<=2) = %.4f\n", Prob_Sim)

% c)
fprintf("c)\n")
experiments = rand(n,N) < p;
dados = zeros(1,n+1);
for i = 0:5
    success = sum(experiments) == i;
    probabilidade = sum(success) / N;
    dados(1,i+1) = probabilidade;
end


bar(0:n,dados)



%% %%% %%% %%% %%% %%

%% TASK 2 %%

%% 1.
%% a) 
%  
%  Probabilidade PELO MENOS UM FILHO EM FAMILIAS DE 2 CRIANÇAS

p = 0.5;
N = 1e4;
num_Children = 2;
k = 1;
experiencias = rand(num_Children, N) <p;
success = sum(experiencias) >=k;
probailidade = sum(success)/N;
probabilidade

%% b) 
% valor teórico 
% P(>=1) = 1 - P(0)
p = 0.5;
k = 0;
n = 2;

probi = nchoosek(n,k)*p^k*(1-p)^(n-k);
probabilidade = 1-probi;

%% c)
%  
% B = probabilidade um deles é rapaz
% A = probabilidade de outro ser rapaz
% probabilidade de (A|B) = P(A e B)/P(B)

p = 0.5;
N = 1e4;
k = 2;
n = 2;
% P(A e B)

experiments = rand(n,N) < p;
A_e_B = sum(experiments) == 2;
A_e_B = sum(A_e_B) / N;

% P(B)


B = sum(experiments) >= 1;
B = sum(B) / N;

Probabilidade = A_e_B / B;
Prob_A_e_B = nchoosek(n,k)*p^k*(1-p)^(n-k);

Prob_B = 1 - nchoosek(n,0)*p^0*(1-p)^(n-0);

P = Prob_A_e_B / Prob_B
% Para 2 crianças, todos os casos equiprováveis são:
% BB, BG, GB, GG
% Condicionando que pelo menos um é rapaz (B), descartamos GG:
% Casos restantes: BB, BG, GB → 3 casos.
% Apenas BB satisfaz "outro também é rapaz" → probabilidade:
% P(outro rapaz | pelo menos 1 rapaz)=1/3≈0.333




%% d)
% sabendo que a primeira criança de 2 é um rapaz probabilidade da 
% segunda criança ser um rapaz 
% A: segunda criança ser um rapaz
% B: primeira criança é um rapaz 
% P(B|A) = P(B e A) / P(A) = P(B) * P(A) /P(A) se forem independentes

N = 1e4;
p = 0.5;
num_of_children = 2;
tosses = ones(num_of_children, N);       % 1ª linha é sempre 1 (rapaz)
tosses(2, :) = rand(1, N) < p;            % a segunda é aleatória 
success = sum(tosses) == 2; 
probi = sum(success) / N;
probi;

% *Conclusão* O resultado mostra 
% que o sexo da segunda criança não 
% depende do sexo da primeira → eventos 
% independentes.

%% e)
%  probabilidade de um dos outros e apenas um também ser rapaz
%  sabendo que pelo menos uma criança é um rapaz

% B: pelo menos um é rapaz

num_of_children = 5;
N = 1e4;
p = 0.5;

families = rand(num_of_children, N) < p;
success = sum(families) >= 1; % pelo menos 1 é rapaz
prob_B = sum(success) / N;
% A: 2 são rapazes P(A e B) = P(A )

success = sum(families) == 2;
prob_A_e_B = sum(success)/ N;
% P(2 rapazes | ≥1 rapaz)= P(2 rapazes) / P(≥1 rapaz)​

probi = prob_A_e_B / prob_B;

%% f)
% repetir e) mas prob de pelo menos um dos outros é um rapaz
% sendo X um rapaz
% P(X >= 2 | X >= 1) = pelo menos um dos outros é rapaz sabendo que pelo 
% menos uma criança é rapaz

% P(X>=2 e X>=1) = P(X>=2)

num_of_children = 5;
N = 1e4;
p = 0.5;

families = rand(num_of_children, N) < p;

success_A = sum(families) >= 2; % P(X >= 2) 
prob_A = sum(success_A) / N;

success_B = sum(families) >= 1;
prob_B = sum(success_B) / N;


probi = prob_A / prob_B
%% 2. 

%% a)
n = 20;
m = 100;
N = 1e4;
% randi( imax, m,n) cria uma matrix m X n com numeros
% aleatorios de 1 a imax
experiments = randi(m, n, N);
contador = 0;

for i =1:N
    
    if length(unique(experiments(:,i))) == n
        contador = contador + 1;
    end
end

prob_a = contador / N;
% b)

contador = 0;

for i = 1:N
    if length(unique(experiments(:,i))) < n
            contador = contador + 1;
    end
end

probi = contador / N;
fprintf("b) P(b) = %.4f == a) 1-P(a) = %.4f\n", prob,1 - prob_a)
%% c)

m = 1000;
m1 = 100000;

N = 1e4;

function A = darts(m,n,N)
    experiments = randi(m, n, N);
    contador = 0;
    for i =1:N
        if length(unique(experiments(:,i))) < n
            contador = contador + 1;
        end
    end
    A = contador / N;
end
x = 10:10:100;
Y = ones(1,10);
X = ones(1,10);
i = 1;
for n = 10:10:100
    Y(1,i) = darts(m,n,N);
    X(1,i) = darts(m1,n,N);
    i = i +1;
end
figure(4)
subplot(1,2,1)
plot(x,X)
title("100000 targets")
xlabel("Steps")
grid on

subplot(1,2,2)
plot(x,Y)
title("1000 targets")
grid on 
%% 3. (OPCIONAL)
% a)
fprintf("\n3.\na)\n")
T = 1000;
a = 0;
b = T - 1;
keys = 10;
N = 1e4;

experiments = randi(T, keys, N);
contador = 0;
for i = 1:N
    if length(unique(experiments(:,i))) ~= keys
        contador = contador + 1;
    end
end

probi = contador / N;
fprintf("Probabilidade pelo menos 1 colisão (simulação) P(X) = %.3f\n", probi)

% b)
fprintf("b)\n")
key = 50;
probabilities = zeros(1,key);
keys = 1:key;
for k = 1:key
    experiments = randi(T, k, N);
    contador = 0;
    for i = 1:N
        if length(unique(experiments(:,i))) ~= k
            contador = contador + 1;
        end
    end
    probabilities(1,k) = contador/N;

end
figure(5)
subplot(2,1,1)
plot(keys, probabilities);
xlabel('Número de chaves')
ylabel('Probabilidade de colisão')
title('3.b) Probabilidade de colisão vs número de chaves')
grid on
xlim([0, key+1])
ylim([0 1.1])

% c) 
Tmax = 1000;
keys = 50;
N = 1e4;
contador = 0;
prob_3_c = zeros(1, Tmax/100);

for T = 100:100:Tmax
    contador = 0;
    experiments = randi(T, keys, N);
    for i = 1:N
        if length(unique(experiments(:, i))) == keys
            contador = contador + 1;
        end
        
        
    end

    prob_3_c(1, T/100) = contador / N;
end
T_values = 100:100:1000;
subplot(2,1,2)
plot(T_values, prob_3_c)
xlabel('Tamanho da tabela T')
ylabel('Probabilidade de nenhuma colisão')
title('3.c) Probabilidade de nenhuma colisão vs T')
grid on
xlim([0, Tmax+50])
ylim([0 0.4])
%% 4. 
%% a)
n = 1;

p = 0;
d = 365;
N = 1e4;

while p <= 0.5   
    n = n +1; 
    experiments = randi(d, n, N);
    contador = 0;
    for i = 1:N
        if length(unique(experiments(:, i))) < n
            contador = contador + 1;
        end
    
    end
    p = contador/ N;
end

n 



%% b)
d = 365;
p = 0;
n = 1;
while p <= 0.9   
    n = n +1; 
    experiments = randi(d, n, N);
    contador = 0;
    for i = 1:N
        if length(unique(experiments(:, i))) < n
            contador = contador + 1;
        end
    
    end
    p = contador/ N;
end

n

%% 5.
%% a)
n = 2;
N = 1e4;
sides = 6;
experiments = randi(6, n, N);

% A
success_A = sum(experiments) == 9;
prob_A = sum(success_A) / N

% B
successes_B = mod(experiments(2,:),2) == 0;
prob_B = sum(successes_B)/ N

% C

contador_C = 0;

for C = 1:N
    if experiments(1,C) == 5 || experiments(2,C) == 5
       contador_C = contador_C + 1;
    end

end
prob_C = contador_C / N

% D
contador_D = 0;
for D = 1:N
        if experiments(1, D) ~= 1  && experiments(2,D) ~= 1
           contador_D = contador_D + 1;
       end
end 

prob_D = contador_D / N 


%% b)


% Prob of A
%       1 2 3 4 5 6
%     1 
%     2
%     3           x
%     4         x
%     5       x
%     6     x
% n número de experiencias

prob_A = 4 / 36;    % la Place (casos favoraveis / possiveis)



% Prob of B
%       1 2 3 4 5 6
%     1   x   x   x
%     2   x   x   x
%     3   x   x   x
%     4   x   x   x
%     5   x   x   x 
%     6   x   x   x

prob_B = 3/6;


% Prob of A and B 

%     1º  1 2 3 4 5 6  <- (2o lançamento)
%     1   
%     2   
%     3             x   
%     4   
%     5         x
%     6   


prob_A_e_B = 2 / 36
independents = 0;
if prob_A_e_B == prob_A * prob_B
    independents = 1;
end

independents

%% c)

% Prob of C

%     1º  1 2 3 4 5 6  <- (2o lançamento)
%     1           x
%     2           x
%     3           x     
%     4           x  
%     5   x x x x x x
%     6           x 
favoraveis = 11;
possiveis = 36;
prob_C = favoraveis / possiveis;

% Prob of pelo menos um é 1
%     1º  1 2 3 4 5 6  <- (2o lançamento)
%     1   x x x x x x
%     2   x
%     3   x   
%     4   x
%     5   x
%     6   x

% 
favoraveis =  36 - 11;
possiveis = 36;
prob_D = favoraveis / possiveis;

% Prob of C and C 

%     1º  1 2 3 4 5 6  <- (2o lançamento)
%     1           
%     2           x
%     3           x     
%     4           x  
%     5     x x x x x
%     6           x 

prob_C_e_D = 9 / 36;

independents = 0;
if prob_C_e_D == prob_C * prob_D
    independents = 1;
end

independents





%% 6.
%% a)
% probability of the transmitted data packets 
% being received with errors

% normal link condition
p1 = 0.001;

% external interfences
p2 = 0.1;

% probability of being with external interfences is 2%
p3 = 0.02;

% probability of being without external interfences

p4 = 1 - 0.02;
% P(erro) = P(erro | sem interferencia) / P(interferencia) || P(erro | sem
% interferencia) / P(interferencia)

p = p1 * p4 + p2 * p3


%% b)

% Probabilidade de erro em condições normais (sem interferências)
p1 = 0.001; 

% Probabilidade de erro com interferências externas
p2 = 0.1; 

% Probabilidade de o link estar com interferências externas
p3 = 0.02;

% Probabilidade de o link estar sem interferências externas
p4 = 1 - p3;

% Calculando a probabilidade total de erro
p_erro = p1 * p4 + p2 * p3;

% Calculando as probabilidades condicionais usando o Teorema de Bayes

% Probabilidade de o link estar sem interferências, dado que houve erro
p_sem_interferencias = (p1 * p4) / p_erro;

% Probabilidade de o link estar com interferências externas, dado que houve erro
p_com_interferencias = (p2 * p3) / p_erro 





%% 7. (OPCIONAL)

% escolher 1 de 100 programas 
% P(Carlos | bug) = ?

% formula P(bug | Carlos) * P(carlos)/ P(bug)

total_programas = 100;
num_cadaProgramador =  [20, 30, 50];

% P(A_i)   ( A_i são os nomes ) 
Prob_A_i = num_cadaProgramador/total_programas;
P_B = 0;   

% P(B| A_i) 
P_B_sabendo_que_Ai = [0.01, 0.05, 0.001];

%indexs para ser mais facil de ir buscar informações
Andre = 1;
Bruno = 2;
Carlos = 3;
% P(B) = somatorio i = 1 → 3(P(bug| A_i) * P(A_i)) 
for i = 1:3
    P_B = P_B + P_B_sabendo_que_Ai(1,i) * Prob_A_i(1,i);
end

% P(Carlos | B) = P(B| Carlos) * P(Carlos) / P(B) 
P_Carlos_sabendo_que_B = P_B_sabendo_que_Ai(1,Carlos) * Prob_A_i(1,Carlos) / P_B;

fprintf("7.\na) Probabilidade do programa selecionado ser do Carlos é: %.4f\n",P_Carlos_sabendo_que_B)









