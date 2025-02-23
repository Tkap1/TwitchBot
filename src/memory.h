#pragma once

typedef unsigned int uint32_t;
typedef unsigned char u8;

constexpr uint32_t MAX_ALLOCATIONS = 100;

struct Allocation
{
	uint32_t size;
	uint32_t used;
	uint8_t *memory;
};

struct AppMemory
{
	uint32_t size;
	uint32_t used;
	uint8_t *memory;

	uint32_t allocationCount;
	Allocation allocations[MAX_ALLOCATIONS];
};

uint8_t *allocate_memory(AppMemory *memory, uint32_t size);
void free_memory(AppMemory *memory, uint8_t *location);