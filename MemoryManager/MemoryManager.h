#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "AllocationStrategy.h"
#include <string>
#include <memory>
#include <vector>

class MemoryManager {
private:
    std::list<MemoryBlock> blocks; // 块链表
    std::shared_ptr<AllocationStrategy> strategy; // 当前分配策略

    int totalMemory;        // 总内存
    int lastAllocIndex = 0; // 用于循环首次适应算法
    int minMemory = 0;      // 最小内存块大小
public:
    explicit MemoryManager(int totalMemory, int minMemory) : totalMemory(totalMemory), minMemory(minMemory) {
        blocks.emplace_back(0, totalMemory); // 初始状态只有一个大块
    }

    void setStrategy(std::shared_ptr<AllocationStrategy> newStrategy);
    std::string printAllBlocks();
    std::string allocate(int processID, int requestSize);
    std::string deallocate(int processID);
    int getMaxMemory();
    int getMinMemory();
    void resetNextFitConfig();
    const std::list<MemoryBlock> &getBlocks();

};

#endif
