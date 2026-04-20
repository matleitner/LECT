% =========================================================================
%  Generate a sinusoidal audio signal and store it in a named variable
%
%  Usage:
%    gen_audio_signal(faudio, fsample, duration)
%
%  Examples:
%    gen_audio_signal(440,  8000,  2.0)
%    gen_audio_signal(1000, 44100, 1.5)
%    gen_audio_signal(3000, 8000,  0.5)
%
%  Each call creates a variable in the workspace named:
%    signal_<faudio>Hz_fs<fsample>
% =========================================================================

function gen_audio_signal(faudio, fsample, duration)

  % ── Generate signal ───────────────────────────────────────────────────────
  t      = (0 : 1/fsample : duration - 1/fsample)';
  signal = sin(2 * pi * faudio * t);

  % ── Store in a named variable in the base workspace ───────────────────────
  varname = sprintf('signal_%dHz_fs%d', faudio, fsample);
  assignin('base', varname, signal);

  % ── Report ────────────────────────────────────────────────────────────────
  fprintf('\nSignal generated:\n');
  fprintf('  Variable name : %s\n', varname);
  fprintf('  Frequency     : %d Hz\n', faudio);
  fprintf('  Sample rate   : %d Hz\n', fsample);
  fprintf('  Duration      : %.2f s\n', duration);
  fprintf('  Num samples   : %d\n', length(signal));
  if faudio >= fsample/2
    fprintf('  WARNING: faudio (%d Hz) >= Nyquist (%d Hz)!\n', faudio, fsample/2);
  end

  % ── Plot first 5 cycles ───────────────────────────────────────────────────
  t_show = min(duration, 5 / faudio);
  n_show = round(t_show * fsample);

  figure('Name', sprintf('Audio signal  %d Hz  @ fs=%d', faudio, fsample), ...
         'NumberTitle', 'off');
  plot(t(1:n_show) * 1000, signal(1:n_show), 'b-', 'LineWidth', 1.2);
  xlabel('Time (ms)');
  ylabel('Amplitude');
  title(sprintf('%s    (showing first %.1f ms)', varname, t_show * 1000));
  grid on;

end
