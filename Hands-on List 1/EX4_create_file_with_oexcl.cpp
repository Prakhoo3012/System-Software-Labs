#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

using namespace std;

int main() {
    const char *filename = "creat_test.txt";

    int rw_fd = open(filename, O_RDWR);
    if (rw_fd == -1) {
        cerr << "O_RDWR open() failed: " << strerror(errno) << endl;
        return 1;
    }
    cout << "Opened '" << filename << "' with O_RDWR, fd = " << rw_fd << endl;

    char buffer[100] = {0};
    ssize_t n = read(rw_fd, buffer, sizeof(buffer) - 1);
    cout << "Read " << n << " bytes: " << buffer;

    const char *append_msg = "line two (written via same rw fd)\n";
    lseek(rw_fd, 0, SEEK_END);              // move to end before writing
    write(rw_fd, append_msg, strlen(append_msg));
    cout << "Wrote additional line using the same fd.\n" << endl;

    close(rw_fd);

    // Trying O_EXCL flag

    cout << "Attempting open() with O_CREAT|O_EXCL on an EXISTING file..." << endl;
    int excl_fd = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0644);
    if (excl_fd == -1) {
        cout << "  -> Failed as expected. errno = " << errno
             << " (" << strerror(errno) << ")" << endl;
    } else {
        cout << "  -> Unexpectedly succeeded, fd = " << excl_fd << endl;
        close(excl_fd);
    }


    return 0;
}