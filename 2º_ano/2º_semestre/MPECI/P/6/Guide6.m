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







%% 4.


lambda_h = 1/(365 * 2);     % estado 1 para 2
lambda_Hypervisor = 1/180;  % 1 para 3
lambda_VM = 1/90;           % 1 para 4

miu_h = 1/2;                % 2 para 3
miu_Hypervisor_VM = 1/(6/24);% 3 para 1
miu_VM = 1/(1/24);            % 4 para 1 
% Estados 1 2 3 4

Estado1_para = [0;lambda_h;lambda_Hypervisor;lambda_VM];
Estado2_para = [0; 0; miu_h; 0];
Estado3_para = [miu_Hypervisor_VM;0;0;0];
Estado4_para = [miu_VM; 0; 0; 0 ];

T =       [ Estado1_para, Estado2_para, Estado3_para, Estado4_para ];

Q = T;
for i = 1:4
    Q(i,i) = -sum(Q(:,i));
end

A = [Q; ones(1,4)];
x = [0;0;0;0; 1];
m = A\x;

P = m(1);
fprintf("Exercício 4\n")


fprintf("a)")
disp(T);

fprintf("b)\nServer availability = %.3f%%\n", P*100);


taxa_falha_total = lambda_VM + lambda_Hypervisor + lambda_h;

MTBF_dias = 1/ taxa_falha_total;
MTTR_dias = (MTBF_dias *(1-P))/P;

MTTF_horas = MTTR_dias * 24;

fprintf("c)\nMTBF = %.2f%%\n", MTBF_dias);
fprintf("MTTR = %.2f%%\n", MTTF_horas);

%% 5

fprintf("5\na)\n");

a_VM = .999;
b = 1;
n = 1;
target  = 0.9999;
calculated = 0;

while true
    n = n+1;
    target0 = 0;
    for i = 0: n-1
        target0 = target0 + binopdf(i,n+b,a_VM)*(i/n);
        
        
    end
    target1 = 0;
    for i = n:n+b
        target1 = target1 + binopdf(i,n+b,a_VM);
    end
    total = target1 + target0;
    if total < target
        n = n -1;
        break;
    end     
     
    
end

fprintf("Maxium value of n = %d\n", n);
fprintf("Resulting VM availability = %.4f %%\n", total * 100)

disponibilidade = zeros(1,1000);
for n = 0:1000
    
    target0 = 0;
    for i = 0: n-1
        target0 = target0 + binopdf(i,n+b,a_VM)*(i/n);
        
        
    end
    target1 = 0;
    for i = n:n+b
        target1 = target1 + binopdf(i,n+b,a_VM);
    end
    total = target1 + target0;
    
    disponibilidade(n+1) = total;
     
    
end
n = 0:1000;
disponibilidade = disponibilidade*100;

plot(n, disponibilidade)
grid on
xlabel("n")
ylabel("VM availability (%)")