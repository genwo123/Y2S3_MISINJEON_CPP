# 🔧 기술 상세

## 📝 목차
- [프로젝트 구조](#프로젝트-구조)
- [핵심 시스템](#핵심-시스템)
- [코드 아키텍처](#코드-아키텍처)
- [개발 환경](#개발-환경)

## 프로젝트 구조
### 디렉토리 구조
```
Y2S3_MISINJEON_CPP/
├── Source/
│   ├── Private/
│   │   ├── Seori.cpp
│   │   ├── Interactable.cpp
│   │   └── Item.cpp
│   └── Public/
│       ├── Seori.h
│       ├── Interactable.h
│       └── Item.h
└── Content/
    ├── Blueprints/
    │   ├── BP_Seori
    │   └── BP_Items
    ├── Maps/
    └── UI/
```

## 핵심 시스템
### 1. 캐릭터 시스템
```cpp
// 서리 캐릭터 핵심 구조
class ASeori : public ACharacter, public IConversation
{
public:
    // 인벤토리 관리
    const int INVENTORY_SIZE = 9;
    TArray<int> inventory;
    
    // 상호작용 관리
    void Interact();
    bool canInteract = false;
};
```

### 2. 인터페이스 시스템
```cpp
// 상호작용 인터페이스
class IInteractable
{
protected:
    InteractType type = InteractType::NONE;
public:
    InteractType virtual getType() { return type; };
    void virtual Interact() {};
};
```

### 3. 데이터 구조
![데이터 테이블 구조]
- Item Data Table
- 상호작용 시스템 구조
- AI 비헤이비어 트리

## 코드 아키텍처
### 1. C++ Core Systems
- 캐릭터 로직
- 상호작용 시스템
- 인벤토리 관리

### 2. Blueprint Integration
![블루프린트 연동]
- UI 위젯
- 애니메이션
- 이벤트 처리

### 3. 최적화 전략
```cpp
// 예시: 인벤토리 업데이트 최적화
void UpdateInventoryUI()
{
    // 인벤토리 창이 열릴 때만 업데이트
    if (!bIsInventoryOpen) return;
    
    // UI 업데이트 로직
}
```

## 개발 환경
### 사용 도구
- Unreal Engine 5.x
- Visual Studio 2022
- Git/GitHub

### 개발 프로세스
- 코어 시스템: C++ 구현
- UI/UX: 블루프린트 활용
- 버전 관리: Git 활용

## 성능 지표
### 메모리 사용
- 평균 메모리 사용량
- 리소스 로딩 전략

### 프레임율 최적화
- 목표 FPS: 60
- 최적화 전략:
  - 동적 리소스 로딩
  - UI 업데이트 최적화
  - AI 처리 최적화

## 추가 기술 문서
- [상호작용 시스템](./systems/interaction.md)
- [인벤토리 시스템](./systems/inventory.md)
- [AI 시스템](./systems/ai.md)
