% Exercicio 1
x1 = linspace(0, 4*pi, 100);
y1 = sin(x1);

plot(x1,y1)

% Exercicio 2

x2 = [ 0 : pi / 150 : 2*pi ];

y1 = sin(x2);
y2 = cos(x2);

plot(x2, y1, 'ob;sin(x);')

%hold on

plot(x2, y2, '+r;cos(x);');

%hold on

% Exercicio 3

theta = [-2*pi:pi/10:2*pi ];

y3 = sin(theta) ./ theta;

plot(theta, y3);

%hold on

% Exercicio 4

x4 = linspace(0, 5, 100);
y4 = exp(x4);

plot(x4, y4)

% Exercicio 5

y5 = exp(-x4);
plot(x4, y5);


% Exercicio 6

x6 = linspace(0,5,100);
y6 = log(x6)

plot(x6, y6)

% Exercicio 7
x7 = linspace(0, 2, 100)
y7_1 = exp(x7)
y7_2 = log(x7)

X = eye(100, 2);
X(:, 1) = y7_1'
X(:, 2) = y7_2'

plot(X)
