N = 50;
h = (0.5).^(0:N-1);             % h[n] truncado
x = ones(1, N);                  % u[n]

y_conv = conv(x, h);

n_ref = 0:2*N-2;
y_ref = 2*(1 - (0.5).^(n_ref+1)); % expressao fechada

figure(3);
subplot(3,1,1); stem(0:N-1, h, 'filled'); title('h[n] (trunc.)'); grid on;
subplot(3,1,2); stem(0:N-1, x, 'filled'); title('x[n]=u[n]');    grid on;
subplot(3,1,3);
  stem(n_ref, y_conv, 'b'); hold on;
  plot(n_ref, y_ref, 'r--', 'LineWidth',1.5);
  legend('conv truncado','expressao fechada');
  title('y[n]'); grid on; xlabel('n');

fprintf('Ganho DC aprox. = %.4f\n', sum(h));
