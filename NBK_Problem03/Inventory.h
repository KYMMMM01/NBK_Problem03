#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Inventory
{
public:
	//생성자 구현 
    // -인벤토리 객체가 생성될 때 호출됩니다.
    //-매개변수로 용량(`capacity`)을 받습니다.
    //(입력하지 않을 경우 기본 10으로 설정)
    //- **예외처리 :**유저가 용량을 0 이하로 입력하면, 최소 용량이 1은 되도록 자동으로 보정합니다.
    //- `new T[capacity_]`를 통해 아이템을 저장할 메모리 공간을 힙(Heap) 메모리에 할당합니다.
	Inventory(int capacity = 10)
	{
        if (capacity < 0)
            capacity = 1;

        capacity_ = capacity;
        size_ = 0;
        pItems_ = new T[capacity];
	}
	//- [ ]  **소멸자 관리 : `~Inventory()`**
    //- 인벤토리 객체가 소멸될 때(예: `main` 함수 종료 시) 자동으로 호출됩니다.
    //- **메모리 누수 방지 * *: 객체가 사라질 때 `delete[] pItems_`를 실행하여 할당받은 메모리를 반납합니다.
    //- 해제 후 포인터를 `nullptr`로 초기화하여 안전성을 높입니다.
    //- 안전한 코드를 위해, 메모리 해제 후 포인터를 `nullptr`로 초기화합니다
	~Inventory()
	{
        delete[] pItems_;
        pItems_ = nullptr;
	}
    
    //- [ ]  **아이템 추가 (`void AddItem(const T& item)`)**
    //- 새로운 아이템을 인벤토리에 추가합니다.
    //- 인벤토리에 여유 공간이 있을 때만 아이템을 저장하고 `size_`를 1 늘립니다.
    //- 공간이 꽉 찼다면 "인벤토리가 꽉 찼습니다!"라는 경고를 띄웁니다.
    void AddItem(const T& item)
    {
        if (capacity_ <= size_)
            cout << "인벤토리가 꽉 찼습니다!" << endl;
        else
        {
            pItems_[size_] = item;
            size_++;
        }
    }

    //- [ ]  **마지막 아이템 제거 (`void RemoveLastItem()`)**
    //- 인벤토리의 가장 마지막에 추가된 아이템을 제거합니다.
    //- 실제로 메모리를 지우는 것이 아니라, 아이템의 개수를 나타내는 `size_`를 1 감소시켜 마지막 아이템에 접근할 수 없도록 만듭니다.
    //- 비어있을 때 제거를 시도하면 "인벤토리가 비어있습니다."라고 안내합니다.
    void RemoveLastItem()
    {
        if (size_ == 0)
        {
            cout << "인벤토리가 비어있습니다." << endl;
            return;
        }
        else
            size_--;
    }

    //전체 출력
    void PrintAllItems() const
    {
        if (size_ == 0)
        {
            cout << "비어있습니다." << endl;
        }
        else
        {
            for (int i = 0; i < size_; i++)
                pItems_[i].PrintInfo();
        }
    }
    
    //정보 조회 함수
        int GetSize() const { return size_; }
        int GetCapacity() const { return capacity_; }

private:
	T* pItems_;
	int capacity_;
	int size_;

};
