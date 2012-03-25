// ItemTitleWnd.cpp 
//

#include "stdafx.h"
#include "DataSizeDef.h"
#include "GanttForm.h"
#include "ItemTitleWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CItemTitleWnd::CItemTitleWnd()
{
}

CItemTitleWnd::~CItemTitleWnd()
{
}


BEGIN_MESSAGE_MAP(CItemTitleWnd, CWnd)
    //{{AFX_MSG_MAP(CItemTitleWnd)
    ON_WM_PAINT()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()



BOOL CItemTitleWnd::PreCreateWindow(CREATESTRUCT& cs) 
{
    BackColor.CreateSolidBrush( RGB(255, 255, 255) );  
    cs.lpszClass = AfxRegisterWndClass(
                        NULL, 
                        AfxGetApp()->LoadStandardCursor(IDC_ARROW),
                        (HBRUSH)BackColor.GetSafeHandle()
                    );

    return CWnd::PreCreateWindow(cs);
}

void CItemTitleWnd::OnPaint() 
{
    CPaintDC dc(this); 
    int      wy;
    char     wbuff[BUFF_SIZE];

    CDC* pDC = &dc;
    
    CRect winrect;

    GetClientRect( &winrect );

    

    
    
    m_Font.CreateFont( fontSize, 0, 0, 0, FW_NORMAL, 
                        FALSE, FALSE, FALSE,
                        SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS,
                        CLIP_DEFAULT_PRECIS,
                        DEFAULT_QUALITY, FIXED_PITCH | FF_MODERN, 
                        "‚l‚r –¾’©\0" );

    LOGFONT logFont;
    m_Font.GetLogFont( &logFont );
    int fHeight = logFont.lfHeight;    

    CFont* oldFont = (CFont *)pDC->SelectObject( m_Font );

    
    pDC->Rectangle( 0, 0, winrect.right, winrect.bottom );

    
    for ( int i = 1; ; i++ ){
        wy = itemHeight * i;
        if ( wy > winrect.bottom ) break ;
        pDC->MoveTo( 0, wy );
        pDC->LineTo( winrect.right, wy );
        wsprintf( wbuff, "ƒ‰ƒCƒ“ID-%02d ", m_startItemNo+i-1 );
        pDC->TextOut( fHeight/2, wy-fHeight-fHeight/2-6, wbuff, strlen(wbuff) );
        
    }


    m_Font.DeleteObject();  

    
}


void CItemTitleWnd::DrawTextCenter( CDC* pDC, int x, int y, int w, int h, int fHeight, char* wbuff )
{
    int     x1,y1,x2,y2;
    CBrush  myBrush1;
    char    wbuff2[BUFF_SIZE];

    x1 = x;
    y1 = y;
    x2 = x + w;
    y2 = y + h;

    
    
    
    

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

void CItemTitleWnd::DrawTaskBar( CDC* pDC, int x, int y, int w, int h, int fHeight, char* wbuff )
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


void CItemTitleWnd::IncItem( int i ) 
{
    m_startItemNo = m_startItemNo+i;
}

void CItemTitleWnd::DecItem( int i )
{
    m_startItemNo = m_startItemNo-i;
}

void CItemTitleWnd::SetItem( int i )
{
    m_startItemNo = i;
}
