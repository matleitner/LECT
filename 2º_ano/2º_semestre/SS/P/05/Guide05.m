
x = [1 0 -1 0];
X = fft(x)
fprintf("| k | Re X[k] | Im X[k] |  X[k]  | ∠X[k] |\n\n")
for k = 1:3
  fprintf("| %d |  %.2f   |  %.2f   |  %.2f  | %.2f |\n",k-1,real(X(k)), imag(X(k)), abs(X(k)), angle(X(k))  )

end
axis = 0:3;
subplot(2,2,[1 2])
stem(axis,x )
xlim([-0.5,4.5])
hold on
plot(axis,  x)
subplot(2,2,3)
stem(axis, X)
xlim([-0.5,4.5])


%% 2.
N = 4;
x_n = [3,1,0];


% Desnormalizar
X = zeros(1,4);
for i = 0:2
  if i == 0 || i == N/2
      X(1,i+1) = x_n(1,i+1) * (N)

  else
      X(1,i+1) = x_n(1,i+1) * (N/2)
  endif
end

X(4) = X(2)
x = ifft(X)

