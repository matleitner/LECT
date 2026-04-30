close all;
clear

% 1)
%% 10kHz = 10000 apostras em 1 segundo, ou seja 1 amostra em T = 1/10000 s
fs = 10000;
t = 0:1/fs:0.1-1/fs;
% 75 * 2   150 * 2   225*2
x = 2*cos(150*pi*t) + sin(300 * pi*t) + 0.5 * cos(450 * pi * t)
N = length(x);
% 2)
figure(1)

subplot(2,1, 1);
plot(t,x,'red', 'LineWidth', 2);
title("Sinal x(t)");
xlabel("t em segundos"); ylabel("x(t)");

hold on
plot(t,2*cos(150*pi*t))

hold on
plot(t, sin(300 * pi*t));

hold on
plot(t,0.5 * cos(450 * pi * t))

legend("x(t)","2cos(150 PI t)", "sin(300 PI t)", "0.5 cos(450 PI t)");
% 3)
% cada "bin" incrementa fs / N por cada bin, ou seja X(1) = amplitude de 10Hz
%
N = fs * 0.1;

X = fft(x);


subplot(2,1,2);
%f = 0:N/2;
%xlabel("bin k (Δf * k = f_k)");
f = (0:N/2) * fs/N; % normalizar fs / N = fΔ
xlabel("Frequência Hz");

magX = abs(X(1:N/2 + 1))/N ;
stem(f, magX);

ylabel("Amplitude");
xlim([0 250]);
xticks(0:10:250);
grid on



% 4)
function indices = cleanPeaks(mag_X)
  minimo = 0.1;
  indices = [];
  for i = 2: length(mag_X)
    if mag_X(i) > mag_X(i-1) && mag_X(i) > mag_X(i+1) && mag_X(i) >  minimo
        indices = [indices i-1]
    endif
  endfor
end

indices = cleanPeaks(magX);
fprintf("O sinal contém n sinusoide(s) no(s) índice(s): ");
for i = 1: length(indices)
    fprintf(" %d, ", indices(i))
end

fprintf("\n");



% 5)

delta_f = fs /N;
frequencias  = indices * delta_f;


fprintf("As frequências presentes no sinal são: ");
for i = 1: length(frequenci3as)
    fprintf(" %dHz, ", frequencias(i))
end

fprintf("\n");

