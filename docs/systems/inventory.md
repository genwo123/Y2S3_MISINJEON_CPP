# 🎒 인벤토리 시스템

## 📝 목차
- [시스템 개요](#시스템-개요)
- [데이터 구조](#데이터-구조)
- [주요 기능](#주요-기능)
- [기술적 구현](#기술적-구현)

## 시스템 개요
단일 배열을 통한 통합 인벤토리 시스템으로, UI상으로는 용도별로 분리되어 보이도록 구현했습니다. 데이터 테이블을 활용해 아이템 정보를 관리하고, 효율적인 아이템 관리 시스템을 구축했습니다.

## 데이터 구조
### 1. 아이템 정보 구조
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

### 2. 아이템 카테고리
```cpp
UENUM(BlueprintType)
enum class E_ItemCategory : uint8 {
    recovery UMETA(DisplayName = "회복 아이템"),
    ticket UMETA(DisplayName = "티켓류"),
    charm UMETA(DisplayName = "부적류"),
    etc UMETA(DisplayName = "기타")
};
```

### 3. 인벤토리 관리
```cpp
// Seori.h
const int INVENTORY_SIZE = 9;
TArray<int> inventory; // itemKey를 저장

// 아이템 설정/조회
void setInventoryItemKey(int index, int value) { inventory[index] = value; }
TArray<int> getInventory() { return inventory; }
```

## 주요 기능
### 1. 통합 인벤토리 관리
![인벤토리 UI 이미지]
- 9칸의 기본 인벤토리
- UI상 분리된 형태로 표시 (일반/부적/재료)
- 아이템 상세 정보 표시

### 2. 아이템 상호작용
```cpp
void ASeori::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
    if (OtherActor->Tags.Contains("Interactable")) {
        canInteract = true;
    }
}
```

### 3. 데이터 테이블 연동
![데이터 테이블 구조 이미지]
- 아이템 정보의 중앙 관리
- 효율적인 데이터 접근 및 수정

## 기술적 구현
### 1. UI 업데이트 최적화
- 인벤토리 창 열 때만 UI 업데이트
- 실제 데이터와 UI 데이터 분리

### 2. 아이템 사용 시스템
```cpp
// 아이템 사용 예시
void UseItem(int32 SlotIndex)
{
    if (inventory[SlotIndex] != -1)
    {
        // 아이템 사용 로직
        // 수량 감소
        if (--itemCount <= 0)
            inventory[SlotIndex] = -1;
    }
}
```

### 3. 확장성
- 추가 인벤토리 탭 구현 가능
- 아이템 종류별 다른 처리 로직

## 개발 과정
### 해결한 문제들
- 데이터 구조 설계 시 확장성 고려
- UI 업데이트 최적화
- 아이템 타입별 처리 로직 통합

### 개선 계획
- [ ] 부적 제작 시스템 통합
- [ ] 드래그 앤 드롭 기능 추가
- [ ] 아이템 정렬 기능

## 기술 스택
- Unreal Engine Data Table
- C++ Core Systems
- Blueprint UI Integration
