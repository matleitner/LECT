% B 1.1

X = [ 4, 1-1j, 2, 1+1j];

x = ifft(X)
% B 1.2

X_rec = fft(x)

max(abs(X_rec - X))


% B 1.3
% X[1] = dft(x)
% x[n] = A + B · cos(2 · PI · n / N + omega)
% X[n] =
N = length(X)

A = X(1)/ N             % X[0]
B =  2* abs(X(2)) /N    % X[1]
phi = angle(X(2))       % X[1]

n = 0:N-1;
x = A + B* cos(2 * pi * n / N + phi);
disp(x);



%% B 2

% B 2_1


[ x8 , X8 ] = impulso (4 ,0,8) ;
%[ x16 ,X16 ] = impulso (4 ,0,16) ;
%[ x32 , X32 ] = impulso (4 ,0,32) ;
%[ x64 ,X64 ] = impulso (4 ,0,64) ;
% B 2_2

find(abs(X8)  < 20*eps) - 1
find(abs(X16)  < 20*eps) - 1
find(abs(X32)  < 20*eps) - 1
find(abs(X64)  < 20*eps) - 1


figure ;
Ns = [8 16 32 64];
Xs = { X8 , X16 , X32 , X64 };

for i = 1:4
  subplot (4 ,1 , i ) ;
  N_i = Ns ( i ) ;
  stem (0: N_i -1 , abs ( Xs { i }) , 'filled') ;
  xlabel ( 'k ') ; ylabel ( '| X [ k ]| ') ;
  title ( sprintf ( 'N = % d ' , N_i ) ) ;
  grid on ;
end

