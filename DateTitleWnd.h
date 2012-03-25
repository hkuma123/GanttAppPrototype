#if !defined(AFX_DATETITLEWND_H__2AE09647_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
#define AFX_DATETITLEWND_H__2AE09647_8919_11D3_A1A5_0080C8885DBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDateTitleWnd : public CWnd
{

public:
    CDateTitleWnd();


public:
    CBrush  BackColor;    
    CFont   m_Font;       
    CTime   m_startTime;  
    int     timeWidth;    
    int     fontSize ;    


public:
    void IncDay( int i ); 
    void DecDay( int i ); 
    void SetDay( CTime itime ); 


    //{{AFX_VIRTUAL(CDateTitleWnd)
    protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    //}}AFX_VIRTUAL


public:
    virtual ~CDateTitleWnd();

    
protected:
    //{{AFX_MSG(CDateTitleWnd)
    afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_DATETITLEWND_H__2AE09647_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
