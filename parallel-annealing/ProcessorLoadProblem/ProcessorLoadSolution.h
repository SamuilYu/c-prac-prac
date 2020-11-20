#ifndef C_PRAC_PRAC_PROCESSORLOADSOLUTION_H
#define C_PRAC_PRAC_PROCESSORLOADSOLUTION_H

#include <vector>
#include <string>
using namespace std;

#include "../Solution/Solution.h"
#include "../Solution/Mutation.h"

class Task {
private:
    string name;
    int duration;
public:
    int getDuration() {
        return duration;
    }

    bool operator< (Task& other) {
        return this->duration < other.duration;
    }
};


class ProcessorLoadSolution: public Solution {
private:
    vector<vector<Task>> processorLoad;
    vector<Task> allTasks;
public:
    size_t numberOfProcessors;

    ProcessorLoadSolution(size_t processorsCount, vector<Task> allTasks);
    void insertTaskAtProcessor(Task task, int processorNumber);
    Task getHeaviestTaskAtProcessorAndRemove(int processorNumber);
};


class ProcessorLoadMutation: public Mutation {
private:
    int counter;
public:
    ProcessorLoadMutation();
};


#endif //C_PRAC_PRAC_PROCESSORLOADSOLUTION_H
