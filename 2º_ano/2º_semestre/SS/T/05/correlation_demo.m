% =========================================================================
%  Correlation of Two Sinusoidal Signals
%  Signals & Systems — Classroom Demo
%
%  x1 = sin(2*pi*f1*t)   fixed frequency
%  x2 = sin(2*pi*f2*t)   frequency controlled by slider
%
%  Zero-lag correlation:   R = sum( x1 .* x2 )
%
%  Usage:  correlation_demo
% =========================================================================

function correlation_demo()

  % ── Parameters ────────────────────────────────────────────────────────────
  f1      = 5;
  fs      = 1000;
  dur     = 1.0;
  t       = (0 : 1/fs : dur - 1/fs)';

  f2_min  = 1;
  f2_max  = 15;
  f2_init = 3;

  x1 = sin(2*pi*f1*t);

  % Accumulator for the correlation-vs-frequency plot
  % NaN means "not yet visited"
  f2_all = f2_min : f2_max;
  R_all  = NaN(size(f2_all));

  % ── Figure & subplots ─────────────────────────────────────────────────────
  figure('Name', 'Correlation of two sinusoids', 'NumberTitle', 'off');

  ax1 = subplot(4, 1, 1);
  ax2 = subplot(4, 1, 2);
  ax3 = subplot(4, 1, 3);
  ax4 = subplot(4, 1, 4);

  % ── Slider ────────────────────────────────────────────────────────────────
  sld = uicontrol('Style', 'slider', ...
                  'Units', 'normalized', ...
                  'Position', [0.10 0.01 0.60 0.025], ...
                  'Min', f2_min, 'Max', f2_max, 'Value', f2_init, ...
                  'SliderStep', [1/(f2_max-f2_min), 2/(f2_max-f2_min)]);

  uicontrol('Style', 'text', ...
            'Units', 'normalized', ...
            'Position', [0.10 0.038 0.60 0.022], ...
            'String', sprintf('f2  (%d - %d Hz)', f2_min, f2_max), ...
            'HorizontalAlignment', 'center');

  lbl = uicontrol('Style', 'text', ...
                  'Units', 'normalized', ...
                  'Position', [0.73 0.008 0.24 0.038], ...
                  'String', sprintf('f2 = %d Hz', f2_init), ...
                  'FontSize', 11, 'FontWeight', 'bold');

  % ── Plot x1 (static) ──────────────────────────────────────────────────────
  plot(ax1, t, x1, 'b-', 'LineWidth', 1.2);
  xlim(ax1, [0, dur]);
  ylim(ax1, [-1.4, 1.4]);
  xlabel(ax1, 'Time (s)');
  ylabel(ax1, 'Amplitude');
  title(ax1, sprintf('x1 = sin(2pi * %d * t)   [fixed]', f1));
  grid(ax1, 'on');

  % ── Slider callback only (addlistener/PostSet avoided — not reliable) ──────
  set(sld, 'Callback', @(src,~) draw_all(round(get(src,'Value'))));

  draw_all(f2_init);

  % =========================================================================
  function draw_all(f2)
    f2 = max(f2_min, min(f2_max, f2));
    set(sld, 'Value', f2);
    set(lbl, 'String', sprintf('f2 = %d Hz', f2));

    x2      = sin(2*pi*f2*t);
    product = x1 .* x2;
    R       = sum(product);

    % Store this result
    R_all(f2 - f2_min + 1) = R;

    % ── x2 ──────────────────────────────────────────────────────────────────
    cla(ax2);
    plot(ax2, t, x2, 'r-', 'LineWidth', 1.2);
    xlim(ax2, [0, dur]);
    ylim(ax2, [-1.4, 1.4]);
    xlabel(ax2, 'Time (s)');
    ylabel(ax2, 'Amplitude');
    title(ax2, sprintf('x2 = sin(2pi * %d * t)   [variable]', f2));
    grid(ax2, 'on');

    % ── Product x1*x2 (fixed y-axis) ─────────────────────────────────────────
    cla(ax3);
    hold(ax3, 'on');
    area(ax3, t, max(product, 0), 'FaceColor', [0.7 1.0 0.7], 'EdgeColor', 'none');
    area(ax3, t, min(product, 0), 'FaceColor', [1.0 0.7 0.7], 'EdgeColor', 'none');
    plot(ax3, t, product, 'k-', 'LineWidth', 1.0);
    plot(ax3, [0 dur], [0 0], 'k--');
    hold(ax3, 'off');
    xlim(ax3, [0, dur]);
    ylim(ax3, [-1.1, 1.1]);
    xlabel(ax3, 'Time (s)');
    ylabel(ax3, 'x1 * x2');
    title(ax3, sprintf('Product  x1 * x2   (sum = %.2f)', R));
    grid(ax3, 'on');

    % ── Correlation vs frequency (grows as slider is moved) ──────────────────
    visited = ~isnan(R_all);
    cla(ax4);
    hold(ax4, 'on');
    % Draw only the points visited so far
    stem(ax4, f2_all(visited), R_all(visited), 'k', 'LineWidth', 1.4);
    % Highlight current point in red
    plot(ax4, f2, R, 'ro', 'MarkerSize', 10, 'LineWidth', 2.0);
    plot(ax4, [f2_min-0.5, f2_max+0.5], [0 0], 'k--');
    hold(ax4, 'off');
    xlim(ax4, [f2_min-0.5, f2_max+0.5]);
    ylim(ax4, [-600, 600]);   % max = N/2 = fs*dur/2 = 500
    set(ax4, 'XTick', f2_min:f2_max);
    xlabel(ax4, 'f2 (Hz)');
    ylabel(ax4, 'sum( x1 * x2 )');
    title(ax4, 'Correlation  vs  f2   (move slider to reveal)');
    grid(ax4, 'on');

    drawnow;
  end % draw_all

end % correlation_demo
