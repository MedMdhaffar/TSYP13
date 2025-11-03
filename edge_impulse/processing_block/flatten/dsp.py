import argparse, sys
import json
import numpy as np
from scipy.stats import skew, kurtosis as calculateKurtosis
from scipy import signal as sig

# === Helper functions ===

def number_of_peaks_finding(array):

    prominence = 0.1 * (np.max(array) - np.min(array))
    peaks = sig.find_peaks(array, prominence=prominence)[0]
    return len(peaks)

def smooth10_n_peaks(array):
    kernel = np.ones(10) / 10
    array_convolved = np.convolve(array, kernel, mode="same")
    return number_of_peaks_finding(array_convolved)

def smooth20_n_peaks(array):
    kernel = np.ones(20) / 20
    array_convolved = np.convolve(array, kernel, mode="same")
    return number_of_peaks_finding(array_convolved)

def diff_peaks_counts(array):
    if array.size < 2:
        return 0
    array_diff = np.diff(array)
    if array_diff.size == 0:
        return 0
    return number_of_peaks_finding(array_diff)

def diff_var(array):
    array_diff = np.diff(array)
    return np.var(array_diff)


# === Main feature generator ===

def generate_features(implementation_version, draw_graphs, raw_data, axes, sampling_freq, scale_axes,
                       mean, variance, skewness, kurtosis,
                      n_peaks, smooth10_peaks, smooth20_peaks, diff_peaks, diff_variance):

    if implementation_version != 1:
        raise Exception('implementation_version should be 1')

    raw_data = raw_data * scale_axes
    raw_data = raw_data.reshape(int(len(raw_data) / len(axes)), len(axes))

    features = []
    labels = []


    # Per-axis features
    for ax in range(len(axes)):
        X = raw_data[:, ax]

        if mean:
            features.append(float(np.mean(X)))
            labels.append(f'{axes[ax]} Mean')

        if variance:
            features.append(float(np.var(X)))
            labels.append(f'{axes[ax]} Variance')

        if kurtosis:
            features.append(float(calculateKurtosis(X)))
            labels.append(f'{axes[ax]} Kurtosis')

        if skewness:
            features.append(float(skew(X)))
            labels.append(f'{axes[ax]} Skewness')

        if n_peaks:
            features.append(float(number_of_peaks_finding(X)))
            labels.append(f'{axes[ax]} Number of Peaks')

        if smooth10_peaks:
            features.append(float(smooth10_n_peaks(X)))
            labels.append(f'{axes[ax]} Smoothed(10) Peaks')

        if smooth20_peaks:
            features.append(float(smooth20_n_peaks(X)))
            labels.append(f'{axes[ax]} Smoothed(20) Peaks')

        if diff_peaks:
            features.append(float(diff_peaks_counts(X)))
            labels.append(f'{axes[ax]} Diff Peaks')

        if diff_variance:
            features.append(float(diff_var(X)))
            labels.append(f'{axes[ax]} Diff Variance')



    return {
        'features': features,
        'graphs': [],
        'labels': labels,
        'fft_used': [],
        'output_config': {'type': 'flat', 'shape': {'width': len(features)}}
    }

# === CLI entry point ===

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Flatten script for raw data')
    parser.add_argument('--features', type=str, required=True,
                        help='Axis data as a flattened array of values (comma-separated)')
    parser.add_argument('--axes', type=str, required=True,
                        help='Names of the axes (comma-separated)')
    parser.add_argument('--frequency', type=float, required=True,
                        help='Sampling frequency in Hz')
    parser.add_argument('--scale-axes', type=float, default=1,
                        help='Scale axes (multiplies by this number, default: 1)')
    parser.add_argument('--draw-graphs', type=lambda x: (str(x).lower() in ['true', '1', 'yes']), required=True,
                        help='Whether to draw graphs')

    # Optional feature toggles
    parser.add_argument('--mean', type=lambda x: (str(x).lower() in ['true', '1', 'yes']), default=True)
    parser.add_argument('--variance', type=lambda x: (str(x).lower() in ['true', '1', 'yes']), default=True)
    parser.add_argument('--skewness', type=lambda x: (str(x).lower() in ['true', '1', 'yes']), default=True)
    parser.add_argument('--kurtosis', type=lambda x: (str(x).lower() in ['true', '1', 'yes']), default=True)
    parser.add_argument('--n-peaks', type=lambda x: (str(x).lower() in ['true', '1', 'yes']), default=False)
    parser.add_argument('--smooth10-peaks', type=lambda x: (str(x).lower() in ['true', '1', 'yes']), default=False)
    parser.add_argument('--smooth20-peaks', type=lambda x: (str(x).lower() in ['true', '1', 'yes']), default=False)
    parser.add_argument('--diff-peaks', type=lambda x: (str(x).lower() in ['true', '1', 'yes']), default=False)
    parser.add_argument('--diff-variance', type=lambda x: (str(x).lower() in ['true', '1', 'yes']), default=False)

    args = parser.parse_args()

    # Prepare data
    raw_features = np.array([float(item.strip()) for item in args.features.split(',')])
    raw_axes = args.axes.split(',')


    try:
        processed = generate_features(
            implementation_version=1,
            draw_graphs=args.draw_graphs,
            raw_data=raw_features,
            axes=raw_axes,
            sampling_freq=args.frequency,
            scale_axes=args.scale_axes,
            mean=args.mean,
            variance=args.variance,
            skewness=args.skewness,
            kurtosis=args.kurtosis,
            n_peaks=args.n_peaks,
            smooth10_peaks=args.smooth10_peaks,
            smooth20_peaks=args.smooth20_peaks,
            diff_peaks=args.diff_peaks,
            diff_variance=args.diff_variance,
        )

        print('Begin output')
        print(json.dumps(processed))
        print('End output')
    except Exception as e:
        print(e, file=sys.stderr)
        exit(1)
