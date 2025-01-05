#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// ANSI color codes for output
#define COLOR_GREEN "\033[1;32m"
#define COLOR_RED "\033[1;31m"
#define COLOR_RESET "\033[0m"


int main(void)
{
    const char *test_inputs[] = {
        "1",
        "2 1",
        "3 1 2",
        "4 3 2 1",
        "5 3 2 1 6",
        "6 9 0 7 5 4",
        "7 1 4 8 6 3 5",
        "8 7 1 4 2 6 3 5",
        "9 8 7 1 4 2 6 3 5",
        "10 9 8 7 1 4 2 6 3 5",
        "11 7 10 9 8 1 4 2 6 3 5",
        "12 11 7 10 9 8 1 4 2 6 3 5",
        NULL
    };

    for (int i = 0; test_inputs[i] != NULL; i++)
    {
        run_test(test_inputs[i]);
        printf("%s\n", test_inputs[i]);
    }

    return 0;
}

void run_test(const char *input)
{
    char command[1024];
    
    // Create the command to run push_swap and pipe it into checker
    snprintf(command, sizeof(command), "./push_swap %s | ./checker %s", input, input);

    // Execute the command
    FILE *output = popen(command, "r");
    if (!output)
    {
        fprintf(stderr, "Error: Failed to execute the command\n");
        return;
    }

    // Read the output from checker
    char result[256];
    if (fgets(result, sizeof(result), output))
    {
        // Check the result and print the appropriate output
        if (strncmp(result, "OK", 2) == 0)
        {
            printf(COLOR_GREEN "OK" COLOR_RESET "\n");
        }
        else
        {
            printf(COLOR_RED "KO" COLOR_RESET "\n");
        }
    }
    else
    {
        fprintf(stderr, "Error: No output from checker\n");
    }

    // Close the output pipe
    pclose(output);
}
