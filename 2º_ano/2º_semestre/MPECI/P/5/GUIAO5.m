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

mean(durationTimes)