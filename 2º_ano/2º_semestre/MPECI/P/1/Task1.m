%%
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





