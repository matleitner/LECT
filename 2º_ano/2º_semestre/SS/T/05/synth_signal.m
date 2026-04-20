% =========================================================================
%  Signal synthesis from a specified DFT
%  Signals & Systems — Classroom Demo
%
%  Magnitude spectrum (Bode-like, real-valued signal):
%
%    |H(f)| = sqrt( max(0, 1-(f/fz)^2) ) / sqrt( 1+(f/fp)^2 )
%
%    fp = 0.10 * Fs  (pole  — soft roll-off starts here)
%    fz = 0.25 * Fs  (zero  — magnitude reaches exactly 0 here)
%
%  Phase: linear,  phi(k) = -2*pi*k*(N/2)/N   (delay = N/2 samples)
%
%  Usage:  synth_signal
% =========================================================================

function synth_signal()

  N  = 512;
  Fs = 1000;          % Hz
  fp = 0.10 * Fs;     % pole frequency
  fz = 0.25 * Fs;     % zero frequency
  delay = N / 2;      % samples — centres pulse in the window

  % ── Positive-frequency bins 0 .. N/2 ─────────────────────────────────────
  k     = (0 : N/2)';
  f_pos = k * Fs / N;

  % ── Magnitude ─────────────────────────────────────────────────────────────
  num = sqrt( max(0, 1 - (f_pos / fz).^2) );
  den = sqrt( 1  + (f_pos / fp).^2 );
  mag = num ./ den;

  % ── Linear phase ──────────────────────────────────────────────────────────
  phi = -2*pi * k * delay / N;

  % ── Build conjugate-symmetric N-point spectrum ────────────────────────────
  H_pos = mag .* exp(1j * phi);
  H = [H_pos; conj(flipud(H_pos(2:end-1)))];

  % ── Time-domain signal ────────────────────────────────────────────────────
  x = real(ifft(H));
  t = (0 : N-1)' / Fs * 1000;    % ms

  % ── Plots ─────────────────────────────────────────────────────────────────
  figure('Name', 'Signal synthesis from DFT specification', 'NumberTitle', 'off');

  % --- Magnitude spectrum ---
  ax1 = subplot(3, 1, 1);
  plot(ax1, f_pos / Fs, mag, 'b-', 'LineWidth', 1.8);
  hold(ax1, 'on');
  plot(ax1, [0.10 0.10], [0 1.05], 'k--');
  plot(ax1, [0.25 0.25], [0 1.05], 'k--');
  text(ax1, 0.10, 1.08, 'pole  (0.1 Fs)', 'HorizontalAlignment', 'center', 'FontSize', 8);
  text(ax1, 0.25, 1.08, 'zero  (0.25 Fs)', 'HorizontalAlignment', 'center', 'FontSize', 8);
  hold(ax1, 'off');
  xlim(ax1, [0, 0.5]);
  ylim(ax1, [0, 1.2]);
  xlabel(ax1, 'Normalised frequency  f / Fs');
  ylabel(ax1, '|H(f)|');
  title(ax1, 'Magnitude spectrum');
  grid(ax1, 'on');

  % --- Phase spectrum ---
  ax2 = subplot(3, 1, 2);
  plot(ax2, f_pos / Fs, phi, 'r-', 'LineWidth', 1.8);
  xlim(ax2, [0, 0.5]);
  xlabel(ax2, 'Normalised frequency  f / Fs');
  ylabel(ax2, 'Phase (rad)');
  title(ax2, sprintf('Linear phase  (delay = %d samples = %.1f ms)', delay, delay/Fs*1000));
  grid(ax2, 'on');

  % --- Time-domain signal ---
  ax3 = subplot(3, 1, 3);
  plot(ax3, t, x, 'k-', 'LineWidth', 1.2);
  xlim(ax3, [0, N/Fs*1000]);
  xlabel(ax3, 'Time (ms)');
  ylabel(ax3, 'Amplitude');
  title(ax3, 'Synthesised signal  x(t) = IDFT{ H }');
  grid(ax3, 'on');

end
