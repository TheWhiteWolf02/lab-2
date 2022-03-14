#ifndef __FILE_H__
#define __FILE_H__

#include "Buffer.h"
#include "Exception.h"
#include <iostream>

using namespace std;

class File {
    // TODO: add public and private members
  private:
    FILE* f;
    const char *mode;

  public:
    // Note: opening the same file twice for writing ("w")
    // at the same time is forbidden
    File(const char *name, const char *mode);
    int read(Buffer &buffer, int size);
    void write(Buffer &buffer, int size);
    void seek(int pos);
    bool endOfFile();
    void seekEnd();
    void close();
    ~File();
};

#endif
