%% 1.
% a)
C = 1e8;            % em bps
throughput = 80e6;  % em bps
B = 800;            % Bytes
L = 8 * B;          % → bits por pacote
Q = 8;              % Queue tamanho
K = Q +1;

lambda = throughput / L;    % recebidos
mu = C / L;                 % trafic
rho = lambda / mu;

j = 0:K;
j = (lambda/mu) .^j;
divisor = sum(j);


taxa = (lambda/mu)^K / divisor;

loss_rate_percent = taxa* 100;


i = 0:K;
numerador = (i .* (lambda/mu).^i);
numerador = sum(numerador);
L = numerador / divisor;

W = L /(lambda*(1-taxa));


fprintf("Exercício 1\n")
fprintf('  a)\n');
fprintf('Atraso médio: %.3f ms\n', W*1000);
fprintf('Taxa de perda: %.3f%%\n', loss_rate_percent );

% b)
fprintf('  b)\n')
target_loss = 0.001; % 0.1%
Q_test = 1;
current_loss = 1;


while current_loss > target_loss
    K_test = Q_test + 1;
    current_loss = (rho^K_test * (1 - rho)) / (1 - rho^(K_test + 1));
    if current_loss > target_loss
        Q_test = Q_test + 1;
    end
end


fprintf('Mínimo Q: %d pacotes\n', Q_test);
fprintf('Taxa de perda real: %.5f%%\n', current_loss * 100);




%% 2.

% a)

fprintf("2.\na)\n");

requests_simutlaneos = 250;
average = 200e-6;

B = 250;
lambda = 1.23e6;
mu = B/average;

ro = lambda  / mu;

Pb = ((1-ro) / (1-ro^(B+1))) * (ro^B);

n = 0:B;

Pn = ((1-ro) / (1-ro^(B+1))) .* (ro.^n);
L = sum(n.*Pn);
lambda_eff = lambda * (1-Pb);

T = L / lambda_eff; 

fprintf("Service blocking probability = %f%%\n", Pb* 100)
fprintf("Avg. service time per request = %.3f microseconds\n", T*1e6)

B = [200, 250, 300, 350];


