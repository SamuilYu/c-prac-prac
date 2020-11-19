#ifndef C_PRAC_PRAC_DISTRIBUTION_H
#define C_PRAC_PRAC_DISTRIBUTION_H

#include "math.h"
#include "time.h"

class GibbsDistribution {
private:
    double getProbability (double energyDifference, double temperature) {
        return exp(-energyDifference / temperature);
    }

public:
    GibbsDistribution() {
        srand(time(0));
    }

    bool shouldChange (double energyDifference, double temperature) {
        double randomDouble = random() % 1000 / 1000;
        return randomDouble < getProbability(energyDifference, temperature);
    }
};


#endif //C_PRAC_PRAC_DISTRIBUTION_H
