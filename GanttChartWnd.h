#if !defined(AFX_GANTTCHARTWND_H__2AE09646_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
#define AFX_GANTTCHARTWND_H__2AE09646_8919_11D3_A1A5_0080C8885DBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DateTitleWnd.h"
#include "ItemTitleWnd.h"

#include "DateTitleWnd.h"
#include "ItemTitleWnd.h"
#include "ChartAreaWnd.h"

class CGanttChartWnd : public CWnd
{

public:
    CGanttChartWnd();


public:
    CBrush    BackColor;

    int  itemTitleWidth;
    int  dateTitleHeight;
    int  chartAreaWidth;
    int  chartAreaHeight;

    int  fontSize ;    
    int  itemHeight;  
    int  timeWidth;   
    int  barHeight;   
    int  barMargin;   
    int  expandCheckWidth;    

    int  dispTotalNumOfDay;
    int  dispTotalNumOfItem;

    int  dispNumOfDay;
    int  dispNumOfItem;

    int  dispItemTitle;
    int  dispDateTitle;

    CTime   m_startTime;      
    int     m_startItemNo;    

    CList<Job*, Job*>  _elemList;

    CItemTitleWnd  m_ItemTitleWnd;
    CDateTitleWnd  m_DateTitleWnd;
    CChartAreaWnd  m_ChartAreaWnd;
    CScrollBar     m_SBarH;
    CScrollBar     m_SBarV;


public:
    void    IncItem( int i );
    void    DecItem( int i );
    void    SetItem( int i );

    void    IncDay( int i );
    void    DecDay( int i );
    void    SetDay( CTime itime );

    void    InvalidateVScroll();
    void    InvalidateHScroll();


    //{{AFX_VIRTUAL(CGanttChartWnd)
    public:
    virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
    protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    //}}AFX_VIRTUAL


public:
    virtual ~CGanttChartWnd();

    
protected:
    //{{AFX_MSG(CGanttChartWnd)
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_GANTTCHARTWND_H__2AE09646_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)

