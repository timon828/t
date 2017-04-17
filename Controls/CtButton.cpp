// CtButton.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Controls.h"
#include "CtButton.h"


// CtButton

IMPLEMENT_DYNAMIC(CtButton, CWnd)

CtButton::CtButton()
{
	m_nCheck = BUTTON_CHECK_NONE;
}

CtButton::~CtButton()
{
}


BEGIN_MESSAGE_MAP(CtButton, CWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZE()
	ON_MESSAGE(DO_ACTION, OnAction)
END_MESSAGE_MAP()



// CtButton �޽��� ó�����Դϴ�.




int CtButton::tCreate(CtWnd* pTWnd)
{
	return 0;
}


void CtButton::SetCheck(int nCheck)
{
	int tmp = m_nCheck;
	m_nCheck = nCheck;
	if (tmp != nCheck)
		UpdateControl();
}


int CtButton::GetCheck()
{
	return m_nCheck;
}


void CtButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	SetCapture();
	CtWnd::OnLButtonDown(nFlags, point);
}


void CtButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	ReleaseCapture();
	CtWnd::OnLButtonUp(nFlags, point);
}


void CtButton::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnMouseHover(nFlags, point);
}


void CtButton::OnMouseLeave()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnMouseLeave();
}


void CtButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnMouseMove(nFlags, point);
}


void CtButton::OnSize(UINT nType, int cx, int cy)
{
	CtWnd::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

LRESULT CtButton::OnAction(WPARAM wParam, LPARAM lParam)
{
	CtWnd* pTWnd = (CtWnd*)lParam;
	switch (wParam)
	{
	case ACTION_RELEASE_CHECK:
		
		break;
	}
	return CtWnd::OnAction(wParam, lParam);
}