// GanttFormView.cpp : 
//

#include "stdafx.h"
#include "GanttForm.h"

#include "GanttFormDoc.h"
#include "GanttFormView.h"

#include <afxtempl.h>
#include "Job.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CGanttFormView, CFormView)

BEGIN_MESSAGE_MAP(CGanttFormView, CFormView)
    //{{AFX_MSG_MAP(CGanttFormView)
    //}}AFX_MSG_MAP
    ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()


CGanttFormView::CGanttFormView()
    : CFormView(CGanttFormView::IDD)
{
    //{{AFX_DATA_INIT(CGanttFormView)
    //}}AFX_DATA_INIT

}

CGanttFormView::~CGanttFormView()
{
}

void CGanttFormView::DoDataExchange(CDataExchange* pDX)
{
    CFormView::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CGanttFormView)
    //}}AFX_DATA_MAP
}

BOOL CGanttFormView::PreCreateWindow(CREATESTRUCT& cs)
{

    return CFormView::PreCreateWindow(cs);
}

void CGanttFormView::OnInitialUpdate()
{
    CFormView::OnInitialUpdate();
    GetParentFrame()->RecalcLayout();
    ResizeParentToFit();

    CRect    rect;
    int        year,month,day;

    m_GanttChartWnd.chartAreaWidth  = 640; 
    m_GanttChartWnd.chartAreaHeight = 400; 

    rect.left   = 16;
    rect.top    = 16;
    rect.right  = 16 + 760;    
    rect.bottom = 16 + 460;    

    m_GanttChartWnd.fontSize    = 14;    
    m_GanttChartWnd.itemHeight  = 40;    
    m_GanttChartWnd.timeWidth   = 40;   
    m_GanttChartWnd.barHeight   = 20;   
    m_GanttChartWnd.barMargin   = 10;   
    m_GanttChartWnd.expandCheckWidth = 16;

    m_GanttChartWnd.dispTotalNumOfDay  = 100;    
    m_GanttChartWnd.dispTotalNumOfItem = 100;    

    year  = 1999;
    month = 10;
    day   = 1; 

    m_GanttChartWnd.m_startTime = CTime( year, month, day, 0, 0, 0 );    
    m_GanttChartWnd.m_startItemNo = 1;    

    m_GanttChartWnd.dispItemTitle = TRUE; 
    m_GanttChartWnd.itemTitleWidth = 100;

    m_GanttChartWnd.dispDateTitle = TRUE; 
    m_GanttChartWnd.dateTitleHeight = 40; 
    
    m_GanttChartWnd.Create(NULL, "Gantt", WS_VISIBLE | WS_CHILD, rect, this, 555 );

    SetInitialData();
}


void CGanttFormView::SetInitialData()
{
    Job* job1;
    Job* job2;
    Job* job3;
    Job* job4;

    job1 = new Job();
    job1->id        = 2;
    job1->name      = "ì‹Æ|‚P";
    job1->days      = 5;
    job1->startTime = CTime( 1999, 10, 3, 0,0,0 );
    job1->endTime   = CTime( 1999, 10, 6, 0,0,0 );
    job1->previousJob = NULL;
    job1->nextJob     = NULL;
    m_GanttChartWnd._elemList.AddTail( job1 );

    job2 = new Job();
    job2->id        = 2;
    job2->name      = "ì‹Æ|‚Q";
    job2->days      = 5;
    job2->startTime = CTime( 1999, 10, 6, 0,0,0 );
    job2->endTime   = CTime( 1999, 10, 9, 0,0,0 );
    job2->previousJob = NULL;
    job2->nextJob     = NULL;
    m_GanttChartWnd._elemList.AddTail( job2 );

    job1->nextJob     = job2;    
    job2->previousJob = job1;    

    job3 = new Job();
    job3->id        = 2;
    job3->name      = "ì‹Æ|‚R";
    job3->days      = 5;
    job3->startTime = CTime( 1999, 10,9, 0,0,0 );
    job3->endTime   = CTime( 1999, 10,12, 0,0,0 );
    job3->previousJob = NULL;
    job3->nextJob     = NULL;
    m_GanttChartWnd._elemList.AddTail( job3 );

    job1->nextJob     = job2;    
    job2->previousJob = job1;    

    job2->nextJob     = job3;    
    job3->previousJob = job2;    

    job4 = new Job();
    job4->id        = 5;
    job4->name      = "ì‹Æ|‚S";
    job4->days      = 4;
    job4->startTime = CTime( 1999, 10,12, 0,0,0 );
    job4->endTime   = CTime( 1999, 10,15, 0,0,0 );
    job4->previousJob = NULL;
    job4->nextJob     = NULL;
    m_GanttChartWnd._elemList.AddTail( job4 );
}








BOOL CGanttFormView::OnPreparePrinting(CPrintInfo* pInfo)
{
    return DoPreparePrinting(pInfo);
}

void CGanttFormView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CGanttFormView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CGanttFormView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
}


#ifdef _DEBUG
void CGanttFormView::AssertValid() const
{
    CFormView::AssertValid();
}

void CGanttFormView::Dump(CDumpContext& dc) const
{
    CFormView::Dump(dc);
}

CGanttFormDoc* CGanttFormView::GetDocument() 
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGanttFormDoc)));
    return (CGanttFormDoc*)m_pDocument;
}
#endif 

