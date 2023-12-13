#include <stdio.h>

int main() {
    // Open the file
    FILE *file = fopen("datalahir	.txt", "r");

    // Check if the file is open
    if (file == NULL) {
        fprintf(stderr, "Error opening the file!\n");
        return 1; // Return an error code
    }

    // Read data from the file
    char line[100]; // Adjust the buffer size according to your needs
    while (fgets(line, sizeof(line), file) != NULL) {
        // Process each line as needed
        printf("%s", line);
    }

    // Close the file
    fclose(file);

    return 0; // Return success
}

