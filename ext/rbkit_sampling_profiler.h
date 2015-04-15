#ifndef RBKIT_SAMPLING_PROFILER
#define RBKIT_SAMPLING_PROFILER
#include <signal.h>
#include <sys/time.h>

void rbkit_install_sampling_profiler(int wall_time);
void rbkit_uninstall_sampling_profiler();
#endif