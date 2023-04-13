#ifndef F_MEDIA_CONFIG
#define F_MEDIA_CONFIG

#define F_MEDIA_CONFIG_SCREEN_WIDTH 200
#define F_MEDIA_CONFIG_SCREEN_HEIGHT 200

#define F_MEDIA_CONFIG_SCREEN_BACKGROUND_COLOR FM::col(FM::Colors::Black, ' ')
#define F_MEDIA_CONFIG_DEFAULT_COLOR FM::col(FM::Colors::Bright_White)

#define F_MEDIA_INIT
#ifdef _WIN32
#include <windows.h>
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#define DISABLE_NEWLINE_AUTO_RETURN 0x0008
void activateVirtualTerminal()
{
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode(handleOut, &consoleMode);
    consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    consoleMode |= DISABLE_NEWLINE_AUTO_RETURN;
    SetConsoleMode(handleOut, consoleMode);
}
#endif
#ifdef _ WIN32
activateVirtualTerminal();
#endif

#endif