% Exercicio 1.1 - Verificacao usando computacao numerica e simbolica
pkg load symbolic
clear

% Ex 1_1 a): x[n] = (0.5)^n u[n]
% Verificacao numerica
n = 0:20;
x_a = (0.5).^n;
figure(1);
stem(n, x_a);
title('x[n] = (0.5)^n u[n]');
xlabel('n'); ylabel('x[n]');
grid on;

%%
% Verificacao simbolica
syms n;
f=(0.5)^n;
F=ztrans(f);
display('Transformada de Z, Ex.1.1 a)');
display(F)

% Ex 1_1 c): x[n] = delta[n] + 2*delta[n-1] + delta[n-2]
% Verificacao numerica
% ____
% ____
n  = [0:20]
% Verificacao simbolica
syms n;
f=kroneckerDelta(n,0)+2*kroneckerDelta(n,1)+kroneckerDelta(n,2);
F=ztrans(f);
display('Transformada de Z, Ex.1.1 c)');
display(F)
