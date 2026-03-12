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
for i = 1:3
    for i2 = 1:3
        fprintf("%.1f  ", T(i,i2))
    end
    fprintf("\n")
end


% b)
% sunny > sunny 
% sunny > sunny > sunny 


% Pobability vector for Day 2
d2 =  T(1,1);

% Probability vector for Day 3
d3 = T(1,1)^2;

fprintf("\nb)\nDay 2: %.2f%%, Day 3: %.2f%%\n" ,d2*100, d3*100 )
% c)

fprintf("\nc)\n")

% 4ª- 5ª- 6ª - S - D
%   1   2    3 
T3 =  T^3;

Prob = T3(1,3) * T(1,1);

fprintf("Probabilidade: %.2f%%", Prob*100)


% d)
v = [1 0 0]';
somador = v;

for i = 2:31
       v= T*v;
       somador = somador + v;

end
somador


% e)
v2 = [0 0 1]';
somador2 = v2;

for i = 2:31
       v2= T*v2;
       somador2 = somador2 + v2;

end
sombador2

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

T = [ p^2, (1-p)^2, p*(1-p), p*(1-p);
       0, 0 , 0, 1;
       0, 0 ,0 ,1 ;
       q^2, q*(1-q), q*(1-q), (1-q)^2]';
T
        
% b) 

state = [1, 0 , 0, 0]';

T5 = T^5 * state
T10 =  T^10 * state
T100 =  T^100 * state
T200 =  T^200 * state


%% 5  Page Rank

    % A   B   C   D  E   F
T = [ 0   1   0   0  0   0;
      0   0   1/2 0  1/2 0;
      0   0   0   1  0   0;
      0   0   1   0  0   0;
      1/3 1/3 0   0  0   1/3;
      0   0   0   0  0   0]'

v = ones(6,1)/6;
T(:,6) = ones(6,1)/6;
pagerank = T^40 * v;
fprintf("Page Rank:\n")
fprintf("   %.2f\n", pagerank)

betha = 0.8;

T = betha * T + (1-betha)*ones(6,6)/6;

pagerank = T^40 * v;


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