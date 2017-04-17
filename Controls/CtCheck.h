#pragma once
#include "CtButton.h"
class CtCheck : public CtButton
{
public:
	CtCheck();
	~CtCheck();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

