x = [1 2 3 2 1];
h = [1 -1];
%h = [1 1]
% 1. Calcule a convolucao
y = conv(x, h);

% 2. Indices
nx = 0:length(x)-1;
nh = 0:length(h)-1;
ny = 0:length(y)-1;

% 3. Subgraficos
figure(1);
subplot(2,2,1); stem(nx, x, 'filled'); title('x[n]'); grid on;
subplot(2,2,2); stem(nh, h, 'filled'); title('h[n]'); grid on;
subplot(2,2,[3 4]); stem(ny, y, 'filled'); title('y[n] = x*h');
xlabel('n'); grid on;

disp('y[n] ='); disp(y)
