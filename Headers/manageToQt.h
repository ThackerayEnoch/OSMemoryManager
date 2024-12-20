//
// Created by ThackerayEnoch on 24-12-15.
//

#ifndef OPERATINGSYSTEMWORKQTVERSION_MANAGETOQT_H
#define OPERATINGSYSTEMWORKQTVERSION_MANAGETOQT_H

#include "../MemoryManager/MemoryManager.h"

class ManageToQt {
public:
    ManageToQt();

    ~ManageToQt();

    void initializeManager(int maxMemory, int minMemory);
    void resetManager();
    void setStrategy(int strategy);
    bool isManagerNull();
    int getMaxMemory();
    const std::list<MemoryBlock> &getBlocks();
    std::string allocate(int processID, int requestSize);
    std::string deallocate(int processID);
    int getMinMemory();
    void resetNextFitConfig();

private:
    MemoryManager *manager;
};


#endif //OPERATINGSYSTEMWORKQTVERSION_MANAGETOQT_H
