#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

double BinCoeff(uint8_t n, uint8_t k);

double Fact(uint8_t i);

void calculateImpedances(int N, double Z0, double ZL);

int main(int argc, char *argv[]) {

  double Z0 = 100.0;
  double ZL = 50.0;

  if (argc > 1) {
    uint8_t N = atoi(argv[1]);
    calculateImpedances(N, Z0, ZL);
  } else {

    uint8_t N = 1;
    printf("\nNumber of sections not defined, calculating for N = 1. \nFor "
           "different number of sections, run ./WilkinsonWideband N, where N "
           "is the number of sections.");
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

  for (int n = 1; n <= N; n++) {

    printf("Zs[%d] = %lf\n", n, Zs[n]);
  }
}
