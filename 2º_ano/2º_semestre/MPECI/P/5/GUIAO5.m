clear all; 
clc;       
close all; 
%% 1.

% a)

lambda = 2;
invmiu = 90;
B = 2;
M = 200;
N = 1e3;

VideoStreamingSimulatorAso(lambda, invmiu, B, M, N);

% b) 
lambda = 2;
invmiu = 90;
B = 2;
M = 200;
N = 1e4;

VideoStreamingSimulatorAso(lambda, invmiu, B, M, N);

% c)

lambda = 3;
invmiu = 90;
B = 2;
M = 200;
N = 1e3;

VideoStreamingSimulatorAso(lambda, invmiu, B, M, N);

% d)

lambda = 3;
invmiu = 90;
B = 2;
M = 200;
N = 1e4;

VideoStreamingSimulatorAso(lambda, invmiu, B, M, N);

%% 2.
lambda = 2;
invmiu = 90;
B = 2;
M = 200;
N = 1e4;

Nsim = 100;
% number of simulations
PB= zeros(1,Nsim); % vector to save results
DB= zeros(1,Nsim); % vector to save results
for it= 1:Nsim
    [PB(it), DB(it)]= VideoStreamingSimulatorAso(lambda, invmiu, B, M, N);
end

alfa= 0.1; % 90% confidence interval
media = mean(PB);
[~, ~, ci] = ttest(PB, media,'alpha',alfa);
fprintf('PB = %.4f [%.4f - %.4f] \n',media*100,ci(1)*100,ci(2)*100);
media = mean(DB);
[~, ~, ci] = ttest(DB, media,'alpha',alfa);
fprintf('DB = %.2f Mbps [%.2f - %.2f]\n',media,ci(1),ci(2));


%% 3.

movies= readcell('moviesMPECI2025.csv','Delimiter',',');
movies= movies(2:end,:);
nMovies= length(movies);

durationTimes= zeros(1,nMovies);
ratings= zeros(1,nMovies);
for i = 1:nMovies
    durationTimes(i)= movies{i,3};
    ratings(i)= movies{i,4};
end


D= unique(durationTimes);
w= zeros(1,length(D));
for i= 1:length(D)
    f= durationTimes == D(i);
    w(i)= sum(ratings(f));
end
Prob= w/sum(w);

%% 3. (Continuação)
% a) Calcular a duração média D
D_avg = sum(D .* Prob'); % O vetor Prob tem de estar alinhado com D
fprintf('Exercise 3(a):\nD = %.2f minutes\n\n', D_avg);

% b) Plot the probability mass function
figure(1);
stem(D, Prob * 100, 'b', 'Marker', 'o', 'MarkerSize', 5);
xlabel('Movie duration (min)');
ylabel('Probability (%)');
xlim([60 130]);
ylim([0 3.5]);
grid on;
title('Exercise 3(b)');

%% 4. 
lambda = 2;
B = 2;
M = 200;
N = 1e5;
Nsim = 20;

% a) Usando o novo simulador (duração discreta)
PB_a = zeros(1, Nsim);
DB_a = zeros(1, Nsim);
for it = 1:Nsim
    % Assumindo que criou uma função VideoStreamingSimulator_Ex4
    [PB_a(it), DB_a(it)] = VideoStreamingSimulatorAso(lambda, D, Prob, B, M, N);
end

alfa = 0.1;
media_PB_a = mean(PB_a);
[~, ~, ci_PB_a] = ttest(PB_a, media_PB_a, 'alpha', alfa);
media_DB_a = mean(DB_a);
[~, ~, ci_DB_a] = ttest(DB_a, media_DB_a, 'alpha', alfa);

fprintf('Exercise 4(a):\n');
fprintf('PB = %.3f [%.3f - %.3f] %%\n', media_PB_a*100, ci_PB_a(1)*100, ci_PB_a(2)*100);
fprintf('DB = %.2f [%.2f - %.2f] Mbps\n\n', media_DB_a, ci_DB_a(1), ci_DB_a(2));

% b) Usando o simulador da Tarefa 2 com média D
function [PB, DB] = VideoStreamingSimulator_Ex4(lambda, D, Prob, B, M, N)
    % lambda: taxa de chegada (pedidos/minuto)
    % D: vetor com as durações dos filmes (minutos) - do Ex 3
    % Prob: vetor com as probabilidades de cada duração - do Ex 3
    % B: débito de cada filme (Mbps)
    % M: capacidade do servidor (número máximo de filmes)
    % N: critério de paragem (número de filmes terminados)

    % --- Inicialização ---
    NextArrival = -log(rand())/lambda;
    NextDeparture = inf(1, M);
    CurrentMovies = 0;
    BlockedRequests = 0;
    TotalMovies = 0;
    
    % Contadores para DB (Average Throughput)
    TotalThroughputTime = 0;
    LastEventTime = 0;
    Clock = 0;

    % --- Ciclo de Simulação ---
    while TotalMovies < N
        [NextEventTime, EventType] = min([NextArrival, NextDeparture]);
        
        % Atualiza estatísticas de Throughput antes de mudar o estado
        TotalThroughputTime = TotalThroughputTime + CurrentMovies * B * (NextEventTime - Clock);
        Clock = NextEventTime;

        if EventType == 1 % Caso: Chegada de um pedido
            if CurrentMovies < M
                CurrentMovies = CurrentMovies + 1;
                % --- PARTE ALTERADA: Escolha da duração discreta ---
                % Usa o método da transformada inversa para a distribuição discreta 
                idx = find(rand <= cumsum(Prob), 1);
                movieDuration = D(idx);
                % --------------------------------------------------
                
                % Encontra um slot livre no servidor
                freeSlot = find(NextDeparture == inf, 1);
                NextDeparture(freeSlot) = Clock + movieDuration;
            else
                BlockedRequests = BlockedRequests + 1;
            end
            NextArrival = Clock - log(rand())/lambda;
            
        else % Caso: Partida (filme terminou)
            CurrentMovies = CurrentMovies - 1;
            NextDeparture(EventType - 1) = inf;
            TotalMovies = TotalMovies + 1;
        end
    end

    % --- Resultados ---
    PB = BlockedRequests / (TotalMovies + BlockedRequests); % Probabilidade de bloqueio 
    DB = TotalThroughputTime / Clock; % Débito médio 
end
PB_b = zeros(1, Nsim);
DB_b = zeros(1, Nsim);
for it = 1:Nsim
    [PB_b(it), DB_b(it)] = VideoStreamingSimulator_Ex4(lambda, D_avg, B, M, N);
end

media_PB_b = mean(PB_b);
[~, ~, ci_PB_b] = ttest(PB_b, media_PB_b, 'alpha', alfa);
media_DB_b = mean(DB_b);
[~, ~, ci_DB_b] = ttest(DB_b, media_DB_b, 'alpha', alfa);

fprintf('Exercise 4(b):\n');
fprintf('PB = %.3f [%.3f - %.3f] %%\n', media_PB_b*100, ci_PB_b(1)*100, ci_PB_b(2)*100);
fprintf('DB = %.2f [%.2f - %.2f] Mbps\n\n', media_DB_b, ci_DB_b(1), ci_DB_b(2));

%% 5. Valores Teóricos (M/M/m/m)

rho = lambda * D_avg; % Tráfego em Erlangs

% Erlang B Formula de forma iterativa para evitar Inf em fatoriais elevados
invB = 1;
for i = 1:M
    invB = 1 + invB * (i / rho);
end
PB_th = 1 / invB;
DB_th = B * rho * (1 - PB_th);

fprintf('Exercise 5:\n');
fprintf('PB = %.3f %%\n', PB_th * 100);
fprintf('DB = %.2f Mbps\n\n', DB_th);

%% 6. Simulador Data Link
lambda_link = 1000;
B_size = 600;
C = 10;
F = 1000;
N_link = 1e4;
Nsim_link = 100;

AM_sim = zeros(1, Nsim_link);
for i = 1:Nsim_link
    AM_sim(i) = LinkSimulator(lambda_link, B_size, C, F, N_link);
end
alfa = 1-0.9;
mean_AM = mean(AM_sim) * 1000;
[~, ~, ci_AM] = ttest(AM_sim * 1000, mean_AM, 'alpha', alfa);

fprintf('Exercise 6:\n');
fprintf('AM = %.4f [%.4f - %.4f] msec\n\n', mean_AM, ci_AM(1), ci_AM(2));

%% 7. Pacotes com Distribuição Discreta

function AM = LinkSimulatorNew(lambda, sizes, probs_sizes, C, F, N)
    % Eventos
    ARRIVAL = 0;       
    DEPARTURE = 1;     
    
    % Inicialização
    Clock = 0;            
    STATE = 0;           
    QUEUE_N = 0;          
    DELAYS = 0;           
    TRANSMITTED = 0;      
    QUEUE = [];           
    
    % Pré-calcular a CDF para amostragem rápida da distribuição discreta
    cdf = cumsum(probs_sizes);
    
    % Primeiro evento
    tmp = Clock + exprnd(1/lambda);
    EventList = [ARRIVAL, tmp, tmp];
    
    while TRANSMITTED < N
        EventList = sortrows(EventList, 2);  
        Event = EventList(1,1);             
        Clock = EventList(1,2);             
        ArrInstant = EventList(1,3);        
        EventList(1,:) = [];                
        
        switch Event
            case ARRIVAL
                % Próxima chegada
                tmp = Clock + exprnd(1/lambda);
                EventList = [EventList; ARRIVAL, tmp, tmp];
                
                if STATE == 0
                    STATE = 1;
                    % AMOSTRAGEM DISCRETA: encontrar o tamanho do pacote
                    packetSize = sizes(find(cdf >= rand(), 1));
                    
                    tTime = (8 * packetSize) / (C * 1e6);
                    EventList = [EventList; DEPARTURE, Clock + tTime, ArrInstant];
                else
                    if QUEUE_N < F
                        QUEUE_N = QUEUE_N + 1;
                        QUEUE = [QUEUE; ArrInstant];
                    end
                end
                
            case DEPARTURE
                DELAYS = DELAYS + (Clock - ArrInstant);
                TRANSMITTED = TRANSMITTED + 1;
                
                if QUEUE_N > 0
                    QInstant = QUEUE(1);
                    % AMOSTRAGEM DISCRETA: novo pacote da fila
                    packetSize = sizes(find(cdf >= rand(), 1));
                    
                    tTime = (8 * packetSize) / (C * 1e6);
                    EventList = [EventList; DEPARTURE, Clock + tTime, QInstant];
                    QUEUE_N = QUEUE_N - 1;
                    QUEUE(1) = [];
                else
                    STATE = 0;
                end
        end
    end
    
    AM = (DELAYS / TRANSMITTED) ;
end


sizes = 64:1500;
probs_sizes = zeros(1, length(sizes));
probs_sizes(sizes == 64) = 0.29606;
probs_sizes(sizes == 110) = 0.16417;
probs_sizes(sizes == 1500) = 0.19601;

% Distribuir a probabilidade restante pelos restantes pacotes
rem_prob = 1 - (0.29606 + 0.16417 + 0.19601);
num_other = length(sizes) - 3;
probs_sizes(probs_sizes == 0) = rem_prob / num_other;

avg_packet_size = sum(sizes .* probs_sizes);
fprintf('Exercise 7:\n');
fprintf('Avg. Packet Size = %.4f Bytes\n', avg_packet_size);

AM_sim7 = zeros(1, Nsim_link);
for i = 1:Nsim_link
    % Assumindo que criou LinkSimulator_Ex7 que aceita tamanho discreto
    AM_sim7(i) = LinkSimulatorNew(lambda_link, sizes, probs_sizes, C, F, N_link);
end

mean_AM7 = mean(AM_sim7) * 1000;
[~, ~, ci_AM7] = ttest(AM_sim7 * 1000, mean_AM7, 'alpha', alfa);
fprintf('AM = %.4f [%.4f - %.4f] msec\n\n', mean_AM7, ci_AM7(1), ci_AM7(2));

%% 8. Variação do Arrival Rate
lambdas = [1000, 1250, 1500, 1750, 2000];
mean_AM8 = zeros(1, length(lambdas));
ci_AM8 = zeros(length(lambdas), 2);

fprintf('Exercise 8:\n');
for idx = 1:length(lambdas)
    temp_AM = zeros(1, Nsim_link);
    for i = 1:Nsim_link
        temp_AM(i) = LinkSimulatorNew(lambdas(idx), sizes, probs_sizes, C, F, N_link);
    end
    mean_AM8(idx) = mean(temp_AM) * 1000;
    [~, ~, ci] = ttest(temp_AM * 1000, mean_AM8(idx), 'alpha', alfa);
    ci_AM8(idx, :) = ci;
    fprintf('lambda = %d: AM = %.4f [%.4f - %.4f] msec\n', lambdas(idx), mean_AM8(idx), ci(1), ci(2));
end
fprintf('\n');

%% 9. Bar chart (Arrival Rates)
figure(2);
err_AM8 = ci_AM8(:,2)' - mean_AM8; % Calcular as margens de erro para o plot
bar(lambdas, mean_AM8, 'b');
hold on;
errorbar(lambdas, mean_AM8, err_AM8, 'k', 'LineStyle', 'none');
hold off;
xlabel('Packet arrival rate (pps)');
ylabel('Avg. packet delay (msec)');
title('Exercise 9');

%% 10. Estimativa de Packet Drop (PD)
lambda_10 = 1800;
F_10 = 100;

function [AM, PD] = LinkSimulator_Ex10(lambda, sizes, probs_sizes, C, F, N)
    ARRIVAL = 0; DEPARTURE = 1;
    Clock = 0; STATE = 0; QUEUE_N = 0;
    DELAYS = 0; TRANSMITTED = 0; QUEUE = [];
    
    % Novos contadores para PD
    TOTAL_ARRIVALS = 0;
    LOST_PACKETS = 0;
    
    cdf = cumsum(probs_sizes);
    tmp = Clock + exprnd(1/lambda);
    EventList = [ARRIVAL, tmp, tmp];
    
    while TRANSMITTED < N
        EventList = sortrows(EventList, 2);
        Event = EventList(1,1);
        Clock = EventList(1,2);
        ArrInstant = EventList(1,3);
        EventList(1,:) = [];
        
        switch Event
            case ARRIVAL
                TOTAL_ARRIVALS = TOTAL_ARRIVALS + 1;
                tmp = Clock + exprnd(1/lambda);
                EventList = [EventList; ARRIVAL, tmp, tmp];
                
                if STATE == 0
                    STATE = 1;
                    packetSize = sizes(find(cdf >= rand(), 1));
                    tTime = (8 * packetSize) / (C * 1e6);
                    EventList = [EventList; DEPARTURE, Clock + tTime, ArrInstant];
                else
                    if QUEUE_N < F
                        QUEUE_N = QUEUE_N + 1;
                        QUEUE = [QUEUE; ArrInstant];
                    else
                        % Fila cheia: pacote é descartado
                        LOST_PACKETS = LOST_PACKETS + 1;
                    end
                end
                
            case DEPARTURE
                DELAYS = DELAYS + (Clock - ArrInstant);
                TRANSMITTED = TRANSMITTED + 1;
                if QUEUE_N > 0
                    QInstant = QUEUE(1);
                    packetSize = sizes(find(cdf >= rand(), 1));
                    tTime = (8 * packetSize) / (C * 1e6);
                    EventList = [EventList; DEPARTURE, Clock + tTime, QInstant];
                    QUEUE_N = QUEUE_N - 1;
                    QUEUE(1) = [];
                else
                    STATE = 0;
                end
        end
    end
    AM = (DELAYS / TRANSMITTED); 
    PD = LOST_PACKETS / TOTAL_ARRIVALS;
end

AM_sim10 = zeros(1, Nsim_link);
PD_sim10 = zeros(1, Nsim_link);

for i = 1:Nsim_link
    % Assumindo que criou LinkSimulator_Ex10 para estimar também PD
    [AM_sim10(i), PD_sim10(i)] = LinkSimulator_Ex10(lambda_10, sizes, probs_sizes, C, F_10, N_link);
end

mean_AM10 = mean(AM_sim10) * 1000;
[~, ~, ci_AM10] = ttest(AM_sim10 * 1000, mean_AM10, 'alpha', alfa);
mean_PD10 = mean(PD_sim10);
[~, ~, ci_PD10] = ttest(PD_sim10, mean_PD10, 'alpha', alfa);

fprintf('Exercise 10:\n');
fprintf('AM = %.4f [%.4f - %.4f] msec\n', mean_AM10, ci_AM10(1), ci_AM10(2));
fprintf('PD = %.3f [%.3f - %.3f] %%\n\n', mean_PD10*100, ci_PD10(1)*100, ci_PD10(2)*100);

%% 11. Variação do Queue Capacity
F_array = [50, 20, 10, 5];
mean_AM11 = zeros(1, length(F_array));
ci_AM11 = zeros(length(F_array), 2);
mean_PD11 = zeros(1, length(F_array));
ci_PD11 = zeros(length(F_array), 2);

fprintf('Exercise 11:\n');
for idx = 1:length(F_array)
    t_AM = zeros(1, Nsim_link);
    t_PD = zeros(1, Nsim_link);
    for i = 1:Nsim_link
        [t_AM(i), t_PD(i)] = LinkSimulator_Ex10(lambda_10, sizes, probs_sizes, C, F_array(idx), N_link);
    end
    
    mean_AM11(idx) = mean(t_AM) * 1000;
    [~, ~, ci_a] = ttest(t_AM * 1000, mean_AM11(idx), 'alpha', alfa);
    ci_AM11(idx, :) = ci_a;
    
    mean_PD11(idx) = mean(t_PD);
    [~, ~, ci_p] = ttest(t_PD, mean_PD11(idx), 'alpha', alfa);
    ci_PD11(idx, :) = ci_p;
    
    fprintf('F = %d: AM = %.4f [%.4f - %.4f] msec\n', F_array(idx), mean_AM11(idx), ci_a(1), ci_a(2));
    fprintf('        PD = %.3f [%.3f - %.3f] %%\n', mean_PD11(idx)*100, ci_p(1)*100, ci_p(2)*100);
end
fprintf('\n');

%% 12. Bar charts (Queue Capacity)
figure(3);
subplot(1,2,1);
err_AM11 = ci_AM11(:,2)' - mean_AM11;
b1 = bar(1:4, mean_AM11);
set(gca, 'xticklabel', F_array);
hold on;
errorbar(1:4, mean_AM11, err_AM11, 'k', 'LineStyle', 'none');
hold off;
xlabel('Queue size (in no. of packets)');
ylabel('Avg. packet delay (msec)');
title('Exercise 12 - AM');

subplot(1,2,2);
err_PD11 = (ci_PD11(:,2)' - mean_PD11) * 100;
b2 = bar(1:4, mean_PD11 * 100);
set(gca, 'xticklabel', F_array);
hold on;
errorbar(1:4, mean_PD11 * 100, err_PD11, 'k', 'LineStyle', 'none');
hold off;
xlabel('Queue size (in no. of packets)');
ylabel('Packet drop probability (%)');
title('Exercise 12 - PD');

%% 13. Valores Teóricos (M/M/1/m)
miu_link = (C * 1e6) / (avg_packet_size * 8);
rho_link = lambda_10 / miu_link;

fprintf('Exercise 13:\n');
for idx = 1:length(F_array)
    m = F_array(idx) + 1; % A capacidade total m é Queue Size + 1 (em serviço)
    
    % Calculo de PD (Probabilidade de Bloqueio - Pm)
    PD_th = ((1 - rho_link) / (1 - rho_link^(m + 1))) * rho_link^m;
    
    % Calculo de L (Numero medio de clientes no sistema)
    L = rho_link * (1 - (m + 1) * rho_link^m + m * rho_link^(m + 1)) / ((1 - rho_link) * (1 - rho_link^(m + 1)));
    
    % Calculo de AM usando a Lei de Little (lambda efetivo)
    lambda_eff = lambda_10 * (1 - PD_th);
    AM_th = L / lambda_eff * 1000; % msec
    
    fprintf('F = %d: AM = %.4f msec\n', F_array(idx), AM_th);
    fprintf('        PD = %.3f %%\n', PD_th * 100);
end
