#ifndef NEXTFITSTRATEGY_H
#define NEXTFITSTRATEGY_H
#include "AllocationStrategy.h"
/**
 * 循环首次适用策略
 **/
class NextFitStrategy : public AllocationStrategy {
	public:
		std::list<MemoryBlock>::iterator allocate(std::list<MemoryBlock> &blocks, int requestSize, int &lastAllocIndex) override {
			// 获取起始迭代器
			auto startIt = std::next(blocks.begin(), lastAllocIndex);
			// 查询上次位置后面合适的块
			auto it = std::find_if(startIt, blocks.end(), [ = ](const MemoryBlock & block) {
				return block.size >= requestSize && block.isFree;
			});
			// 没发现合适的块 查询上次位置前面合适的块
			if (it == blocks.end()) {
				it = std::find_if(blocks.begin(), startIt, [ = ](const MemoryBlock & block) {
					return block.size >= requestSize && block.isFree;
				});
			}
			// 切割内存块
			if (it != blocks.end() && it->size > requestSize) {
				int remainingSize = it->size - requestSize;
				it->size = requestSize;
				MemoryBlock newBlock(it->address + requestSize, remainingSize);
				blocks.insert(std::next(it), newBlock);
			}
			lastAllocIndex = it == blocks.end() ? 0 : std::distance(blocks.begin(), it);
			return it;
		}
};

#endif
