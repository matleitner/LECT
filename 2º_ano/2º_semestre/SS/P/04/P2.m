x = [3 2 1];
h = [1 2 2 1];
h  = [1 0 0 0 0 1];
y1 = conv(x, h);
y2 = conv(h, x);             % ordem trocada

disp('y1 = '); disp(y1)
disp('y2 = '); disp(y2)
disp('Sao iguais? '); disp(isequal(y1, y2))

figure(2);
subplot(2,1,1); stem(0:length(y1)-1, y1,'filled');
  title('conv(x,h)'); grid on;
subplot(2,1,2); stem(0:length(y2)-1, y2,'filled');
  title('conv(h,x)'); grid on;
