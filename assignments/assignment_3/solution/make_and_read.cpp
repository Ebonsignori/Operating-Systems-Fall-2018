/* Project: make_and_write_pipe_process
 *
 * Description: Works in conjunction with the read_pipe_process program. This program takes a file path, creates a pipe
 *  at that path (if it doesn't exist) and accepts command-line user input until "quit" or "exit" are entered. The input
 *  is written to the pipe file where it is read from the read_pipe_process program.
 *
 *  Author: Evan Bonsignori */

#include <iostream>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <unistd.h>
#include <signal.h>

using namespace std;

const int MAX_STRING_SIZE = 180;
int pipe_instance = -1;
void sigintHandler(int sig_num);

int main() {
    // Catch ctrl+c signal
    signal(SIGINT, sigintHandler);

    string user_str;

    string pipe_file;
    printf("Enter location of existing pipe file, or where to create a pipe file.\nPath: ");
    try {
        getline(cin, pipe_file);
    } catch (...) {
        printf("Invalid user input.\nExiting program...");
        return 1;
    }
    mkfifo(pipe_file.c_str(), 0777);

    printf("Waiting for another process to connect to pipe...\n");
    while (pipe_instance < 1) {
        pipe_instance = open(pipe_file.c_str(), O_WRONLY);
    }
    printf("Pipe created and connection initialized!\n");
    printf("Type quit or exit to halt program execution.\n");
    while (true) {
        try {
            printf("Message to send: ");
            getline(cin, user_str);
        } catch (...) {
            printf("Invalid user input.\nExiting program...");
            close(pipe_instance);
            return 1;
        }

        if (user_str.length() > MAX_STRING_SIZE) {
            printf("Please enter a message that is less than %d characters.\n", MAX_STRING_SIZE);
            continue;
        }

        try {
            write(pipe_instance, user_str.c_str(), user_str.length());
        } catch (...) {
            printf("Something went wrong while writing to pipe.\nExiting Program...");
            return 1;
        }

        // Quit program if user entered quit or exit
        if (user_str == "quit" || user_str == "exit") {
            printf("Exiting program...");
            close(pipe_instance);
            return 0;
        }
    }
}

void sigintHandler(int sig_num) {
    signal(SIGINT, sigintHandler); // Always catch ctrl+c
    printf("\nPlease type exit or quit to halt execution...\n");
//    fflush(stdout);
}