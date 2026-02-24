% Exercicio 1

a = [1 2 3 4 5];
b = [1;2;3;4;5;];

% Exercicio 2
r1 = [1:10];           % inicio inclusive : fim inclusive
r2 = [1:0.1:10];       % inicio inc. : step : fim inc.


r3 = linspace(0, 2*pi, 100); % inicio, fim, numero de amostras

% Exercicio 3

% c = a*a % erro porque não dá para multiplicar uma matriz 1x5 por 1x5

% Exercicio 4

a.*a;  % multiplicar elemento a elemento .*

a.^3;  % elemento a elemento elevar a 3

%Exercicio 5

produtoInternoAeB = a * b;

% Exercicio 6

%whos;

% Exercicio 7

M = randi([0,100], 3, 4); % matriz aleatoria 3 x 4

M(1:2, :);      % fazer display das duas primeiras linhas
M( : , 1:3);    % display das 3 primeiras colunas

% Exercicio 8
M;
%  dá erro M*M
M';    %M' transposta de M

M * M';

% Exercicio 9

eye(3);    % Matriz identidade 3x3
eye(4,2);  % Matriz identidade 4x2


zeros(4);   % O mesmo mas matriz nula 4x4
zeros(4,2); % 4x2

ones(4)     % 4x4 tudo a 1
ones(4,2)   % 4x2 tudo a 1

% Exercicio 10
N = M(:, 2:4);   % N = desde a 2ª coluna até à 4ª

M(2, :) = [];    % remove a 2ª linhas
M(:, 1) = [];    % remove a 1ª coluna


