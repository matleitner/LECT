% Polinómios

p = [1 -3 2];

r = roots(p);

poly(r);
polyval(p,r);

p1 = [ 1 0 1 ];
p2 = [ 1 0 1 -1 ];

conv(p1,p2);

% Exercicio 1

sin(pi / 2);
cos(pi / 2);
tan(pi / 2);
sqrt(pi / 2);
cbrt(pi / 2);

% Exercicio 2

log(-1);
sqrt(-1);

% Exercicio 3
x = linspace(-1, 1, 100);

e.^x;

% Exercicio 4

x = linspace(-pi, pi, 100);

sin(x + pi/10) .* cos(x);

% Exercicio 5

p1 = [1 0 0 0 0 0 10];
p2 = [1 -2 3];
conv(p1, p2);


% Exercicio 6.
% Obtenha o polinómio cujas raízes são
% os números inteiros 1, 2 e 3.

r = [1 2 3];

poly(r);


% Exercicio 7

p = [ 1 4 -3 1]

roots(p)


omega = linspace(0, 2*pi, 100)
x = exp(i * omega)

polyval(p, x)


