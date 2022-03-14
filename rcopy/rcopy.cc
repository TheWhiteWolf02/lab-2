#include "File.h"
#include "Buffer.h"
#include "Exception.h"
#include <iostream>

using namespace std;

#define BUFFER_SIZE 1024

int main(const int argc, const char **argv) {
    try
    {
        if(strcmp(argv[1],argv[2]) == 0) {
            throw Exception(Exception::SAME_FILE_NAME, "File names cannot be the same");
        }
        //File *f1 = File("test1.txt", "r");
        //File *f2 = File("test2.txt", "w");
        File f1 = File(argv[1], "r");
        File f2 = File(argv[2], "w");
        Buffer buffer = Buffer(BUFFER_SIZE);
        int i, count = 0;

        while (f1.endOfFile() == false)
        {
            int read = f1.read(buffer, BUFFER_SIZE);
            count++;
        }
        
        for(i = count - 1; i >= 0; i--)
        {
            f1.seek(BUFFER_SIZE * i);
            int read = f1.read(buffer, BUFFER_SIZE);
            buffer.reverse(read);
            f2.seekEnd();
            f2.write(buffer, read);
        }

        f1.close();
        f2.close();
        return 0;
    }
    catch(Exception e)
    {
        e.printErrorDetails();
        //throw e;
    }
}
