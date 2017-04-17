// CtFrame.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Controls.h"
#include "CtFrame.h"


// CtFrame

IMPLEMENT_DYNAMIC(CtFrame, CWnd)

CtFrame::CtFrame()
{
	m_pTMenuBar = NULL;
}

CtFrame::~CtFrame()
{
}


BEGIN_MESSAGE_MAP(CtFrame, CWnd)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ACTIVATE()
	ON_WM_CTLCOLOR()
	ON_WM_DROPFILES()
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
	ON_WM_NCACTIVATE()
	ON_WM_NCCALCSIZE()
	ON_WM_NCCREATE()
	ON_WM_NCDESTROY()
	ON_WM_NCHITTEST()
	ON_WM_NCLBUTTONDBLCLK()
	ON_WM_NCLBUTTONDOWN()
	ON_WM_NCLBUTTONUP()
	ON_WM_NCMBUTTONDBLCLK()
	ON_WM_NCMBUTTONDOWN()
	ON_WM_NCMBUTTONUP()
	ON_WM_NCMOUSEHOVER()
	ON_WM_NCMOUSELEAVE()
	ON_WM_NCMOUSEMOVE()
	ON_WM_NCPAINT()
	ON_WM_NCRBUTTONDBLCLK()
	ON_WM_NCRBUTTONDOWN()
	ON_WM_NCRBUTTONUP()
	ON_WM_NCXBUTTONDBLCLK()
	ON_WM_NCXBUTTONDOWN()
	ON_WM_NCXBUTTONUP()
END_MESSAGE_MAP()



// CtFrame �޽��� ó�����Դϴ�.




int CtFrame::CreateFrame(CWnd* pWnd)
{
	if (pWnd == NULL)
		return -1;
	CRect rc;
	pWnd->GetClientRect(rc);
	if (Create(NULL, TEXT("CtFrame"), WS_CHILD | WS_VISIBLE, rc, pWnd, 1) == FALSE)
		return -1;

	LONG lStyle = GetWindowLong(GetSafeHwnd(), GWL_STYLE);
	lStyle |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	SetWindowLong(GetSafeHwnd(), GWL_STYLE, lStyle);
	lStyle = GetWindowLong(GetSafeHwnd(), GWL_EXSTYLE);
	lStyle |= WS_EX_ACCEPTFILES;
	SetWindowLong(GetSafeHwnd(), GWL_EXSTYLE, lStyle);

	OnSize(0, rc.Width(), rc.Height());
	ShowWindow(SW_SHOW);
	UpdateControl();
	return 0;
}


int CtFrame::tSetMenuBar(CtMenuBar* pTMenuBar)
{
	if (pTMenuBar == NULL)
		return -1;
	m_pTMenuBar = pTMenuBar;
	return 0;
}


CtMenuBar* CtFrame::tGetMenuBar()
{
	return m_pTMenuBar;
}


int CtFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CtWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return 0;
}


void CtFrame::OnDestroy()
{
	CtWnd::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CtFrame::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CtWnd::OnActivate(nState, pWndOther, bMinimized);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


HBRUSH CtFrame::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CtWnd::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}


void CtFrame::OnDropFiles(HDROP hDropInfo)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnDropFiles(hDropInfo);
}


BOOL CtFrame::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return 0;
}


void CtFrame::OnKillFocus(CWnd* pNewWnd)
{
	CtWnd::OnKillFocus(pNewWnd);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


int CtFrame::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CtWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
}


void CtFrame::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// ���콺�� �����쿡 �ö� Ư�� �ð����� �������� �ʾ����� MOUSE_OVER �޼��� �߻���.

	CtWnd::OnMouseHover(nFlags, point);
}


void CtFrame::OnMouseHWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// �� ����� ����Ϸ��� Windows Vista �̻��� �־�� �մϴ�.
	// _WIN32_WINNT ��ȣ�� 0x0600���� ũ�ų� ���ƾ� �մϴ�.
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnMouseHWheel(nFlags, zDelta, pt);
}


void CtFrame::OnMouseLeave()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnMouseLeave();
}


void CtFrame::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnMouseMove(nFlags, point);
}


BOOL CtFrame::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CtWnd::OnMouseWheel(nFlags, zDelta, pt);
}


void CtFrame::OnMove(int x, int y)
{
	CtWnd::OnMove(x, y);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CtFrame::OnSetFocus(CWnd* pOldWnd)
{
	CtWnd::OnSetFocus(pOldWnd);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CtFrame::OnSize(UINT nType, int cx, int cy)
{
	CtWnd::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


BOOL CtFrame::OnNcActivate(BOOL bActive)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CtWnd::OnNcActivate(bActive);
}


void CtFrame::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}


BOOL CtFrame::OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (!CtWnd::OnNcCreate(lpCreateStruct))
		return FALSE;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return TRUE;
}


void CtFrame::OnNcDestroy()
{
	CtWnd::OnNcDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


LRESULT CtFrame::OnNcHitTest(CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CtWnd::OnNcHitTest(point);
}


void CtFrame::OnNcLButtonDblClk(UINT nHitTest, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcLButtonDblClk(nHitTest, point);
}


void CtFrame::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcLButtonDown(nHitTest, point);
}


void CtFrame::OnNcLButtonUp(UINT nHitTest, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcLButtonUp(nHitTest, point);
}


void CtFrame::OnNcMButtonDblClk(UINT nHitTest, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcMButtonDblClk(nHitTest, point);
}


void CtFrame::OnNcMButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcMButtonDown(nHitTest, point);
}


void CtFrame::OnNcMButtonUp(UINT nHitTest, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcMButtonUp(nHitTest, point);
}


void CtFrame::OnNcMouseHover(UINT nFlags, CPoint point)
{
	// �� ����� ����Ϸ��� Windows 2000 �̻��� �ʿ��մϴ�.
	// _WIN32_WINNT �� WINVER ��ȣ�� 0x0500���� ũ�ų� ���ƾ� �մϴ�.
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcMouseHover(nFlags, point);
}


void CtFrame::OnNcMouseLeave()
{
	// �� ����� ����Ϸ��� Windows 2000 �̻��� �ʿ��մϴ�.
	// _WIN32_WINNT �� WINVER ��ȣ�� 0x0500���� ũ�ų� ���ƾ� �մϴ�.
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcMouseLeave();
}


void CtFrame::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcMouseMove(nHitTest, point);
}


void CtFrame::OnNcPaint()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CtWnd::OnNcPaint()��(��) ȣ������ ���ʽÿ�.
}


void CtFrame::OnNcRButtonDblClk(UINT nHitTest, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcRButtonDblClk(nHitTest, point);
}


void CtFrame::OnNcRButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcRButtonDown(nHitTest, point);
}


void CtFrame::OnNcRButtonUp(UINT nHitTest, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcRButtonUp(nHitTest, point);
}


void CtFrame::OnNcXButtonDblClk(short nFlags, UINT nButton, CPoint point)
{
	// �� ����� ����Ϸ��� Windows 2000 �̻��� �ʿ��մϴ�.
	// _WIN32_WINNT �� WINVER ��ȣ�� 0x0500���� ũ�ų� ���ƾ� �մϴ�.
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcXButtonDblClk(nFlags, nButton, point);
}


void CtFrame::OnNcXButtonDown(short nFlags, UINT nButton, CPoint point)
{
	// �� ����� ����Ϸ��� Windows 2000 �̻��� �ʿ��մϴ�.
	// _WIN32_WINNT �� WINVER ��ȣ�� 0x0500���� ũ�ų� ���ƾ� �մϴ�.
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcXButtonDown(nFlags, nButton, point);
}


void CtFrame::OnNcXButtonUp(short nFlags, UINT nButton, CPoint point)
{
	// �� ����� ����Ϸ��� Windows 2000 �̻��� �ʿ��մϴ�.
	// _WIN32_WINNT �� WINVER ��ȣ�� 0x0500���� ũ�ų� ���ƾ� �մϴ�.
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CtWnd::OnNcXButtonUp(nFlags, nButton, point);
}
