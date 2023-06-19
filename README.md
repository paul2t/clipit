# clipit
This program copies all the arguments it receives to the Windows clipboard.

The whitespaces (`' ', '\t', '\n', '\r'`) at the beginning and end of the arguments are ignored.

Latest release : https://github.com/paul2t/clipit/releases/latest

# Add it to the context menu
By default you can `shift`+`right click` on Windows to copy the path of a file.

Here you can have it without having to press `shift`: https://www.winhelponline.com/blog/copy-as-path-always-show-right-click-windows-10/

But this path is surounded by double quotes. Which can be annoying sometimes.


With `clipit.exe` and `clipit_path.reg`, you can have a contextual menu item that will copy the path without those double quotes.

Unfortunately, it doesn't work with multiple files selected. Only one file path will be in the clipboard. I think it could be fixed by appending to the cliboard when the program is launched several times quickly. It will need to remember when it was last launched.

Copy `clipit.exe` where you want.

Launch `clipit_path.reg`

Using regedit, edit the registry key:

    HKEY_CLASSES_ROOT\Allfilesystemobjects\shell\clipit\command

And set it to the path where you put `clipit.exe`

The default value is:

    "%SystemDrive%\work\tools\bin\clipit.exe" %1

Keep the `%1` as it is what gives the path to the executable.
