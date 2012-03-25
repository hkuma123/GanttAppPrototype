// GanttFormView.h

#if !defined(AFX_GANTTFORMVIEW_H__2AE0963C_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
#define AFX_GANTTFORMVIEW_H__2AE0963C_8919_11D3_A1A5_0080C8885DBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GanttChartWnd.h"

class CGanttFormView : public CFormView
{
protected: 
    CGanttFormView();
    DECLARE_DYNCREATE(CGanttFormView)

public:
    //{{AFX_DATA(CGanttFormView)
    enum{ IDD = IDD_GANTTFORM_FORM };
    //}}AFX_DATA

public:
    CGanttChartWnd m_GanttChartWnd;


    CGanttFormDoc* GetDocument();


public:
    void SetInitialData();


    //{{AFX_VIRTUAL(CGanttFormView)
    public:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    
    virtual void OnInitialUpdate(); 
    virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
    virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
    virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
    virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
    //}}AFX_VIRTUAL


public:
    virtual ~CGanttFormView();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:


protected:
    //{{AFX_MSG(CGanttFormView)
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  
inline CGanttFormDoc* CGanttFormView::GetDocument()
   { return (CGanttFormDoc*)m_pDocument; }
#endif


//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_GANTTFORMVIEW_H__2AE0963C_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
