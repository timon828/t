// CtToolTip.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Controls.h"
#include "CtToolTip.h"


// CtToolTip

IMPLEMENT_DYNAMIC(CtToolTip, CWnd)

CtToolTip::CtToolTip()
{

}

CtToolTip::~CtToolTip()
{
}


BEGIN_MESSAGE_MAP(CtToolTip, CWnd)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_MESSAGE(ACTION_TOOLTIP_SHOW, OnActionToolTipShow)
	ON_MESSAGE(ACTION_TOOLTIP_CLOSE, OnActionToolTipClose)
END_MESSAGE_MAP()



// CtToolTip �޽��� ó�����Դϴ�.




int CtToolTip::tCreate(CtWnd* pTWnd)
{
	return 0;
}


void CtToolTip::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnTimer(nIDEvent);
}


int CtToolTip::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CtWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return 0;
}


void CtToolTip::OnDestroy()
{
	CtWnd::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


LRESULT CtToolTip::OnActionToolTipShow(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT CtToolTip::OnActionToolTipClose(WPARAM wParam, LPARAM lParam)
{
	return 0;
}




