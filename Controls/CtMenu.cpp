// CtMenu.cpp : ���� �����Դϴ�.
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



// CtMenu �޽��� ó�����Դϴ�.




int CtMenu::tCreate(CtWnd* pTWnd)
{
	return 0;
}


int CtMenu::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CtWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return 0;
}


void CtMenu::OnDestroy()
{
	CtWnd::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CtMenu::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnLButtonUp(nFlags, point);
}


void CtMenu::OnSetFocus(CWnd* pOldWnd)
{
	CtWnd::OnSetFocus(pOldWnd);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CtMenu::OnKillFocus(CWnd* pNewWnd)
{
	CtWnd::OnKillFocus(pNewWnd);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CtMenu::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnMouseHover(nFlags, point);
}


void CtMenu::OnMouseLeave()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnMouseLeave();
}


void CtMenu::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnMouseMove(nFlags, point);
}
