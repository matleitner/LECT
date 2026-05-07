pkg load signal

fs = 1000;

T = 0.2;

t = 0:1/fs:T-1/fs;


x = 2 * cos(200 * pi * t) + sin(500 * pi * t)
figure
plot(t,x)
title("AA")

figure
N = fs * T;

X = fft(x);
delta_f = fs / N; # se f = k * delta_f então e o max k é N, então 1000 = 200 * deltaf

mag_X = abs(X) /N;
subplot(2,1,1)
stem((0:N/2-1) * delta_f, mag_X(1:N/2));
title("fft(x[n])")
xlabel("frequência Hz"); ylabel("Magnitude");
threshold = max(mag_X) * 0.1;

[peaks index] = findpeaks(abs(X(1:N/2)), 'MinPeakHeight', threshold);
peaks;
index = index -1;

fprintf("Resolução de frequencia: %d", delta_f);
fprintf("Indices k: \n")
display(index);

X_1024 = fft(x, 1024);
subplot(2,1,2)
stem((0:N/2-1 )*delta_f, abs(X_1024(1:N/2)))
title("N = 1024")
xlabel("frequência Hz"); ylabel("Magnitude");
length(X_1024);

# 2.

#  y[n] = 0.7 y[n-1] + x[n] + 0.5x[n-1]

b = [1 0.5]
a = [1 -0.7]



