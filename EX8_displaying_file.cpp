#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

using namespace std;

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        cerr << "Cannot open '" << argv[1] << "': " << strerror(errno) << endl;
        return 1;
    }

    char line[MAX_LINE];
    int pos = 0;
    char ch;
    ssize_t n;
    int line_number = 1;

    while ((n = read(fd, &ch, 1)) > 0) {
        if (ch == '\n' || pos == MAX_LINE - 1) {
            line[pos] = '\0';
            cout << "Line " << line_number << ": " << line << endl;
            line_number++;
            pos = 0;
        } else {
            line[pos++] = ch;
        }
    }

    if (n == -1) {
        cerr << "read() error: " << strerror(errno) << endl;
        close(fd);
        return 1;
    }

    // Handle a final line that has no trailing '\n' before EOF
    if (pos > 0) {
        line[pos] = '\0';
        cout << "Line " << line_number << ": " << line << endl;
    }

    close(fd);
    cout << "-- End of file reached, fd closed --" << endl;

    return 0;
}