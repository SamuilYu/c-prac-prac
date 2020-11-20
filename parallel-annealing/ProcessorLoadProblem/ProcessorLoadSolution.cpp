#include "ProcessorLoadSolution.h"
#include <algorithm>
using namespace std;


ProcessorLoadSolution::ProcessorLoadSolution(size_t processorsCount, vector <Task> allTasks) {
    this->allTasks = allTasks;
    this->processorLoad.resize(processorsCount);
    numberOfProcessors = processorsCount;
}

void ProcessorLoadSolution::InitSolution() {
    sort(this->allTasks.begin(), this->allTasks.end());

    for (size_t i = 0; i < allTasks.size(); i++) {
        processorLoad[i % processorLoad.size()].emplace_back(allTasks[i]);
    }
}

double ProcessorLoadSolution::getEnergy() {
    double sum = 0;
    for (const auto &processor : processorLoad) {
        for (size_t i = 0; i < processor.size(); i++) {
            sum += (processor.size() - i) * processor[i].duration;
        }
    }
    return sum;
}

void ProcessorLoadSolution::insertTaskAtProcessor(Task task, int processorNumber) {
    processorLoad[processorNumber].insert(processorLoad + processorNumber, task);
}

Task ProcessorLoadSolution::getHeaviestTaskAtProcessorAndRemove(int processorNumber) {
    vector<Task>::iterator longestTask = max_element(processorLoad[processorNumber].begin(), processorLoad[processorNumber].end());
    Task temporaryTask = longestTask.base();
    processorLoad[processorNumber].erase(longestTask);
    return temporaryTask;
}

ProcessorLoadMutation::ProcessorLoadMutation() {
    counter = 0;
}

Solution ProcessorLoadMutation::getNeighborSolution(Solution& solution) {
    ProcessorLoadSolution typeCastedSolution = static_cast<ProcessorLoadSolution>(solution);
    typeCastedSolution.insertTaskAtProcessor(
            typeCastedSolution.getHeaviestTaskAtProcessorAndRemove(counter),
            (counter - 1) % typeCastedSolution.numberOfProcessors
            );
    counter = (counter + 1) % typeCastedSolution.numberOfProcessors;
    return typeCastedSolution;
}