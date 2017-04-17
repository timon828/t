#pragma once
#include "CtButton.h"
class CtRadio : public CtButton
{
public:
	CtRadio();
	~CtRadio();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg LRESULT OnAction(WPARAM wParam, LPARAM lParam);
};

