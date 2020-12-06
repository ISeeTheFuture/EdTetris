
#include "Core.h"

int main() {

	if (!CCore::GetInst()->Init()) { // 초기화 실패 시
		CCore::DestroyInst();
		return 0;
	}

	CCore::GetInst()->Run();

	CCore::DestroyInst();

	return 0;
}