// DateTitleWnd.cpp
//

#include "stdafx.h"
#include "DataSizeDef.h"
#include "GanttForm.h"
#include "DateTitleWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CDateTitleWnd::CDateTitleWnd()
{
}

CDateTitleWnd::~CDateTitleWnd()
{
}


BEGIN_MESSAGE_MAP(CDateTitleWnd, CWnd)
    //{{AFX_MSG_MAP(CDateTitleWnd)
    ON_WM_PAINT()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()



BOOL CDateTitleWnd::PreCreateWindow(CREATESTRUCT& cs) 
{
    BackColor.CreateSolidBrush( RGB(255, 255, 255) );    // white
    cs.lpszClass = AfxRegisterWndClass(
                        NULL, 
                        AfxGetApp()->LoadStandardCursor(IDC_ARROW),
                        (HBRUSH)BackColor.GetSafeHandle()
                    );

    return CWnd::PreCreateWindow(cs);
}

static char* DayOfWeeks[] = {
    "Sat","Sun","Mon","Thu","Wed","Thr","Fri","Sat"
};

void CDateTitleWnd::OnPaint() 
{
    CPaintDC dc(this); 
    CRect    rect;
    int      wx,wy;
    char     wbuff1[BUFF_SIZE];
    char     wbuff2[BUFF_SIZE];

    GetClientRect( &rect );

    CDC* pDC = &dc;


    m_Font.CreateFont( fontSize, 0, 0, 0, FW_NORMAL, 
                        FALSE, FALSE, FALSE,
                        SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS,
                        CLIP_DEFAULT_PRECIS,
                        DEFAULT_QUALITY, FIXED_PITCH | FF_MODERN, 
                        "‚l‚r –¾’©\0" );

    LOGFONT logFont;
    m_Font.GetLogFont( &logFont );
    int fHeight = logFont.lfHeight;    // int lfWidth = logFont.lfWidth;

    CFont* oldFont = (CFont *)pDC->SelectObject( m_Font );

    // ----------------------------------------------------------

    CTime     date1 = m_startTime;    
    CTimeSpan sdate( 1, 0, 0, 0 );    

    CPen SolidPen( PS_SOLID, 1, (COLORREF) 0 );  // black
    CPen *oldPen;

    for ( int j = 1; ; j++ ){

        wx = timeWidth * j;

        if ( wx >(rect.right + timeWidth) ) break ;

        oldPen = pDC->SelectObject( &SolidPen );
        pDC->MoveTo( wx, 0 );
        pDC->LineTo( wx, rect.bottom );
        pDC->SelectObject( oldPen );            

        wsprintf( wbuff1, "%d/%02d", date1.GetMonth(), date1.GetDay()   );
        wsprintf( wbuff2, "%s",      DayOfWeeks[ date1.GetDayOfWeek() ] );
        wx = timeWidth * (j-1) + timeWidth/8;
        wy = rect.bottom/4 -2;
        pDC->TextOut( wx,   wy,    wbuff1, strlen(wbuff1) );
        pDC->TextOut( wx+8, wy+16, wbuff2, strlen(wbuff2) );

        date1 = date1 + sdate;    
    }

    pDC->SelectStockObject(NULL_BRUSH);
    pDC->Rectangle( 0, 0, rect.right, rect.bottom );

    m_Font.DeleteObject();  //,fontInit=1;
}

void CDateTitleWnd::IncDay( int i ) 
{
    CTimeSpan sdate( i, 0, 0, 0 );    
    m_startTime = m_startTime + sdate;
}

void CDateTitleWnd::DecDay( int i )
{
    CTimeSpan sdate( i, 0, 0, 0 );    
    m_startTime = m_startTime - sdate;
}

void CDateTitleWnd::SetDay( CTime itime )
{
    m_startTime = itime;
}
