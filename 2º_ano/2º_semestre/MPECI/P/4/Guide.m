%% 1. 


%% 1.
% Consider a wireless link between multiple stations for data communications. Consider the
% bit error rate (ber) introduced by the wireless link (due to the variation of the propagation
% and interference factors along with time) given by the following Markov chain:
%
%   600          100           20            5
% ------> 10^-6 ------> 10^-5 ------> 10^-4 ------> 10^-3 ------> 10^-2
% <------       <------       <------       <------       <------
%    8             5             2             1
%
% where the state transition rates are in number of transitions per hour. Assume that all
% stations detect with a probability of 100% when the data frames sent by the other stations
% are received with errors.
%
% (a) Determine the probability of the link being on each state.
% (b) Determine the average time percentage the link is on each state.
% (c) Determine the average holding time (in minutes) of the link on each state.
% (d) Determine the probability (in %) of a data frame of 100 Bytes to be received with
%     errors (i.e., with at least one bit in error).
% (e) Determine the probability (in %) of a data frame of 1500 Bytes to be received without
%     errors.
% (f) When a data frame of 1500 Bytes is received with errors, what is the probability of the
%     link being in state 10^-6? And in state 10^-2? Compare these probabilities with the
%     probabilities in 1(a) and draw conclusions.
%

% a)

   % 1e-6 1e-5 1e-4 1e-3 1e-2

T = [  0   8    0    0     0;
       600 0    5    0     0;
       0   100  0    2     0;
       0   0    20   0     1;
       0   0    0    5     0; 
    ]';

n = length(T);
Q = T;

for i = 1:n
    Q(i,i) = -sum(T(:,i));
end



M = [Q; ones(1,n)];
x = [zeros(n,1); 1];
u = M\x;
fprintf("b)\n\n")
for i = 1:length(u)
    fprintf("Prob do estado %d: %.2e\n",i, u(i));
end


% b)
media = u*100 ;
disp(media);


% c)
m = 1 ./ sum(T) * 60;
fprintf("c)\n")
for i = 1:length(u)
    fprintf("Minutos %d: %.2f min\n",i, m(i));
end


% d)

bytesSent = 100 * 8;

% P(E) = P(E| 1e-6) * P(1e-6) + P(E| 1e-5) * P(1e-5) 
%        +  ... 
M = zeros(1,n);
p = [1e-6 1e-5  1e-4 1e-3 1e-2];
k = 0;

for i = 1:n
    M(1,i) = nchoosek(bytesSent, k) * p(1,i)^(k)* (1-p(1,i))^(bytesSent-k);
    
end
M = 1-M;

P_E = 0;
for i = 1:n
    P_E = P_E + M(1,i)* u(i);
end
fprintf("d)\n%.4f%%\n",P_E*100)


% e)
bytesSent = 1500 * 8;
M = zeros(1,n);
p = [1e-6 1e-5 1e-4 1e-3 1e-2];
k = 0;

for i = 1:n
    M(1,i) = nchoosek(bytesSent, k) * p(1,i)^(k)* (1-p(1,i))^(bytesSent-k);    
end



P_E = 0;

for i = 1:n
    P_E = P_E + M(1,i)* u(i);
end

fprintf("e)\n%.2f%%\n",P_E*100)

% f)


P_E = 1- P_E;
P_Erro_dado_X = 1-(1-p).^bytesSent;

P_Erro_Total = sum(P_Erro_dado_X .*u');

fprintf("f)\n")
P = (P_Erro_dado_X(1) * u(1) )/P_Erro_Total;
fprintf("1e-6: %.2e\n", P);

P = (P_Erro_dado_X(5) * u(5) )/P_Erro_Total;

fprintf("1e-2: %.2e\n", P);

%% 2. 
%% 2.
% Consider a company providing all services on a single server. The server can break down
% due to 2 causes: hardware failure or software failure. The amount of time the server runs
% until a hardware/software failure is exponentially distributed with an average of 500 days
% and 90 days, respectively. The hardware/software repair time is exponentially distributed
% with an average of 1 day and 4 hours, respectively. A hardware failure requires first the
% hardware repair and then the software repair, while a software failure requires only the
% software repair.
%
% (a) Draw the state transition diagram of the Markov chain modeling this system with state
%     transition rates in number of transitions per day.
% (b) Define, in Matlab, the corresponding state transition matrix.
% (c) Compute the limiting probabilities (in %) of each state.
% (d) What is the probability (in %) of the server being available?
% (e) What is the average time (in hours) that the server is down in one month of 30 days?

% b)
lambda_s = 1/90;
lambda_h = 1/500;

T = [ 0  lambda_h lambda_s
      0     0       1;
      6     0       0;]';

fprintf("b)\n")
disp(T);
% c)
n = length(T);
Q =  T;
for i= 1:n
    Q(i,i) = -sum(Q(:,i));
end

M = [Q; ones(1,n)];
x = [zeros(n,1); 1];
u = M\x;

fprintf("Probabilidades Limite:\n")
fprintf("UP: %.4f%%\n", u(1)*100)
fprintf("HW Repair: %.4f%%\n", u(2)*100)
fprintf("SW Repair: %.4f%%\n", u(3)*100)

% d)
fprintf("d)\n")
u(1)

% e)

prob_down = u(2) + u(3);

horas = 30 * 24;

tempo_dowm = prob_down * horas;
fprintf("e) Tempo médio down por mês: %.2f horas\n", tempo_dowm)


%% 3.
%
%% 3.
% Consider a Data Center with 100 servers and t maintenance technicians. The amount of
% time each server runs until it fails is exponentially distributed with an average of 200 days.
% The server repair time of each technician is exponentially distributed with an average of 36
% hours. Consider a birth-dead process with states n = 0, 1, ..., 100 representing the number
% of failing servers.
%
% (a) Consider t = 1 technician. Compute first the state limiting probabilities and then:
%     i) determine the average number of servers down,
%     ii) determine the average number of technicians in repairing activities,
%     iii) determine the probability (in %) of at least 90 servers being in operation.
% (b) Repeat 3(a) considering t = 2 technicians.
% (c) Repeat 3(a) considering t = 3 technicians. Compare all results and draw conclusions.

% i) 
fprintf("Exercicio 3\n3.\n  i) ")
lambda_F = 1/200;
lambda_R = 24/36;
lambda = 0:99;
lambda = (100-lambda)* lambda_F;
miu = ones(1, 100)*lambda_R;
miu(1,1) = lambda_R;

co = [1 , lambda./miu];
co = cumprod(co);

u = co/ sum(co);
states = 0:100;
media = sum(u.*states);
disp(media*100)

% ii)
fprintf("  ii)")

p = 1 - u(1);
disp(p*100);

% iii) 

l = sum(u(1,1:11));

fprintf("  iii)")
disp(l*100);



% b

% i) 
fprintf("b)\n  i) ")
lambda_F = 1/200;
lambda_R = 24/36;
lambda = 0:99;
lambda = (100-lambda)* lambda_F;
miu = ones(1, 100)*lambda_R*2;
miu(1,1) = lambda_R;

co = [1 , lambda./miu];
co = cumprod(co);

u = co/ sum(co);
states = 0:100;
media = sum(u.*states);
disp(media*100)

% ii)
fprintf("  ii)")

p =  u(2) + 2*sum(u(3:100));
disp(p*100);

% iii) 

l = sum(u(1,1:11)) * 100;

fprintf("  iii)")
disp(l);


% c

% i) 
fprintf("c)\n  i) ")
lambda_F = 1/200;
lambda_R = 24/36;
lambda = 0:99;
lambda = (100-lambda)* lambda_F;
miu = ones(1, 100)*lambda_R*3;
miu(1,1) = lambda_R;
miu(1,2) = 2*lambda_R;

co = [1 , lambda./miu];
co = cumprod(co);

u = co/ sum(co);
states = 0:100;
media = sum(u.*states);
disp(media*100)

% ii)
fprintf("  ii)")

p =  u(2) + 2*u(3) + 3*sum(u(4:100));
disp(p*100);

% iii) 

l = sum(u(1,1:11)) * 100;

fprintf("  iii)")
disp(l);


%% 4.
%
%% 4.
% Consider a M/M/1 queuing system such that the arriving rate of clients is lambda = 8 clients per
% minute and the average serving time of each client is 1/mu = 0.1 minutes.
%
% (a) What is the average time each client stays in the system?
% (b) What is the average server occupation (in %)?
% (c) What is the average queue occupation, i.e., the average number of clients in the queue?
% (d) What is the probability (in %) of the queue occupation becoming larger than 6 clients?
%     And larger than 20 clients? And larger than 40 clients?
% (e) Using Matlab plot function, plot a graph of the average time each client stays in the
%     system as a function of the client arriving rate lambda (from lambda = 1 to lambda = 9).
%

fprintf("4.\na)")
% a)
niu = 10;
lambda = 8;
% Teorema de Little
W = 1 / (niu - lambda);
p = lambda / niu;

disp(W);
fprintf("b)")
disp(p)


% c) 

Wq =  W - 1 / niu;

Lq = lambda * Wq;

fprintf("c)")
disp(Lq)

% d) 
fprintf("d)\n")
P6 = p^(8) * 100;
P20 = p^22 * 100;
P40 = p^42 * 100;

fprintf("P(X>6) =")
disp(P6);

fprintf("P(X>20) =")
disp(P20);

fprintf("P(X>40) =")
disp(P40);



% e)

fprintf("e)\n")
lambda = 1 : 0.1 : 9;
W = 1 ./ (niu - lambda);


figure;
plot(lambda, W, 'LineWidth', 2, 'Color', 'b');
grid on;
xlabel('lambda');
ylabel('(W) ');
title('lambda = [1, 9]');

%% 5. 
%% 5.
% Consider a M/M/1/m queuing system such that the arriving rate of clients is lambda = 80 clients
% per second, the average serving time of each client is 1/mu = 0.01 seconds and the system
% capacity is m = 10 clients. Clients are discarded when they arrive and the system is full.
%
% (a) What is the probability of each client being discarded?
% (b) What is the average time (in milliseconds) each client stays in the system when it is
%     not discarded?
% (c) What is the average queue occupation?
% (d) Using Matlab bar function, plot a bar chart of the client discard probability as a
%     function of the system capacity m (for m = 5, 10, 15, ..., 40). What do you conclude
%     from this chart?
lambda = 80;
mu = 1/0.01;
m = 10;
rho = lambda/mu;
divisor = sum(rho.^(0:m));
% a)

P = (lambda / mu).^(0:m) / divisor;

pi_m = P(end);

fprintf("a)\nProbabilidade de cada cliente ser discarded: pi_m = %.4f\n", pi_m)



% b)

L = sum((0:m) .* P);
lambda_ef = lambda *  (1- pi_m);
W = L / lambda_ef;

fprintf("b)\nTempo médio é: %.5f que cada cliente fica no sistema *QUANDO NÃO É DISCARTADO*\n", W*1000)


% c) 
W_Q = W -  1/mu;
L_Q = lambda_ef * W_Q;

fprintf("c)\nA ocupação média da fila é: %0.2f\n",L_Q)

% d)
M = 5:5:40
P = zeros(1,length(M))

function P = prob(m)
    lambda = 80;
    mu = 1/0.01;
    rho = lambda/mu;
    divisor = sum(rho.^(0:m));
    P = (lambda / mu).^(0:m) / divisor;
    P = P(end);
end

for i = 1:length(M)
    P(i) = prob(M(i))
end
figure
bar(M, P)
grid on;
xlabel('Capacidade do Sistema (m)');
ylabel('Probabilidade de Descarte (P_m)');
title('Probabilidade de Descarte vs. Capacidade do Sistema');