#include <memory>
using namespace std;

#include "Annealing.h"
#include "Distribution/Distribution.h"
#include "Solution/Solution.h"
#include "Temperature/Temperature.h"

Solution Annealing::findSolution() {
    stopCounter = 0;
    while (stopCounter < STOP_NUMBER) {
        temperature->coolDown();
        for (int iteration = 0; iteration < ITERATIONS_BEFORE_TEMPERATURE_CHANGE; iteration++) {
            makeStep();
        }
    }

    return bestSolution;
}

void Annealing::makeStep() {
    unique_ptr<Solution> newSolution = mutationGenerator->getNeighborSolution(currentSolution);
    makeChoice(newSolution)
}

void Annealing::makeChoice(Solution newSolution) {
    double energyDifference = newSolution.getEnergy() - bestSolution->getEnergy();

    if (energyDifference > 0 || distribution.shouldChange(energyDifference, temperature->getTemperature())) {
        currentSolution = newSolution;
    }

    if (energyDifference > 0) {
        stopCounter = 0;
        bestSolution = newSolution;
    } else {
        stopCounter++;
    }
}
