#ifndef __EXECPTION_H__
#define __EXECPTION_H__

#include <iostream>

using namespace std;

class Exception: exception {
    // TODO: add private and public Members
  private:
    int errorNo;
    const char *errorMessage;

  public:
    enum ErrorType {
      MEMORY_ALLOCATION_FAILED,
      INVALID_BUFFER_SIZE,
      INVALID_ARGUMENT,
      INVALID_FILE_OPENING_MODE,
      FILE_WRITE_FAILED,
      FILE_READ_FAILED,
      FILE_SEEK_FAILED,
      FILE_OPEN_FAILED,
      FILE_CLOSE_FAILED,
      FILE_READ_PERMISSION_NOT_FOUND,
      FILE_WRITE_PERMISSION_NOT_FOUND,
      SAME_FILE_NAME,
      FILE_NOT_BEEN_OPENED_YET,
      FERROR_FAILED,
      FILE_ENDOFFILE_ERROR
    };

    Exception(int errorNo, const char *errorMessage);
    const char *getMessage();
    int getErrno();
    void printErrorDetails();
};

#endif