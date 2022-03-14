#include "Exception.h"

// TODO: add implementation of class Exception
Exception::Exception(int errorNo, const char *errorMessage) {
    errorNo = errorNo;
    errorMessage = errorMessage;
}

int Exception::getErrno() {
    return errorNo;
}

const char *Exception::getMessage() {
    return errorMessage;
}

void Exception::printErrorDetails() {
    std::cerr << "Error code: " << getErrno() << " and message: " << getMessage() << '\n';
}
