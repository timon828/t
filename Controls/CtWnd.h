#pragma once


// CtWnd

class CtWnd : public CWnd
{
	DECLARE_DYNAMIC(CtWnd)

public:
	CtWnd();
	virtual ~CtWnd();
private:
	DWORD m_dwResult;	// 모달 다이얼로그 사용시 모달 리턴값
	CRect m_rcDlg;		// 다이얼로그 생성시 필요한 좌표로만 사용 생성 이후에는 사용하지 않는다.
	WORD m_nWndIDD;		// 윈도우의 아이디가 필요할 경우 설정해서 사용
	BOOL isModal;		// 모달 윈도우 여부
	std::vector<CtGroup*> m_vGroup;// 그룹이 생성되면 동적할당하여 사용한다.
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


