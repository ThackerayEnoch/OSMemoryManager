#ifndef WORSTFITSTRATEGY_H
#define WORSTFITSTRATEGY_H

#include "AllocationStrategy.h"
/**
 * 最坏适用策略
 **/
class WorstFitStrategy : public AllocationStrategy {
	public:
		std::list<MemoryBlock>::iterator allocate(std::list<MemoryBlock> &blocks, int requestSize, int &) override {
			auto it = blocks.end();
			int maxWaste = 0;
			// 遍历查找最大值
			for (auto curr = blocks.begin(); curr != blocks.end(); ++curr) {
				if (curr->size >= requestSize && curr->size - requestSize > maxWaste && curr->isFree) {
					maxWaste = curr->size - requestSize;
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
