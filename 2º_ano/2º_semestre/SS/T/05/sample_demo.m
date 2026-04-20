
close all

t_cont = linspace(0,2,1000);
t_disc = 0: 1/12:2;

x1_cont = sin(2*pi*t_cont);
x1_disc = sin(2*pi*t_disc);

figure(1)
ax1 = plot(t_cont,x1_cont);
hold on
stem(t_disc,x1_disc);
pause()
set(ax1,'visible','off')

pause();


x2_cont = sin(2*pi*8*t_cont);
x2_disc = sin(2*pi*8*t_disc);

figure(2);
ax2 = plot(t_cont,x2_cont,'--');

hold on
stem(t_disc,x2_disc);
pause()
set(ax2,'visible','off')
pause()

x2_conta = -sin(2*pi*4*t_cont);
plot(t_cont,x2_conta,'--r')