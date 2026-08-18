#include <iostream>
#include <unistd.h>
#include <cerrno>
#include <cstring>
using namespace std;

#define BUF_SIZE 128

int main() {
    char buffer[BUF_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(0, buffer, BUF_SIZE)) > 0) {
        ssize_t bytes_written = write(1, buffer, bytes_read); // write(fd, location_of_data, data_toWirte);

        if (bytes_written == -1) {
            const char *err_msg = "write() failed\n";
            write(2, err_msg, strlen(err_msg));
            return 1;
        }
    }

    if (bytes_read == -1) {
        const char *err_msg = "read() failed\n";
        write(2, err_msg, strlen(err_msg));
        return 1;
    }

    // bytes_read == 0 means EOF was reached cleanly
    const char *bye = "-- EOF reached, exiting --\n";
    write(1, bye, strlen(bye));

    return 0;
}