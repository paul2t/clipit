#include "stdio.h"
#include "windows.h"

#pragma comment(lib, "user32")

bool copy_to_clipboard(const void* content, size_t size) {
    bool result = false;
    if (OpenClipboard(0)) {
        EmptyClipboard();
        HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, size);
        if (hg) {
            memcpy(GlobalLock(hg), content, size);
            GlobalUnlock(hg);
            SetClipboardData(CF_TEXT, hg);
        }
        CloseClipboard();
        GlobalFree(hg);
    }
    return result;
}

bool is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// WinMain to avoid console showing up.
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    const char* line = GetCommandLineA();
    if (!line) return 0;

    // Skip the command path
    const char* at = line;
    if (*at == '\"') {
        // If it is surrounded with double quotes, we go to the other matching quote.
        // That may be the reason why " is not allowed in a file name on windows.
        ++at;
        while (*at && *at != '\"') {
            ++at;
        }
        ++at;
    } else {
        while (*at && !is_whitespace(*at)) {
            ++at;
        }
    }

    // skip one whitespace
    if (*at)
        ++at;

    // trim whitespaces at the start
    while (is_whitespace(*at)) {
        ++at;
    }

    const char* content = at;
    size_t len = strlen(content);

    // trim whitespaces at the end
    while (len > 0 && is_whitespace(content[len-1])) {
        --len;
    }
    
    copy_to_clipboard(content, len * sizeof(*line) + 1);

    return 0;
}
