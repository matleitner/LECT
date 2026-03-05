%% 1.

%% a) e b)
figure(1)
X = 1:6;
Y = ones(1,6) * 1/6;
subplot(1,2,1) % organizar o plot em 1 linha e 2 
               % colunas e 1 que é o sitio onde quero meter o grafico
stem(X,Y)
xlim([0 7])
ylim([0 1/5])
grid on
title('1(a)')
xlabel('x')
ylabel('Prob. mass function of x')


subplot(1,2,2)
Z = cumsum(Y);
stairs([0 X 7],[0 Z 1])   % isto pega  no vetor X
                          % e mete entre 0 e 7 e 0 Z 1.1
xlim([0 7])
ylim([0 1.1])
ylabel('Cumulative distribution function of x')
xlabel('x')
title('1(b)')
grid on

%% 2.
% a)
figure(2)
T = 90 + 9 + 1;
prob = 1 / 100;
% b)
X = [5, 10, 100];
prob = [90/T, 9/T, 1/T ];
% c) 
x = cumsum(prob);
stairs([0 X], [0 x])
xticks([0 5 10 100])
ylim([0 1.1])

%% 3. 
X = 0:4;
% a)
fprintf("Exercicio a)")
N  = 1e4;
experiments = rand(4,N) < 0.5;
P = zeros(1,5);

for i = 0:4
   success = sum(experiments) == i;
   prob = sum(success)/ N;
   j = i + 1;
   P(1,j) = prob;
end

P

% b)
fprintf("Exercicio b)")
media = sum(X.*P)
variancia = sum(X.^2 .* P) - media.^2
desvio = sqrt(variancia) % variancia ^(1/2)



% c) 
fprintf("Exercicio c)")
n = 4;
p = 0.5;
P = zeros(1,5);
for k = 0:4
    prob = nchoosek(n,k)*p^k*(1-p)^(n-k);
    j = k + 1;
    P(1,j) = prob;
end
% d)
fprintf("Exercicio d)")
P

% e)
fprintf("Exercicio e)")
media = sum(X.*P)
variancia = sum(X.^2 .* P) - media.^2
desvio = sqrt(variancia) % variancia ^(1/2)

%f)
fprintf("Exercicio f)")

% i) 
p = 0;
for i = 2:4
    j = i + 1;
    p = p + P(1,j);  
end
p_AtLeast2Heads = p

% ii)

p = 0;

for i = 0:1
    j = i + 1;
    p = p + P(1, j);
end
p_upTo1HEAD = p


% iii)

p = 0;

for i = 1:3
    p = p + P(1, i);
end
p_between1and3HEADS = p


%% 6.

BER = 1e-5;
% a) probabilidade de 100 Bytes serem 
% recebidos sem erros ( teórico )

% k = probabilidade de...
% X variável aleatória 
% n número de bits

function p = Poisson(X,n, k)
    lambda = n * k;
    p = (lambda^X)/factorial(X) * exp(-lambda);
end

function prob = binomialDis(n,k,p)
    prob = nchoosek(n,k)*p^k*(1-p)^(n-k);
end

X = 0;
n = 8 * 100;

poisson = Poisson(X, n, BER)
binomialDistribution = binomialDis(n,X,BER)

% b) pelo menos 2 erros = 1 - P(0) - P(1)
n = 8 * 1000;
fprintf("Pelo menos 2 erros\n\n\nBinomial:")
probPeloMenos2ErrosD = 1 - binomialDis(n,0,BER) - binomialDis(n,1,BER) 
fprintf("\nPoisson:")
probPeloMenos2ErrosP = 1 - Poisson(0,n,BER) - Poisson(1, n, BER)
fprintf("%.3f\n", probPeloMenos2ErrosP*100);


%% 7.


% uma distribuição de POISSON com uma 
% média de 5 mensagens por segundo é o
% mesmo que dizer que o lambda  (taxa media de eventos)
% é 5

% a) the probability of the server to receive less 
% than 10 messages in an interval of 2 seconds,

N = 1e4;
lambda = 5 * 2; % 5 * 2 segundos
k = 10;
experiments = poissrnd(lambda, 1, N ) < k;
prob_sim_a = sum(experiments) / N
prob_theoretical = 0;
for i = 0:k-1
    prob_theoretical = prob_theoretical + lambda ^ i / factorial(i) * exp(-lambda);   
end
prob_theoretical_a = prob_theoretical

% (b) the probability of the server to receive more than 
% 30 messages in an interval of 5 seconds.

N = 1e4;
lambda = 5 * 5; % 5 emails/s* 5 = emails/ 5segundos
k = 30;
experiments = poissrnd(lambda, 1, N ) <= k;
prob_sim = sum(experiments) / N
prob_theoretical = 0;


for i = 0:k
    prob_theoretical = prob_theoretical + lambda ^ i / factorial(i) * exp(-lambda);   
end
% P(X > 30) = 1 - P(X <=30)

prob_theoretical = 1-prob_theoretical
prob_sim   = 1 - prob_sim


%% 8.

% a) Using Matlab exppdf function, plot the probability 
% density function of X for the values from 0 to 10
lambda  = 1;
X = 0 :0.1: 10;
Y = exppdf(X, lambda);

figure(1);
plot(X,Y);

% b)Using Matlab exprnd function, generate a vector 
% with 10⁵ random values of X and plot a
% histogram of the generated values with 100 bins. 
% Is the histogram in accordance with the
% probability density function of X?  













%% 9. 

% a) Show that the average of the generated values is 
% in accordance with the average of the
% exponential distribution.

lambda = 0.2;
N = 1e2;
X = rand(N);
media = 1 / 0.2;

a = exprnd(lambda, X); 




%% 13. 


% mean = 20 g
% var = 9 → desv padrão = 3
% cookie weight are ind and identically distributed

% a) E[S_n] and Var[S_n]
% sum of each E[X_i], sum(Var[X_i])
% sol: E = n * 20  n * sigma² 

% b) 
% desigualdade  Markov
% 66.7 %

% c) 
% desigualdade Chebyshev
% 9.0%


% d) 
% distribuição gaussiana ? 
% 68.27%