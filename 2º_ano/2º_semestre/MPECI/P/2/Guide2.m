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

w
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

% P(event) = number of favorable banknotes / total banknotes
% ​
T = 90 + 9 + 1;
prob100 = 1 / 100;
prob10 = 9 / 100;
prob5 = 90 / 100;
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

fprintf(" P: ")
for n = 1:5 
fprintf("%.3f→",P(1,n));

end
fprintf("\n");
% b)
fprintf("Exercicio b)")
media = sum(X.*P);
variancia = sum(X.^2 .* P) - media.^2;
desvio = sqrt(variancia); % variancia ^(1/2)
fprintf(" Média %.3f, Variância: %.3f, Desvio Padrão: %f.3", media, variancia, desvio)


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

for n = 1:5
    fprintf("%.3f→", P(1,n))
end

fprintf("\n");
% e)
fprintf("Exercicio e)")
media = sum(X.*P);
variancia = sum(X.^2 .* P) - media.^2;
desvio = sqrt(variancia); % variancia ^(1/2)
fprintf(" Média %.3f, Variância: %.3f, Desvio Padrão: %f.3\n", media, variancia, desvio)

%f)
fprintf("Exercicio f)")

% i) 
p = 0;
for i = 2:4
    j = i + 1;
    p = p + P(1,j);  
end
p_AtLeast2Heads = p;
fprintf("\ni) P(X>=2)%.2f\n", p_AtLeast2Heads)
% ii)

p = 0;

for i = 0:1
    j = i + 1;
    p = p + P(1, j);
end
p_upTo1HEAD = p;

fprintf("ii) P(X<=1) = %.3f\n", p_upTo1HEAD)


% iii)

p = 0;

for i = 1:3
    p = p + P(1, i);
end
p_between1and3HEADS = p;

fprintf("iii) P(1<=X<=3) = %.3f\n", p_between1and3HEADS)


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

poisson = Poisson(X, n, BER);
binomialDistribution = binomialDis(n,X,BER);

fprintf("Poisson: %.3f \t Binomial: %.3\n", poisson, binomialDistribution)

% b) pelo menos 2 erros = 1 - P(0) - P(1)
n = 8 * 1000;
fprintf("Pelo menos 2 erros\nBinomial: ")
probPeloMenos2ErrosD = 1 - binomialDis(n,0,BER) - binomialDis(n,1,BER);
fprintf(" P(X>=2) = 1 - P(0) - P(1) = %.3f", probPeloMenos2ErrosD)
fprintf("\nPoisson: ")
probPeloMenos2ErrosP = 1 - Poisson(0,n,BER) - Poisson(1, n, BER);
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
prob_sim_a = sum(experiments) / N;
prob_theoretical = 0;
for i = 0:k-1
    prob_theoretical = prob_theoretical + lambda ^ i / factorial(i) * exp(-lambda);   
end
prob_theoretical_a = prob_theoretical;

% (b) the probability of the server to receive more than 
% 30 messages in an interval of 5 seconds.

N = 1e4;
lambda = 5 * 5; % 5 emails/s* 5 = emails/ 5segundos
k = 30;
experiments = poissrnd(lambda, 1, N ) <= k;
prob_sim = sum(experiments) / N;
prob_theoretical = 0;


for i = 0:k
    prob_theoretical = prob_theoretical + lambda ^ i / factorial(i) * exp(-lambda);   
end
% P(X > 30) = 1 - P(X <=30)

prob_theoretical = 1-prob_theoretical;
prob_sim   = 1 - prob_sim;


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

media = 1 / lambda;
N = 1e5;
X = exprnd(media, 1, N);
histogram(X, 100)

%% 9. 

% a) Show that the average of the generated values is 
% in accordance with the average of the
% exponential distribution.

lambda = 0.2;
N = 1e5;
media_lambda = 1 / 0.2;

media_sim = sum(exprnd(1/lambda,1,N)) / N ;

fprintf("9.\n")
fprintf("  a)\n   Teorico: %.3f vs Simulação: %.3f\n", media_lambda, media_sim);

% 
% b) With the 10⁵ random values generated, show 
% that the exponential distribution has no
% memory, i.e., 𝑃(𝑋 > 𝑠 + 𝑡 |𝑋 > 𝑡) = 𝑃(𝑋 > 𝑠). For example, 
% use the values s = 2 and t = 3 (but the same 
% happens for any pair of values)
lambda = 0.2;
N = 1e5;
experiments = exprnd(1/lambda, 1, N);
s = 2; 
t = 3;
prob_biggerS = sum(experiments > s) / N;
prob_biggerS_plus_T = sum(experiments > t+s) / N;
prob_biggerT = sum(experiments > t) / N;

prob = prob_biggerS_plus_T / prob_biggerT;
fprintf("  b)\n");
fprintf("   P(X > %d | X > %d) = %f\n", s+t, t, prob);
fprintf("   P(X > %d) = %f\n", s, prob_biggerS);

%% 10.
fprintf("10.\n")
lambdaX = 0.4;
lambdaY = 0.1;
N = 1e5;
X = exprnd(1/lambdaX, 1,N);
Y = exprnd(1/lambdaY, 1, N);

success = zeros(1,N);

for i = 1:N 
    if X(1,i) < Y(1,i)
        success(i) = 1;
    end
end
prob = sum(success) / N;
probCalc = lambdaX / (lambdaX+lambdaY);

fprintf("P(X<Y) = %.3f\n lambdaX / (lambdaX + lambdaY) = %.3f\n", prob, probCalc)
%% 12. 
% a)
fprintf("12.\n");

mu = 100;
sigma = 10;

maxNumberOfStudents = 20; % per class
% each student is 
% enrolled in one pratical class
N = 1e5;
n = 5:7;

% gerar numeros de Gauss de N(100,10)
X = mu + sigma*randn(1,N);

capacidadeAulas = 20*n;


prob100= sum(X <= n(1,1)*maxNumberOfStudents) / N; % 20 * 5
prob120= sum(X <= n(1,2)*maxNumberOfStudents) / N; % 20 * 6
prob140= sum(X <= n(1,3)*maxNumberOfStudents) / N; % 20 * 7

fprintf("P(X<=5*20)= %.3f\nP(X<=6*20) = %.3f\nP(X<=7*20)= %.3f\n",prob100, prob120, prob140 )
% b)

P = normcdf(n*20,mu, sigma);
prob_sim100 = P(1,1);
prob_sim120 = P(1,2);
prob_sim140 = P(1,3);
fprintf("\n\nPor simulação:\n")
fprintf("P(X<=5*20)= %.3f\nP(X<=6*20) = %.3f\nP(X<=7*20)= %.3f\n",prob_sim100, prob_sim120, prob_sim140 )

%% 13. 


% mean = 20 g
% var = 9 → desv padrão = 3
mu = 20;
var = 9;

% cookie weight are ind and identically distributed

% a) E[S_n] and Var[S_n]
% sum of each E[X_i], sum(Var[X_i])


fprintf("13.\n\n  a)\n    sol: E[S_n] = n * µ = n * 20; Var[S_n] =  n * sigma² = n*9\n")

% b) 
% desigualdade  Markov
% 66.7 %
% P(X >= 30g) <= E[X_i]/30;
prob_b = mu / 30;
fprintf("  b)\n    P(X >= 30g) <= %.2f%%\n", prob_b*100)
% c) 
% desigualdade Chebyshev
% P(|X - µ| >= 10) <= Var(X)/10
prob_C = var / 10^2;
fprintf("  c)\n    P(|X - µ| >= 10) <= %.2f%%\n", prob_C*100)
% 9.0%


% d) 
% distribuição gaussiana ? 
% 68.27%
% S_100 = X_1 + ... + X_100;

% E[S_100] = µ * 100 : 
E_S100 = mu * 100;

% Var[S_100] = var * 100 :
Var_S100 = var * 100;



% 1970 - 2000 = -30;  -30 / Var[S_100] = -1 
% 2030 - 2000 =  30; " " " = 1;
% Pelo TLC
% P(1970 <S_100  < 2030) = P(-1 < Z_100 < 1) ;

% não percebi ponta 

p = normcdf(2030, E_S100, sqrt(Var_S100)) - normcdf(1970, E_S100, sqrt(Var_S100));
fprintf("  d)\n    Prob = normcdf(2030, E_S100, sqrt(Var_S100)) -\n     normcdf(1970, E_S100, sqrt(Var_S100) = %.2f%%\n", p*100)
