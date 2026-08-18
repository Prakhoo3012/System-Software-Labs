#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cerrno>
#include <cstring>

using namespace std;

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <source_file> <destination_file>" << endl;
        return 1;
    }

    const char *src_path = argv[1];
    const char *dst_path = argv[2];

    int src_fd = open(src_path, O_RDONLY);
    if (src_fd == -1) {
        cerr << "Cannot open source '" << src_path << "': "
             << strerror(errno) << endl;
        return 1;
    }

    // ---------- Fetch source's permission bits, to mirror real cp behavior ----------
    struct stat src_stat;
    if (fstat(src_fd, &src_stat) == -1) {
        cerr << "fstat() failed: " << strerror(errno) << endl;
        close(src_fd);
        return 1;
    }
    mode_t src_mode = src_stat.st_mode & 0777;  // extract just the permission bits

    // ---------- Open/create destination (write only, truncate, same permissions) ----------
    int dst_fd = open(dst_path, O_CREAT | O_WRONLY | O_TRUNC, src_mode);
    if (dst_fd == -1) {
        cerr << "Cannot open destination '" << dst_path << "': "
             << strerror(errno) << endl;
        close(src_fd);
        return 1;
    }

    // ---------- Copy loop: read from src, write to dst, repeat until EOF ----------
    char buffer[BUF_SIZE];
    ssize_t bytes_read, bytes_written;
    long total_bytes = 0;

    while ((bytes_read = read(src_fd, buffer, BUF_SIZE)) > 0) {
        bytes_written = write(dst_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            cerr << "write() error or partial write to destination" << endl;
            close(src_fd);
            close(dst_fd);
            return 1;
        }
        total_bytes += bytes_written;
    }

    if (bytes_read == -1) {
        cerr << "read() error on source: " << strerror(errno) << endl;
        close(src_fd);
        close(dst_fd);
        return 1;
    }

    close(src_fd);
    close(dst_fd);

    cout << "Copied " << total_bytes << " bytes from '" << src_path
         << "' to '" << dst_path << "'" << endl;

    return 0;
}