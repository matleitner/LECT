% Exercicio 1.2 - Transformada Z Inversa
% Parte (a)
disp("a)")
num = [2];  % O numerador correcto é [2 0]. neste caso faz-se divisão por z
den = conv([1 -0.5], [1 -0.3]);
[r, p, k] = residue(num, den);

disp('Coeficientes da Fracao Parcial (dividida por z):');
disp('Residuos:'); disp(r);
disp('Polos:'); disp(p);
disp('Termo direto:'); disp(k);
disp('Não esquecer de multiplicar por z a fracção final!')

% Reconstruir a sequencia
n = 0:20;
x_n = r(1)*(p(1).^n) + r(2)*(p(2).^n);
figure(121);
stem(n, x_n);
title('Transformada Z Inversa de X(z) Ex 1.2 a)');
xlabel('n'); ylabel('x[n]');
grid on;