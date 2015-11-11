#ifndef MEMORY_H
#define MEMORY_H

#include "../Queue/Queue.h"

class Memory
{
private:
    Queue<double> queue;  //double ??
public:
    Memory() {}
    Memory(int maxMemorySize);
    ~Memory() {}
    void SetMaximumSize(int maxSize) {queue.SetMaximumSize(maxSize);}
};

#endif // MEMORY_H
