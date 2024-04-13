#include <stdio.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
    HANDLE hFile;
    DWORD dwBytesWritten;

    // Create the file with read-only permissions
    hFile = CreateFile("testfile.txt", GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        perror("Error creating file");
        return 1;
    }
    else
    {
        puts("Success creating file");
    }

    // Close the file
    CloseHandle(hFile);

    // Set the file permissions to read-only
    if (!SetFileAttributes("testfile.txt", FILE_ATTRIBUTE_READONLY))
    {
        perror("Error setting file attributes");
        return 1;
    }

    return 0;
}
