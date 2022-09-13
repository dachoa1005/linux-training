#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    // char command[1000] = {0};
    // int result;
    // sprintf(command, "/home/dachoa1005/Desktop/linux-training/ %s; echo  %d", argv[1], result);
    // cout << command << endl;
    // system(command);
    // printf("Result: %s\n" , result);
    for (int i = 0; i < argc; i++){
        cout << argv[i] << endl;
    }
    return 12;
}
