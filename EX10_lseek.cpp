#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cerrno>
#include <cstring>

using namespace std;

int main() {
    const char *filename = "lseek_test.txt";

    int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd == -1) {
        cerr << "open() failed: " << strerror(errno) << endl;
        return 1;
    }

    // ---------- Write first 10 bytes ----------
    const char *first = "AAAAAAAAAA";   // exactly 10 bytes
    ssize_t w1 = write(fd, first, 10);
    cout << "Wrote " << w1 << " bytes: \"" << first << "\"" << endl;

    // ---------- Move the file offset forward by 10 bytes (leaving a gap) ----------
    off_t new_pos = lseek(fd, 10, SEEK_CUR);
    if (new_pos == -1) {
        cerr << "lseek() failed: " << strerror(errno) << endl;
        close(fd);
        return 1;
    }
    cout << "lseek() moved offset forward by 10; new offset = " << new_pos << endl;

    // ---------- Write next 10 bytes AFTER the gap ----------
    const char *second = "BBBBBBBBBB";  // exactly 10 bytes
    ssize_t w2 = write(fd, second, 10);
    cout << "Wrote " << w2 << " bytes: \"" << second << "\"" << endl;

    // ---------- Check resulting file size via fstat ----------
    struct stat st;
    fstat(fd, &st);
    cout << "\nFinal file size (st_size)   : " << st.st_size << " bytes" << endl;
    cout << "Blocks actually allocated   : " << st.st_blocks
         << " x 512-byte units = " << (st.st_blocks * 512) << " bytes" << endl;
    cout << "(Expected logical size = 10 + 10 + 10 = 30 bytes: "
         << "10 written, 10-byte gap, 10 written)" << endl;

    close(fd);
    cout << "\nNow inspect the raw bytes with: od -c " << filename << endl;

    return 0;
}