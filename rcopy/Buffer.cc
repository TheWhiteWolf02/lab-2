#include "Buffer.h"
#include "Exception.h"

// TODO: add implementation of class Buffer
Buffer::Buffer(int size) {
    try
    {
        if(size <= 0) {
            throw Exception(Exception::INVALID_BUFFER_SIZE, "Invalid Buffer size");
        }

        buffer = (char *) malloc(size);
        if(buffer == NULL) {
            throw Exception(Exception::MEMORY_ALLOCATION_FAILED, "Memory Allocation Failed");
        }
    }
    catch(Exception e)
    {
        e.printErrorDetails();
        throw e;
    }
}

void Buffer::reverse(int size) {
    char temp;
    int left = 0, right = size - 1, i;

    while(left < right)
    {
        temp = buffer[right];
        buffer[right] = buffer[left];
        buffer[left] = temp;
        ++left;
        --right;
    }

    /*
    cout << "Before" << endl;
    for(i = 0; i < end; i++) {
        cout << buffer[i];
    }
    cout << " " << endl;

    for(start = 0; start < end; start++, end--) {
        temp = buffer[start];
        cout << temp << " and " << buffer[start] << endl;
        buffer[start] = buffer[end];
        cout << buffer[start] << " and " << buffer[end] << endl;
        buffer[end] = temp;
        cout << buffer[end] << " and " << temp << endl;
    }

    cout << "After" << endl;
    for(i = 0; i < end; i++) {
        cout << buffer[i];
    }
    cout << " " << endl;
    */
}

Buffer::~Buffer() {
    free(buffer);
    buffer = NULL;
}
