#ifndef MEMORY_H
#define MEMORY_H

#include "../Queue/Queue.h"
#include "../Request/Request.h"

class Memory
{
private:
    Queue<Request> queue;
public:
    Memory() {}
    Memory(int maxMemorySize): queue(maxMemorySize) {}
    ~Memory() {}
    void SetMaximumSize(int maxSize) {queue.SetMaximumSize(maxSize);}
    Request GetRequest() {return queue.Get();}
    void PutRequest(const Request& request) {queue.Add(request);}
};

#endif // MEMORY_H
