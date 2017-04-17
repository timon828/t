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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nCheck = GetCheck();
	nCheck = (nCheck == BUTTON_CHECK_NONE) ? BUTTON_CHECK_SELECT : BUTTON_CHECK_NONE;
	SetCheck(nCheck);
	CtButton::OnLButtonUp(nFlags, point);
}
