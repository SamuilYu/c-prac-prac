#ifndef C_PRAC_PRAC_TEMPERATURE_H
#define C_PRAC_PRAC_TEMPERATURE_H


class Temperature {
private:
    int counter;
    double baseTemperature;
public:
    Temperature(double baseTemperature);
    double virtual getNext();
};

class BoltzmannTemperature : public Temperature {};

class CauchyTemperature : public Temperature {};

class LogLinearTemperature : public Temperature {};


#endif //C_PRAC_PRAC_TEMPERATURE_H
