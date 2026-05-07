function [x X] = impulso(larg,inicio=0,N=256)
%IMPULSO Gera um impulso retangular e calcula a sua DFT.
%   [x, X] = IMPULSO(larg) cria um sinal discreto x com N=256 amostras,
%   contendo um impulso retangular de largura 'larg' iniciado em 'inicio=0',
%   e calcula a DFT X = fft(x).
%
%   [x, X] = IMPULSO(larg, inicio) permite definir a amostra inicial do
%   impulso (indice base 0 no argumento de entrada).
%
%   [x, X] = IMPULSO(larg, inicio, N) define o numero total de amostras do
%   sinal.
%
%   Entradas:
%   larg   - largura do impulso (numero de amostras a 1).
%   inicio - indice inicial do impulso (base 0). Valor por omissao: 0.
%   N      - numero total de amostras do sinal. Valor por omissao: 256.
%
%   Saidas:
%   x - sinal no dominio do tempo.
%   X - DFT de x.
%
%   Efeitos graficos:
%   A funcao apresenta tres figuras: sinal no tempo, magnitude da DFT e
%   magnitude/fase da DFT em subplots.
%
%   Exemplo:
%   [x, X] = impulso(8, 10, 128);

i = 0:N-1;  % Índice de amostras
x = zeros(1, N); % Inicializa o vetor de amostras com zeros

Largura = larg; % Largura do impulso

figure; % Cria uma nova figura para o impulso
% Define o impulso
x(inicio+1 : inicio + Largura ) = 1;
% Exibe o impulso
stem(i, x);
xlabel('Amostras');
ylabel('Amplitude');
legendaSinal = sprintf('Impulso. Largura = %d', Largura);
title(legendaSinal);
axis([0 N-1 -0.5 1.5]);
grid on;

figure; % Cria uma nova figura para a DFT
X = fft(x); % Calcula a DFT do impulso
magnitude = abs(X); % Calcula a magnitude da DFT
fase = angle(X); % Fase da DFT

subplot(2,1,1);
stem(0:N-1, magnitude);
xlabel('Índice de Frequência');
ylabel('Magnitude');
legendaTransf = sprintf('Módulo da DFT do impulso (Largura = %d)', Largura);
title(legendaTransf);
axis([0 N-1 0 max(magnitude)*1.1]);
grid on;

subplot(2,1,2);
stem(0:N-1, fase);
xlabel('Índice de Frequência');
ylabel('Fase (rad)');
legendaFase = sprintf('Fase da DFT do impulso (Largura = %d)', Largura);
title(legendaFase);
axis([0 N-1 -pi pi]);
grid on;

return