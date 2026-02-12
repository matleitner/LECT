% a)
N = 1e5;
p = 0.5;
n = 15;

tosses = rand(n, N) < p;
successes_a = sum(tosses) == 6;
prob_a = sum(successes_a) / N;

% b) 

successes_b = sum(tosses) >= 6;
prob_b = sum(successes_b) / N;

prob_a 
prob_b
