% Colunas definem estado atual, Linhas o próximo

%% 1. 
% a)
%           Sunny Cloudy Rainy
% Sunny     
% Cloudy 
% Rainy
T = [ 0.7, 0.2, 0.1;
     0.2, 0.3, 0.5; 
     0.3, 0.3, 0.4]';

fprintf("a)\nT =\n")
disp(T)


% b)
% sunny > sunny 
% sunny > sunny > sunny 
state = [1 0 0]';
% Pobability vector for Day 2
d2 =  T * state;
Prob_day2_sunny = d2(1);

% Probability vector for Day 3
Prob_3_sabendo_2_sunny = T(:,1);

Prob_day_2_and_3 = Prob_day2_sunny * Prob_3_sabendo_2_sunny(1);

fprintf("\nb)\nProbabilidade de dias 2 e 3 serem Sunny: %.2f%%\n", Prob_day_2_and_3*100)

% c)

fprintf("\nc)\n")

% 4ª- 5ª- 6ª - S - D
%   1   2    3 
T3 =  T^3;

Prob = T3(1,3) * T(1,1);

fprintf("Probabilidade: %.2f%%\n", Prob*100)


% d)
fprintf("d)\n")
v = [1 0 0]';
somador = v;

for i = 2:31
       v= T*v;
       somador = somador + v;

end
somador


% e)
fprintf("e)\n")
v2 = [0 0 1]';
somador2 = v2;

for i = 2:31
       v2= T*v2;
       somador2 = somador2 + v2;

end
somador2

% f) 
painProb = [0.1 0.3 0.5];
d1 = [1 0 0 ]';
somador3 = painProb * d1 ;
for i = 2:31
    d1 = T*d1;
    somador3 = somador3 + painProb * d1;
end

somador3

    % Sol Cloudy Rainy
d1 = [ 0 0 1 ]';
somador4 = painProb * d1 ;
for i = 2:31
    d1 = T*d1;
    somador4 = somador4 + painProb * d1;
end
somador4

%% 3.

% a) 
p = 0.4;
q = 0.6;
fprintf("3.\na)\n\nCol -> Linha\n")

T = [ p^2, (1-p)^2, p*(1-p), p*(1-p);
       0, 0 , 0, 1;
       0, 0 ,0 ,1 ;
       q^2, q*(1-q), q*(1-q), (1-q)^2]';
T
% b) 
fprintf("b)\n")
state = [1, 0 , 0, 0]';

T5 = T^5 * state
T10 =  T^10 * state
T100 =  T^100 * state
T200 =  T^200 * state
% c)
fprintf("c)\n")
contador = 1;
state_A = [1,0,0,0]';
state_B = [0,1,0,0]';
state_C = [0,0,1,0]';
state_D = [0,0,0,1]';

function counter = limit(T, state)
    
    contador = 1;
    T_new = T * state;
    T_old = state;
    condicao = true;
    while condicao
        T_old = T_new;
        T_new = T * T_old;
        if max(abs(T_new - T_old)) < 1e-4    % 1e-4 porque não consegui fazer T_new == T_old e T_new - 
                                        % T_old nunca dá exatamente 0
            condicao = false;
        end
        contador = contador + 1;
    end

    counter = contador;
end

contador_A = limit(T,state_A);
contador_B = limit(T,state_B);
contador_C = limit(T,state_C);
contador_D = limit(T,state_D);
fprintf("Limite Probabilidade estado A: %d \n",contador_A)
fprintf("Limite Probabilidade estado B: %d \n",contador_B)
fprintf("Limite Probabilidade estado C: %d \n",contador_C)
fprintf("Limite Probabilidade estado D: %d \n",contador_D)


%% 4.
% a)
fprintf("4.\na)\n\n")
T = rand(20) % matrix 20 x 20 aleatoria 
T = T ./ sum(T); % dividir pela soma de cada coluna 

stoicastic = sum(T);
stoicastic_check = true;
for i = 1:20
    if(abs(stoicastic(i)-1) > 1e-5) 
        stoicastic_check = false;
    end

end

stoicastic_check

% b)
state_1 = zeros(1,20); state_1(1,1) = 1;
probs_2 = state_1 * T^2;
probs_5 = state_1 * T^5;
probs_10 = state_1 * T^10;
probs_100 = state_1 * T^100;
p_2 = probs_2(1,20);
p_5 = probs_5(1,20);
p_10 = probs_10(1,20);
p_100 = probs_100(1,20);


fprintf("b)\n\n     Probabilidade estado 1 → 20 em 2 transições é de: %.5f%%\n", p_2*100)
fprintf("     Probabilidade estado 1 → 20 em 5 transições é de: %.5f%%\n", p_5*100)
fprintf("     Probabilidade estado 1 → 20 em 10 transições é de: %.5f%%\n", p_10*100)
fprintf("     Probabilidade estado 1 → 20 em 100 transições é de: %.5f%%\n", p_100*100)
fprintf("\nConclusão: Após muitas transições (como 100), a probabilidade de estar no estado 20 estabiliza, \nindicando que a cadeia de Markov tende a uma distribuição estacionária, independentemente do estado inicial.\n");
%% 5  Page Rank

    % A   B   C   D  E   F
T = [ 0   1   0   0  0   0;
      0   0   1/2 0  1/2 0;
      0   0   0   1  0   0;
      0   0   1   0  0   0;
      1/3 1/3 0   0  0   1/3;
      0   0   0   0  0   0]'
% a)
 
v = ones(6,1)/6;
pagerank = T^40 * v;
fprintf("Page Rank:\n")
fprintf("   %.2f\n", pagerank)

% b)

fprintf("b)\n Spider trap is C and D, that the only way out of C is D and the only way out D e to C and they can't go elsewhere. Dead-end is F.\n")
% c)

T(:,6) = ones(6,1)/6;

fprintf("c)\nTo solve the dead-end problem:\n");
T

%d)

fprintf("d)\n")

betha = 0.8;

T = betha * T + (1-betha)*ones(6)/6;

pagerank = T^40 * v

% e)
v = ones(6,1)/6;
v_ant = v;
contador = 1;
continuar = true;

while continuar 
    v = T*v;
    if max(abs(v-v_ant)) <1e-4
        continuar = false;
    end
    contador = contador +1;
    v_ant = v;
end

fprintf("Contador: %d\n", contador)


%% 6. (OPCIONAL)
fprintf("6.\n")
% a)


%      a    b   c   d   e  f 
H = [  0    1   0   0   0  0;
      1/2   0   0   0   0 1/2;
      1/2   0   0  1/2  0  0;
       0    0   1   0   0  0;
      1/4  1/4 1/4 1/4  0  0;
       0    0   0   1   0  0; ]';
betha = 0.85;
N = 6;
N_X_N = ones(N)/N;

A = betha * H + (1 - betha) * N_X_N;

x0 = ones(N,1)/N;
x = x0;
iter = 1;
epsilon = 0.01;
fprintf("a)\n")
while 1 

    % fprintf(1,"Iter: %d\n", iter)
    xOld = x;
    x = A*x;
    if max(abs(x-xOld))<epsilon 
        break; end
    
    iter = iter + 1;
end

pages = ["a.pt" "b.es" "c.fr" "d.br" "e.com" "f.nl"];
iMax = 1;
iMin = 1;
for i = 2:6
    if x(i) > x(iMax)
        iMax = i;
    end
    if x(i) < x(iMin)
        iMin = i;
    end
end
fprintf("  The page that has the highest pagerank is: %s with a prob of %.4f\n",pages(iMax), x(iMax) )
fprintf("  The page that has the lowest pagerank is: %s with a prob of %.4f\n",pages(iMin), x(iMin) )



% b)
% r * T = r;
% 

fprintf("b)\n")

M6 = A - eye(N);
M6(end,:) = ones(1, N);
b6  = zeros(N,1);
b6(end)  = 1;

solve = M6\b6;
for i = 1:6
    fprintf("  %s : %.4f\n", pages(i), solve(i)) 
end


