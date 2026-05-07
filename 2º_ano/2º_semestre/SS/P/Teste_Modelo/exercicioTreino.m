
% x = 4 * cos(160* pi* t) + 2 * sin(480*pi * t).
% 1.

fprintf("A frequência máxima é de max(80, 240) = 240 e a taxa de Nyquist minima é 2 * f_max = 2 *240 = 480 Hz;\n")
% 2.

fs = 10e3; % 10 kHz
T = 0.1;

t = 0:1/fs:T-1/fs;

x = 4 * cos(160* pi* t) + 2 * sin(480*pi * t);
subplot(3,1,1)
plot(t,x)
title("f de Amostragem = 10kHz")
ylabel("Amplitude")
xlabel("t (s)")
hold on


fs_1 = 300;
fs_2 = 600;

t_1 = 0:1/fs_1:T-1/fs_1;
t_2 = 0:1/fs_2:T-1/fs_2;

x_1 = 4 * cos(160* pi* t_1) + 2 * sin(480*pi * t_1);
x_2 = 4 * cos(160* pi* t_2) + 2 * sin(480*pi * t_2);


subplot(3,1,2)
plot(t,x)
hold on
stem(t_1, x_1, 'r')

title("f de Amostragem = 300Hz")
ylabel("Amplitude")
xlabel("t (s)")
subplot(3,1,3)
plot(t,x)
hold on
stem(t_2, x_2, 'g')
hold on
title("f de Amostragem = 600Hz")
ylabel("Amplitude")
xlabel("t (s)")
grid on
fprintf("Como f1 < f de Nyquist, o gráfico 2, é o que vai ocorrer o fenómeno de aliasing, porque a frequencia é demasiado inferior à de Nyquist e não é possivel representar corretamente o sinal original\n")
