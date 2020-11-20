#ifndef C_PRAC_PRAC_ANNEALING_H
#define C_PRAC_PRAC_ANNEALING_H

#include <memory>
using namespace std;

#include "Solution/Mutation.h"
#include "Solution/Solution.h"
#include "Distribution/Distribution.h"
#include "Temperature/Temperature.h"
#define STOP_NUMBER 100
#define ITERATIONS_BEFORE_TEMPERATURE_CHANGE 7

class Annealing {
private:
    shared_ptr<Mutation> mutationGenerator;
    shared_ptr<Temperature> temperature;
    shared_ptr<Solution> bestSolution;
    shared_ptr<Solution> currentSolution;
    GibbsDistribution distribution;
    int stopCounter;

    Annealing() {
        distribution = new GibbsDistribution();
        temperature = new Temperature(100);
        currentSolution = new Solution();
        currentSolution->InitSolution();
        bestSolution = currentSolution;
    }

    Solution findSolution ();
    void makeStep();
    void makeChoice(Solution newSolution);
};

#endif //C_PRAC_PRAC_ANNEALING_H
