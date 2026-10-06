#include <stdio.h>
#include <stdlib.h>

int main() {
    setbuf(stdout,NULL);
    // 1. Open a text file for writing ("w")
    FILE *write_ptr = fopen("C:\\Users\\sir\\CLionProjects\\c90\\log.txt", "w");
    if (write_ptr == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    // Write text formatting
    fprintf(write_ptr, "System Log Entry\n");
    fprintf(write_ptr, "Status: OK\n");
    fclose(write_ptr); // Always close the file to flush buffers

    // 2. Open the text file for reading ("r")
    FILE *read_ptr = fopen("log.txt", "r");
    if (read_ptr == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    char buffer[256];
    printf("--- Reading Text File Content ---\n");
    // Read line-by-line until end-of-file
    while (fgets(buffer, sizeof(buffer), read_ptr) != NULL) {
        printf("%s", buffer);
    }

    fclose(read_ptr);
    return 0;
}
