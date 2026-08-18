#include <iostream>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <unistd.h>      // symlink(), link()
#include <sys/stat.h>    // mkfifo()
#include <sys/types.h>
#include <fcntl.h>

using namespace std;

int main() {
    FILE *fp = fopen("original.txt", "w");
    if (fp == nullptr) {
        perror("fopen failed");
        return 1;
    }
    fprintf(fp, "This is the original file\n");
    fclose(fp);
    cout << "Created original.txt" << endl;

    // ---------- Step 1: soft link ----------
    if (symlink("original.txt", "soft_cpp.txt") == -1) {
        cerr << "symlink() failed: " << strerror(errno) << endl;
        return 1;
    }
    cout << "Soft link soft_cpp.txt created" << endl;

    // ---------- Step 2: hard link ----------
    if (link("original.txt", "hard_cpp.txt") == -1) {
        cerr << "link() failed: " << strerror(errno) << endl;
        return 1;
    }
    cout << "Hard link hard_cpp.txt created" << endl;

    // ---------- Step 3: FIFO ----------
    if (mkfifo("myfifo_cpp", 0666) == -1) {
        cerr << "mkfifo() failed: " << strerror(errno) << endl;
        return 1;
    }
    cout << "FIFO myfifo_cpp created" << endl;

    // ---------- Verify with stat() ----------
    struct stat st_orig, st_hard;
    stat("original.txt", &st_orig);
    stat("hard_cpp.txt", &st_hard);

    cout << "\nVerification:" << endl;
    cout << "  original.txt inode = " << st_orig.st_ino
         << ", link count = " << st_orig.st_nlink << endl;
    cout << "  hard_cpp.txt inode = " << st_hard.st_ino
         << ", link count = " << st_hard.st_nlink << endl;

    if (st_orig.st_ino == st_hard.st_ino)
        cout << "  -> Confirmed: hard link shares the same inode." << endl;

    return 0;
}
