; CLW �t�@�C���� MFC ClassWizard �̏����܂�ł��܂��B

[General Info]
Version=1
LastClass=CGanttChartWnd
LastTemplate=generic CWnd
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GanttForm.h"
LastPage=0

ClassCount=10
Class1=CGanttFormApp
Class2=CGanttFormDoc
Class3=CGanttFormView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=GanttCharWnd
Class7=CGanttChartWnd
Class8=CDateTitleWnd
Class9=CItemTitleWnd
Class10=CChartAreaWnd
Resource3=IDD_GANTTFORM_FORM

[CLS:CGanttFormApp]
Type=0
HeaderFile=GanttForm.h
ImplementationFile=GanttForm.cpp
Filter=N

[CLS:CGanttFormDoc]
Type=0
HeaderFile=GanttFormDoc.h
ImplementationFile=GanttFormDoc.cpp
Filter=N

[CLS:CGanttFormView]
Type=0
HeaderFile=GanttFormView.h
ImplementationFile=GanttFormView.cpp
Filter=D
LastObject=CGanttFormView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=GanttForm.cpp
ImplementationFile=GanttForm.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_GANTTFORM_FORM]
Type=1
Class=CGanttFormView
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTTON1,button,1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:GanttCharWnd]
Type=0
HeaderFile=GanttCharWnd.h
ImplementationFile=GanttCharWnd.cpp
BaseClass=generic CWnd
Filter=W
LastObject=GanttCharWnd

[CLS:CGanttChartWnd]
Type=0
HeaderFile=GanttChartWnd.h
ImplementationFile=GanttChartWnd.cpp
BaseClass=CWnd
Filter=W
LastObject=CGanttChartWnd
VirtualFilter=WC

[CLS:CDateTitleWnd]
Type=0
HeaderFile=DateTitleWnd.h
ImplementationFile=DateTitleWnd.cpp
BaseClass=CWnd
Filter=W
LastObject=CDateTitleWnd
VirtualFilter=WC

[CLS:CItemTitleWnd]
Type=0
HeaderFile=ItemTitleWnd.h
ImplementationFile=ItemTitleWnd.cpp
BaseClass=CWnd
Filter=W
LastObject=CItemTitleWnd
VirtualFilter=WC

[CLS:CChartAreaWnd]
Type=0
HeaderFile=ChartAreaWnd.h
ImplementationFile=ChartAreaWnd.cpp
BaseClass=CWnd
Filter=W
LastObject=CChartAreaWnd
VirtualFilter=WC

