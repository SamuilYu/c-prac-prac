#include "Temperature.h"

Temperature ::Temperature(double baseTemperature) {
    this->baseTemperature = baseTemperature;
    counter = 0;
}

double CauchyTemperature::coolDown() {
    counter++;
    currentTemperature = baseTemperature / (1 + counter);
}

double BoltzmannTemperature::coolDown() {
    counter++;
    currentTemperature = baseTemperature / log(1 + counter);
}

double LogLinearTemperature::coolDown() {
    counter++;
    currentTemperature = baseTemperature * log(1 + counter) / (1 + counter);
}


