% a)
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

