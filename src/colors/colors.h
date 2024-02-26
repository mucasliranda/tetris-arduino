#pragma once
#include <vector>

extern const uint32_t darkGrey;
extern const uint32_t green;
extern const uint32_t red;
extern const uint32_t orange;
extern const uint32_t yellow;
extern const uint32_t purple;
extern const uint32_t cyan;
extern const uint32_t blue;
extern const uint32_t lightBlue;
extern const uint32_t darkBlue;

std::vector<uint32_t> GetCellColors();

uint32_t GetRandomColor();