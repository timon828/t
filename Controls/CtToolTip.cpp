// CtToolTip.cpp : 구현 파일입니다.
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



// CtToolTip 메시지 처리기입니다.




int CtToolTip::tCreate(CtWnd* pTWnd)
{
	return 0;
}


void CtToolTip::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CtWnd::OnTimer(nIDEvent);
}


int CtToolTip::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CtWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


void CtToolTip::OnDestroy()
{
	CtWnd::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


LRESULT CtToolTip::OnActionToolTipShow(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT CtToolTip::OnActionToolTipClose(WPARAM wParam, LPARAM lParam)
{
	return 0;
}




