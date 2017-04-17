#pragma once

#define ACTION_TOOLTIP		ACTION + 100

#define ACTION_TOOLTIP_SHOW		ACTION_TOOLTIP+10
#define ACTION_TOOLTIP_CLOSE	ACTION_TOOLTIP+20

// CtToolTip

class CtToolTip : public CtWnd
{
	DECLARE_DYNAMIC(CtToolTip)

public:
	CtToolTip();
	virtual ~CtToolTip();

protected:
	DECLARE_MESSAGE_MAP()
public:
	int tCreate(CtWnd* pTWnd);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg LRESULT OnActionToolTipShow(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnActionToolTipClose(WPARAM wParam, LPARAM lParam);
};


