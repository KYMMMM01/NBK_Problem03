#include <iostream>
#include "Inventory.h"
#include "Item.h"

int main()
{	
	//용량이 4인 인벤토리 생성
	Inventory<Item>inven(4);
	//기본값
	Inventory<Item>inven2;

	//아이템 추가
	inven.AddItem(Item("롱소드", 350));
	inven.AddItem(Item("천갑옷", 300));
	inven.AddItem(Item("곡괭이", 875));
	inven.AddItem(Item("거인의 허리띠", 1000));

	//전체 출력
	inven.PrintAllItems();

	//꽉 찼을 때 추가 시도
	inven.AddItem(Item("무한의 대검", 3800));

	//마지막 아이템 제거
	inven.RemoveLastItem();
	 
	//다시 출력
	inven.PrintAllItems();

	return 0;
}