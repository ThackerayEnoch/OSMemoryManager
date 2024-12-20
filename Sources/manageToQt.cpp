//
// Created by ThackerayEnoch on 24-12-15.
//

#include "../Headers/manageToQt.h"
#include "../MemoryManager/FirstFitStrategy.h"
#include "../MemoryManager/NextFitStrategy.h"
#include "../MemoryManager/BestFitStrategy.h"
#include "../MemoryManager/WorstFitStrategy.h"

ManageToQt::ManageToQt() {
    this->manager = nullptr;
}

ManageToQt::~ManageToQt() {
    delete manager;
}

void ManageToQt::initializeManager(int maxMemory, int minMemory) {
    this->manager = new MemoryManager(maxMemory,minMemory);
    setStrategy(0);
}

void ManageToQt::resetManager() {
    delete manager;
}

void ManageToQt::setStrategy(int strategy) {
    switch (strategy) {
        case 0:
            manager->setStrategy(std::make_shared<FirstFitStrategy>());
            break;
        case 1:
            manager->setStrategy(std::make_shared<NextFitStrategy>());
            break;
        case 2:
            manager->setStrategy(std::make_shared<BestFitStrategy>());
            break;
        case 3:
            manager->setStrategy(std::make_shared<WorstFitStrategy>());
            break;
        default:
            break;
    }
}

bool ManageToQt::isManagerNull() {
    return manager == nullptr;
}

int ManageToQt::getMaxMemory() {
    return manager->getMaxMemory();
}

const std::list<MemoryBlock> &ManageToQt::getBlocks() {
    return manager->getBlocks();
}

std::string ManageToQt::allocate(int processID, int requestSize) {
    return manager->allocate(processID, requestSize);
}

std::string ManageToQt::deallocate(int processID) {
    return manager->deallocate(processID);
}

int ManageToQt::getMinMemory() {
    return manager->getMinMemory();
}

void ManageToQt::resetNextFitConfig() {
    manager->resetNextFitConfig();

}
