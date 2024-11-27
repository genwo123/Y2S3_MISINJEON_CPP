# 🎒 인벤토리 시스템

## 📝 목차
- [시스템 개요](#시스템-개요)
- [데이터 구조](#데이터-구조)
- [주요 기능](#주요-기능)
- [기술적 구현](#기술적-구현)

## 시스템 개요
단일 배열을 통한 통합 인벤토리 시스템으로, UI상으로는 용도별로 분리되어 보이도록 구현했습니다. 데이터 테이블을 활용해 아이템 정보를 관리하고, 효율적인 아이템 관리 시스템을 구축했습니다.

## 데이터 구조
### 1. 데이터 테이블 구조
![데이터 테이블 설정](/docs/assets/images/ui/ui_inventory_datatable_setup.JPG)
*아이템 데이터 테이블 구조 및 설정*

### 2. 아이템 데이터 구조
![데이터 구조](/docs/assets/images/ui/ui_inventory_data_structure.JPG)
*아이템 속성 및 카테고리 구조*

```cpp
// ItemData 구조
struct S_ItemData
{
    FText Name;
    FText Description;
    UTexture2D* DetailImage;
    FText Class;
    USoundBase* SFX;
    E_ItemCategory Category;
    int32 SlotQuantity;
    E_ItemRarity ItemRarity;
    UTexture2D* FocusImage;
};
```

### 3. 인벤토리 관리
```cpp
// Seori.h
const int INVENTORY_SIZE = 9;
TArray<int> inventory; // itemKey를 저장
```

## 주요 기능
### 1. UI 데이터 바인딩
![데이터 바인딩](/docs/assets/images/ui/ui_inventory_data_binding.JPG)
*인벤토리 UI와 데이터 바인딩 시스템*

### 2. 데이터 테이블 연동
- 중앙 집중식 아이템 데이터 관리
- 데이터 테이블을 통한 효율적인 정보 접근
- 아이템 속성의 동적 업데이트

### 3. 카테고리 시스템
```cpp
UENUM(BlueprintType)
enum class E_ItemCategory : uint8 {
    recovery UMETA(DisplayName = "회복 아이템"),
    ticket UMETA(DisplayName = "티켓류"),
    charm UMETA(DisplayName = "부적류"),
    etc UMETA(DisplayName = "기타")
};
```

## 기술적 구현
### 1. 블루프린트 구현
- 데이터 테이블 기반 아이템 정보 관리
- UI 위젯과 데이터 바인딩
- 효율적인 메모리 관리

### 2. 아이템 사용 시스템
```cpp
void UseItem(int32 SlotIndex)
{
    if (inventory[SlotIndex] != -1)
    {
        // 아이템 사용 로직
        if (--itemCount <= 0)
            inventory[SlotIndex] = -1;
    }
}
```

### 3. 최적화
- 필요한 경우에만 UI 업데이트
- 데이터 캐싱을 통한 성능 향상
- 효율적인 메모리 사용

## 개선 계획
- [ ] 드래그 앤 드롭 기능 추가
- [ ] 아이템 정렬 시스템 구현
- [ ] 인벤토리 확장 기능

*모든 시스템은 데이터 테이블과 블루프린트를 통해 효율적으로 구현되었습니다.*
