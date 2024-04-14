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
    }
    else
    {
        printf("File created successfully.\n");
        // Close the file
        CloseHandle(hFile);
    }

    /* SetFileAttributes() Function:
     * Used to set the attributes of a file.
     * Takes the file name and the attributes you want to set.
     * Returns TRUE if successful, or FALSE otherwise
     */
    // Set the file permissions to read-only
    if (SetFileAttributes("file.txt", FILE_ATTRIBUTE_READONLY))
    {
        printf("File attributes set successfully.\n");
    }
    else
    {
        printf("Failed to set file attributes.\n");
    }

    return 0;
}
