#include "Timing.h"
#include <Settings.h>

std::chrono::steady_clock::time_point Timing::startTime = std::chrono::steady_clock::now();
int Timing::offset = settings["metadata"]["offset"];