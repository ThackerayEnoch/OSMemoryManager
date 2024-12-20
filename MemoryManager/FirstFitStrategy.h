#ifndef FIRSTFITSTRATEGY_H
#define FIRSTFITSTRATEGY_H
#include "AllocationStrategy.h"
/**
 * 首次适应策略
 **/
class FirstFitStrategy : public AllocationStrategy {
	public:
		std::list<MemoryBlock>::iterator allocate(std::list<MemoryBlock> &blocks, int requestSize, int &) override {
			// 寻找匹配块
			auto it = std::find_if(blocks.begin(), blocks.end(), [ = ](const MemoryBlock & block) {
				return block.size >= requestSize && block.isFree;
			});
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
