// CtMenuBar.cpp : ���� �����Դϴ�.
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



// CtMenuBar �޽��� ó�����Դϴ�.




int CtMenuBar::tCreate(CtWnd* pTWnd)
{
	return 0;
}


int CtMenuBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CtWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return 0;
}


void CtMenuBar::OnDestroy()
{
	CtWnd::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CtMenuBar::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CtWnd::OnActivate(nState, pWndOther, bMinimized);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CtMenuBar::OnChangeUIState(UINT nAction, UINT nUIElement)
{
	// �� ����� ����Ϸ��� Windows 2000 �̻��� �ʿ��մϴ�.
	// _WIN32_WINNT �� WINVER ��ȣ�� 0x0500���� ũ�ų� ���ƾ� �մϴ�.
	CtWnd::OnChangeUIState(nAction, nUIElement);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


HBRUSH CtMenuBar::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CtWnd::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}


BOOL CtMenuBar::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CtWnd::OnEraseBkgnd(pDC);
}


void CtMenuBar::OnKillFocus(CWnd* pNewWnd)
{
	CtWnd::OnKillFocus(pNewWnd);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


int CtMenuBar::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CtWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
}


void CtMenuBar::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnMouseHover(nFlags, point);
}


void CtMenuBar::OnMouseHWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// �� ����� ����Ϸ��� Windows Vista �̻��� �־�� �մϴ�.
	// _WIN32_WINNT ��ȣ�� 0x0600���� ũ�ų� ���ƾ� �մϴ�.
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnMouseHWheel(nFlags, zDelta, pt);
}


void CtMenuBar::OnMouseLeave()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnMouseLeave();
}


void CtMenuBar::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnMouseMove(nFlags, point);
}


BOOL CtMenuBar::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CtWnd::OnMouseWheel(nFlags, zDelta, pt);
}


void CtMenuBar::OnMove(int x, int y)
{
	CtWnd::OnMove(x, y);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CtMenuBar::OnSetFocus(CWnd* pOldWnd)
{
	CtWnd::OnSetFocus(pOldWnd);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CtMenuBar::OnSize(UINT nType, int cx, int cy)
{
	CtWnd::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}
