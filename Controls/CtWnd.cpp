// CtWnd.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Controls.h"
#include "CtWnd.h"


// CtWnd

IMPLEMENT_DYNAMIC(CtWnd, CWnd)

CtWnd::CtWnd()
{
	m_rcDlg = CRect(0,0,100,100);// 기본 다이얼로그 사이즈 다이얼로그일때만 사용됨.
	m_dwResult = 0;
	isModal = FALSE;
}

CtWnd::~CtWnd()
{
	tDeleteAllGroup();
}


BEGIN_MESSAGE_MAP(CtWnd, CWnd)
	ON_WM_CLOSE()
	ON_WM_ACTIVATE()
	ON_WM_ACTIVATEAPP()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEHOVER()
	ON_MESSAGE(DO_ACTION, OnAction)
END_MESSAGE_MAP()



// CtWnd 메시지 처리기입니다.

int CtWnd::tCrete(CtWnd* pTWnd)
{
	UpdateControl();
	return 0;
}


int CtWnd::tSetToolTip(tTOOLTIP* pToolTip)
{
	UpdateControl();
	return 0;
}


tTOOLTIP* CtWnd::tGetToolTip()
{
	return NULL;
}


DWORD CtWnd::DoModal()
{
	return DoModal(GetDesktopWindow());
}

DWORD CtWnd::DoModal(CWnd* pParent)
{
	if (pParent == NULL)
		pParent = GetDesktopWindow();
	CString strClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, 0, (HBRUSH)(COLOR_WINDOW + 1));
	if (CreateEx(0, strClass, _T("CtDialog"), WS_POPUP, m_rcDlg.left, m_rcDlg.top, m_rcDlg.right, m_rcDlg.bottom, pParent->GetSafeHwnd(), NULL, NULL) == FALSE)
		return -1;
	if (GetSafeHwnd())
	{

	}
	isModal = TRUE;
	RunModalLoop(MLF_SHOWONIDLE);
	UpdateControl();
	return m_dwResult;
}



void CtWnd::CloseModal(DWORD dwResult)
{
	UpdateControl();
	EndModalLoop(dwResult);
	ShowWindow(SW_HIDE);
	m_dwResult = dwResult;
	CWnd::OnClose();
}


void CtWnd::OnCancel()
{
	if (isModal)
		CloseModal(IDCANCEL);
}


void CtWnd::OnOk()
{
	if (isModal)
		CloseModal(IDOK);
}



int CtWnd::tSetDialog(WORD id, int x, int y, int w, int h)
{
	tSetIDD(id);
	m_rcDlg = CRect(x, y, w, h);
	return 0;
}


int CtWnd::tSetIDD(WORD id)
{
	m_nWndIDD = id;
	return 0;
}


int CtWnd::tGetIDD()
{
	return m_nWndIDD;
}


void CtWnd::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (isModal)
		CloseModal(IDCANCEL);
}


void CtWnd::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CWnd::OnActivate(nState, pWndOther, bMinimized);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	UpdateControl();
}


void CtWnd::OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
	CWnd::OnActivateApp(bActive, dwThreadID);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	UpdateControl();
}


void CtWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	UpdateControl();
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


int CtWnd::UpdateControl()
{
	if (GetSafeHwnd())
	{
		CClientDC cdc(this);
		CRect rc;
		GetClientRect(rc);

		CDC memdc;
		memdc.CreateCompatibleDC(&cdc);
		CBitmap bit;
		bit.CreateCompatibleBitmap(&cdc, rc.right, rc.bottom);
		CBitmap* old = memdc.SelectObject(&bit);
		DrawControl(&memdc, rc);
		cdc.BitBlt(0, 0, rc.right, rc.bottom, &memdc, rc.left, rc.top, SRCCOPY);
		memdc.SelectObject(old);
		memdc.DeleteDC();
	}
	return 0;
}


int CtWnd::tAddGroup(int nGIDD)
{
	CtGroup* pGroup = tGetGroup(nGIDD);
	if (pGroup == NULL)
	{
		pGroup = new CtGroup();
		m_vGroup.push_back(pGroup);
	}
	return 0;
}


CtGroup* CtWnd::tGetGroup(int nGIDD)
{
	for (vector <int>::size_type i = 0; i < m_vGroup.size(); i++)
	{
		if (m_vGroup[i] == NULL)
			continue;
		if (m_vGroup[i]->GetIDD() == nGIDD)
			return m_vGroup[i];
	}
	return NULL;
}


CtGroup* CtWnd::tGetGroup(CtWnd* pTWnd)
{
	for (vector <int>::size_type i = 0; i < m_vGroup.size(); i++)
	{
		if (m_vGroup[i] == NULL)
			continue;
		if (m_vGroup[i]->IsItem(pTWnd))
			return m_vGroup[i];
	}
	return NULL;
}


int CtWnd::tDeleteGroup(int nGIDD)
{
	for (vector <int>::size_type i = 0; i < m_vGroup.size(); i++)
	{
		if (m_vGroup[i] == NULL)
			continue;
		if (m_vGroup[i]->GetIDD() == nGIDD)
		{
			CtGroup* pGroup = m_vGroup[i];
			delete pGroup;
			m_vGroup.erase(m_vGroup.begin() + i, m_vGroup.begin() + i);
			break;
		}
	}
	return 0;
}


int CtWnd::tDeleteAllGroup()
{
	for (vector <int>::size_type i = 0; i < m_vGroup.size(); i++)
	{
		if (m_vGroup[i] == NULL)
			continue;
		CtGroup* pGroup = m_vGroup[i];
		delete pGroup;
	}
	m_vGroup.clear();
	return 0;
}


int CtWnd::tAddGroupItem(int nGIDD, CtWnd* pTWnd)
{
	tAddGroup(nGIDD);
	CtGroup* pGroup = tGetGroup(nGIDD);
	if (pGroup == NULL)
		return -1;
	return pGroup->AddItem(pTWnd);
}


int CtWnd::tDeleteGroupItem(int nGIDD, CtWnd* pTWnd)
{
	CtGroup* pGroup = tGetGroup(nGIDD);
	if (pGroup == NULL)
		return -1;
	return pGroup->DeleteItem(pTWnd);
}



void CtWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	TRACKMOUSEEVENT MouseEvent;
	::ZeroMemory(&MouseEvent, sizeof(MouseEvent));
	MouseEvent.cbSize = sizeof(MouseEvent);
	MouseEvent.dwFlags = TME_LEAVE | TME_HOVER;
	MouseEvent.hwndTrack = GetSafeHwnd();
	MouseEvent.dwHoverTime = 500;
	::_TrackMouseEvent(&MouseEvent);
	UpdateControl();
	CWnd::OnMouseMove(nFlags, point);
}


void CtWnd::OnMouseLeave()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	UpdateControl();
	CWnd::OnMouseLeave();
}


void CtWnd::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 마우스가 윈도우에 올라서 특정 시간동안 움직이지 않았을때 MOUSE_OVER 메세지 발생함.
	UpdateControl();
	CWnd::OnMouseHover(nFlags, point);
}

LRESULT CtWnd::OnAction(WPARAM wParam, LPARAM lParam)
{
	CtWnd* pTWnd = (CtWnd*)lParam;
	switch (wParam)
	{
	case ACTION_GROUP_SELECT:
		if (pTWnd)
		{
			CtGroup* pGroup = tGetGroup(pTWnd);
			if (pGroup)
				pGroup->DoAction((CtWnd*)wParam);
		}
		break;
	}
	return 0;
}


int CtWnd::DrawControl(CDC* pDC, CRect rc)
{
	if (pDC == NULL)
		return -1;
	if (pDC->GetSafeHdc() == NULL)
		return -1;
	
	SKETCH::RECT(pDC, rc, TCR_BG, TCR_OUTLINE);
	return 0;
}