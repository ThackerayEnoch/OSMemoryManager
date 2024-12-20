#include "MemoryManager.h"
#include "MemoryException.h"

void MemoryManager::setStrategy(std::shared_ptr<AllocationStrategy> newStrategy) {
    strategy = std::move(newStrategy);
}

std::string MemoryManager::printAllBlocks() {
    std::string result("------------------------------------------\n");
    for (const auto &block: blocks) {
        result.append("起始地址: " + std::to_string(block.address) + ", 大小: " + std::to_string(block.size) +
                      "MB, 已分配: " + (block.isFree ? "0" : "1"));
        if (!block.isFree) {
            result.append(", 进程ID: " + std::to_string(block.processID));
        }
        result.append("\n");
    }
    return result.append("------------------------------------------\n");
}

std::string MemoryManager::allocate(int processID, int requestSize) {
    if (!strategy) {
        throw MemoryException("未选择分配策略!\n");
    }
    if(requestSize==0){
        throw MemoryException("请求内存大小不能为0!");
    }
    auto it = strategy->allocate(blocks, requestSize, lastAllocIndex);
    if (it == blocks.end()) {
        throw MemoryException("分配失败！无可用块。\n");
    }
    // 标识内存块
    it->isFree = false;
    it->processID = processID;
    return "分配成功，起始地址: " + std::to_string(it->address) + ", 大小: " + std::to_string(it->size) + "\n";
}

std::string MemoryManager::deallocate(int processID) {
    auto it = blocks.begin();
    int count = 0;
    do {
        it = find_if(blocks.begin(), blocks.end(), [=](const MemoryBlock &block) {
            return block.processID == processID;
        });
        if (it == blocks.end() && count == 0) {
            throw MemoryException("回收失败！没有该块。");
        } else if (it == blocks.end()) {
            break;
        }
        int distance = std::distance(blocks.begin(), it);

        // 块合并与销毁
        if (it != blocks.begin()) {
            auto prev = std::prev(it);
            if (prev->isFree) {
                it->address = prev->address;
                it->size += prev->size;
                it = blocks.erase(prev); // 更新迭代器
                if (distance < lastAllocIndex) {
                    lastAllocIndex--;
                }
            }
        }
        if (std::next(it) != blocks.end()) {
            auto next = std::next(it);
            if (next->isFree) {
                it->size += next->size;
                blocks.erase(next);
                if (distance < lastAllocIndex) {
                    lastAllocIndex--;
                }
            }
        }
        it->isFree = true;
        it->processID = -1;
        count++;
    } while (it != blocks.end());
    return "回收成功";
}

int MemoryManager::getMaxMemory() {
    return totalMemory;
}

const std::list<MemoryBlock> &MemoryManager::getBlocks() {
    return blocks;
}

int MemoryManager::getMinMemory() {
    return minMemory;
}

void MemoryManager::resetNextFitConfig() {
    lastAllocIndex = 0;

}


