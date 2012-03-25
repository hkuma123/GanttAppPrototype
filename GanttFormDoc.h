// GanttFormDoc.h 
//

#if !defined(AFX_GANTTFORMDOC_H__2AE0963A_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
#define AFX_GANTTFORMDOC_H__2AE0963A_8919_11D3_A1A5_0080C8885DBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGanttFormDoc : public CDocument
{
protected: 
    CGanttFormDoc();
    DECLARE_DYNCREATE(CGanttFormDoc)

public:

    //{{AFX_VIRTUAL(CGanttFormDoc)
    public:
    virtual BOOL OnNewDocument();
    virtual void Serialize(CArchive& ar);
    //}}AFX_VIRTUAL


public:
    virtual ~CGanttFormDoc();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    //{{AFX_MSG(CGanttFormDoc)
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_GANTTFORMDOC_H__2AE0963A_8919_11D3_A1A5_0080C8885DBF__INCLUDED_)
