#ifndef BESTFITSTRATEGY_H
#define BESTFITSTRATEGY_H

#include "AllocationStrategy.h"
/**
 * 最佳适用策略
 **/
class BestFitStrategy : public AllocationStrategy {
	public:
		std::list<MemoryBlock>::iterator allocate(std::list<MemoryBlock> &blocks, int requestSize, int &) override {
			auto it = blocks.end();
			int minWaste = INT_MAX;
			// 遍历查找最小值
			for (auto curr = blocks.begin(); curr != blocks.end(); curr++) {
				if (curr->size >= requestSize && curr->size - requestSize < minWaste && curr->isFree) {
					minWaste = curr->size - requestSize;
					it = curr;
				}
			}
			// 切割内存块
			if (it != blocks.end() && it->size > requestSize) {
				int remainingSize = it->size - requestSize;
				it->size = requestSize;
				MemoryBlock newBlock(it->address + requestSize, remainingSize);
				blocks.insert(std::next(it), newBlock);
			}
			return it;
		}
};

#endif
