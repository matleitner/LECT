% Exercicio 1
vetor = []
counter = 0;
for  n = 1 : 1000,
  x = rand();

  if x < 0.3,
    counter = counter + 1;
    vetor(counter) = x;

  endif

end

%vetor


% Exercicio 2

x = linspace( 0, 2, 100)
A = []

for n = 1:10,
  alpha = 1 + 0.1* n;

  y2 = exp( alpha * x );

  A(:, n) = y2;

end

%plot(A);


% Exercicio 3
% Expansão de Taylor

A = zeros(1,100);
x = linspace(0, 2 * pi, 100);
x = x'
for n = 1 : 5,

     A = A + x.^n / factorial(n) * sin(n * pi/2);

end

%plot(A)


% Exercicio 4
M = []

for n1 = 1 : 10,
  for n2 = 1 : 10,
    v(n2) = randi([1,101]);
  end
  M(:, n1) = v
end

M
