%Considere o sinal discreto $x[n]$ com $L=8$ amostras unitárias ($x[n]=1, 0 \le n < L$) e $N=32$.
%Espectro: Crie um script prob3.m que calcule a magnitude da DFT deste sinal usando a função fft().
%Zero-Padding: Calcule a DFT para $N=32$ e $N=128$.
%Visualize ambos os espectros de magnitude em função da frequência normalizada.
%Janelamento: O que acontece à largura do lobo principal e à posição dos zeros quando aumentamos $N$ mantendo $L$ fixo? Justifique com base na resolução espectral.
%Reconstrução: Use a função ifft() para recuperar o sinal original a partir de $X[k]$ e verifique se o erro quadrático médio (MSE) entre o original e o reconstruído é aproximadamente zero.

L = 8;

N1 = 32;
N2 = 128;

x1 = [ones(1, L), zeros(1,N1-L)];
x2 = [ones(1, L), zeros(1,N2-L)];

X2 = fft(x2);
X1 = fft(x1);


f1 = (0:N1-1)/N1;
f2 = (0:N2-1)/N2;

subplot(2,1,1)
stem(f1, abs(X1));

subplot(2,1,2);
stem(f2, abs(X2));


x_req = ifft(X2);

mse = mean(abs(x_req-x2).^2);
fprintf('O erro quadrático médio (MSE) é: %e\n', mse);
