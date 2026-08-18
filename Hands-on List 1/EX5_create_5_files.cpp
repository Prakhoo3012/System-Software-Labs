#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

using namespace std;

int main() {
    const int NUM_FILES = 5;
    int fds[NUM_FILES];

    for (int i = 0; i < NUM_FILES; i++) {
        string filename = "file" + to_string(i + 1) + ".txt";

        fds[i] = open(filename.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (fds[i] == -1) {
            cerr << "open() failed for " << filename << ": "
                 << strerror(errno) << endl;
            return 1;
        }

        cout << "Opened " << filename << " with fd = " << fds[i] << endl;
    }

    pid_t pid = getpid();
    cout << "\nAll 5 files open. PID = " << pid << endl;
    cout << "Inspect now: ls -l /proc/" << pid << "/fd" << endl;

    // Keep the process alive (and the fds open) so we can inspect /proc
    while (true) {
        sleep(1);
    }

    return 0;
}