#include <stdio.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
    // Create the file with read-only permissions
    HANDLE hFile = CreateFile(
        "file.txt",            // File name
        GENERIC_WRITE,         // Desired access
        0,                     // Share mode (0 for exclusive access) (can be FILE_SHARE_READ)
        NULL,                  // Security attributes
        CREATE_ALWAYS,         // Creation disposition
        FILE_ATTRIBUTE_NORMAL, // File attributes
        NULL                   // Template file (not used)
    );

    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("Failed to create file.\n");
        return 1;
    }

    char buffer[] = "Hello, world!";
    DWORD bytesWritten;

    printf("Size of buffer is: %zu\n", sizeof(buffer));    // 14
    printf("String length of buffer is: %zu\n", strlen(buffer)); // 13

    if (!WriteFile(hFile, buffer, strlen(buffer), &bytesWritten, NULL))
    {
        printf("Failed to write to file.\n");
    }
    else
    {
        printf("Data written to file successfully.\n");
    }
    CloseHandle(hFile);
    return 0;
}

/* In Windows, you can use the CreateFile() function to create or open a file.
 * This function provides more control over file creation and attributes compared to the standard C fopen() function.
 */

/* Buffer array contains a string with a null terminator (\0) at the end.
 * When you use sizeof(buffer) to determine the size of the data to write, it includes this null terminator
 * Which is being interpreted as part of the data to be written to the file.
 * To fix this we can use:
 *    sizeof(buffer) - 1
 *    strlen(buffer)
 */