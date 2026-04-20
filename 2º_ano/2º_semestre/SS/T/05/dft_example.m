% =========================================================================
%  DFT example: rectangular pulse
%  Shows  x[n]  <-->  X[k]  and recovers x[n] via IDFT
%
%  The signal is a rectangular pulse of length L inside an N-point window.
%  Analytic DFT (for verification):
%
%    X[k] = sum_{n=0}^{L-1} e^{-j 2pi k n / N}
%           = e^{-j pi k (L-1)/N}  *  sin(pi k L/N) / sin(pi k/N)
%
%  Usage:  dft_example
% =========================================================================

function dft_example()

  % ── Parameters ────────────────────────────────────────────────────────────
  N = 32;    % DFT size (number of samples)
  L = 8;     % pulse length (samples)
  n = 0:N-1; % sample index

  % ── Time-domain signal ────────────────────────────────────────────────────
  x        = zeros(1, N);
  x(1:L)   = 1;            % pulse at n = 0 .. L-1

  % ── DFT (direct) ──────────────────────────────────────────────────────────
  X   = fft(x);

  % Positive frequencies: bins 0 .. N/2
  bins = 0 : N/2;
  Xp   = X(bins + 1);
  mag  = abs(Xp);
  ph   = angle(Xp);

  % Real and imaginary parts (cosine/sine coefficients, unscaled)
  ReX =  real(X);
  ImX = -imag(X);   % note: fft uses exp(-j...), so sine coeff = -imag

  % ── IDFT (inverse) — recover x[n] ─────────────────────────────────────────
  x_rec = real(ifft(X));   % real() discards numerical noise (~1e-15)

  % ── Reconstruction error ──────────────────────────────────────────────────
  err = max(abs(x - x_rec));
  fprintf('\nDFT/IDFT round-trip max error: %.2e  (numerical noise)\n', err);

  % =========================================================================
  figure('Name', 'DFT example: rectangular pulse  x[n] <-> X[k]', ...
         'NumberTitle', 'off');

  % (a) x[n] — time domain
  subplot(4, 2, [1 2]);
  stem(n, x, 'k', 'filled', 'MarkerSize', 4);
  xlim([-1, N]);
  ylim([-0.2, 1.4]);
  xlabel('n  (sample index)');
  ylabel('x[n]');
  title(sprintf('(a)  x[n]: rectangular pulse,  L = %d,  N = %d', L, N));
  grid on;

  % (b) Re X[k]
  subplot(4, 2, 3);
  stem(bins, ReX(bins+1), 'b', 'filled', 'MarkerSize', 4);
  xlim([-1, N/2+1]);
  xlabel('k');  ylabel('Re X[k]');
  title('(b)  Real part of X[k]  (cosine coefficients)');
  grid on;

  % (c) Im X[k]  (note: plotted as -imag = sine coeff)
  subplot(4, 2, 4);
  stem(bins, ImX(bins+1), 'r', 'filled', 'MarkerSize', 4);
  xlim([-1, N/2+1]);
  xlabel('k');  ylabel('-Im X[k]');
  title('(c)  Imaginary part of X[k]  (sine coefficients, negated)');
  grid on;

  % (d) Magnitude |X[k]|
  subplot(4, 2, 5);
  stem(bins, mag, 'k', 'filled', 'MarkerSize', 4);
  xlim([-1, N/2+1]);
  xlabel('k');  ylabel('|X[k]|');
  title('(d)  Magnitude spectrum  |X[k]|');
  grid on;

  % (e) Phase angle(X[k])
  subplot(4, 2, 6);
  stem(bins, ph, 'k', 'filled', 'MarkerSize', 4);
  xlim([-1, N/2+1]);
  ylim([-pi-0.3, pi+0.3]);
  set(gca, 'YTick', [-pi -pi/2 0 pi/2 pi], ...
           'YTickLabel', {'-pi','-pi/2','0','pi/2','pi'});
  xlabel('k');  ylabel('angle X[k]  (rad)');
  title('(e)  Phase spectrum  angle(X[k])  — wrapped to [-pi, pi]');
  grid on;

  % (f) x_rec[n] = IDFT{X[k]}  — should be identical to x[n]
  subplot(4, 2, [7 8]);
  stem(n, x_rec, 'k', 'filled', 'MarkerSize', 4);
  xlim([-1, N]);
  ylim([-0.2, 1.4]);
  xlabel('n  (sample index)');
  ylabel('x_{rec}[n]');
  title(sprintf('(f)  x_{rec}[n] = IDFT{X[k]}   — max error vs x[n]: %.1e', err));
  grid on;

end
