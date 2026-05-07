# fs - 1s
# x  - 0.2
fs = 1000

T = 0.2

t = 0:1/fs:T-1/fs
x = 2 * cos( 2 * pi * 100 * t) + sin( 2 * pi * 250 * t);

amostras = t(1:50)
stem(amostras, x(1:50))
xlabel("n"); ylabel("x[n]");
title("x[n] = 2 cos(200 pi n) + sin(500 pi n)");


N = length(x)
fs * T
X = fft(x);
figure
stem(0:N-1,X)
