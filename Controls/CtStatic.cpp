// CtStatic.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Controls.h"
#include "CtStatic.h"


// CtStatic

IMPLEMENT_DYNAMIC(CtStatic, CWnd)

CtStatic::CtStatic()
{

}

CtStatic::~CtStatic()
{
}


BEGIN_MESSAGE_MAP(CtStatic, CWnd)
END_MESSAGE_MAP()



// CtStatic 메시지 처리기입니다.




int CtStatic::tCreate(CtWnd* pTWnd)
{
	return 0;
}
