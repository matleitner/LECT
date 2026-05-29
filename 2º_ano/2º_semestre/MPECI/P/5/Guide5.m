clear all; 
clc;       
close all; 
clear; close all; clc;

%1
% Consider the provided Matlab function VideoStreamingSimulator() that implements a
% discrete event simulator of a video-streaming server. The simulator assumes that the arrival of
% movie requests is a Poisson process and the duration of the movies is exponentially distributed.
% Save the file to your Matlab current folder. A description of the input parameters is obtained
% running in the Matlab Command Window:
%
% 1.
% Based on the provided simulator, develop a new function to visualize the evolution of the
% number of simultaneous movies transmitted by the server during the simulation run. Then,
% consider an average movie duration of 90 minutes, B = 2 Mbps and M = 200, and run the
% simulator for the cases:
% (a) arrival rate of 2 requests/minute and N = 10^3,
% (b) arrival rate of 2 requests/minute and N = 10^4,
% (c) arrival rate of 3 requests/minute and N = 10^3,
% (d) arrival rate of 3 requests/minute and N = 10^4.
%% 1.
function [Tempo, FilmesTransmissao] = VideoStreamingSimulatorAso(lambda, invmiu, B, M, N)
    % Events:
    ARRIVAL= 0; 	    % request of a movie
    DEPARTURE= 1; 	    % end of a movie transmission
    % Initialization of variables and List of Events:
    Clock= 0; 		    % simulation clock
    STATE= 0; 		    % no. of movies in transmission
    TRANSMITTED= 0; 	% no. of transmitted movies
    EventList= [ARRIVAL, Clock + exprnd(1/lambda)];

    %!!!!!!! 
    Tempo = [];
    FilmesTransmissao = [];
    %!!!!!!!
    
    while TRANSMITTED < N
        EventList= sortrows(EventList,2); % sort EventList by time
        event= EventList(1,1);		      % register event type in first row
        Clock= EventList(1,2);		      % update current clock with time instant of first row
        EventList(1,:)= []; 		      % delete first row of EventList
        switch event
            case ARRIVAL
                EventList= [EventList; ARRIVAL, Clock + exprnd(1/lambda)];       % add future ARRIVAL
                if STATE < M
                    STATE= STATE + 1;
                    EventList= [EventList; DEPARTURE, Clock + exprnd(invmiu)];   % add future DEPARTURE
                end
            case DEPARTURE
                STATE= STATE - 1;
                TRANSMITTED= TRANSMITTED + 1;
        end
        %!!!!!!!
        Tempo = [Tempo; Clock];
        FilmesTransmissao = [FilmesTransmissao; STATE];
        %!!!!!!!
    end
    
end

% a)
figure;

lambda = 2;
invmiu = 90;
B = 2;
M = 200;
N = 1e3;
[x, y] = VideoStreamingSimulatorAso(lambda,invmiu, B,M,N);
subplot(2,2,1);
plot(x,y);
title("a)")
xlabel("Time(minutes)")
ylabel("No. of simultaneous movies")
xlim([0,600])


% b)
lambda = 2;
N = 1e4;
[x, y] = VideoStreamingSimulatorAso(lambda,invmiu, B,M,N);
subplot(2,2,2);
plot(x,y);
title("b)")
xlabel("Time(minutes)")
ylabel("No. of simultaneous movies")
xlim([0,500])




% c)

lambda = 3;
N = 1e3;
[x, y] = VideoStreamingSimulatorAso(lambda,invmiu, B,M,N);
subplot(2,2,3);
plot(x,y);
title("c)")
xlabel("Time(minutes)")
ylabel("No. of simultaneous movies")
xlim([0,500])


% d)

lambda = 3;
N = 1e4;
[x, y] = VideoStreamingSimulatorAso(lambda,invmiu, B,M,N);
subplot(2,2,4);
plot(x,y);
title("d)")
xlabel("Time(minutes)")
ylabel("No. of simultaneous movies")
xlim([0,4500])

%% 2.
% 2.
% Based on the provided simulator VideoStreamingSimulator(), develop another
% simulator adding the estimation of the following two performance parameters (see slides
% 10-12 of module TP10):
% PB - probability of a movie request being blocked (i.e., being refused) because the server
%      is transmitting at its capacity (in maximum number of simultaneous movies)
% DB - average throughput (in Mbps) of the movies being transmitted by the server
%
% Then, consider the case of an arrival rate of 2 requests/minute, an average movie duration
% of 90 minutes, B = 2 Mbps, M = 200 and N = 10^4. Develop a Matlab script to compute the
% estimated values and the associated 90% confidence intervals (see slides 40-41 of module
% TP10) of the performance parameters PB and DB:
% (a) based on 10 runs of this simulator,
% (b) based on 100 runs of this simulator.
% Justify the width difference of the obtained confidence intervals between the two cases.
% The results should not be too different of:
% Exercise 2(a):
%   PB = 1.147 [0.935 - 1.360] %
%   DB = 348.94 [346.68 - 351.20] Mbps
% Exercise 2(b):
%   PB = 0.948 [0.885 - 1.011] %
%   DB = 350.53 [349.89 - 351.17] Mbps
function [PB,DB] =  VideoStreamingSimulator2(lambda, invmiu, B, M, N)

% Events 
ARRIVAL = 0;        % request of a movie
DEPARTURE = 1;      % end of a movie transmission
%Inicialization of variables and List of Events:
Clock = 0;          % simulation time 
STATE = 0;          % no. of movies in transmission 
TRANSMITTED = 0;    % no. of transmitted movies
N_ARRIVALS = 0;     % no. of movie requests
BLOCKED = 0;        % no. of refused movies
LOAD = 0;           % integral of the bitrate in transmission

EventList = [ARRIVAL, Clock + exprnd(1/lambda)];

while TRANSMITTED < N
    EventList = sortrows(EventList, 2);             % sort EventList by time
    event = EventList(1,1);                         % register event type in first row
    PreviousClock = Clock;                          % save previous clock
    Clock = EventList(1,2);                         % delete first row of EventList
    EventList(1,:) = [];
    LOAD = LOAD + B*STATE*(Clock- PreviousClock);
    switch event
        case ARRIVAL 
            EventList = [EventList; ARRIVAL, Clock + exprnd(1/lambda)]; % add future event
            N_ARRIVALS = N_ARRIVALS + 1;
            if STATE < M
                STATE = STATE + 1;
                EventList = [EventList; DEPARTURE, Clock + exprnd(invmiu)]; % add future event
            else 
                BLOCKED = BLOCKED + 1;
            end



        case DEPARTURE
            STATE = STATE - 1;
            TRANSMITTED = TRANSMITTED + 1;
    end 
end

PB = BLOCKED / N_ARRIVALS;
DB = LOAD / Clock;
end
% a)
lambda = 2;
invmiu = 90;
B = 2;
M = 200;
N = 1e4;
Nsim = 10;
PB = zeros(1,Nsim);
DB = zeros(1,Nsim);


for it = 1:Nsim
    [PB(it),DB(it)] = VideoStreamingSimulator2(lambda,invmiu, B,M,N);
end
fprintf("Esercise 2(a)\n")

alpha = 0.1;
media_PB = mean(PB);
[~,~,ci] = ttest(PB, media_PB, 'alpha',alpha);
fprintf("PB = %.4f [%.4f - %.4f] %%\n", media_PB*100, ci(1)*100, ci(2)*100);

fprintf("Esercise 2(b)\n")

media_DB = mean(DB);
[~,~,ci] = ttest(DB, media_DB, 'alpha',alpha);
fprintf("PB = %.2f [%.2f - %.2f] Mbps\n", media_DB, ci(1), ci(2));


%% 3.
% The previous simulations have considered an exponentially distributed movie duration.
% Now, the aim is to consider the movie duration statistics based on some input data.
% Compute the parameters of a discrete variable representing the movie duration statistics
% based on the provided CSV file moviesMPECI2025.csv and using the method proposed
% in TP classes (slides 12-15 of module TP10). Then,
% (a) compute the resulting average movie duration D,
% (b) plot the probability mass function of the discrete variable.
% Exercise 3(a):
%   D = 100.39 minutes
% Plot of exercise 3(b)
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

% a) Calcular a duração média D
D_avg = sum(D(:) .* Prob(:)); % O vetor Prob tem de estar alinhado com D
fprintf('Exercise 3(a):\nD = %.2f minutes\n\n', D_avg);
percentagem = Prob * 100;

% b) Plot the probability mass function
figure;
stem(D, percentagem, 'b', 'Marker', 'o', 'MarkerSize', 5);
xlabel('Movie duration (min)');
ylabel('Probability (%)');
xlim([60 130]);
ylim([0 3.5]);
grid on;
title('Exercise 3(b)');

% 4. 
% Based on the simulator developed in 2. (that already includes the estimation of PB and
% DB), develop a new simulator changing the statistics of the movie duration to the ones of
% the discrete variable whose parameters were determined in 3.
% Then, consider the case of an arrival rate of 2 requests/minute, B = 2 Mbps, M = 200 and
% N = 10^5. Develop a Matlab script to compute the estimated values and the associated 90%
% confidence intervals of the performance parameters PB and DB based on 20 runs using:
% (a) this simulator,
% (b) the simulator developed in 2. with an average movie duration D (computed in 3.).
% Compare the results of the two cases and draw conclusions. The results should look like:
% Exercise 4(a):
%   PB = 5.668 [5.573 - 5.764] %
%   DB = 378.51 [378.31 - 378.71] Mbps
% Exercise 4(b):
%   PB = 5.696 [5.586 - 5.806] %
%   DB = 378.35 [378.11 - 378.60] Mbps
%

% a) Usando o novo simulador (duração discreta)
function [PB,DB] =  VideoStreamingSimulator4(lambda, B, M, N,Prob,D)
cdf = cumsum(Prob);

% Events 
ARRIVAL = 0;        % request of a movie
DEPARTURE = 1;      % end of a movie transmission
%Inicialization of variables and List of Events:
Clock = 0;          % simulation time 
STATE = 0;          % no. of movies in transmission 
TRANSMITTED = 0;    % no. of transmitted movies
N_ARRIVALS = 0;     % no. of movie requests
BLOCKED = 0;        % no. of refused movies
LOAD = 0;           % integral of the bitrate in transmission

EventList = [ARRIVAL, Clock + exprnd(1/lambda)];

while TRANSMITTED < N
    EventList = sortrows(EventList, 2);             % sort EventList by time
    event = EventList(1,1);                         % register event type in first row
    PreviousClock = Clock;                          % save previous clock
    Clock = EventList(1,2);                         % delete first row of EventList
    EventList(1,:) = [];
    LOAD = LOAD + B*STATE*(Clock- PreviousClock);
    switch event
        case ARRIVAL 
            
            EventList = [EventList; ARRIVAL, Clock + exprnd(1/lambda)]; % add future event
            N_ARRIVALS = N_ARRIVALS + 1;
            if STATE < M
                STATE = STATE + 1;
                r = rand();
                % Encontra o primeiro índice onde a probabilidade acumulada é maior que r
                idx = find(cdf >= r, 1, 'first'); 
                duracao_filme = D(idx);
                EventList = [EventList; DEPARTURE, Clock + duracao_filme]; % add future event
            else 
                BLOCKED = BLOCKED + 1;
            end



        case DEPARTURE
            STATE = STATE - 1;
            TRANSMITTED = TRANSMITTED + 1;
    end 
end

PB = BLOCKED / N_ARRIVALS;
DB = LOAD / Clock;
end

lambda = 2;
B = 2;
M = 200;
N = 1e5;
Nsim = 20;
PB_a = zeros(1, Nsim);
DB_a = zeros(1, Nsim);
for it = 1:Nsim
    % Assumindo que criou uma função VideoStreamingSimulator_Ex4
    [PB_a(it), DB_a(it)] = VideoStreamingSimulator4(lambda, B, M, N, Prob, D);
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
PB_b = zeros(1, Nsim);
DB_b = zeros(1, Nsim);
for it = 1:Nsim
    [PB_b(it), DB_b(it)] = VideoStreamingSimulator2(lambda, D_avg, B, M, N);
end

media_PB_b = mean(PB_b);
[~, ~, ci_PB_b] = ttest(PB_b, media_PB_b, 'alpha', alfa);
media_DB_b = mean(DB_b);
[~, ~, ci_DB_b] = ttest(DB_b, media_DB_b, 'alpha', alfa);

fprintf('Exercise 4(b):\n');
fprintf('PB = %.3f [%.3f - %.3f] %%\n', media_PB_b*100, ci_PB_b(1)*100, ci_PB_b(2)*100);
fprintf('DB = %.2f [%.2f - %.2f] Mbps\n\n', media_DB_b, ci_DB_b(1), ci_DB_b(2));

%% 5. Valores Teóricos (M/M/m/m)
% Consider an arrival rate of 2 requests/minute, an average movie duration of D (computed
% in 3.), B = 2 Mbps and M = 200. Determine the theoretical values of the performance
% parameters PB and DB by modelling the video-streaming server as a M/M/m/m queuing
% system. Compare these results with the previous simulation results (obtained in 4.) and
% draw conclusions.
% Exercise 5:
%   PB = 5.669 %
%   DB = 378.81 Mbps
%
lambda = 2;

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
% Consider the provided Matlab function LinkSimulator() that implements a discrete event
% simulator of a data link connection. Save the file to your Matlab current folder. The simulator
% assumes that the arrival of packets is a Poisson process and the packet size is exponentially
% distributed. The simulator includes the appropriate statistical counters to estimate at the end the
% AM (average packet delay) performance parameter.
% A description of the input and output parameters is obtained running in the Matlab Command
% Window:
%
% 6.
% Consider the case of a packet arrival rate of 1000 pps (packets/second), an average packet
% size of 600 Bytes, a link capacity of 10 Mbps (Megabits/second) and a queue capacity of
% 1000 packets. Develop a Matlab script to compute the estimated value and the associated
% 90% confidence interval of AM (in milliseconds), based on 100 runs of the simulator with
% N = 10^4. The results should look like:
% Exercise 6:
%   AM = 0.9231 [0.9191 - 0.9271] msec
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
% 7.
% The provided simulator assumes that the packet size is exponentially distributed. Based on
% the provided simulator LinkSimulator(), develop a new simulator changing the
% statistics of the packet size to consider that the size of each packet is between 64 and 1500
% Bytes with the probabilities:
% - 64 Bytes with probability 29.606%,
% - 110 Bytes with probability 16.417%,
% - 1500 Bytes with probability 19.601%,
% - all other values (i.e., from 65 to 109 and from 111 to 1499) with the same probability.
% First, compute the resulting average packet size. Then, consider again the case of a packet
% arrival rate of 1000 pps, a link capacity of 10 Mbps and a queue capacity of 1000 packets.
% Develop a Matlab script to compute the estimated value and the associated 90% confidence
% interval of AM (in milliseconds), based on 100 runs of the simulator with N = 10^4. Compare
% these results with the previous ones (obtained in 6.) and draw conclusions. The results
% should look like:
% Exercise 7:
%   Avg. Packet Size = 600.0030 Bytes
%   AM = 0.9190 [0.9152 - 0.9228] msec
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
% 8.
% Consider the case of a link capacity of 10 Mbps and a queue capacity of 1000 packets. With
% the simulator developed in 7., develop a Matlab script to compute the estimated value and
% the associated 90% confidence interval of AM based on 100 runs of the simulator with
% N = 10^4 considering:
% (a) a packet arrival rate of 1000 pps,
% (b) a packet arrival rate of 1250 pps,
% (c) a packet arrival rate of 1500 pps,
% (d) a packet arrival rate of 1750 pps,
% (e) a packet arrival rate of 2000 pps.
% Analyse these results and draw conclusions. The results should look like:
% Exercise 8:
%   lambda= 1000: AM = 0.9212 [0.9178 - 0.9246] msec
%   lambda= 1250: AM = 1.1996 [1.1929 - 1.2064] msec
%   lambda= 1500: AM = 1.6976 [1.6801 - 1.7151] msec
%   lambda= 1750: AM = 2.9792 [2.9273 - 3.0311] msec
%   lambda= 2000: AM = 12.0880 [11.1627 - 13.0132] msec
%

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
% 9.
% Present the simulation results of in a bar chart with the confidence intervals in error bars
% on the same plot (Footnote 1). Analyse the width of the obtained confidence intervals and take
% conclusions on the confidence of the results. The visualization should look like:
%
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
% 10.
% Based on the simulator developed in 7., develop another simulator to add the estimation of
% the following performance parameter:
% PD - packet drop (i.e., the probability of a packet being discarded because the queue is full
%      when it arrives)
% Then, consider the case of a packet arrival rate of 1800 pps (packets/second), a link capacity
% of 10 Mbps and a queue capacity of 100 packets. Develop a Matlab script to compute the
% estimated values and the associated 90% confidence intervals of AM (in milliseconds) and
% PD, based on 100 runs of the simulator with N = 10^4. What do you conclude about the
% behaviour of the system concerning the queue capacity? The results should look like:
% Exercise 10:
%   AM = 3.5636 [3.4448 - 3.6825] msec
%   PD = 0.000 [0.000 - 0.000] %
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
% Consider the case of a packet arrival rate of 1800 pps and a link capacity of 10 Mbps.
% Compute the estimated values and the associated 90% confidence intervals of AM and PD
% based on 100 runs of the simulator with N = 10^4 considering:
% (a) a queue capacity of 50 packets,
% (b) a queue capacity of 20 packets,
% (c) a queue capacity of 10 packets,
% (d) a queue capacity of 5 packets.
% Compare these results and draw conclusions. The results should look like:
% Exercise 11:
%   F= 50: AM = 3.5186 [3.4456 - 3.5916] msec  PD = 0.005 [0.002 - 0.008] %
%   F= 20: AM = 3.0265 [2.9936 - 3.0594] msec  PD = 0.577 [0.535 - 0.618] %
%   F= 10: AM = 2.2555 [2.2421 - 2.2690] msec  PD = 3.269 [3.197 - 3.341] %
%   F= 5:  AM = 1.5178 [1.5128 - 1.5228] msec  PD = 8.972 [8.886 - 9.059] %
%
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
% 12.
% Present the simulation results of 11. in a bar chart with the confidence intervals in error
% bars on the same plot. Analyse the width of the obtained confidence intervals and take
% conclusions
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
%
% 13.
% For each case in 11., determine the theoretical values of the performance parameters AM
% and PD by modelling the data link connection as a M/M/1/m queuing system. Compare
% these results with the simulation results (obtained in 11.) and draw conclusions.
% Exercise 13:
%   F= 50: AM = 3.5152 msec  PD = 0.008 %
%   F= 20: AM = 3.0386 msec  PD = 0.658 %
%   F= 10: AM = 2.2070 msec  PD = 3.294 %
%   F= 5:  AM = 1.4780 msec  PD = 8.832 %
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
