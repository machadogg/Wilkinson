#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265359

double BinCoeff(uint8_t n, uint8_t k);

double Fact(uint8_t i);

void calculateImpedances(int N, double Z0, double ZL);

int main(int argc, char *argv[]) {

  double Z0 = 100.0;
  double ZL = 50.0;
  char *eptr;
  if (!strcmp(argv[1], "help")) {

    printf("This function receives N, Z0 and ZL\n");
    return 0;
  }

  if (argc == 2) {
    uint8_t N = atoi(argv[1]);
    calculateImpedances(N, Z0, ZL);

  } else if (argc == 4) {
    uint8_t N = atoi(argv[1]);
    Z0 = strtod(argv[2], &eptr);
    ZL = strtod(argv[3], &eptr);
    calculateImpedances(N, Z0, ZL);

  } else {

    uint8_t N = 1;
    printf("\nNumber of sections not defined, calculating for N = 1. \nFor "
           "different number of sections, run ./WilkinsonWideband N, where N "
           "is the number of sections.\n");
    calculateImpedances(1, Z0, ZL);
  }

  return 0;
}

double Fact(uint8_t i) { return tgamma(i + 1); }

double BinCoeff(uint8_t n, uint8_t k) {

  return Fact(n) / (Fact(n - k) * Fact(k));
}

void calculateImpedances(int N, double Z0, double ZL) {

  double Zs[N + 1];
  Zs[0] = Z0;

  for (int n = 0; n < N; n++) {
    Zs[n + 1] = Zs[n] * exp(pow(2, -N) * BinCoeff(N, n) * log(ZL / Z0));
  }

  Zs[0] = ZL;
  printf("\n");
  for (int n = 0; n <= N; n++) {

    printf("Zs[%d] = %lf\n", n, Zs[n]);
  }

  double A = (1 / (pow(2, N + 1)) * log(ZL / Z0));

  double BW = 2 - (4 / PI) * acos(0.5 * (pow(0.05 / fabs(A), 1.0 / N)));

  printf("\nBandwidth for Gamma_m = 0.05 =  %.2f%% \n\n", BW * 100);
}
