%% 
% 1. 
% a) 

p = 0.5;
N = 1e4;
num_Children = 2;

experiencias = rand(num_Children, N) <p;
success = sum(experiencias) >=1;
prob = sum(success)/N;
prob;

%% 
% b)
% P(>=1) = 1 - P(0)
p = 0.5;
k = 0;
n = 2;

prob = nchoosek(n,k)*p^k*(1-p)^(n-k);
1-prob;

%%
% c)
% B = probabilidade um deles é boy
% A = probabilidade de outro ser boy
% probabilidade de (A|B) = P(A e B)/P(B)

p = 0.5;
N = 1e4;
k = 2;
n = 2;
% P(A e B)

A_e_B = rand(n,N) < p;
A_e_B = sum(A_e_B) == 2;
A_e_B = sum(A_e_B) / N;

% P(B)

B = rand(n,N) < p;
B = sum(B) >= 1;
B = sum(B) / N;

Probabilidade = A_e_B / B