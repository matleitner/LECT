%% 1. c) Esboço de y[n]



x = [1 2 3 2 1];
h = [1 -1];

% 1. Calcule a convolucao
y = conv(x, h);

% 2. Indices
nx = 0:length(x)-1;
nh = 0:length(h)-1;
ny = 0:length(y)-1;

% 3. Subgraficos
figure(1);
subplot(3,1,1); stem(nx, x, 'filled'); title('x[n]'); grid on;
subplot(3,1,2); stem(nh, h, 'filled'); title('h[n]'); grid on;
subplot(3,1,3); stem(ny, y, 'filled'); title('y[n] = x*h');
xlabel('n'); grid on;

disp('y[n] ='); disp(y)

%% 2. d)
x = [3 2 1];
h = [1 2 2 1];

% h2 = δ[n] + δ[n-5]
h2 = [1 0 0 0 0 1];
% repetição de x em n = 0 e n = 5
y1 = conv(x, h);
y2 = conv(h, x); % ordem trocada
y3 = conv(x,h2);
disp('y1 = '); disp(y1)
disp('y2 = '); disp(y2)
disp('Sao iguais? '); disp(isequal(y1, y2))

figure(2);
subplot(2,1,1); stem(0:length(y1)-1, y1,'filled');
title('conv(x,h)'); grid on;
subplot(2,1,2); stem(0:length(y2)-1, y2,'filled');
title('conv(h,x)'); grid on;
figure(3);
stem(0:length(y3)-1, y3, 'filled');

