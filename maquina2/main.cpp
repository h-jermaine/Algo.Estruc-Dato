#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <string>
#include <iostream>
#define BT1 101
#define BT2 102

#define BTLEER 201
#define CAJALEER 202

#define BEDIT1 151
#define BEDIT2 152
#define BEDIT3 153


HWND boton1;
HWND boton2;

HWND cajaLeer;
HWND botonLeer;

HWND hEdtNum1;
HWND hEdtNum2;
HWND hEdtNum3;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

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
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Code::Blocks Template Windows App"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           800,                 /* The programs width */
           600,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );


    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

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


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HINSTANCE hThisInstance;
    HDC hdc;
    RECT rect;
    HWND filedit;
    char txt[1024];
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            cajaLeer = CreateWindowEx(0, _T("EDIT"), _T(""), ES_LEFT|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP|ES_MULTILINE, 150, 20, 200, 30,
                                       hwnd, (HMENU)CAJALEER,hThisInstance, NULL);;
            botonLeer = CreateWindowEx(0, "button", ("Leer"), WS_VISIBLE|WS_CHILD, 360, 20, 100, 30, hwnd, (HMENU)BTLEER,0, 0);;
            boton1 = CreateWindowEx(0, "button", ("Cambiar"), WS_VISIBLE|WS_CHILD, 390, 100, 100, 30, hwnd, (HMENU)BT1,0, 0);
            boton2 = CreateWindowEx(0, "button", ("Sig"), WS_VISIBLE|WS_CHILD, 495, 100, 100, 30, hwnd, (HMENU)BT2,0, 0);
            hEdtNum1 = CreateWindowEx(0, _T("EDIT"), _T(""), ES_LEFT|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP|ES_MULTILINE, 15, 100, 100, 30,
                                       hwnd, (HMENU)BEDIT1,hThisInstance, NULL);
            hEdtNum2 = CreateWindowEx(0, _T("EDIT"), _T(""), ES_LEFT|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP|ES_MULTILINE, 120, 100, 100, 30,
                                       hwnd, (HMENU)BEDIT2,hThisInstance, NULL);
            hEdtNum3 = CreateWindowEx(0, _T("EDIT"), _T(""), ES_LEFT|WS_CHILD|WS_VISIBLE|WS_BORDER|WS_TABSTOP|ES_MULTILINE, 225, 100, 150, 30,
                                       hwnd, (HMENU)BEDIT3,hThisInstance, NULL);
            break;
        case WM_COMMAND:
            if(wParam == BT1){
                filedit = GetDlgItem(hwnd, BEDIT1); // I tried with and without this
                //editlength = GetWindowTextLength(filedit);
                GetWindowText(filedit, txt, sizeof(txt));

                MessageBox(hwnd, txt, _T("edit text"), 0);
            }

            break;
        case WM_PAINT:{
            hdc = BeginPaint(hwnd, &ps);
            for(int i = 20; i < 420; i += 50){
                for(int j = 150; j < 450; j += 50){
                    TextOut(hdc, i, j, "*", 1);
                }
                std::cout << std::endl;
            }
            EndPaint(hwnd, &ps);
            return 0;
            break;
        }
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
