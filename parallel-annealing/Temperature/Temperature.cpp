#include "Temperature.h"

Temperature ::Temperature(double baseTemperature) {
    this->baseTemperature = baseTemperature;
    counter = 0;
}

double LogLinearTemperature ::getNext() {
    counter++;
    return baseTemperature * log(1 + counter) / (1 + counter);
}

double CauchyTemperature ::getNext() {
    counter++
    return baseTemperature / (1 + counter);
}

double BoltzmannTemperature::getNext() {
    counter++;
    return baseTemperature / log(1 + counter);
}

