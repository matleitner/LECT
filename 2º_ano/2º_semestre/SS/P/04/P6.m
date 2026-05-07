n   = 0:9;
x   = [0 1 2 8 4 5 6 -3 8 9];
ref = 0:9;                        % sinal correcto

% -- MA de 3 amostras ---------------------------------------------------------
hMA3 = (1/3)*[1 1 1];
y3_full = conv(x, hMA3);
y_MA3 = y3_full(2:11);            % alinhar: atraso = (3-1)/2 = 1

% -- MA de 5 amostras ---------------------------------------------------------
hMA5 = (1/5)*ones(1,5);
y5_full = conv(x, hMA5);
y_MA5 = y5_full(3:12);         % COMPLETE: atraso = (5-1)/2 = ? 2

% -- Mediana de ordem 3 -------------------------------------------------------
y_med = medfilt1(x, 3);

% -- Erro quadratico medio -----------------------------------------------------
fprintf('MSE MA-3:    %.4f\n', mean((y_MA3 - ref).^2));
fprintf('MSE MA-5:    %.4f\n', mean((y_MA5 - ref).^2));
fprintf('MSE mediana: %.4f\n', mean((y_med  - ref).^2));

% -- Grafico -------------------------------------------------------------------
figure(6);
plot(n, ref,   'k--', 'LineWidth',1.5,'DisplayName','Referencia'); hold on;
stem(n, x,     'b',                   'DisplayName','x[n] ruidoso');
plot(n, y_MA3, 'r-o', 'LineWidth',1.2,'DisplayName','MA-3');
plot(n, y_MA5, 'm-s', 'LineWidth',1.2,'DisplayName','MA-5');
plot(n, y_med, 'g-^', 'LineWidth',1.2,'DisplayName','Mediana-3');
legend; grid on; xlabel('n');
title('Comparacao de filtros');
