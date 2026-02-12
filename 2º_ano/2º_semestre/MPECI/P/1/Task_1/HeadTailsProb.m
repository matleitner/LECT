function HeadTailsProb(p, n, k,N)
    tosses = rand(n,N) < p;
    successes = sum(tosses)  == k;
    prob = sum(successes) / N;
    prob
end
