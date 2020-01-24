#include "Timing.h"
#include <EchoSettings.h>

std::chrono::steady_clock::time_point Echo::Timing::startTime = std::chrono::steady_clock::now();
int Echo::Timing::offset = Echo::settings["metadata"]["offset"];