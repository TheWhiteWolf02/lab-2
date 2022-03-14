#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <iostream>

using namespace std;

class Buffer {
    // TODO: add public and private members
  private:
    char *buffer;
    void allocateMemory();

  public:
    Buffer(int size);
    void reverse(int size);
    friend class File;
    ~Buffer();
};

#endif