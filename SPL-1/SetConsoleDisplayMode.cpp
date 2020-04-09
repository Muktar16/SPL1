BOOL NT_SetConsoleDisplayMode(HANDLE hOutputHandle, DWORD dwNewMode)

{
    typedef BOOL (WINAPI *SCDMProc_t) (HANDLE, DWORD, LPDWORD);
    SCDMProc_t SetConsoleDisplayMode;
    HMODULE hKernel32;
    BOOL bFreeLib = FALSE, ret;
    const char KERNEL32_NAME[] = "kernel32.dll";
    hKernel32 = GetModuleHandleA(KERNEL32_NAME);
    if (hKernel32 == NULL)
    {
        hKernel32 = LoadLibraryA(KERNEL32_NAME);
        if (hKernel32 == NULL)

            return FALSE;



        bFreeLib = true;

    }



    SetConsoleDisplayMode =

        (SCDMProc_t)GetProcAddress(hKernel32, "SetConsoleDisplayMode");

    if (SetConsoleDisplayMode == NULL)

    {

        SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
        ret = FALSE;
    }
    else
    {

        DWORD tmp;

        ret = SetConsoleDisplayMode(hOutputHandle, dwNewMode, &tmp);
    }
    if (bFreeLib)
        FreeLibrary(hKernel32);
    return ret;
}
