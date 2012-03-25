// GanttForm.h
//

#if !defined(AFX_GANTTFORM_H__2AE09634_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
#define AFX_GANTTFORM_H__2AE09634_8919_11D3_A1A5_0080C8885DBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
    #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       

class CGanttFormApp : public CWinApp
{
public:
    CGanttFormApp();

    //{{AFX_VIRTUAL(CGanttFormApp)
    public:
    virtual BOOL InitInstance();
    //}}AFX_VIRTUAL

    //{{AFX_MSG(CGanttFormApp)
    afx_msg void OnAppAbout();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_GANTTFORM_H__2AE09634_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
