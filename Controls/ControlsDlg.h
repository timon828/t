
// ControlsDlg.h : ��� ����
//

#pragma once


// CControlsDlg ��ȭ ����
class CControlsDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CControlsDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	CtFrame m_frame;
// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CONTROLS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
