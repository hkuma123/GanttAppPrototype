// GanttChartWnd.cpp 
//

#include "stdafx.h"
#include "GanttForm.h"
#include "GanttChartWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CGanttChartWnd::CGanttChartWnd()
{
}

CGanttChartWnd::~CGanttChartWnd()
{
}


BEGIN_MESSAGE_MAP(CGanttChartWnd, CWnd)
    //{{AFX_MSG_MAP(CGanttChartWnd)
    ON_WM_CREATE()
    ON_WM_VSCROLL()
    ON_WM_HSCROLL()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()



BOOL CGanttChartWnd::PreCreateWindow(CREATESTRUCT& cs) 
{
    return CWnd::PreCreateWindow(cs);
}

int CGanttChartWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    
    return 0;
}

BOOL CGanttChartWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{

    BOOL  vbool = CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
    CRect rect1;
    int   scrollBarWidth  = 16;
    int   drawAreaXMargin = dispItemTitle ? 2 : 0; 
    int   drawAreaYMargin = dispDateTitle ? 2 : 0;

    // ---------------------------------------------------- 
    if ( dispDateTitle == TRUE ){

    m_DateTitleWnd.timeWidth  = timeWidth;
    m_DateTitleWnd.fontSize   = fontSize;

    rect1.left   = itemTitleWidth +drawAreaXMargin;    //x1
    rect1.top    = 0;    //y1
    rect1.right  = itemTitleWidth + drawAreaXMargin + chartAreaWidth;    //x2
    rect1.bottom = dateTitleHeight ;    //y2

    m_DateTitleWnd.Create(NULL, "D1", WS_VISIBLE | WS_CHILD , rect1, this, 999 );
    m_DateTitleWnd.m_startTime = m_startTime;

    }
    // ---------------------------------------------------- 
    if ( dispItemTitle == TRUE ){ 

    m_ItemTitleWnd.itemHeight = itemHeight;
    m_ItemTitleWnd.fontSize   = fontSize;

    rect1.left   = 0;    //x1
    rect1.top    = dateTitleHeight + drawAreaYMargin;    //y1
    rect1.right  = itemTitleWidth;     //x2
    rect1.bottom = dateTitleHeight + drawAreaYMargin + chartAreaHeight ;    //y2

    m_ItemTitleWnd.Create(NULL, "D2", WS_VISIBLE | WS_CHILD , rect1, this, 999 );
    m_ItemTitleWnd._pElemList = &_elemList;
    m_ItemTitleWnd.m_startItemNo = m_startItemNo;

    }
    // ---------------------------------------------------- 

    m_ChartAreaWnd.itemHeight = itemHeight;  
    m_ChartAreaWnd.timeWidth  = timeWidth;   
    m_ChartAreaWnd.barHeight  = barHeight;   
    m_ChartAreaWnd.barMargin  = barMargin;   
    m_ChartAreaWnd.fontSize   = fontSize;
    m_ChartAreaWnd.expandCheckWidth = expandCheckWidth;

    rect1.left   = itemTitleWidth  + drawAreaXMargin;    //x1
    rect1.top    = dateTitleHeight + drawAreaYMargin;    //y1
    rect1.right  = itemTitleWidth  + drawAreaXMargin + chartAreaWidth;     //x2
    rect1.bottom = dateTitleHeight + drawAreaYMargin + chartAreaHeight;    //y2

    m_ChartAreaWnd.Create(NULL, "D3", WS_VISIBLE | WS_CHILD , rect1, this, 999 );

    m_ChartAreaWnd._pElemList = &_elemList;
    m_ChartAreaWnd.m_startTime = m_startTime; 
    m_ChartAreaWnd.m_startItemNo = m_startItemNo;

    // ---------------------------------------------------- 

    rect1.left   = itemTitleWidth  + drawAreaXMargin;                     //x1
    rect1.top    = dateTitleHeight + drawAreaYMargin + chartAreaHeight +1 ;    //y1
    rect1.right  = itemTitleWidth  + drawAreaXMargin + chartAreaWidth;     //x2
    rect1.bottom = rect1.top + scrollBarWidth;                     //y2

    m_SBarH.Create( SBS_HORZ|WS_CHILD|WS_VISIBLE, rect1, this, 0 );
    m_SBarH.SetScrollRange(0,dispTotalNumOfDay-1);
    m_SBarH.SetScrollPos(0);

    // ---------------------------------------------------- 
    dispNumOfItem = 10; //attention : must calculate!

    rect1.left   = itemTitleWidth  + drawAreaXMargin + chartAreaWidth +1;  //x1
    rect1.top    = dateTitleHeight + drawAreaYMargin;         //y1
    rect1.right  = rect1.left + scrollBarWidth;       //x2
    rect1.bottom = dateTitleHeight + drawAreaYMargin + chartAreaHeight ; //y2

    m_SBarV.Create( SBS_VERT|WS_CHILD|WS_VISIBLE, rect1, this, 0 );
    m_SBarV.SetScrollRange(0,dispTotalNumOfItem-dispNumOfItem);
    m_SBarV.SetScrollPos(0);

    return vbool;
}

void CGanttChartWnd::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    int y,ymin,ymax;
    int ydelta = 10;
    int status = 0 ;

    y = pScrollBar->GetScrollPos();
    pScrollBar->GetScrollRange(&ymin, &ymax);

    switch(nSBCode)
    {
        case SB_THUMBPOSITION:
            status=1;
            y = nPos;
            SetItem(m_startItemNo+y);
            break;
        case SB_LINEUP:
            if ( y > ymin ){
                status=1;
                y--;
                DecItem(1);
            }
            break;
        case SB_LINEDOWN:
            if ( y < ymax ){
                status=1;
                y++;
                IncItem(1);
            }
            break;
        case SB_PAGEUP:
            if ( y - ydelta >= ymin ){
                status=1;
                y-=ydelta;
                DecItem(ydelta);
            }else {             
                status=1;
                DecItem( y - ymin );            
                y = ymin;
            }
            break;
        case SB_PAGEDOWN:
            if ( y + ydelta <= ymax ){
                status=1;
                y+=ydelta;
                IncItem(ydelta);
            }else {             
                status=1;
                IncItem( ymax - y );            
                y = ymax;
            }
            break;
    }

    //if ( y<ymin ) y = ymin;
    //else if ( y>ymax ) y = ymax;

    pScrollBar->SetScrollPos(y);

    if ( status )
        InvalidateVScroll();

    CWnd::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CGanttChartWnd::IncItem( int i )
{
    m_ChartAreaWnd.IncItem(i);
    m_ItemTitleWnd.IncItem(i);
}


void CGanttChartWnd::DecItem( int i )
{
    m_ChartAreaWnd.DecItem(i);
    m_ItemTitleWnd.DecItem(i);
}

void CGanttChartWnd::SetItem( int i )
{
    m_ChartAreaWnd.SetItem(i);
    m_ItemTitleWnd.SetItem(i);
}


void CGanttChartWnd::InvalidateVScroll()
{
    m_ChartAreaWnd.Invalidate();
    if ( m_ItemTitleWnd.GetSafeHwnd() )
        m_ItemTitleWnd.Invalidate();
}


void CGanttChartWnd::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    int x,xmin,xmax;
    int xdelta = 10;
    int status = 0 ;

    x = pScrollBar->GetScrollPos();
    pScrollBar->GetScrollRange(&xmin, &xmax);

    switch(nSBCode)
    {
        case SB_THUMBPOSITION:
            status=1;
            x = nPos;
            SetDay( m_startTime + CTimeSpan(x,0,0,0) );
            break;
        case SB_LINEUP:
            if ( x > xmin ){
                status=1;
                x--;
                DecDay(1);
            }
            break;
        case SB_LINEDOWN:
            if ( x < xmax ){
                status=1;
                x++;
                IncDay(1);
            }
            break;
        case SB_PAGEUP:
            if ( x - xdelta >= xmin ){
                status=1;
                x-=xdelta;
                DecDay(xdelta);
            }else {             
                status=1;
                DecDay( x - xmin );
                x = xmin;
            }
            break;
        case SB_PAGEDOWN:
            if ( x + xdelta <= xmax ){
                status=1;
                x+=xdelta;
                IncDay(xdelta);
            }else {             
                status=1;
                IncDay( xmax - x );            
                x = xmax;
            }
            break;
    }

    //if ( x<xmin ) x = xmin;
    //else if ( x>xmax ) x = xmax;

    pScrollBar->SetScrollPos(x);

    if ( status )
        InvalidateHScroll();

    CWnd::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CGanttChartWnd::IncDay( int i )
{
    m_DateTitleWnd.IncDay(i);
    m_ChartAreaWnd.IncDay(i);
}

void CGanttChartWnd::DecDay( int i )
{
    m_DateTitleWnd.DecDay(i);
    m_ChartAreaWnd.DecDay(i);
}

void CGanttChartWnd::SetDay( CTime itime )
{
    m_DateTitleWnd.SetDay(itime);
    m_ChartAreaWnd.SetDay(itime);
}

void CGanttChartWnd::InvalidateHScroll()
{
    m_ChartAreaWnd.Invalidate();
    if ( m_DateTitleWnd.GetSafeHwnd() )
        m_DateTitleWnd.Invalidate();
}
