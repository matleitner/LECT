% =========================================================================
%  Fourier Series Approximation of a Square Wave
%  Signals & Systems — Classroom Demo
%
%  Usage:  fourier_square_wave
% =========================================================================

function fourier_square_wave()

  N_max = 50;
  t     = linspace(0, 4*pi, 2000);

  % Ideal square wave (period 2pi, amplitude +-1)
  sq_ideal = sign(sin(t));
  sq_ideal(sq_ideal == 0) = 1;

  % Spectrum: harmonic orders 1, 2, 3, ..., 2*N_max-1
  % Even orders have zero amplitude; odd orders have amplitude 4/(n*pi)
  harm_orders = 1:(2*N_max-1);
  amp_all     = zeros(size(harm_orders));
  amp_all(1:2:end) = (4/pi) ./ harm_orders(1:2:end);

  % ── Figure with two subplots ──────────────────────────────────────────────
  figure('Name', 'Fourier Series — Square Wave', 'NumberTitle', 'off');

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
    for k = 1:N
      m         = 2*k - 1;
      comp      = (4/pi) * sin(m*t) / m;
      approx    = approx + comp;
      sins(k,:) = comp;
    end

    % ── Waveform panel ───────────────────────────────────────────────────────
    cla(ax_wave);
    hold(ax_wave, 'on');

    % Individual sinusoids (thin blue, only for small N)
    if N <= 12
      for k = 1:N
        plot(ax_wave, t, sins(k,:), 'b-', 'LineWidth', 0.8);
      end
    end

    % Ideal square wave (dashed black)
    plot(ax_wave, t, sq_ideal, 'k--', 'LineWidth', 1.5);

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
                           N, repmat('s',1,N>1), 2*N-1));
    if N <= 12
      legend(ax_wave, [repmat({''},1,N), {'Ideal square wave','Fourier approx.'}], ...
             'Location', 'northeast');
    else
      legend(ax_wave, {'Ideal square wave','Fourier approx.'}, ...
             'Location', 'northeast');
    end
    grid(ax_wave, 'on');

    % ── Spectrum panel ───────────────────────────────────────────────────────
    highest = 2*N - 1;   % highest active harmonic order

    cla(ax_spec);
    hold(ax_spec, 'on');

    % All bars in grey first
    bar(ax_spec, harm_orders, amp_all, 0.6, ...
        'FaceColor', [0.75 0.75 0.75], 'EdgeColor', 'none');

    % Overplot active odd orders in red
    active_orders = 1:2:highest;
    active_amps   = (4/pi) ./ active_orders;
    bar(ax_spec, active_orders, active_amps, 0.6, ...
        'FaceColor', 'r', 'EdgeColor', 'none');

    hold(ax_spec, 'off');
    xlim(ax_spec, [0, 2*N_max]);
    ylim(ax_spec, [0, (4/pi)*1.1]);
    xlabel(ax_spec, 'Harmonic order n');
    ylabel(ax_spec, 'Amplitude  4/(n*pi)');
    title(ax_spec, 'Harmonic spectrum  (even harmonics are zero)');
    grid(ax_spec, 'on');

    drawnow;
  end % draw_all

end % fourier_square_wave
