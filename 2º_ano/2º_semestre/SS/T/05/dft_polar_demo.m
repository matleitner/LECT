% =========================================================================
%  DFT in polar form — magnitude and phase
%  Style: DSP Guide Fig. 8-10
%
%  Shows a time-domain signal and its DFT displayed as:
%    (a) x[n]          — time domain
%    (b) |X[k]|        — magnitude spectrum
%    (c) angle(X[k])   — phase spectrum (wrapped, -pi to +pi)
%
%  The signal is a rectangular pulse: easy to predict analytically
%  (magnitude = |sinc-like|, phase = linear with jumps at zeros).
%
%  Usage:  dft_polar_demo
% =========================================================================

function dft_polar_demo()

  N = 64;          % DFT length

  % ── Time-domain signal: rectangular pulse ─────────────────────────────────
  x = zeros(1, N);
  pulse_start  = 4;
  pulse_length = 10;
  x(pulse_start : pulse_start + pulse_length - 1) = 1;

  % ── DFT ───────────────────────────────────────────────────────────────────
  X   = fft(x);

  % Positive frequencies only: bins 0 .. N/2
  bins = 0 : N/2;
  Xpos = X(bins + 1);          % +1 because Octave is 1-indexed

  mag   = abs(Xpos);
  phase = angle(Xpos);         % wrapped to (-pi, +pi]

  % ── Plots ─────────────────────────────────────────────────────────────────
  figure('Name', 'DFT in polar form  (DSP Guide style)', 'NumberTitle', 'off');

  % (a) Time domain
  subplot(3, 1, 1);
  stem(0:N-1, x, 'k', 'filled', 'MarkerSize', 3);
  xlim([-1, N]);
  ylim([-0.2, 1.4]);
  xlabel('Sample  n');
  ylabel('Amplitude');
  title('(a)  Time-domain signal  x[n]');
  grid on;

  % (b) Magnitude
  subplot(3, 1, 2);
  stem(bins, mag, 'k', 'filled', 'MarkerSize', 3);
  xlim([-1, N/2 + 1]);
  xlabel('Frequency bin  k  (0 = DC,  N/2 = Nyquist)');
  ylabel('|X[k]|');
  title('(b)  Magnitude spectrum');
  grid on;

  % (c) Phase
  subplot(3, 1, 3);
  stem(bins, phase, 'k', 'filled', 'MarkerSize', 3);
  xlim([-1, N/2 + 1]);
  ylim([-pi - 0.3, pi + 0.3]);
  set(gca, 'YTick', [-pi, -pi/2, 0, pi/2, pi], ...
           'YTickLabel', {'-pi', '-pi/2', '0', 'pi/2', 'pi'});
  xlabel('Frequency bin  k');
  ylabel('Phase (rad)');
  title('(c)  Phase spectrum  (wrapped to [-pi, +pi])');
  grid on;

end
