#include "stdafx.h"
#include "CtCheck.h"


CtCheck::CtCheck()
{
}


CtCheck::~CtCheck()
{
}
BEGIN_MESSAGE_MAP(CtCheck, CtButton)
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


void CtCheck::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int nCheck = GetCheck();
	nCheck = (nCheck == BUTTON_CHECK_NONE) ? BUTTON_CHECK_SELECT : BUTTON_CHECK_NONE;
	SetCheck(nCheck);
	CtButton::OnLButtonUp(nFlags, point);
}
