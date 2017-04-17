// CtFrame.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Controls.h"
#include "CtFrame.h"


// CtFrame

IMPLEMENT_DYNAMIC(CtFrame, CWnd)

CtFrame::CtFrame()
{
	m_pTMenuBar = NULL;
}

CtFrame::~CtFrame()
{
}


BEGIN_MESSAGE_MAP(CtFrame, CWnd)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ACTIVATE()
	ON_WM_CTLCOLOR()
	ON_WM_DROPFILES()
	ON_WM_ERASEBKGND()
	ON_WM_KILLFOCUS()
	ON_WM_MOUSEACTIVATE()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSEHWHEEL()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_MOVE()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_WM_NCACTIVATE()
	ON_WM_NCCALCSIZE()
	ON_WM_NCCREATE()
	ON_WM_NCDESTROY()
	ON_WM_NCHITTEST()
	ON_WM_NCLBUTTONDBLCLK()
	ON_WM_NCLBUTTONDOWN()
	ON_WM_NCLBUTTONUP()
	ON_WM_NCMBUTTONDBLCLK()
	ON_WM_NCMBUTTONDOWN()
	ON_WM_NCMBUTTONUP()
	ON_WM_NCMOUSEHOVER()
	ON_WM_NCMOUSELEAVE()
	ON_WM_NCMOUSEMOVE()
	ON_WM_NCPAINT()
	ON_WM_NCRBUTTONDBLCLK()
	ON_WM_NCRBUTTONDOWN()
	ON_WM_NCRBUTTONUP()
	ON_WM_NCXBUTTONDBLCLK()
	ON_WM_NCXBUTTONDOWN()
	ON_WM_NCXBUTTONUP()
END_MESSAGE_MAP()



// CtFrame 메시지 처리기입니다.




int CtFrame::CreateFrame(CWnd* pWnd)
{
	if (pWnd == NULL)
		return -1;
	CRect rc;
	pWnd->GetClientRect(rc);
	if (Create(NULL, TEXT("CtFrame"), WS_CHILD | WS_VISIBLE, rc, pWnd, 1) == FALSE)
		return -1;

	LONG lStyle = GetWindowLong(GetSafeHwnd(), GWL_STYLE);
	lStyle |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	SetWindowLong(GetSafeHwnd(), GWL_STYLE, lStyle);
	lStyle = GetWindowLong(GetSafeHwnd(), GWL_EXSTYLE);
	lStyle |= WS_EX_ACCEPTFILES;
	SetWindowLong(GetSafeHwnd(), GWL_EXSTYLE, lStyle);

	OnSize(0, rc.Width(), rc.Height());
	ShowWindow(SW_SHOW);
	UpdateControl();
	return 0;
}


int CtFrame::tSetMenuBar(CtMenuBar* pTMenuBar)
{
	if (pTMenuBar == NULL)
		return -1;
	m_pTMenuBar = pTMenuBar;
	return 0;
}


CtMenuBar* CtFrame::tGetMenuBar()
{
	return m_pTMenuBar;
}


int CtFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CtWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


void CtFrame::OnDestroy()
{
	CtWnd::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CtFrame::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CtWnd::OnActivate(nState, pWndOther, bMinimized);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


HBRUSH CtFrame::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CtWnd::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void CtFrame::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnDropFiles(hDropInfo);
}


BOOL CtFrame::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return 0;
}


void CtFrame::OnKillFocus(CWnd* pNewWnd)
{
	CtWnd::OnKillFocus(pNewWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


int CtFrame::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CtWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
}


void CtFrame::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 마우스가 윈도우에 올라서 특정 시간동안 움직이지 않았을때 MOUSE_OVER 메세지 발생함.

	CtWnd::OnMouseHover(nFlags, point);
}


void CtFrame::OnMouseHWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// 이 기능을 사용하려면 Windows Vista 이상이 있어야 합니다.
	// _WIN32_WINNT 기호는 0x0600보다 크거나 같아야 합니다.
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnMouseHWheel(nFlags, zDelta, pt);
}


void CtFrame::OnMouseLeave()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnMouseLeave();
}


void CtFrame::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnMouseMove(nFlags, point);
}


BOOL CtFrame::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CtWnd::OnMouseWheel(nFlags, zDelta, pt);
}


void CtFrame::OnMove(int x, int y)
{
	CtWnd::OnMove(x, y);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CtFrame::OnSetFocus(CWnd* pOldWnd)
{
	CtWnd::OnSetFocus(pOldWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CtFrame::OnSize(UINT nType, int cx, int cy)
{
	CtWnd::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


BOOL CtFrame::OnNcActivate(BOOL bActive)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CtWnd::OnNcActivate(bActive);
}


void CtFrame::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}


BOOL CtFrame::OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (!CtWnd::OnNcCreate(lpCreateStruct))
		return FALSE;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return TRUE;
}


void CtFrame::OnNcDestroy()
{
	CtWnd::OnNcDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


LRESULT CtFrame::OnNcHitTest(CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CtWnd::OnNcHitTest(point);
}


void CtFrame::OnNcLButtonDblClk(UINT nHitTest, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcLButtonDblClk(nHitTest, point);
}


void CtFrame::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcLButtonDown(nHitTest, point);
}


void CtFrame::OnNcLButtonUp(UINT nHitTest, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcLButtonUp(nHitTest, point);
}


void CtFrame::OnNcMButtonDblClk(UINT nHitTest, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcMButtonDblClk(nHitTest, point);
}


void CtFrame::OnNcMButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcMButtonDown(nHitTest, point);
}


void CtFrame::OnNcMButtonUp(UINT nHitTest, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcMButtonUp(nHitTest, point);
}


void CtFrame::OnNcMouseHover(UINT nFlags, CPoint point)
{
	// 이 기능을 사용하려면 Windows 2000 이상이 필요합니다.
	// _WIN32_WINNT 및 WINVER 기호는 0x0500보다 크거나 같아야 합니다.
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcMouseHover(nFlags, point);
}


void CtFrame::OnNcMouseLeave()
{
	// 이 기능을 사용하려면 Windows 2000 이상이 필요합니다.
	// _WIN32_WINNT 및 WINVER 기호는 0x0500보다 크거나 같아야 합니다.
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcMouseLeave();
}


void CtFrame::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcMouseMove(nHitTest, point);
}


void CtFrame::OnNcPaint()
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CtWnd::OnNcPaint()을(를) 호출하지 마십시오.
}


void CtFrame::OnNcRButtonDblClk(UINT nHitTest, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcRButtonDblClk(nHitTest, point);
}


void CtFrame::OnNcRButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcRButtonDown(nHitTest, point);
}


void CtFrame::OnNcRButtonUp(UINT nHitTest, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcRButtonUp(nHitTest, point);
}


void CtFrame::OnNcXButtonDblClk(short nFlags, UINT nButton, CPoint point)
{
	// 이 기능을 사용하려면 Windows 2000 이상이 필요합니다.
	// _WIN32_WINNT 및 WINVER 기호는 0x0500보다 크거나 같아야 합니다.
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcXButtonDblClk(nFlags, nButton, point);
}


void CtFrame::OnNcXButtonDown(short nFlags, UINT nButton, CPoint point)
{
	// 이 기능을 사용하려면 Windows 2000 이상이 필요합니다.
	// _WIN32_WINNT 및 WINVER 기호는 0x0500보다 크거나 같아야 합니다.
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcXButtonDown(nFlags, nButton, point);
}


void CtFrame::OnNcXButtonUp(short nFlags, UINT nButton, CPoint point)
{
	// 이 기능을 사용하려면 Windows 2000 이상이 필요합니다.
	// _WIN32_WINNT 및 WINVER 기호는 0x0500보다 크거나 같아야 합니다.
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnNcXButtonUp(nFlags, nButton, point);
}
