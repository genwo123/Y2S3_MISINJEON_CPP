# 🤝 상호작용 시스템

## 📝 목차
- [시스템 개요](#시스템-개요)
- [주요 기능](#주요-기능)
- [기술적 구현](#기술적-구현)
- [개발 과정](#개발-과정)

## 시스템 개요
단일 상호작용 키를 통해 다양한 오브젝트와 상호작용할 수 있는 통합 시스템을 구현했습니다. 
상호작용 가능한 대상을 타입별로 분류하여 각각 다른 동작을 수행하도록 설계했습니다.

## 주요 기능
### 1. 통합 상호작용 인터페이스
```cpp
// Interactable.h의 핵심 인터페이스 코드
UENUM(BlueprintType)
enum class InteractType : uint8 {
    NONE UMETA(DisplayName = "None"),
    STATIC UMETA(DisplayNmae = "Static"),
    ITEM UMETA(DisplayNmae = "Item"),
    NPC UMETA(DisplayName = "NPC")
};
```

이 코드를 통해 모든 상호작용 가능한 오브젝트들이 공통된 인터페이스를 공유하며, 타입에 따라 다른 동작을 수행할 수 있습니다.

### 2. 상호작용 처리 로직
```cpp
void ASeori::Interact() {
    if (!canInteract) return;
    if (Talking) return;
    FHitResult HitResult;
    // ... LineTrace 코드
    if (HitResult.GetActor() != nullptr) {
        AActor* target = HitResult.GetActor();
        IInteractable* targetInteract = Cast<IInteractable>(target);
        if (targetInteract == nullptr) return;

        InteractType type = targetInteract->getType();
        // ... 타입별 처리
    }
}
```

![상호작용 판정 이미지]

플레이어 전방의 LineTrace를 통해 상호작용 가능한 오브젝트를 감지하고, 해당 오브젝트의 타입에 따라 적절한 동작을 수행합니다.

## 기술적 구현
### 타입별 처리 방식
1. STATIC: 고정 오브젝트와의 상호작용 (예: 개찰구)
   - ![개찰구 상호작용 이미지]
   - 개찰구와 같은 고정 오브젝트는 플레이어의 아이템 소지 여부를 확인하고 그에 따른 동작을 수행합니다.

2. ITEM: 아이템 획득 및 인벤토리 저장
   - ![아이템 획득 이미지]
   - 획득한 아이템은 자동으로 인벤토리에 저장되며, UI를 통해 피드백을 제공합니다.

3. NPC: 대화 시스템 활성화 및 카메라 전환
   - ![NPC 대화 이미지]
   - NPC와의 대화 시 자연스러운 카메라 전환과 대화 UI가 활성화됩니다.

### 개발 특징
- LineTrace를 통한 정확한 상호작용 타겟팅
- 인터페이스 기반의 확장 가능한 시스템 설계
- 직관적인 사용자 경험을 위한 단일 키 인터랙션

## 개발 과정
### 초기 설계
- 각각의 상호작용을 개별적으로 구현했으나, 코드의 재사용성과 확장성을 위해 인터페이스 기반 시스템으로 리팩토링
- LineTrace 방식을 통해 정확한 상호작용 타겟팅 구현
- 사용자 경험을 고려하여 단일 키로 모든 상호작용을 통합

### 문제 해결
- 다양한 상호작용 타입을 통합적으로 관리하기 위한 인터페이스 설계
- 카메라 전환과 대화 시스템의 자연스러운 연동
- 상호작용 가능 상태에 대한 명확한 피드백 제공

## 개선 사항
- [ ] 상호작용 가능 오브젝트에 대한 시각적 피드백 강화
- [ ] 더 다양한 상호작용 타입 추가 가능성
- [ ] 상호작용 범위 조절 기능
