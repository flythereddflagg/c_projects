// from http://www.winprog.org/tutorial/start.html
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, int nCmdShow)
{
    MessageBox(NULL, "Hello World!", "Note", MB_OK);
    return 0;
}