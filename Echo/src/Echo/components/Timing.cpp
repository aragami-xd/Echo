#include "Timing.h"
#include <Settings.h>

std::chrono::steady_clock::time_point Echo::Timing::startTime = std::chrono::steady_clock::now();
int Echo::Timing::offset = settings["metadata"]["offset"];