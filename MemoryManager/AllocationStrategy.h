#ifndef ALLOCATIONSTRATEGY_H
#define ALLOCATIONSTRATEGY_H

#include <algorithm>
#include <list>
#include "MemoryBlock.h"

class AllocationStrategy {
	public:
		virtual ~AllocationStrategy() = default;
		virtual std::list<MemoryBlock>::iterator allocate(std::list<MemoryBlock> &blocks, int requestSize, int &lastAllocIndex) = 0;
};

#endif
