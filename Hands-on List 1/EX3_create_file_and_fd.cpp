#include <iostream>
#include <fcntl.h>      // creat(), open() flags
#include <unistd.h>     // close(), write()
#include <cerrno>
#include <cstring>

using namespace std;

int main() {
    const char *filename = "creat_test.txt";

    // creat() is equivalent to open(filename, O_CREAT|O_WRONLY|O_TRUNC, mode)
    int fd = creat(filename, 0644);

    if (fd == -1) {
        cerr << "creat() failed: " << strerror(errno) << endl;
        return 1;
    }

    cout << "File '" << filename << "' created successfully." << endl;
    cout << "File descriptor value: " << fd << endl;

    close(fd);
    cout << "File descriptor " << fd << " closed." << endl;

    return 0;
}