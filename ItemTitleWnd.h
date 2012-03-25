#if !defined(AFX_ITEMTITLEWND_H__2AE09648_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
#define AFX_ITEMTITLEWND_H__2AE09648_8919_11D3_A1A5_0080C8885DBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
#include "Job.h"


class CItemTitleWnd : public CWnd
{

public:
    CItemTitleWnd();


public:
    int     itemHeight ;
    int     m_startItemNo;
    CBrush    BackColor;
    CFont   m_Font;
    int     fontSize ;

    CList<Job*, Job*>  *_pElemList;


public:
    void  IncItem( int i); 
    void  DecItem( int i); 
    void  SetItem( int i); 

    void  DrawTextCenter( CDC* pDC, int x, int y, int w, int h, int fHeight, char* wbuff );
    void  DrawTaskBar( CDC* pDC, int x, int y, int w, int h, int fHeight, char* wbuff );


    //{{AFX_VIRTUAL(CItemTitleWnd)
    protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    //}}AFX_VIRTUAL


public:
    virtual ~CItemTitleWnd();

    
protected:
    //{{AFX_MSG(CItemTitleWnd)
    afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_ITEMTITLEWND_H__2AE09648_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
