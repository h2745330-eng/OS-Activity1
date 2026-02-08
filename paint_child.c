#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    printf("Parent started.\n");

    if (!CreateProcess(
            NULL,
            "mspaint.exe",
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi
        )) {
        printf("CreateProcess failed. Error = %lu\n", GetLastError());
        return 1;
    }

    printf("Child created successfully.\n");
    printf("Child PID = %lu\n", pi.dwProcessId);
    printf("Parent exiting now.\n");

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
