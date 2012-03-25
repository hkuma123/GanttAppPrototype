// MainFrm.h : CMainFrame 
//

#if !defined(AFX_MAINFRM_H__2AE09638_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
#define AFX_MAINFRM_H__2AE09638_8919_11D3_A1A5_0080C8885DBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
    
protected: 
    CMainFrame();
    DECLARE_DYNCREATE(CMainFrame)

public:

public:

    //{{AFX_VIRTUAL(CMainFrame)
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    //}}AFX_VIRTUAL

public:
    virtual ~CMainFrame();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:  
    CStatusBar  m_wndStatusBar;
    CToolBar    m_wndToolBar;

protected:
    //{{AFX_MSG(CMainFrame)
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_MAINFRM_H__2AE09638_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
