#ifndef C_PRAC_PRAC_MUTATION_H
#define C_PRAC_PRAC_MUTATION_H

#include "Solution.h"

class Mutation {
public:
    virtual Solution getNeighborSolution (Solution& solution);
};


#endif //C_PRAC_PRAC_MUTATION_H
