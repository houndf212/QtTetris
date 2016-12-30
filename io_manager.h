#ifndef IO_MANAGER_H
#define IO_MANAGER_H
#include <memory>
#include "io_network.h"

class IO_Manager
{
public:
    static void init();
    static IO_Network* get();
private:
    static std::unique_ptr<IO_Network> io;
    static const QString kFileName;
};

#endif // IO_MANAGER_H
