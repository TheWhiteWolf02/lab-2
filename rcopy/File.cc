// TODO: Implement all methods of class File
#include "File.h"
#include <unistd.h>

File::File(const char *name, const char *mode) {
    try
    {
        /*
        if(strcmp(mode, "w") == 0 && access(name, W_OK) == false) {
            throw Exception(Exception::FILE_WRITE_PERMISSION_NOT_FOUND, "File Write permission not found");
        }
        cout << "x";
        
        if(strcmp(mode, "r") == 0 && access(name, R_OK) == false) {
            throw Exception(Exception::FILE_READ_PERMISSION_NOT_FOUND, "File Read permission not found");
        }
        */
        f = fopen(name, mode);

        if(f == NULL) {
            throw Exception(Exception::FILE_OPEN_FAILED, "File open failed");
        }

        mode = mode;
        
    }
    catch(Exception e)
    {
        e.printErrorDetails();
        throw e;
    }
}

int File::read(Buffer &buffer, int size) {
    try
    {
        if(size <= 0) {
            throw Exception(Exception::INVALID_BUFFER_SIZE, "Invalid buffer size");
        }

        if(f == NULL) {
            throw Exception(Exception::FILE_NOT_BEEN_OPENED_YET, "File has not been opened yet");
        }

        errno = 0;
        int read = fread(buffer.buffer, 1, size, f);
        if(read != size) {
            int flag = ferror(f);

            if(errno != 0) {
                throw Exception(Exception::FILE_READ_FAILED, "File write failed");
            }

            if(flag != 0) {
                throw Exception(Exception::FERROR_FAILED, "Ferror failed");
            }
        }
        
        return read;
    }
    catch(Exception e)
    {
        e.printErrorDetails();
        throw e;
    }
}

void File::write(Buffer &buffer, int size) {
    try
    {
        if(size <= 0) {
            throw Exception(Exception::INVALID_BUFFER_SIZE, "Invalid buffer size");
        }

        if(f == NULL) {
            throw Exception(Exception::FILE_NOT_BEEN_OPENED_YET, "File has not been opened yet");
        }

        errno = 0;
        int write = fwrite(buffer.buffer, 1, size, f);
        int flag = ferror(f);

        if(errno != 0) {
            throw Exception(Exception::FILE_WRITE_FAILED, "File write failed");
        }

        if(flag != 0) {
            throw Exception(Exception::FERROR_FAILED, "Ferror failed");
        }

        if(write != size) {
            throw Exception(Exception::FILE_WRITE_FAILED, "File write failed");
        }
    }
    catch(Exception e)
    {
        e.printErrorDetails();
        throw e;
    }
}

void File::seek(int pos) {
    try
    {
        if(f == NULL) {
            throw Exception(Exception::FILE_NOT_BEEN_OPENED_YET, "File has not been opened yet");
        }

        int seek = fseek(f, pos, SEEK_SET);

        if(seek != 0) {
            throw Exception(Exception::FILE_SEEK_FAILED, "File seek failed");
        }
    }
    catch(Exception e)
    {
        e.printErrorDetails();
        throw e;
    }
}

void File::seekEnd() {
    try
    {
        if(f == NULL) {
            throw Exception(Exception::FILE_NOT_BEEN_OPENED_YET, "File has not been opened yet");
        }

        int seek = fseek(f, 0, SEEK_END);

        if(seek != 0) {
            throw Exception(Exception::FILE_SEEK_FAILED, "File seek failed");
        }
    }
    catch(Exception e)
    {
        e.printErrorDetails();
        throw e;
    }
}

void File::close() {
    try
    {
        if(f == NULL) {
            throw Exception(Exception::FILE_NOT_BEEN_OPENED_YET, "File has not been opened yet");
        }

        int close = fclose(f);

        if(close != 0) {
            throw Exception(Exception::FILE_CLOSE_FAILED, "File close failed");
        }
        f = NULL;
    }
    catch(Exception e)
    {
        e.printErrorDetails();
        throw e;
    }
}

bool File::endOfFile() {
    try
    {
        if(f == NULL) {
            throw Exception(Exception::FILE_NOT_BEEN_OPENED_YET, "File has not been opened yet");
        }
        
        errno = 0;
        if(errno != 0) {
            throw Exception(Exception::FILE_ENDOFFILE_ERROR, "calling end of file caused error");
        }

        return feof(f);
    }
    catch(Exception e)
    {
        e.printErrorDetails();
        throw e;
    }
}

File::~File() {
    f = NULL;
}
