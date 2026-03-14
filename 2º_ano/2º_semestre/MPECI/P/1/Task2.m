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
prob = sum(success)/N;
prob

%% b) 
% valor teórico 
% P(>=1) = 1 - P(0)
p = 0.5;
k = 0;
n = 2;

prob = nchoosek(n,k)*p^k*(1-p)^(n-k);
probabilidade = 1-prob;

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

Probabilidade = A_e_B / B
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
prob = sum(success) / N;
prob;

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

prob = prob_A_e_B / prob_B;

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


prob = prob_A / prob_B
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

prob = contador / N;
prob_a = prob;
% b)

contador = 0;

for i = 1:N
    if length(unique(experiments(:,i))) < n
            contador = contador + 1;
    end
end

prob = contador / N;
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