#pragma once

#define BUTTON_CHECK_NONE 0
#define BUTTON_CHECK_SELECT 1
// CtButton

class CtButton : public CtWnd
{
	DECLARE_DYNAMIC(CtButton)

public:
	CtButton();
	virtual ~CtButton();
private:
	int m_nCheck;
protected:
	DECLARE_MESSAGE_MAP()
public:
	int tCreate(CtWnd* pTWnd);
	void SetCheck(int nCheck);
	int GetCheck();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg LRESULT OnAction(WPARAM wParam, LPARAM lParam);
};


