#pragma once


// CtWnd

class CtWnd : public CWnd
{
	DECLARE_DYNAMIC(CtWnd)

public:
	CtWnd();
	virtual ~CtWnd();
private:
	DWORD m_dwResult;	// ��� ���̾�α� ���� ��� ���ϰ�
	CRect m_rcDlg;		// ���̾�α� ������ �ʿ��� ��ǥ�θ� ��� ���� ���Ŀ��� ������� �ʴ´�.
	WORD m_nWndIDD;		// �������� ���̵� �ʿ��� ��� �����ؼ� ���
	BOOL isModal;		// ��� ������ ����
	std::vector<CtGroup*> m_vGroup;// �׷��� �����Ǹ� �����Ҵ��Ͽ� ����Ѵ�.
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual int tCrete(CtWnd* pTWnd);
	int tSetToolTip(tTOOLTIP* pToolTip);
	tTOOLTIP* tGetToolTip();
	DWORD DoModal();
	DWORD DoModal(CWnd* pParent);
	void CloseModal(DWORD dwResult);
	void OnCancel();
	void OnOk();
	int tSetDialog(WORD id, int x, int y, int w, int h);
	int tSetIDD(WORD id);
	int tGetIDD();
	afx_msg void OnClose();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadID);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	int UpdateControl();
	int tAddGroup(int nGIDD);
	CtGroup* tGetGroup(int nGIDD);
	CtGroup* tGetGroup(CtWnd* pTWnd);
	int tDeleteGroup(int nGIDD);
	int tDeleteAllGroup();
	int tAddGroupItem(int nGIDD, CtWnd* pTWnd);
	int tDeleteGroupItem(int nGIDD, CtWnd* pTWnd);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg LRESULT OnAction(WPARAM wParam, LPARAM lParam);
	int DrawControl(CDC* pDC, CRect rc);
};


