/* Project: read_pipe_process
 *
 * Description: Works in conjunction with the make_and_write_pipe_process program. This program takes a file path, and
 *  opens the pipe file if the pipe has been created. Otherwise it waits until the pipe is created. Once created, the
 *  program listens for input entered into the pipe from the make_and_write_pipe_process and outputs it to the command
 *  line. Upon receiving "exit" or "quit" the program quits.
 *
 *  Author: Evan Bonsignori */

#include <iostream>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <unistd.h>

using namespace std;

const int MAX_STRING_SIZE = 180;
int pipe_instance = -1;
void sigintHandler(int sig_num);

int main() {
    // Catch ctrl+c signal
    signal(SIGINT, sigintHandler);

    char read_in[MAX_STRING_SIZE];

    string user_str;

    string pipe_file;
    printf("Enter location of existing pipe file, or path of location where another process will create a pipe file.\nPath: ");
    try {
        getline(cin, pipe_file);
    } catch (...) {
        printf("Invalid user input.\nExiting program...");
        return 1;
    }
    mkfifo(pipe_file.c_str(), 0777);

    printf("Waiting for pipe to be created...\n");
    while (pipe_instance < 1) {
        pipe_instance = open(pipe_file.c_str(), O_RDONLY);
    }
    printf("Pipe created!\nWaiting for user input...\n");

    while (true) {
        // Empty previous input
        memset(read_in, 0, sizeof(read_in));

        // Read from pipe
        read(pipe_instance, read_in, MAX_STRING_SIZE);

        // Print message from other user if there is a message
        if (read_in[0] != '\0') {
            printf("Message from other user: %s\n", read_in);
        }

        // Quit this program if other user entered quit or exit
        if (strcmp(read_in, "quit") == 0 || strcmp(read_in, "exit") == 0) {
            printf("Exit message received from other user.\nExiting program...");
            close(pipe_instance);
            return 0;
        }
    }
}

void sigintHandler(int sig_num) {
    signal(SIGINT, sigintHandler); // Always catch ctrl+c
    printf("\nPlease type exit or quit to halt execution...\n");
    fflush(stdout);
}