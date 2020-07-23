#include <iostream>
#include <windows.h>

int main()
{
    std::cout << "Hello World!\n";

    LPCTSTR windowName = L"Minecraft 1.8.9";
    auto hwnd = FindWindow(nullptr, windowName);

    std::cout << hwnd;

    if (GetWindowLongPtr(hwnd, GWL_STYLE) & WS_POPUP)
    {
        SetWindowLongPtr(hwnd, GWL_STYLE, WS_VISIBLE | WS_OVERLAPPEDWINDOW);
        SetWindowPos(hwnd, NULL, 0, 0, 600, 400, SWP_FRAMECHANGED);
    }
    else
    {
        int w = GetSystemMetrics(SM_CXSCREEN);
        int h = GetSystemMetrics(SM_CYSCREEN);
        SetWindowLongPtr(hwnd, GWL_STYLE, WS_VISIBLE | WS_POPUP);
        SetWindowPos(hwnd, HWND_TOP, 0, 0, w, h, SWP_FRAMECHANGED);
    }

    std::cin.get();
}