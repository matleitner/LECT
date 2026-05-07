h1 = [1  1];
h2 = [1 -1];
h3 = [0  0  1];                  % delta[n-2]
x = [ 1 1 1 2 2 2 ];
% Associatividade: (h1*h2)*h3 == h1*(h2*h3)?
h12   = conv(h1, h2);
h123a = conv(h12, h3);
h23   = conv(h2, h3);
h123b = conv(h1, h23);
y = conv(x, h12);
disp('Associativa? '); disp(isequal(h123a, h123b))
disp("Convolulão x e h12, calcula y[n] = x[n] - x[n-2]");disp(y);
% Comutatividade
disp('Comutativa? '); disp(isequal(conv(h1,h2), conv(h2,h1)))

% Atraso: x*delta[n-2] = x[n-2]
x = [3 1 4 1 5];
y_atraso = conv(x, h3);
disp('x original:  '); disp(x)
disp('x atrasado:  '); disp(y_atraso)

% Inversao de h1: h_inv tal que h1*h_inv = delta
% Obter os primeiros 8 coeficientes de h_inv por deconv
% solução aumentar o numero de 0's em  delta8
delta8 = [1 zeros(1,8)];

h_inv = deconv(delta8, h1);
disp('h_inv (aprox.) = '); disp(h_inv)


% Verificar: h1*h_inv ~= delta?
disp('h1 * h_inv = '); disp(conv(h1, h_inv))

% Visualizar h12 e h123
figure(5);
subplot(2,1,1); stem(0:length(h12)-1,  h12,  'filled');
  title('h12=h1*h2'); grid on;
subplot(2,1,2); stem(0:length(h123a)-1,h123a,'filled');
  title('h123=h12*h3 (atrasado 2)'); grid on;
