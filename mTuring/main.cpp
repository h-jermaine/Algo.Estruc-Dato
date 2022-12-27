//#define _WIN32_WINNT 0x0500
#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <iostream>
#include <tchar.h>
#include <windows.h>
//#include "resource.h"

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (message)                  /* handle the messages */
    {
        case WM_PAINT:
            {
                hdc = BeginPaint(hwnd, &ps);
                //SelectObject(hdc, hfDefault);
                TCHAR text[] = "Defenestration can be hazardous";
                for(int i = 100; i < 300; i += 50){
                    for(int j = 100; j < 300; j += 50)
                    {
                        //Ellipse(hdc, i, j, 10, 10);
                        TextOut(hdc, i, j, "*", 1);
                    }
                    std::cout << std::endl;
                }
                //TextOut(hdc, 100, 100, text, ARRAYSIZE(text));
                Ellipse(hdc, 10, 10, 50, 50);
                Ellipse(hdc, 20, 20, 50, 50);

                EndPaint(hwnd, &ps);
                return 0;
                break;
            }
        /*case WM_PAINT:
            {
                hdc = BeginPaint(hwnd, &ps);
                //Ellipse(hdc, 10, 10, 50, 50);
                EndPaint(hwnd, &ps);
                break;
            }*/
        case WM_COMMAND:

           break;
        break;
            case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        /*case WM_LBUTTONDOWN:
            {
                char szFileName[MAX_PATH];
                HINSTANCE hInstance = GetModuleHandle(NULL);

                GetModuleFileName(hInstance, szFileName, MAX_PATH);
                MessageBox(hwnd, szFileName, "This program is:", MB_OK | MB_ICONINFORMATION);
            }*/
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK ButtonProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    //wincl.hIcon = LoadIcon (GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON));
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    //wincl.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 16, 16, 0);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    //wincl.lpszMenuName = MAKEINTATOM(IDR_MYMENU);                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    WNDCLASSEX wcButton = { 0 };
    wcButton.cbSize = sizeof(WNDCLASSEX);
    wcButton.style = CS_HREDRAW | CS_VREDRAW;
    wcButton.lpfnWndProc = ButtonProc;
    wcButton.hInstance = hThisInstance;
    wcButton.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcButton.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wcButton.lpszClassName = "Button";
    RegisterClassEx(&wcButton);

    if (!RegisterClassEx (&wcButton))
        return 0;

    HWND hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL,
    10, 10, 200, 50, hwnd, (HMENU)1, hThisInstance, NULL);
    if (!hEdit)
        return 1;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Code::Blocks Template Windows App"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           700,                 /* The programs width */
           450,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    HWND hButton = CreateWindowEx(0, "Button", "Obtener texto", WS_CHILD | WS_VISIBLE,
    10, 70, 100, 20, hwnd, (HMENU)2, hThisInstance, NULL);

    if (!hButton)
        return 1;
    /* Make the window visible on the screen */
    ShowWindow (hwnd, SW_SHOWDEFAULT);
    //MessageBox(NULL, "Goodbye, cruel world!", "Note", MB_OK);
    /* Para ocultar la ventana de cmd */
    //ShowWindow (GetConsoleWindow(), SW_HIDE);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


LRESULT CALLBACK ButtonProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HWND hEdit;
    switch (uMsg)
    {
    case WM_LBUTTONDOWN:
    {
        // Obtiene la longitud del texto ingresado por el usuario
        int textLength = GetWindowTextLength(hEdit) + 1;

        // Crea una matriz de caracteres para almacenar el texto
        char* text = new char[textLength];

        // Obtiene el texto ingresado por el usuario
        GetWindowText(hEdit, text, textLength);

        // Muestra el texto en un cuadro de diálogo
        MessageBox(NULL, text, "Texto ingresado", MB_OK);

        // Limpia la memoria
        delete[] text;

        return 0;
    }
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
