// CtMenu.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Controls.h"
#include "CtMenu.h"


// CtMenu

IMPLEMENT_DYNAMIC(CtMenu, CWnd)

CtMenu::CtMenu()
{

}

CtMenu::~CtMenu()
{
}


BEGIN_MESSAGE_MAP(CtMenu, CWnd)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONUP()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CtMenu 메시지 처리기입니다.




int CtMenu::tCreate(CtWnd* pTWnd)
{
	return 0;
}


int CtMenu::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CtWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


void CtMenu::OnDestroy()
{
	CtWnd::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CtMenu::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnLButtonUp(nFlags, point);
}


void CtMenu::OnSetFocus(CWnd* pOldWnd)
{
	CtWnd::OnSetFocus(pOldWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CtMenu::OnKillFocus(CWnd* pNewWnd)
{
	CtWnd::OnKillFocus(pNewWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CtMenu::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnMouseHover(nFlags, point);
}


void CtMenu::OnMouseLeave()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnMouseLeave();
}


void CtMenu::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnMouseMove(nFlags, point);
}
