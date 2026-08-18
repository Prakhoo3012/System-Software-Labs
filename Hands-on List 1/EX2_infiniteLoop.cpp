#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

int main() {
    pid_t pid = getpid();
    cout << "My pid: " << pid << endl;
    cout << "Check /proc/" << pid << "/ in another terminal now." << endl;
    
    while(true) {
        cout << "Hello from: " << pid << endl;
        sleep(5);
    }

    return 0;
}
