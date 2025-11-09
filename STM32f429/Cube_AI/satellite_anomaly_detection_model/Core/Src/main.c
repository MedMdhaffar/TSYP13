/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

#include "ai_platform.h"
#include "network.h"
#include "network_data.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

// Array containing the floating-point data
float rawData[] = {
    -3.76e-05f, -3.77e-05f, -3.84e-05f, -3.73e-05f, -3.77e-05f,
    -3.78e-05f, -3.76e-05f, -3.70e-05f, -3.70e-05f, -3.67e-05f,
    -3.65e-05f, -3.62e-05f, -3.52e-05f, -3.65e-05f, -3.56e-05f,
    -3.60e-05f, -3.51e-05f, -3.61e-05f, -3.56e-05f, -3.55e-05f,
    -3.49e-05f, -3.45e-05f, -3.44e-05f, -3.43e-05f, -3.30e-05f,
    -3.38e-05f, -3.33e-05f, -3.30e-05f, -3.26e-05f, -3.15e-05f,
    -3.20e-05f, -3.09e-05f, -3.12e-05f, -3.12e-05f, -3.08e-05f,
    -3.05e-05f, -3.04e-05f, -3.02e-05f, -3.01e-05f, -3.05e-05f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    -2.80e-05f, -6.00e-06f, -5.04e-06f, -4.34e-06f, -3.79e-06f,
    -3.51e-06f, -3.23e-06f, -3.09e-06f, -2.39e-06f, -1.70e-06f,
    -1.42e-06f, -1.56e-06f, -3.14e-07f, 6.6387e-07f, 6.64132e-07f,
    1.22028e-06f, 1.91408e-06f, 1.91355e-06f, 3.58095e-06f, 3.02428e-06f,
    3.45297e-06f, 3.58262e-06f, 4.83743e-06f, 5.11424e-06f, 5.66862e-06f,
    6.08596e-06f, 6.78112e-06f, 6.78242e-06f, 7.61518e-06f, 7.61952e-06f,
    7.89456e-06f, 8.32403e-06f, 8.04298e-06f, 9.56912e-06f, 9.56786e-06f,
    9.28592e-06f, 9.98672e-06f, 9.70838e-06f, 1.01289e-05f, 1.15204e-05f,
    1.13781e-05f, 1.15195e-05f, 1.19392e-05f, 1.34649e-05f, 1.33294e-05f,
    1.24978e-05f, 1.26381e-05f, 1.34772e-05f, 1.40319e-05f, 1.4316e-05f,
    1.47308e-05f, 1.5422e-05f, 1.59819e-05f, 1.6123e-05f, 1.63986e-05f,
    1.62642e-05f, 1.75129e-05f, 1.7516e-05f, 1.73867e-05f, 1.83564e-05f,
    1.83647e-05f, 1.89173e-05f, 1.8919e-05f, 1.93373e-05f, 1.96137e-05f,
    2.00382e-05f, 2.10109e-05f, 2.03187e-05f, 2.10118e-05f, 2.07378e-05f,
    2.17092e-05f, 2.15757e-05f, 2.22714e-05f, 2.20011e-05f, 2.25592e-05f,
    2.29745e-05f, 2.36662e-05f, 2.32626e-05f, 2.32579e-05f, 2.38146e-05f,
    2.40978e-05f, 2.40953e-05f, 2.4517e-05f, 2.5631e-05f, 2.5638e-05f,
    2.56397e-05f, 2.53599e-05f, 2.5777e-05f, 2.64747e-05f, 2.59233e-05f,
    2.70339e-05f, 2.73123e-05f, 2.63418e-05f, 2.7183e-05f, 2.76028e-05f,
    2.74638e-05f, 2.67724e-05f, 2.85761e-05f, 2.73296e-05f, 2.85801e-05f,
    2.81719e-05f, 2.81727e-05f, 2.83126e-05f, 2.80429e-05f, 2.77651e-05f,
    2.84584e-05f, 2.88727e-05f, 2.81841e-05f, 2.79066e-05f, 2.88823e-05f,
    2.86057e-05f, 2.76337e-05f, 2.80546e-05f, 2.90321e-05f, 2.86118e-05f,
    2.84818e-05f, 2.83446e-05f, 2.86252e-05f, 2.79233e-05f, 2.91807e-05f,
    2.79313e-05f, 2.75183e-05f, 2.82181e-05f, 2.78024e-05f, 2.82245e-05f,
    2.82234e-05f, 2.76722e-05f, 2.80931e-05f, 2.83717e-05f, 2.79604e-05f,
    2.75422e-05f, 2.78267e-05f, 2.8239e-05f, 2.72692e-05f, 2.74091e-05f,
    2.71351e-05f, 2.74156e-05f, 2.71388e-05f, 2.64462e-05f, 2.74217e-05f,
    2.70042e-05f, 2.67258e-05f, 2.67324e-05f, 2.57584e-05f, 2.58978e-05f,
    2.56226e-05f, 2.63222e-05f, 2.47923e-05f, 2.53487e-05f, 2.48018e-05f,
    2.45232e-05f, 2.52121e-05f, 2.47932e-05f, 2.46685e-05f, 2.42504e-05f,
    2.35537e-05f, 2.34164e-05f, 2.32805e-05f, 2.35618e-05f, 2.3839e-05f,
    2.31458e-05f, 2.30079e-05f, 2.2727e-05f, 2.21787e-05f, 2.27315e-05f,
    2.23086e-05f, 2.18957e-05f, 2.18968e-05f, 2.19007e-05f, 2.1488e-05f,
    2.09326e-05f, 2.12042e-05f, 2.01017e-05f, 2.0237e-05f, 2.02441e-05f,
    2.00974e-05f, 1.98199e-05f, 2.01009e-05f, 1.99577e-05f, 1.95496e-05f,
    1.94141e-05f, 1.89923e-05f, 1.95421e-05f, 1.91305e-05f, 1.89929e-05f,
    1.88536e-05f, 1.87164e-05f, 1.87173e-05f, 1.85781e-05f, 1.8576e-05f,
    1.7883e-05f, 1.74631e-05f, 1.78817e-05f, 1.74646e-05f, 1.77441e-05f,
    1.70488e-05f, 1.70442e-05f, 1.67674e-05f, 1.71845e-05f, 1.64952e-05f,
    1.51041e-05f, 1.6632e-05f, 1.66241e-05f, 1.64902e-05f, 1.62086e-05f,
    1.62089e-05f, 1.59312e-05f, 1.63487e-05f, 1.66221e-05f, 1.64865e-05f,
    1.5655e-05f, 1.64835e-05f, 1.66182e-05f, 1.64781e-05f, 1.60627e-05f,
    1.66171e-05f, 1.63398e-05f, 1.57838e-05f, 1.67547e-05f, 1.68969e-05f,
    1.64744e-05f, 1.67519e-05f, 1.6749e-05f, 1.5777e-05f, 1.73028e-05f,
    1.73015e-05f, 1.7021e-05f, 1.68839e-05f, 1.79927e-05f, 1.84113e-05f,
    1.78568e-05f, 1.79882e-05f, 1.85431e-05f, 1.89595e-05f, 1.95187e-05f,
    1.89541e-05f, 1.93764e-05f, 1.96504e-05f, 2.06165e-05f, 2.06178e-05f,
    2.07573e-05f, 2.11648e-05f, 2.2003e-05f, 2.14433e-05f, 2.18647e-05f,
    2.19994e-05f, 2.22739e-05f, 2.32465e-05f, 2.36574e-05f, 2.40831e-05f,
    2.36542e-05f, 2.40742e-05f, 2.42122e-05f, 2.50419e-05f, 2.51802e-05f,
    2.57393e-05f, 2.55955e-05f, 2.71233e-05f, 2.55878e-05f, 2.71137e-05f,
    2.69752e-05f, 2.68297e-05f, 2.69669e-05f, 2.76604e-05f, 2.73814e-05f,
    2.83543e-05f, 2.79295e-05f, 2.91814e-05f, 2.9179e-05f, 2.89e-05f,
    2.98739e-05f, 3.01432e-05f, 3.06978e-05f, 3.04215e-05f, 3.12506e-05f,
    3.09671e-05f, 3.09679e-05f, 3.20782e-05f, 3.22205e-05f, 3.26293e-05f,
    3.16546e-05f, 3.26208e-05f, 3.38768e-05f, 3.41507e-05f, 3.38687e-05f,
    3.48433e-05f, 3.52539e-05f, 3.49787e-05f, 3.48425e-05f, 3.62163e-05f,
    3.58049e-05f, 3.66361e-05f, 3.70515e-05f, 3.64964e-05f, 3.70459e-05f,
    3.81546e-05f, 3.80154e-05f, 3.87071e-05f, 3.87012e-05f, 3.84226e-05f,
    3.92567e-05f, 3.91116e-05f, 3.98101e-05f, 3.98085e-05f, 4.02177e-05f,
    4.02126e-05f, 4.1041e-05f, 4.04896e-05f, 4.07668e-05f, 4.10434e-05f,
    4.18756e-05f, 4.09006e-05f, 4.11745e-05f, 4.20024e-05f, 4.24229e-05f,
    4.24204e-05f, 4.21374e-05f, 4.29683e-05f, 4.26904e-05f, 4.29644e-05f,
    4.32393e-05f, 4.26832e-05f, 4.32349e-05f, 4.33773e-05f, 4.3373e-05f,
    4.37914e-05f, 4.37838e-05f, 4.36446e-05f, 4.47513e-05f, 4.34968e-05f,
    4.46053e-05f, 4.405e-05f, 4.40499e-05f, 4.39086e-05f, 4.39059e-05f,
    4.33474e-05f, 4.3347e-05f, 4.37623e-05f, 4.30603e-05f, 4.3063e-05f,
    4.25063e-05f, 4.30555e-05f, 4.31986e-05f, 4.26413e-05f, 4.27753e-05f,
    4.23545e-05f, 4.20807e-05f, 4.20776e-05f, 4.12398e-05f, 4.08243e-05f,
    4.08206e-05f, 4.15113e-05f, 4.06759e-05f, 4.12337e-05f, 4.08124e-05f,
    4.02573e-05f, 4.10867e-05f, 4.03872e-05f, 3.99682e-05f, 4.0113e-05f,
    3.9413e-05f, 3.77459e-05f, 3.89919e-05f, 3.85734e-05f, 3.81592e-05f,
    3.77378e-05f, 3.78729e-05f, 3.70428e-05f, 3.73151e-05f, 3.60639e-05f,
    3.64792e-05f, 3.59192e-05f, 3.52279e-05f, 3.52267e-05f, 3.42463e-05f,
    3.41102e-05f, 3.24415e-05f, 3.28588e-05f, 3.20237e-05f, 3.31341e-05f,
    3.11903e-05f, 3.10438e-05f, 3.11836e-05f, 3.04845e-05f, 2.95115e-05f,
    2.93728e-05f, 2.85393e-05f, 2.81221e-05f, 2.72834e-05f, 2.72868e-05f,
    2.70062e-05f, 2.54713e-05f, 2.50597e-05f, 2.39433e-05f, 2.32525e-05f,
    2.31087e-05f, 2.22741e-05f, 2.15776e-05f, 2.07427e-05f, 1.94876e-05f,
    1.87901e-05f, 1.89295e-05f, 1.76798e-05f, 1.75345e-05f, 1.61443e-05f,
    1.44763e-05f, 1.51705e-05f, 1.35069e-05f, 1.29456e-05f, 1.25288e-05f,
    1.14172e-05f, 1.00273e-05f, 1.00206e-05f, 8.07553e-06f, 7.94013e-06f,
    6.54714e-06f, 5.57261e-06f, 5.43312e-06f, 4.59629e-06f, 3.34969e-06f,
    1.81895e-06f, 1.95577e-06f, 9.85418e-07f, 8.37774e-07f, -9.63e-07f,
    -1.52e-06f, -2.91e-06f, -3.05e-06f, -4.17e-06f, -4.72e-06f,
    -5.97e-06f, -6.80e-06f, -7.23e-06f, -7.78e-06f, -8.33e-06f,
    -9.59e-06f, -1.01e-05f, -1.14e-05f, -1.25e-05f, -1.26e-05f,
    -1.39e-05f, -1.49e-05f, -1.54e-05f, -1.60e-05f, -1.70e-05f,
    -1.79e-05f, -1.90e-05f, -1.96e-05f, -2.03e-05f, -2.09e-05f,
    -2.15e-05f, -2.21e-05f, -2.28e-05f, -2.43e-05f, -2.42e-05f,
    -2.52e-05f, -2.63e-05f, -2.61e-05f, -2.73e-05f, -2.78e-05f,
    -2.86e-05f, -2.99e-05f, -2.99e-05f, -3.02e-05f, -3.13e-05f,
    -3.16e-05f, -3.25e-05f, -3.25e-05f, -3.32e-05f, -3.31e-05f,
    -3.32e-05f, -3.48e-05f, -3.48e-05f, -3.50e-05f, -3.60e-05f,
    -3.67e-05f, -3.71e-05f, -3.70e-05f, -3.81e-05f, -3.88e-05f,
    -3.85e-05f, -3.91e-05f, -3.91e-05f, -3.94e-05f, -3.99e-05f,
    -4.02e-05f, -4.05e-05f, -4.12e-05f, -4.03e-05f, -4.14e-05f,
    -4.09e-05f, -4.12e-05f, -4.13e-05f, -4.14e-05f, -4.10e-05f,
    -4.14e-05f, -4.17e-05f
};



uint32_t timestamps[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14,
    14, 15, 16, 17, 19, 19, 20, 21, 22, 24, 24, 25, 26, 27,
    29, 29, 30, 31, 32, 34, 34, 35, 36, 37, 39, 39, 40, 41,
    42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55,
    56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
    84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97,
    99, 99, 100, 101, 102, 104, 104, 105, 106, 107, 109, 109, 110, 111,
    112, 114, 114, 115, 116, 117, 119, 119, 120, 121, 122, 124, 124, 125,
    126, 127, 129, 129, 130, 131, 132, 134, 134, 135, 136, 137, 139, 139,
    140, 141, 142, 144, 144, 145, 146, 147, 149, 149, 150, 151, 152, 154,
    154, 155, 156, 157, 159, 159, 160, 161, 162, 164, 164, 165, 166, 167,
    169, 169, 170, 171, 172, 174, 174, 175, 176, 177, 179, 179, 180, 181,
    182, 184, 184, 185, 186, 187, 189, 189, 190, 191, 192, 194, 194, 195,
    196, 197, 199, 199, 200, 201, 202, 204, 204, 205, 206, 207, 209, 209,
    210, 211, 212, 214, 214, 215, 216, 217, 219, 219, 220, 221, 222, 224,
    224, 225, 226, 227, 229, 229, 230, 231, 232, 234, 234, 235, 236, 237,
    239, 239, 240, 241, 242, 244, 244, 245, 246, 247, 249, 249, 250, 251,
    252, 254, 254, 255, 256, 257, 258, 259, 260, 261, 262, 264, 264, 265,
    266, 267, 269, 269, 270, 271, 272, 274, 274, 275, 276, 277, 279, 279,
    280, 281, 282, 284, 284, 285, 286, 287, 289, 409, 410, 411, 412, 414,
    414, 415, 416, 417, 419, 419, 420, 421, 422, 424, 424, 425, 426, 427,
    429, 429, 430, 431, 432, 434, 434, 435, 436, 437, 439, 439, 440, 441,
    442, 444, 444, 445, 446, 447, 449, 449, 450, 451, 452, 454, 454, 455,
    456, 457, 459, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469,
    470, 471, 472, 474, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483,
    484, 485, 486, 487, 489, 489, 490, 491, 492, 493, 494, 495, 496, 497,
    498, 499, 500, 501, 502, 504, 504, 505, 506, 507, 509, 509, 510, 511,
    512, 513, 514, 515, 516, 517, 519, 519, 520, 521, 522, 523, 524, 525,
    526, 527, 528, 529, 530, 531, 532, 534, 534, 535, 536, 537, 538, 539,
    540, 541, 542, 543, 544, 545, 546, 547, 549, 549, 550, 551, 552, 553,
    554, 555, 556, 557, 558, 559, 560, 561, 562, 564, 564, 565, 566, 567,
    568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 579, 579, 580, 581,
    582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 594, 594
};
uint32_t DATA_LENGTH = sizeof(rawData)/sizeof(rawData[0]);
//feature extraction functions
uint64_t gaps_squared(uint32_t *timestamps, uint32_t length) {
    uint64_t sum = 0;
    for (uint32_t i = 1; i < length; i++) {
        uint32_t delta = timestamps[i] - timestamps[i - 1];
        sum += (uint64_t)delta * (uint64_t)delta;
    }
    return sum;
}

// Compute max-min based prominence
float compute_prominence(const float *arr, uint32_t len) {
    float mn = arr[0], mx = arr[0];
    for (uint32_t i = 1; i < len; i++) {
        if (arr[i] < mn) mn = arr[i];
        if (arr[i] > mx) mx = arr[i];
    }
    return 0.1f * (mx - mn);
}

// Count peaks
uint32_t count_peaks(const float *arr, uint32_t len) {
    float prom = compute_prominence(arr, len);
    uint32_t count = 0;

    for (uint32_t i = 1; i < len - 1; i++) {
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            if ((arr[i] - arr[i-1] > prom) || (arr[i] - arr[i+1] > prom))
                count++;
        }
    }
    return count;
}

// Convolve with uniform kernel of size N
void smooth(const float *src, float *dst, uint32_t len, uint32_t window) {
    float scale = 1.0f / (float)window;

    for (uint32_t i = 0; i < len; i++) {
        float sum = 0.0f;
        int32_t start = (int32_t)i - (window / 2);
        int32_t end   = (int32_t)i + (window / 2);

        for (int32_t j = start; j <= end; j++) {
            if (j >= 0 && j < (int32_t)len)
                sum += src[j] * scale;
        }
        dst[i] = sum;
    }
}

// diff and diff2
uint32_t diff_array(const float *src, float *dst, uint32_t len, uint32_t order) {
    if (order == 1) {
        for (uint32_t i = 1; i < len; i++)
            dst[i-1] = src[i] - src[i-1];
        return len - 1;
    } else { // n=2
        for (uint32_t i = 2; i < len; i++)
            dst[i-2] = (src[i] - src[i-1]) - (src[i-1] - src[i-2]);
        return len - 2;
    }
}

// Variance of diff or diff2
float diff_var(const float *arr, uint32_t len, uint32_t order) {
    float diff_buffer[DATA_LENGTH];
    uint32_t new_len = diff_array(arr, diff_buffer, len, order);

    float mean = 0;
    for (uint32_t i = 0; i < new_len; i++) mean += diff_buffer[i];
    mean /= new_len;

    float var = 0;
    for (uint32_t i = 0; i < new_len; i++)
        var += (diff_buffer[i] - mean)*(diff_buffer[i] - mean);

    return var / new_len;
}

// Smooth + peak count
uint32_t smooth_n_peaks(const float *arr, uint32_t len, uint32_t window) {
    float buffer[DATA_LENGTH];
    smooth(arr, buffer, len, window);
    return count_peaks(buffer, len);
}

// Diff peaks
uint32_t diff_n_peaks(const float *arr, uint32_t len, uint32_t order) {
    float buffer[DATA_LENGTH];
    uint32_t new_len = diff_array(arr, buffer, len, order);
    return count_peaks(buffer, new_len);
}


// Mean
float compute_mean(const float *arr, uint32_t len) {
    float sum = 0.0f;
    for (uint32_t i = 0; i < len; i++)
        sum += arr[i];
    return sum / len;
}

// Variance
float compute_var(const float *arr, uint32_t len) {
    float mean = compute_mean(arr, len);
    float sum = 0.0f;
    for (uint32_t i = 0; i < len; i++)
        sum += (arr[i] - mean) * (arr[i] - mean);
    return sum / len;
}

// Standard Deviation
float compute_std(const float *arr, uint32_t len) {
    return sqrtf(compute_var(arr, len));
}

// Skewness
float compute_skew(const float *arr, uint32_t len) {
    float mean = compute_mean(arr, len);
    float std_dev = compute_std(arr, len);
    float sum = 0.0f;
    for (uint32_t i = 0; i < len; i++)
        sum += powf((arr[i] - mean) / std_dev, 3);
    return sum / len;
}

// Kurtosis
float compute_kurtosis(const float *arr, uint32_t len) {
    float mean = compute_mean(arr, len);
    float std_dev = compute_std(arr, len);
    float sum = 0.0f;
    for (uint32_t i = 0; i < len; i++)
        sum += powf((arr[i] - mean) / std_dev, 4);
    return sum / len - 3.0f; // excess kurtosis
}


ai_handle network;
float aiInData[AI_NETWORK_IN_1_SIZE];
float aiOutData[AI_NETWORK_OUT_1_SIZE];
ai_u8 activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];
const char* activities[AI_NETWORK_OUT_1_SIZE+1] =
{
"normal", "anomaly"
};
ai_buffer* ai_input;
ai_buffer* ai_output;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CRC_HandleTypeDef hcrc;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
static void AI_Init(void);
static void AI_Run(float *pIn, float *pOut);
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CRC_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void vprint(const char *fmt, va_list argp)
{
    char string[200];
    if(0 < vsprintf(string, fmt, argp)) // build string
    {
        HAL_UART_Transmit(&huart1, (uint8_t*)string, strlen(string), 0xffffff); // send message via UART
    }
}

void ei_printf(const char *format, ...) {
    va_list myargs;
    va_start(myargs, format);
    vprint(format, myargs);
    va_end(myargs);
}

void simulate_adcs_correction() {
    int total_iterations = 595;
    int predictedClass = 1; // ADCS Anomaly Detected

    if (predictedClass == 1) {
        ei_printf("--- ADCS ANOMALY ALERT: Magnetometer and Sun Sensor Drift Detected ---\r\n");
        ei_printf("INITIATING EMERGENCY ATTITUDE CORRECTION MANEUVER (595 steps)\r\n");

        for (int i = 0; i < total_iterations; i++) {
            // Use the iteration number (i) to alternate focus between the two sensor types

            if (i % 2 == 0) {
                // Even steps focus on Magnetometer correction/validation
                float magnetic_field_error = (float)rand() / (float)RAND_MAX * 0.1; // Simulate small error reduction
                ei_printf("[%04d/%d] Magnetometer Check: Firing Reaction Wheel Z-Axis. Error: %.4f uT.\r\n",
                          i + 1, total_iterations, magnetic_field_error);
            } else {
                // Odd steps focus on Sun Sensor correction/validation
                int sun_sensor_id = (i / 2) % 6 + 1; // Cycle through 6 simulated sensors (SS1 to SS6)
                float sun_angle_deviation = (float)rand() / (float)RAND_MAX * 0.5; // Simulate small angular deviation
                ei_printf("[%04d/%d] Sun Sensor SS-%d Adjustment: Applying Magnetorquer. Deviation: %.2f degrees.\r\n",
                          i + 1, total_iterations, sun_sensor_id, sun_angle_deviation);
            }
        }

        ei_printf("--- 595 CORRECTION CYCLES COMPLETE ---\r\n");
        ei_printf("ADCS STATUS: Stabilizing. Re-calibrating Magnetometer and Sun Sensor inputs.\r\n");
    }
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CRC_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  AI_Init();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  uint32_t n = DATA_LENGTH;

	  // 1. duration
	  float duration = (float)(n - 1);

	  // 2. mean
	  float mean = 0.0f;
	  for (uint32_t i = 0; i < n; i++)
		  mean += rawData[i];
	  mean /= n;

	  // 3. variance
	  float var = 0.0f;
	  for (uint32_t i = 0; i < n; i++)
		  var += (rawData[i] - mean)*(rawData[i] - mean);
	  var /= n;

	  // 4. kurtosis
	  float kurtosis = 0.0f;
	  for (uint32_t i = 0; i < n; i++) {
		  float dev = rawData[i] - mean;
		  kurtosis += powf(dev, 4);
	  }
	  kurtosis = (kurtosis / n) / powf(sqrtf(var), 4) - 3.0f; // excess kurtosis

	  // 5. skew
	  float skew = 0.0f;
	  for (uint32_t i = 0; i < n; i++) {
		  float dev = rawData[i] - mean;
		  skew += powf(dev, 3);
	  }
	  skew /= n;
	  skew /= powf(sqrtf(var), 3);

	  // 6. n_peaks
	  uint32_t n_peaks = count_peaks(rawData, n);

	  // 7. smooth10_n_peaks
	  uint32_t smooth10_peaks = smooth_n_peaks(rawData, n, 10);

	  // 8. smooth20_n_peaks
	  uint32_t smooth20_peaks = smooth_n_peaks(rawData, n, 20);

	  // 9. diff_peaks
	  uint32_t diff_peaks_val = diff_n_peaks(rawData, n, 1);

	  // 10. diff_var
	  float diff_var_val = diff_var(rawData, n, 1);

	  // 11. gaps_squared
	  uint64_t gaps_sq = gaps_squared(timestamps, n);



	  // Store in aiInData
	  aiInData[0] = duration;
	  aiInData[1] = mean;
	  aiInData[2] = var;
	  aiInData[3] = kurtosis;
	  aiInData[4] = skew;
	  aiInData[5] = (float)n_peaks;
	  aiInData[6] = (float)smooth10_peaks;
	  aiInData[7] = (float)smooth20_peaks;
	  aiInData[8] = (float)diff_peaks_val;
	  aiInData[9] = diff_var_val;
	  aiInData[10] = (float)gaps_sq;

	  // Example print
	  for(int i = 0; i < AI_NETWORK_IN_1_SIZE; i++)
		  ei_printf("aiInData[%d] = %.12e\r\n", i, aiInData[i]);
	  // Run inference on the neural network
	  ei_printf("Performing inference...\r\n");
	  AI_Run(aiInData, aiOutData );

	  // Display the results
	  for (uint32_t i = 0; i < AI_NETWORK_OUT_1_SIZE; i++) {
		  ei_printf("Output[%lu]: %8.6f\r\n", i, aiOutData[i]);
	  }

	  // Determine the predicted class
	  uint32_t predictedClass = (*aiOutData > 0.5) ? 1 : 0;
	  ei_printf("Predicted Class: %d - %s\r\n", (int)predictedClass, activities[predictedClass]);
	  if (predictedClass == 1){simulate_adcs_correction(); }


  while (1) {}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
static void AI_Init(void)
{
ai_error err;
/* Create a local array with the addresses of the activations buffers */
const ai_handle act_addr[] = { activations };
/* Create an instance of the model */
err = ai_network_create_and_init(&network, act_addr, NULL);
if (err.type != AI_ERROR_NONE) {
printf("ai_network_create error - type=%d code=%d\r\n", err.type, err.code);
Error_Handler();
}
ai_input = ai_network_inputs_get(network, NULL);
ai_output = ai_network_outputs_get(network, NULL);
}

static void AI_Run(float *pIn, float *pOut)
{
ai_i32 batch;
ai_error err;
/* Update IO handlers with the data payload */
ai_input[0].data = AI_HANDLE_PTR(pIn);
ai_output[0].data = AI_HANDLE_PTR(pOut);
batch = ai_network_run(network, ai_input, ai_output);
if (batch != 1) {
err = ai_network_get_error(network);
printf("AI ai_network_run error - type=%d code=%d\r\n", err.type, err.code);
Error_Handler();
}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
