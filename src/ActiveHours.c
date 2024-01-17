// ActiveHours.c

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {

    // Open the key

    HKEY key = NULL;
    LONG Open = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\WindowsUpdate\\UX\\Settings", 0, KEY_READ, &key);

    if (Open != ERROR_SUCCESS) {

        printf("Could not open key.\n");
        return -1;
    }

    // Values we want

    DWORD szStart;
    DWORD tStart;

    DWORD szEnd;
    DWORD tEnd;

    const char* Value1 = "SmartActiveHoursStart";
    const char* Value2 = "SmartActiveHoursEnd";

    // Get data type and size

    LONG check1 = RegQueryValueExA(key, Value1, NULL, &tStart, NULL, &szStart);
    LONG check2 = RegQueryValueExA(key, Value2, NULL, &tEnd, NULL, &szEnd);

    if (check1 != ERROR_SUCCESS || check2 != ERROR_SUCCESS) {

        printf("Count not get data types or sizes.\n");

        RegCloseKey(key);

        return -1;

    }

    // Do the querys

    BYTE* Start = (BYTE*)malloc(szStart);
    BYTE* End = (BYTE*)malloc(szEnd);

    LONG check3 = RegQueryValueExA(key, Value1, NULL, &tStart, Start, &szStart);
    LONG check4 = RegQueryValueExA(key, Value2, NULL, &tEnd, End, &szEnd);

    if (check3 != ERROR_SUCCESS || check4 != ERROR_SUCCESS) {

        printf("Could not query values.\n");

        RegCloseKey(key);

        free(Start);
        free(End);

        return -1;
    }

    // Print values

    printf("SmartActiveHoursStart: %lu\n", *(DWORD*)Start);
    printf("SmartActiveHoursEnd: %lu\n", *(DWORD*)End);

    // Close key

    RegCloseKey(key);

    // No longer using this data we can free it

    free(Start);
    free(End);

    return 0;
}
