#include "../includes/colors.h"

const Color Cyan = {0, 255, 255, 255};        // I block
const Color Yellow = {255, 255, 0, 255};      // O block
const Color Purple = {128, 0, 128, 255};      // T block
const Color Green = {0, 255, 0, 255};         // S block
const Color Red = {255, 0, 0, 255};           // Z block
const Color Blue = {0, 0, 255, 255};          // J block
const Color Orange = {255, 165, 0, 255};      // L block
const Color DarkGray = {50, 50, 50, 255};     // Background
const Color LightGray = {200, 200, 200, 255}; // Grid

std::vector<Color> GetAllColors() {
  return {DarkGray, Cyan, Yellow, Purple, Green, Red, Blue, Orange};
}
