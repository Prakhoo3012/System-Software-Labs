// The atime/mtime/ctime distinction is the trickiest part conceptually, so let's be precise:

// mtime changes when you edit the file's content.
// ctime changes when you edit the file's metadata — e.g., running chmod or chown bumps ctime but not mtime, because the content didn't change, only permissions did. Note: writing content also bumps ctime, since the size/mtime fields themselves are metadata being updated too — so ctime ≥ mtime always in practice.
// atime changes just by reading the file — even cat file.txt bumps it. (Many modern Linux systems mount filesystems with relatime or noatime for performance, so atime updates may be lazier than you'd expect — worth mentioning if your lab output looks odd.)
// Linux has no true creation/birth time exposed via classic stat() (some filesystems track it as st_birthtime via statx(), but that's a newer, separate call — not part of this lab)
#include <iostream>
#include <sys/stat.h>
#include <ctime>
#include <cerrno>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    struct stat fileStat;

    if (stat(argv[1], &fileStat) == -1) {
        cerr << "stat() failed for '" << argv[1] << "': "
             << strerror(errno) << endl;
        return 1;
    }

    cout << "File: " << argv[1] << endl;
    cout << "--------------------------------------------" << endl;

    cout << "a. Inode number       : " << fileStat.st_ino << endl;
    cout << "b. Hard link count    : " << fileStat.st_nlink << endl;
    cout << "c. UID (owner)        : " << fileStat.st_uid << endl;
    cout << "d. GID (group)        : " << fileStat.st_gid << endl;
    cout << "e. Size (bytes)       : " << fileStat.st_size << endl;
    cout << "f. Preferred block sz : " << fileStat.st_blksize << " bytes" << endl;
    cout << "g. Number of blocks   : " << fileStat.st_blocks
         << " (512-byte units)" << endl;

    // ctime() converts a time_t into a human-readable string.
    // Note: ctime() here means "convert time", unrelated to st_ctime's name -
    // an unfortunate naming collision in the C standard library.
    cout << "h. Last access time   : " << ctime(&fileStat.st_atime);
    cout << "i. Last modified time : " << ctime(&fileStat.st_mtime);
    cout << "j. Last change time   : " << ctime(&fileStat.st_ctime);

    return 0;
}