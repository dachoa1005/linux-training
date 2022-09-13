#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int fd[2];  // pipe sẽ gồm 2 phương thức là wirte(fd[1]) và read(fd[0])
    pipe(fd);   //create pipe  
    int i, testval = 0, status;
    int val = 0;
    ofstream out{"sample.txt"};
    pid_t pid = fork();

    if (pid == 0)
    {
        // child process
        testval = 10010;
        //sent the value on the write descriptor:
        write(fd[1], &testval, sizeof(testval));
        cout << "child sent value: " << testval << endl;
        close(fd[1]);
    }
    else
    {
        // parent process
        close(fd[1]);
        // read the data from the child process
        read(fd[0], &testval, sizeof(testval));
        cout << "parent received value: " << testval << endl;
    }
    
    out.close();
    return 0;
}
