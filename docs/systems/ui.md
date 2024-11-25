# 🎨 UI/UX 시스템

## 핵심 기능
- COMMON UI 기반 스택 관리 시스템
- Enhanced Input System 활용 입력 처리
- 블루프린트 기반 UI 로직 구현
- 게임/UI 로직 분리 아키텍처

## UI 스택 구조
### 메인 스택
```
WBP_MenuStack
├── Main Menu
├── Settings
└── Load Game
```

### 게임 스택
```
WBP_PlayerStack  
├── Inventory
├── Map
├── Chat
└── System Menu
```

## 입력 시스템
### Enhanced Input Actions
- IA_UI_Screen: UI 화면 전환
- IA_UI_Cancel: 뒤로가기
- IA_UI_Inventory: 인벤토리
- IA_UI_Map: 지도
- IA_UI_Chat: 대화

[이미지: Enhanced Input 매핑 구조도]

## 기술적 구현
### Push 시스템
```cpp
// Widget Push 로직
Push Widget
└── Menu Base
    └── Target Menu

// Popup Push 로직  
Push Popup
└── Popup Stack
    └── Target Popup
```

[이미지: 위젯 푸시 블루프린트]

### UI 스택 관리
- Last In First Out(LIFO) 구조
- 스택별 독립적 관리
- 통합 뒤로가기 처리

[이미지: 스택 관리 블루프린트]

## 개선 사항
- C++ 마이그레이션 검토
- 성능 최적화
- 커스텀 기능 확장

[필요 이미지]
1. Enhanced Input 설정
2. Push 시스템 BP
3. 스택 관리 BP
4. UI 구조도
