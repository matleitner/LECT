% =========================================================================
%  Fourier Series Approximation of a Sawtooth Wave
%  Signals & Systems — Classroom Demo
%
%  The sawtooth wave has ALL harmonics (odd and even):
%
%    f(t) = (2/pi) * sum_{n=1}^{N} (-1)^(n+1) * sin(n*t) / n
%
%  Compare with the square wave, which has only odd harmonics.
%
%  Usage:  fourier_sawtooth
% =========================================================================

function fourier_sawtooth()

  N_max = 50;
  t     = linspace(0, 4*pi, 2000);

  % Ideal sawtooth wave (period 2pi, amplitude -1 to +1)
  % Shifted by half a period so f(0)=0, matching the sine series (all sines are zero at t=0)
  saw_ideal = mod(t + pi, 2*pi) / pi - 1;

  % Spectrum: ALL harmonic orders 1..N_max are present
  harm_orders = 1:N_max;
  amp_all     = (2/pi) ./ harm_orders;   % coefficient magnitude for order n

  % ── Figure ───────────────────────────────────────────────────────────────
  figure('Name', 'Fourier Series — Sawtooth Wave', 'NumberTitle', 'off');

  ax_wave = subplot(2, 1, 1);
  ax_spec = subplot(2, 1, 2);

  % ── Slider ────────────────────────────────────────────────────────────────
  sld = uicontrol('Style', 'slider', ...
                  'Units', 'normalized', ...
                  'Position', [0.10 0.01 0.70 0.03], ...
                  'Min', 1, 'Max', N_max, 'Value', 1, ...
                  'SliderStep', [1/(N_max-1), 5/(N_max-1)]);

  lbl = uicontrol('Style', 'text', ...
                  'Units', 'normalized', ...
                  'Position', [0.82 0.005 0.15 0.035], ...
                  'String', 'N = 1', ...
                  'FontSize', 10, 'FontWeight', 'bold');

  % ── Callbacks ─────────────────────────────────────────────────────────────
  set(sld, 'Callback', @(src,~) draw_all(round(get(src,'Value'))));
  addlistener(sld, 'Value', 'PostSet', ...
              @(~,~) draw_all(round(get(sld,'Value'))));

  draw_all(1);

  % =========================================================================
  function draw_all(N)
    N = max(1, min(N_max, N));
    set(sld, 'Value', N);
    set(lbl, 'String', sprintf('N = %d', N));

    % Build Fourier approximation and individual sinusoids
    approx = zeros(size(t));
    sins   = zeros(N, length(t));
    for n = 1:N
      comp      = (2/pi) * (-1)^(n+1) * sin(n*t) / n;
      approx    = approx + comp;
      sins(n,:) = comp;
    end

    % ── Waveform panel ───────────────────────────────────────────────────────
    cla(ax_wave);
    hold(ax_wave, 'on');

    % Individual sinusoids (thin blue, only for small N)
    if N <= 12
      for n = 1:N
        plot(ax_wave, t, sins(n,:), 'b-', 'LineWidth', 0.8);
      end
    end

    % Ideal sawtooth (dashed black)
    plot(ax_wave, t, saw_ideal, 'k--', 'LineWidth', 1.5);

    % Fourier approximation (solid red, thicker)
    plot(ax_wave, t, approx, 'r-', 'LineWidth', 2.0);

    hold(ax_wave, 'off');
    xlim(ax_wave, [0, 4*pi]);
    ylim(ax_wave, [-1.6, 1.6]);
    set(ax_wave, 'XTick', (0:4)*pi, ...
                 'XTickLabel', {'0','pi','2pi','3pi','4pi'});
    xlabel(ax_wave, 'Time (rad)');
    ylabel(ax_wave, 'Amplitude');
    title(ax_wave, sprintf('Fourier approximation: N = %d term%s (up to harmonic order %d)', ...
                           N, repmat('s',1,N>1), N));
    if N <= 12
      legend(ax_wave, [repmat({''},1,N), {'Ideal sawtooth','Fourier approx.'}], ...
             'Location', 'northeast');
    else
      legend(ax_wave, {'Ideal sawtooth','Fourier approx.'}, ...
             'Location', 'northeast');
    end
    grid(ax_wave, 'on');

    % ── Spectrum panel ───────────────────────────────────────────────────────
    cla(ax_spec);
    hold(ax_spec, 'on');

    % Inactive harmonics (grey)
    if N < N_max
      bar(ax_spec, harm_orders(N+1:end), amp_all(N+1:end), 0.6, ...
          'FaceColor', [0.75 0.75 0.75], 'EdgeColor', 'none');
    end

    % Active harmonics (red) — all orders 1..N
    bar(ax_spec, harm_orders(1:N), amp_all(1:N), 0.6, ...
        'FaceColor', 'r', 'EdgeColor', 'none');

    hold(ax_spec, 'off');
    xlim(ax_spec, [0, N_max+1]);
    ylim(ax_spec, [0, (2/pi)*1.1]);
    xlabel(ax_spec, 'Harmonic order n');
    ylabel(ax_spec, 'Amplitude  2/(n*pi)');
    title(ax_spec, 'Harmonic spectrum  (all harmonics are present)');
    grid(ax_spec, 'on');

    drawnow;
  end % draw_all

end % fourier_sawtooth
