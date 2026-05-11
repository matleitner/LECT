% ----------------------------------------------------------------------------------------------------
% Sensors and Signals Course Unit, UA/DETI
% Paulo Pedreiras, Pedro Fonseca, Luis Silva
% {pbrp,pf,lems}@ua.pt
%
% Script to evaluate a second-order resonant filter
% H(z) = (z+1)^2 / ((z-p1)(z-p2))
% where p1 and p2 are complex conjugates
%
% Note: the definition of normalized frequency is not unique.
%   Textbooks: often defined as f/fs
%   Software: often defined as w/pi = f/(fs/2)
% ----------------------------------------------------------------------------------------------------

clear all;
close all;
clc;

% Parameters
fs = 1e3;  % Sampling frequency (Hz)
f_res = 0.2 * fs;  % Resonance frequency (Hz)
w_res = 2*pi*f_res/fs;  % Normalized resonance frequency (rad/sample)

% Define pole radius (closer to 1 gives sharper resonance)
p = 0.95; % Pole radii to compare

% Frequency vector for analysis
w = linspace(0, pi, 2000);
f = w * fs / (2*pi);  % Convert to Hz

% Define complex conjugate poles
p1 = p * exp(1j*w_res);
p2 = p * exp(-1j*w_res);

% Calculate the DC gain
z = 1;
numerator = (z + 1).^2;
denominator = (z - p1) .* (z - p2);
DCGain =  denominator ./ numerator;

% Compute the normalized frequency response (i.e. with DC gain = 0 dB)
z = exp(1j*w);
numerator = (z + 1).^2;
denominator = (z - p1) .* (z - p2);
H = DCGain * (numerator ./ denominator);

% Magnitude and phase
H_mag = abs(H);
H_dB = 20*log10(H_mag);
H_phase = angle(H) * 180/pi;  % Convert to degrees

% Find peak (resonance)
[peak_mag, peak_idx] = max(H_mag);
peak_freq = f(peak_idx);
peak_dB = H_dB(peak_idx);

% Find -3dB bandwidth
half_power = peak_dB - 3;
idx_3dB = find(H_dB >= half_power);
if ~isempty(idx_3dB)
  f_lower = f(idx_3dB(1));
  f_upper = f(idx_3dB(end));
  bandwidth = f_upper - f_lower;
  Q_factor = peak_freq / bandwidth;
else
  bandwidth = NaN;
  Q_factor = NaN;
end

% Plot magnitude response (linear)

% Create figure
figure('Position', [100, 100, 1200, 800]);

% Plot magnitude response (dB)
subplot(3,1,1);
plot(f, H_dB, 'b', 'LineWidth', 2);
hold on;
plot(peak_freq, peak_dB, ['b' 'o'], 'MarkerSize', 8, 'MarkerFaceColor', 'b');
plot([f_lower f_upper], [half_power half_power], ['b' '--'], 'LineWidth', 1.5);

% Plot phase response
subplot(3,1,2);
plot(f, H_phase, 'b', 'LineWidth', 2);
hold on;

% Plot pole-zero diagram
subplot(3,1,3);
plot(real(p1), imag(p1), ['b' 'x'], 'MarkerSize', 12, 'LineWidth', 3);
hold on;
plot(real(p2), imag(p2), ['b' 'x'], 'MarkerSize', 12, 'LineWidth', 3);
plot(-1, 0, ['b' 'o'], 'MarkerSize', 10, 'LineWidth', 2);  % Double zero at z=-1

% Print results
fprintf('\n========== Filter with r = %.2f ==========\n', p);
fprintf('Poles: p1 = %.4f + j%.4f, p2 = %.4f - j%.4f\n', ...
            real(p1), imag(p1), real(p2), abs(imag(p2)));
fprintf('Pole magnitude: |p| = %.4f\n', abs(p1));
fprintf('Pole angle: angle(p) = %.4f rad = %.2f degrees\n', angle(p1), angle(p1)*180/pi);
fprintf('Resonance frequency: %.2f Hz (expected: %.2f Hz)\n', peak_freq, f_res);
fprintf('Peak magnitude: %.4f (%.2f dB)\n', peak_mag, peak_dB);
fprintf('Bandwidth (-3dB): %.2f Hz\n', bandwidth);
fprintf('Quality factor Q: %.2f\n', Q_factor);
fprintf('==========================================\n');


% Finalize subplot 1 (Magnitude - dB)
subplot(3,1,1);
grid on;
xlabel('Frequency (Hz)', 'FontSize', 11);
ylabel('Magnitude (dB)', 'FontSize', 11);
title('Magnitude Response (dB)', 'FontSize', 12, 'FontWeight', 'bold');
xlim([0 fs/2]);
ylim([-40 max(H_dB)+5]);

% Finalize subplot 2 (Phase)
subplot(3,1,2);
grid on;
xlabel('Frequency (Hz)', 'FontSize', 11);
ylabel('Phase (degrees)', 'FontSize', 11);
title('Phase Response', 'FontSize', 12, 'FontWeight', 'bold');
xlim([0 fs/2]);

% Finalize subplot 3 (Pole-Zero)
subplot(3,1,3);
% Draw unit circle
theta = linspace(0, 2*pi, 100);
plot(cos(theta), sin(theta), 'k--', 'LineWidth', 1);
hold on;
plot([-1.5 1.5], [0 0], 'k-', 'LineWidth', 0.5);
plot([0 0], [-1.5 1.5], 'k-', 'LineWidth', 0.5);
axis equal;
grid on;
xlabel('Real Part', 'FontSize', 11);
ylabel('Imaginary Part', 'FontSize', 11);
title('Pole-Zero Diagram', 'FontSize', 12, 'FontWeight', 'bold');
xlim([-1.2 1.2]);
ylim([-1.2 1.2]);
