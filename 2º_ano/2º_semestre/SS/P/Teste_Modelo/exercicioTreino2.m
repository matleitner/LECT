% 2.

%Um sistema LTI tem a resposta impulsional $h[n] = \{1, 0.5, 0.25\}$ para $n=0, 1, 2$.
%A entrada é $x[n] = u[n] - u[n-5]$.

%Cálculo: Determine manualmente o comprimento da saída $y[n] = x[n] * h[n]$ e os seus índices extremos.

% Implementação: Crie um script prob2.m que calcule a convolução usando a função conv().


%Gráficos: Visualize $x[n]$, $h[n]$ e $y[n]$ em sub-gráficos alinhados verticalmente.
% Propriedade: Verifique computacionalmente se a ordem dos fatores altera o resultado
%(conv(x, h) vs conv(h, x)) e identifique a propriedade demonstrada.

h = [1 0.5 0.25];
x = [1 0 0 0 0 -1];
N = length(h) + length(x) - 1

n_min_h = 2;
n_min_x = 5;
n_max_h = 0
n_max_x = 1
minimo = n_min_h + n_min_x;
maximo = n_max_h + n_max_x;
fprintf("O cálculo do comprimento da sáida da convolução é: %d, e o min é %d e o máx é: %d\n", N, minimo, maximo)

%% Implementação
n_h = 0:2;
n_x = 0:5;
y = conv(x, h)
subplot(3,1,1);
stem(n_h,h)
title("h[n]");
subplot(3,1,2);
stem(n_x, x);
title("x[n]");

subplot(3,1,3);
stem(0:N-1, y);
title("Convolução y[n] = x[n] * h[n]\n");

y_comparar = conv(h, x);

fprintf("São iguais?");
fprintf("%d\n",y_comparar==y);

