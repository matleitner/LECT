%% 
% 1. 
% a) Probabilidade PELO MENOS UM FILHO EM FAMILIAS DE 2 CRIANÇAS

p = 0.5;
N = 1e4;
num_Children = 2;

experiencias = rand(num_Children, N) <p;
success = sum(experiencias) >=1;
prob = sum(success)/N;
prob;

%% 
% b) valor teórico 
% P(>=1) = 1 - P(0)
p = 0.5;
k = 0;
n = 2;

prob = nchoosek(n,k)*p^k*(1-p)^(n-k);
probabilidade = 1-prob;

%% 
% c)
% B = probabilidade um deles é rapaz
% A = probabilidade de outro ser rapaz
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

Probabilidade = A_e_B / B;

%%
% d) sabendo que a primeira criança de 2 é um rapaz probabilidade da 
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
prob

%%
% e) probabilidade de um dos outros e apenas um também ser rapaz
%  sabendo que pelo menos uma criança é um rapaz

% A: 

num_of_children = 5;
