
// Controls.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CControlsApp:
// �� Ŭ������ ������ ���ؼ��� Controls.cpp�� �����Ͻʽÿ�.
//

class CControlsApp : public CWinApp
{
public:
	CControlsApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CControlsApp theApp;