#ifndef C_PRAC_PRAC_TEMPERATURE_H
#define C_PRAC_PRAC_TEMPERATURE_H


class Temperature {
protected:
    int counter;
    double baseTemperature;
    double currentTemperature;
public:
    Temperature(double baseTemperature);
    double getTemperature() {
        return currentTemperature;
    };
    virtual void coolDown();
};

class BoltzmannTemperature : public Temperature {};

class CauchyTemperature : public Temperature {};

class LogLinearTemperature : public Temperature {};


#endif //C_PRAC_PRAC_TEMPERATURE_H
