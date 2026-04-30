% Problema 2

% 1)
time_resolution = 1/(20*10^3);
duration = 0.05;
t = 0:time_resolution:0.05-time_resolution;

xa = cos(2 * pi * 800 * t);


% 2)

fs4 = 400;
fs12 = 1200;
fs32 = 3200;

t4 = 0:1/fs4:0.05-1/fs4;
t12 = 0:1/fs12:0.05-1/fs12;
t32 = 0:1/fs32:0.05-1/fs32;

x4  = cos(2 * pi * 800 * t4 );
x12 = cos(2 * pi * 800 * t12 );
x32  = cos(2 * pi * 800 * t32 );
% 3)
figure
subplot(4,3, [1 3])
plot(t,xa);
title("xa");
subplot(4,3, [4 6])
plot(t4, x4);
title("x4")
subplot(4,3,[7 9])
plot(t12, x12)
title("x12")
subplot(4,3, [10 12])
plot(t32, x32);
title("x32")

% 4)
N = length(t)/2;

Xa = fft(xa);
X4 = fft(x4);
X12 = fft(x12);
X32 = fft(x32);

Na = length(xa);
N4 = length(x4);
N12 = length(x12);
N32 = length(x32);

ka = (0:Na/2);
k4 = (0:N4/2);
k12 = (0:N12/2);
k32 = (0:N32/2);

%     k values, transformed in freq values
fa = ka*(20000/Na);
f4 = k4*(400/N4);
f12 = k12*(1200/N12);
f32 = k32*(3200/N32);

% magnitudes normalizadas
Ma = abs(Xa(1:Na/2+1))/Na;
M4 = abs(X4(1:N4/2+1))/N4;
M12 = abs(X12(1:N12/2+1))/N12;
M32 = abs(X32(1:N32/2+1))/N32;
% arrays de diferentes tamanhos usei {} cell arrays

name = {"Xa", "X4", "X12", "X32"};
freqs = {fa, f4, f12, f32};
k = {ka, k4, k12, k32};
magnitudes = {Ma, M4, M12, M32};


figure



for i = 1:4

    subplot(4,3, [3*(i-1)+1 (i)*3])
    stem(k{i}, magnitudes{i});
    title(name{i});
    ylabel("Amplitude");
    xlabel("indices k")
    xlim([0 length((k{i}))]);
endfor
freq_resposta_Xa = [];
freq_resposta_X4 = [];
freq_resposta_X12 = [];
freq_resposta_X32 = [];

for i = 1 : 4
    for j = 1:length(magnitudes{i})
      switch i
        case 1
            if(magnitudes{i}(j) > 0.1)
              freq_resposta_Xa = [freq_resposta_Xa, freqs{i}(j)];
            endif
        case 2
            if(magnitudes{i}(j) > 0.1)
              freq_resposta_X4 = [freq_resposta_X4, freqs{i}(j)];
            endif
        case 3
            if(magnitudes{i}(j) > 0.1)
              freq_resposta_X12 = [freq_resposta_X12, freqs{i}(j)];
            endif
        case 4
            if(magnitudes{i}(j) > 0.1)
              freq_resposta_X32 = [freq_resposta_X32, freqs{i}(j)];
            endif
      end
    endfor
endfor


display(freq_resposta_Xa)
display(freq_resposta_X4)
display(freq_resposta_X12)
display(freq_resposta_X32)

