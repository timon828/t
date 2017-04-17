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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nCheck = GetCheck();
	nCheck = BUTTON_CHECK_SELECT;// 레디오 버튼은 무조건 셀렉트
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
	case ACTION_RELEASE_CHECK:// 체크해제
		int nCheck = GetCheck();
		nCheck = BUTTON_CHECK_NONE;
		SetCheck(nCheck);
		break;
	}
	return CtButton::OnAction(wParam, lParam);
}
