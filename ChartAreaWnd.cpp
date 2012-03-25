// ChartAreaWnd.cpp 
//

#include "stdafx.h"
#include "DataSizeDef.h"
#include "GanttForm.h"
#include "ChartAreaWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CChartAreaWnd::CChartAreaWnd()
{
    dragStatus = 0;
}

CChartAreaWnd::~CChartAreaWnd()
{
}


BEGIN_MESSAGE_MAP(CChartAreaWnd, CWnd)
    //{{AFX_MSG_MAP(CChartAreaWnd)
    ON_WM_LBUTTONDOWN()
    ON_WM_MOUSEMOVE()
    ON_WM_LBUTTONUP()
    ON_WM_PAINT()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()



BOOL CChartAreaWnd::PreCreateWindow(CREATESTRUCT& cs) 
{
    BackColor.CreateSolidBrush( RGB(255, 255, 255) );
    cs.lpszClass = AfxRegisterWndClass(
                        NULL, 
                        AfxGetApp()->LoadStandardCursor(IDC_ARROW),
                        (HBRUSH)BackColor.GetSafeHandle()
                    );

    return CWnd::PreCreateWindow(cs);
}

void CChartAreaWnd::OnLButtonDown(UINT nFlags, CPoint point) 
{
    spx = DpToLpX( point.x );
    spy = DpToLpY( point.y );

    int pick_flag = PickJob( point );

    CWnd::OnLButtonDown(nFlags, point);
}

void CChartAreaWnd::OnMouseMove(UINT nFlags, CPoint point) 
{

    if ( point.x < 0 || drawWidth  < point.x ||
         point.y < 0 || drawHeight < point.y )
         return;

    if ( (spx + timeWidth/2) < point.x) { 
        point.x = spx + timeWidth;
        spx = spx + timeWidth;
    }else if ( (spx - timeWidth/2) > point.x) { 
        point.x = spx - timeWidth;
        spx = spx - timeWidth;
    }else{
        return;
    }

    if ( dragStatus == 1 )
        DrawRubberRectangle( bwx1, bwy1, bwx2, bwy2 ); 

    if ( dragStatus == 2 )
        DrawRubberRectangle( owx1, owy1, owx2, owy2 ); 

    if ( dragStatus == 1 || dragStatus == 2 ){

        // left expand
        if ( rubberType == 1 ) { 
            wx1 = point.x - pick_x ; 
            wx2 = bwx2; 
        }
            
        // move
        if ( rubberType == 2 ) { 
            wx1 = point.x - pick_x ; 
            wx2 = wx1 + (bwx2-bwx1); 
        }

        // right expand
        if ( rubberType == 3 ) { 
            wx1 = bwx1; 
            wx2 = point.x - pick_x + ( bwx2 - bwx1 ) ;
        }

        wy1 = bwy1; 
        wy2 = bwy2; 

        DrawRubberRectangle( wx1, wy1, wx2, wy2 );

        owx1 = wx1;
        owx2 = wx2;
        owy1 = wy1;
        owy2 = wy2;

        dragStatus =2;
    }

    CWnd::OnMouseMove(nFlags, point);
}

void CChartAreaWnd::OnLButtonUp(UINT nFlags, CPoint point) 
{
    
    if ( dragStatus == 0 ){ 
        dragStatus = 0;
        return;
    }

    if ( dragStatus == 1 ){
        DrawRubberRectangle( bwx1, bwy1, bwx2, bwy2 );
        dragStatus = 0;
        return;
    }

    dragStatus = 0;

    DrawRubberRectangle( owx1, owy1, owx2, owy2 );


    CTime oldStartTime = currentJob->startTime;
    CTime oldEndTime   = currentJob->endTime;

    int startDate = ( wx1 - 0 ) / timeWidth ;
    int endDate   = ( wx2 - 0 ) / timeWidth ;

    CTimeSpan tmSpan1( startDate, 0,0,0 );
    CTimeSpan tmSpan2( endDate,   0,0,0 );

    currentJob->startTime = m_startTime + tmSpan1;  
    currentJob->endTime   = m_startTime + tmSpan2;
    
    CTimeSpan tmSpan3 = currentJob->endTime - currentJob->startTime; 

    currentJob->days = tmSpan3.GetDays();

    CheckNextJob( currentJob, oldEndTime );     
    CheckPreviousJob( currentJob, oldStartTime );     

    Invalidate();    

    CWnd::OnLButtonUp(nFlags, point);
}


void CChartAreaWnd::CheckNextJob( Job* icurrentJob, CTime ioldEndTime ) 
{
    CTime ioldEndTime2;    

    if ( icurrentJob->nextJob != NULL ){
        Job* nextJob = icurrentJob->nextJob;
        CTimeSpan tmSpan1 = icurrentJob->endTime -    ioldEndTime;
        ioldEndTime2 = nextJob->endTime;
        nextJob->startTime = nextJob->startTime + tmSpan1; 
        nextJob->endTime   = nextJob->endTime   + tmSpan1; 
        CTimeSpan tmSpan2 =  nextJob->endTime - nextJob->startTime; 
        nextJob->days = tmSpan2.GetDays();
        CheckNextJob( nextJob,ioldEndTime2  );
    }
}

void CChartAreaWnd::CheckPreviousJob( Job* icurrentJob, CTime ioldStartTime ) 
{
    CTime ioldStartTime2;    

    if ( icurrentJob->previousJob != NULL ){
        Job* previousJob = icurrentJob->previousJob;
        CTimeSpan tmSpan1 = icurrentJob->startTime - ioldStartTime;
        ioldStartTime2 = previousJob->startTime;
        previousJob->startTime = previousJob->startTime + tmSpan1; 
        previousJob->endTime   = previousJob->endTime   + tmSpan1; 
        CTimeSpan tmSpan2 =  previousJob->endTime - previousJob->startTime; 
        previousJob->days = tmSpan2.GetDays();
        CheckPreviousJob( previousJob,ioldStartTime2  );
    }
}


static char* DayOfWeeks[] = {
    "“y","“ú","ŒŽ","‰Î","…","–Ø","‹à","“y"
};

void CChartAreaWnd::OnPaint() 
{
    int      wx,wy;
    CPaintDC dc(this); 

    CDC* pDC = &dc;

    CRect winrect;

    GetClientRect( &winrect );

    drawWidth  = winrect.right ; 
    drawHeight = winrect.bottom; 

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

    pDC->Rectangle( 0, 0, winrect.right, winrect.bottom );

    for ( int i = 1; ; i++ ){
        wy = itemHeight * i;
        if ( wy >= ( winrect.bottom ) ) break ;
        pDC->MoveTo( 0, wy );
        pDC->LineTo( winrect.right, wy );
    }

    CPen dotPen( PS_DOT,   1, (COLORREF) 0 );
    CPen *oldPen;

    for ( int j = 1; ; j++ ){

        wx = timeWidth * j;
        if ( wx >= drawWidth ) break ;

        oldPen = pDC->SelectObject( &dotPen );
        pDC->MoveTo( wx, 0 );
        pDC->LineTo( wx, drawHeight );
        pDC->SelectObject( oldPen );
    }

    POSITION  pos = _pElemList->GetHeadPosition();
    while ( pos ) {
        Job* job  = _pElemList->GetNext( pos );
        int  itemId    = job->id;

        if( itemId >= m_startItemNo /* && itemId <=m_endItemNo */ ) { 

            CTimeSpan tmSpan1 = job->startTime - m_startTime;
            CTimeSpan tmSpan2 = job->endTime   - m_startTime;
            CTimeSpan tmSpan3 = job->endTime   - job->startTime;

            int startDate = tmSpan1.GetDays();
            int endDate   = tmSpan2.GetDays();
            int tmpDate   = tmSpan3.GetDays();
    
            bwx1 = (startDate) * timeWidth; 
            bwx2 = (endDate    )  * timeWidth ;
            bwy1 = (itemId-m_startItemNo-1)  * itemHeight + barMargin; 
            bwy2 = (itemId-m_startItemNo-1)  * itemHeight + barMargin + barHeight ;

            char* pBuff = (job->name).GetBuffer(BUFF_SIZE);
            DrawTaskBar( pDC, bwx1, bwy1, bwx2-bwx1, bwy2-bwy1, fHeight, pBuff );    
            (job->name).ReleaseBuffer();

            job->x1 = bwx1;
            job->y1 = bwy1;
            job->x2 = bwx2;
            job->y2 = bwy2;

        }

    }

    m_Font.DeleteObject();  //,fontInit=1;

}



int CChartAreaWnd::PickJob( CPoint ipoint ) 
{
    int pick_flag = 0;

    CPoint point = DpToLp( ipoint );

    POSITION  pos = _pElemList->GetHeadPosition();
    while ( pos ) {
        currentJob= _pElemList->GetNext( pos );
        int  itemId      = currentJob->id;
    
        bwx1 = currentJob->x1; 
        bwx2 = currentJob->x2;
        bwy1 = currentJob->y1; 
        bwy2 = currentJob->y2;
        
        if ( bwx1 < point.x && point.x < bwx2 && bwy1 < point.y && point.y < bwy2 ){ 
            pick_flag = 1;
            break;
        }
    }
    if( pick_flag ){
        dragStatus = 1;
        pick_x = point.x - bwx1;
        if ( point.x < (bwx1+expandCheckWidth) )        rubberType = 1;
        else if ( point.x > (bwx2-expandCheckWidth) )    rubberType = 3;
        else                                            rubberType = 2;

        DrawRubberRectangle( bwx1, bwy1, bwx2, bwy2 );
    
    }

    if ( rubberType == 2 )
        ::SetCursor( ::LoadCursor(NULL, IDC_SIZEALL) );

    return pick_flag;

}


void CChartAreaWnd::DrawRubberRectangle( int x1, int y1, int x2, int y2 )
{
    int  surroundDelta = 2;
    CDC* pDC = GetDC();

    pDC->SetBkColor( RGB(0,0,0) );              
    pDC->SetROP2( R2_XORPEN );                  
    pDC->SelectStockObject(NULL_BRUSH);         
    CPen pen( PS_SOLID, 2, RGB(255, 255, 0) );  
    CPen* oldPen = pDC->SelectObject( &pen );

    pDC->Rectangle( x1-surroundDelta, y1-surroundDelta, 
                    x2+surroundDelta, y2+surroundDelta );

    pDC->SelectObject( oldPen );
}

void CChartAreaWnd::DrawTaskBar( CDC* pDC, int x, int y, int w, int h, int fHeight, char* wbuff )
{
    int     x1,y1,x2,y2;
    CBrush* pOldBrush; 
    CPen*   pOldPen;
    CBrush  myBrush1;
    char    wbuff2[BUFF_SIZE];

    x1 = x;
    y1 = y;
    x2 = x + w;
    y2 = y + h;

    COLORREF col = RGB( 190, 190, 190 );
    
    CPen    pen1( PS_SOLID, 1, col );  
    myBrush1.CreateSolidBrush( col );
    pDC->SetBkColor( col );    
    pOldPen   = pDC->SelectObject( &pen1 );
    pOldBrush = pDC->SelectObject( &myBrush1 );

    pDC->Rectangle( x1, y1, x2, y2 );    

    pDC->MoveTo( x1, y1 );
    pDC->LineTo( x2, y1 );
    pDC->LineTo( x2, y2 );
    pDC->LineTo( x1, y2 );
    pDC->LineTo( x1, y1 );

    pDC->SelectObject( pOldPen );
    pDC->SelectObject( pOldBrush );

    x1 = x1+1;
    y1 = y1+1;    
    x2 = x2-1;
    y2 = y2-1;


    CPen    pen2( PS_SOLID, 1, RGB(255, 255, 255) );  
    pOldPen = pDC->SelectObject( &pen2 );
    pDC->MoveTo( x1, y1 );
    pDC->LineTo( x2, y1 );
    pDC->MoveTo( x1, y1 );
    pDC->LineTo( x1, y2 );
    pDC->SelectObject( pOldPen );


    CPen    pen3( PS_SOLID, 1, RGB(0, 0, 0) );  
    pOldPen = pDC->SelectObject( &pen3 );
    pDC->MoveTo( x2, y2 );
    pDC->LineTo( x2, y1 );
    pDC->MoveTo( x2, y2 );
    pDC->LineTo( x1, y2 );
    pDC->SelectObject( pOldPen );


    int slen = strlen(wbuff);

    for(;;) {
        if ( (fHeight/2)*slen > w ) 
            slen = slen - 2;
        else
            break;
    }

    if ( slen > 0 ){ 
        strncpy( wbuff2, wbuff, slen );
        wbuff2[slen] = '\0';
        pDC->TextOut( x1 + (w-(fHeight/2)*strlen(wbuff2))/2, 
                      y1 + (h-(fHeight))/2 ,
                      wbuff2, strlen(wbuff2) );
    }

}

void CChartAreaWnd::IncDay( int i ) 
{
    CTimeSpan sdate( i, 0, 0, 0 );        
    m_startTime = m_startTime + sdate;
}

void CChartAreaWnd::DecDay( int i )
{
    CTimeSpan sdate( i, 0, 0, 0 );        
    m_startTime = m_startTime - sdate;
}

void CChartAreaWnd::SetDay( CTime itime  )
{
    m_startTime = itime;
}

void CChartAreaWnd::IncItem( int i ) 
{
    m_startItemNo = m_startItemNo +i;
}

void CChartAreaWnd::DecItem( int i )
{
    m_startItemNo = m_startItemNo -i;
}

void CChartAreaWnd::SetItem( int i )
{
    m_startItemNo = i;
}


CPoint CChartAreaWnd::DpToLp( CPoint point ) { return point; }
int    CChartAreaWnd::DpToLpX( int ix ) { return ix; }
int    CChartAreaWnd::DpToLpY( int iy ) { return iy; }

CPoint CChartAreaWnd::LpToDp( CPoint point ) { return point; }
int    CChartAreaWnd::LpToDpX( int ix ) { return ix; }
int    CChartAreaWnd::LpToDpY( int iy ) { return iy; }


