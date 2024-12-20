#ifndef MEMORYBLOCK_H
#define MEMORYBLOCK_H

class  MemoryBlock {
	public:
		int processID;	// 进程ID
		int address;    // 起始地址
		int size;       // 内存块大小
		bool isFree;	// 是否空闲
        bool isLeft;
		MemoryBlock(int addr, int sz) : address(addr), size(sz), isFree(true), processID(-1),isLeft(false) {}
        MemoryBlock(int addr,int sz,bool isLeft):address(addr),size(sz),isFree(true),processID(-1),isLeft(isLeft){}
};

#endif
