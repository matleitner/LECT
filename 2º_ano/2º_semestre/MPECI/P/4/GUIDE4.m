%% 1. 
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

