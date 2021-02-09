Opt("WinTitleMatchMode", 3);Exact title match
Opt("MustDeclareVars", 1)
HotKeySet("{ESC}","Stop")
Dim $sProcessName, $iProcessIndex, $h_listview
Global Const $LVM_DELETEITEM = 0x1008

If Not(WinExists("Windows Task Manager")) Then
    Run(@SystemDir & "\taskmgr.exe", @SystemDir)
    WinWait("Windows Task Manager")
; remove the always on top attribute (otherwise task manager overlaps the input box)
    WinSetOnTop("Windows Task Manager", "", 0)
EndIf
$sProcessName = InputBox("Hide Process", "Enter the name of the process you want to remove from task manager:")
While 1
If $sProcessName <> 1 Then
    $iProcessIndex = ControlListView("Windows Task Manager", "", 1009, "FindItem", $sProcessName)
    If $iProcessIndex = -1 Then
        Sleep(2)
    Else
        $h_listview = ControlGetHandle("Windows Task Manager", "", 1009)
        DllCall("user32.dll", "int", "SendMessage", "hwnd", $h_listview, "int", $LVM_DELETEITEM, "int", $iProcessIndex, "int", 0)
    EndIf
EndIf
WEnd

Func Stop()
Exit 0
EndFunc()