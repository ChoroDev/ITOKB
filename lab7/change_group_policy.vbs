Set WshShell = WScript.CreateObject("WScript.Shell")
WshShell.RegWrite "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Group Policy Objects\{80CBF39A-F4B9-44D0-997A-869892E4C64B}User" & _
"\Software\Microsoft\Windows\CurrentVersion\Policies\Programs", "NoProgramsCPL"
WshShell.RegWrite "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Group Policy Objects\{80CBF39A-F4B9-44D0-997A-869892E4C64B}User" & _
"\Software\Microsoft\Windows\CurrentVersion\Policies\Programs\NoProgramsCPL", 0, "REG_DWORD"
WScript.Echo "NoProgramsCPL:" & (WshShell.RegRead("HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Group Policy Objects\" & _
"{80CBF39A-F4B9-44D0-997A-869892E4C64B}User\Software\Microsoft\Windows\CurrentVersion\Policies\Programs\NoProgramsCPL"))
