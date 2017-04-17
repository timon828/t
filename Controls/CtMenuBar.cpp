// CtMenuBar.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Controls.h"
#include "CtMenuBar.h"


// CtMenuBar

IMPLEMENT_DYNAMIC(CtMenuBar, CWnd)

CtMenuBar::CtMenuBar()
{

}

CtMenuBar::~CtMenuBar()
{
}


BEGIN_MESSAGE_MAP(CtMenuBar, CWnd)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ACTIVATE()
	ON_WM_CHANGEUISTATE()
	ON_WM_CTLCOLOR()
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
END_MESSAGE_MAP()



// CtMenuBar 메시지 처리기입니다.




int CtMenuBar::tCreate(CtWnd* pTWnd)
{
	return 0;
}


int CtMenuBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CtWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


void CtMenuBar::OnDestroy()
{
	CtWnd::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CtMenuBar::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CtWnd::OnActivate(nState, pWndOther, bMinimized);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CtMenuBar::OnChangeUIState(UINT nAction, UINT nUIElement)
{
	// 이 기능을 사용하려면 Windows 2000 이상이 필요합니다.
	// _WIN32_WINNT 및 WINVER 기호는 0x0500보다 크거나 같아야 합니다.
	CtWnd::OnChangeUIState(nAction, nUIElement);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


HBRUSH CtMenuBar::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CtWnd::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


BOOL CtMenuBar::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CtWnd::OnEraseBkgnd(pDC);
}


void CtMenuBar::OnKillFocus(CWnd* pNewWnd)
{
	CtWnd::OnKillFocus(pNewWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


int CtMenuBar::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CtWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
}


void CtMenuBar::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnMouseHover(nFlags, point);
}


void CtMenuBar::OnMouseHWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// 이 기능을 사용하려면 Windows Vista 이상이 있어야 합니다.
	// _WIN32_WINNT 기호는 0x0600보다 크거나 같아야 합니다.
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnMouseHWheel(nFlags, zDelta, pt);
}


void CtMenuBar::OnMouseLeave()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnMouseLeave();
}


void CtMenuBar::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnMouseMove(nFlags, point);
}


BOOL CtMenuBar::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CtWnd::OnMouseWheel(nFlags, zDelta, pt);
}


void CtMenuBar::OnMove(int x, int y)
{
	CtWnd::OnMove(x, y);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CtMenuBar::OnSetFocus(CWnd* pOldWnd)
{
	CtWnd::OnSetFocus(pOldWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CtMenuBar::OnSize(UINT nType, int cx, int cy)
{
	CtWnd::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
