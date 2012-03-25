#if !defined(AFX_CHARTAREAWND_H__2AE09649_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
#define AFX_CHARTAREAWND_H__2AE09649_8919_11D3_A1A5_0080C8885DBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
#include "Job.h"

#define BUFF_SIZE    1024

class CChartAreaWnd : public CWnd
{

public:
    CChartAreaWnd();


public:
    CBrush    BackColor;

    int itemTitleWidth;     
    int dateTitleHeight;    
    int chartAreaWidth;     
    int chartAreaHeight;    

    int drawWidth;   
    int drawHeight;  

    int itemHeight;  
    int timeWidth;   
    int barHeight;   
    int barMargin;   

    int pick_x,pick_y;    
    int spx,spy;          

    int wx1,wy1,wx2,wy2;        
    int bwx1,bwy1,bwx2,bwy2;    
    int owx1,owy1,owx2,owy2;    

    int dragStatus;    
    int rubberType;    
    int expandCheckWidth;    

    CTime    m_startTime;      
    CTime   dispStartDate;    
    CTime   dispEndDate  ;    

    int     m_startItemNo;    
    int     dispStartItemNo;  
    int     dispEndItemNo;    

    int     dispNumOfDate;    
    int     dispNumOfItem;    

    Job* currentJob ;

    
    CList<Job*, Job*>  *_pElemList;
    CFont m_Font;
    int   fontSize;



public:

    void CheckNextJob( Job* icurrentJob, CTime ioldEndTime ) ;
    void CheckPreviousJob( Job* icurrentJob, CTime ioldStartTime ) ;

    
    void IncDay( int i ); 
    void DecDay( int i ); 
    void SetDay( CTime itime ); 

    
    void IncItem( int i ); 
    void DecItem( int i ); 
    void SetItem( int i );

    
    CPoint DpToLp( CPoint point ); 
    int    DpToLpX( int ix );
    int    DpToLpY( int iy );

    
    CPoint LpToDp( CPoint point );
    int    LpToDpX( int ix ); 
    int    LpToDpY( int iy );

    
    int    PickJob( CPoint ipoint ); 

    
    void   DrawRubberRectangle( int x1, int y1, int x2, int y2 );

    
    void   DrawTaskBar( CDC* pDC, int x, int y, int w, int h, int fHeight, char* wbuff );


    

    //{{AFX_VIRTUAL(CChartAreaWnd)
    protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    //}}AFX_VIRTUAL


public:
    virtual ~CChartAreaWnd();

    
protected:
    //{{AFX_MSG(CChartAreaWnd)
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}


#endif // !defined(AFX_CHARTAREAWND_H__2AE09649_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
