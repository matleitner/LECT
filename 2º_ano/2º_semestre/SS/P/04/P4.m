y = [1 4 7 6 2 ];
x = [1 2];

% Identificacao por desconvolucao
% h dá um vetor de 4 elementos porque n_Y = n_x + n_h - 1 <=> n_h = 5 - 2 + 1 = 4 resta o h[4]

[h, resto] = deconv(y, x);
disp('h[n] = '); disp(h)
disp('Resto (deve ser ~0): '); disp(resto)

% Verificacao
y_check = conv(x, h);
disp("y_check"); disp(y_check);
disp('Correcto? '); disp(isequal(y, y_check))

% Grafico
figure(4);
subplot(3,1,1); stem(0:length(x)-1, x, 'filled'); title('x[n]'); grid on;
subplot(3,1,2); stem(0:length(h)-1, h, 'filled'); title('h[n]'); grid on;
subplot(3,1,3);
  stem(0:length(y)-1, y, 'b'); hold on;
  stem(0:length(y_check)-1, y_check, 'r--');
  legend('y original','y verificado'); title('y[n]'); grid on;
