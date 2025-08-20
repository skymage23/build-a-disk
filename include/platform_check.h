//I purposefully did not put an include guard.
//This is to prevent compilation on untested systems.

#if !(defined(__linux__) || defined(__APPLE__))
#error "You are building for an unsupported platform. We must stop here. Supported platforms are Linux and Mac OS."
#endif