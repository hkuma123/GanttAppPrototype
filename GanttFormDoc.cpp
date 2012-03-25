// GanttFormDoc.cpp 
//

#include "stdafx.h"
#include "GanttForm.h"

#include "GanttFormDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CGanttFormDoc, CDocument)

BEGIN_MESSAGE_MAP(CGanttFormDoc, CDocument)
    //{{AFX_MSG_MAP(CGanttFormDoc)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()


CGanttFormDoc::CGanttFormDoc()
{

}

CGanttFormDoc::~CGanttFormDoc()
{
}

BOOL CGanttFormDoc::OnNewDocument()
{
    if (!CDocument::OnNewDocument())
        return FALSE;

    return TRUE;
}




void CGanttFormDoc::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
    }
    else
    {
    }
}


#ifdef _DEBUG
void CGanttFormDoc::AssertValid() const
{
    CDocument::AssertValid();
}

void CGanttFormDoc::Dump(CDumpContext& dc) const
{
    CDocument::Dump(dc);
}
#endif //_DEBUG

