#include "stdafx.h"
#include "CtRadio.h"


CtRadio::CtRadio()
{
}


CtRadio::~CtRadio()
{
}

BEGIN_MESSAGE_MAP(CtRadio, CtButton)
	ON_WM_LBUTTONUP()
	ON_MESSAGE(DO_ACTION, OnAction)
END_MESSAGE_MAP()



void CtRadio::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int nCheck = GetCheck();
	nCheck = BUTTON_CHECK_SELECT;// ����� ��ư�� ������ ����Ʈ
	SetCheck(nCheck);
	CWnd* pParent = GetParent();
	if (pParent)
		pParent->SendMessage(DO_ACTION, (WPARAM)ACTION_GROUP_SELECT, (LPARAM)this);
	CtButton::OnLButtonUp(nFlags, point);
}

LRESULT CtRadio::OnAction(WPARAM wParam, LPARAM lParam)
{
	CtWnd* pTWnd = (CtWnd*)lParam;
	switch (wParam)
	{
	case ACTION_RELEASE_CHECK:// üũ����
		int nCheck = GetCheck();
		nCheck = BUTTON_CHECK_NONE;
		SetCheck(nCheck);
		break;
	}
	return CtButton::OnAction(wParam, lParam);
}
