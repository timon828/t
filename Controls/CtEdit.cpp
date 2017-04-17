// CtEdit.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Controls.h"
#include "CtEdit.h"


// CtEdit

IMPLEMENT_DYNAMIC(CtEdit, CEdit)

CtEdit::CtEdit()
{

}

CtEdit::~CtEdit()
{
}


BEGIN_MESSAGE_MAP(CtEdit, CEdit)
END_MESSAGE_MAP()



// CtEdit 메시지 처리기입니다.




int CtEdit::tCreate(CtWnd* pTWnd)
{
	return 0;
}
