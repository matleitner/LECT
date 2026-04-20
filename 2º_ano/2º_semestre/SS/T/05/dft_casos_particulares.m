N = 32;          % two full periods
T = 16;          % period in samples
n = 0:N-1;

titlestring1='';
titlestring2='';



% Sinusoide
x = sin(2*pi*n/T);
titlestring1 = sprintf('Sine wave  (T = %d samples, N = %d points)',T,N);
titlestring2 = sprintf('Discrete Fourier Transform of x');
% Impulso rectangular
%Largura = 4;
%Atraso = 6;
%x = zeros(1,N);
%x(Atraso+1:Atraso+Largura) = 1;
%titlestring1 = sprintf('Impulso  (Atraso = %d, Largura = %d)',Atraso,Largura);
%titlestring2 = sprintf('Discrete Fourier Transform of x');



figure
stem(n, x);
grid on;
xlabel('n');
ylabel('x[n]');
title(titlestring1);


figure
X  = fft(x)
subplot(211)
stem(n,abs(X))
xlabel('n');
ylabel('|X[n]|');
subplot(212)
stem(n,angle(X))
xlabel('n');
ylabel('angle(X[n])');
title(titlestring1);

