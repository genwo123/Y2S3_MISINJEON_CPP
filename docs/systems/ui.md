네, Common UI를 활용했다는 점을 명확히 하고, 관련 내용을 더 자세히 설명하도록 수정하겠습니다:

# 🎨 UI/UX 시스템

## 📝 목차
- [시스템 개요](#시스템-개요)
- [Common UI 스택 시스템](#common-ui-스택-시스템)
- [UI 구조](#ui-구조)
- [입력 시스템](#입력-시스템)
- [기술적 구현](#기술적-구현)

## 시스템 개요
언리얼 엔진의 Common UI 프레임워크를 기반으로 한 스택 관리 시스템과 Enhanced Input System을 활용하여 게임의 UI/UX를 구현했습니다. Common UI의 장점을 살려 체계적인 UI 관리와 직관적인 사용자 경험을 제공합니다.

![UI 시스템 구조도](/docs/assets/images/ui/ui_chat_system.JPG)
*Common UI 기반 시스템 구조도*

## Common UI 스택 시스템
### 1. Common UI 기반 구조
```cpp
// Common UI 기반 스택 구조
Common Game UI
├── Root Layout
├── Game Layer
└── Menu Layer
    ├── Main Stack
    └── Overlay Stack
```

![스택 구조도](/docs/assets/images/ui/ui_title_screen.JPG)
*Common UI 스택 구조도*

### 2. 스택 관리 특징
- Common UI의 Layer 기반 관리
- Push/Pop 인터페이스 활용
- 자동 포커스 처리
- 입력 우선순위 관리

## UI 구조
### 1. 게임 레이어
![게임 UI](/docs/assets/images/ui/ui_game_icons.JPG)
*게임 내 UI 구성*

- 상태 정보
- 미니맵
- 퀵슬롯
- 인터랙션 UI

### 2. 메뉴 레이어
![메뉴 시스템](/docs/assets/images/ui/ui_play_inventory.JPG)
*메뉴 시스템 구조*

- 인벤토리
- 캐릭터 정보
- 설정 메뉴
- 시스템 메뉴

## 입력 시스템
### Enhanced Input 연동
![입력 시스템](/docs/assets/images/ui/ui_input_mapping.JPG)
*Enhanced Input 매핑 구조*

- UI 관련 입력 처리
- 메뉴 전환 입력
- 게임/UI 입력 분리

## 기술적 구현
### 1. Common UI 활용
```cpp
// Common UI 기본 구조
GameUI : CommonUI
├── Push/Pop 인터페이스
├── Layer 관리
└── 포커스 시스템
```

### 2. UI 이벤트 처리
![UI 이벤트](/docs/assets/images/ui/ui_health_update.JPG)
*UI 이벤트 처리 시스템*

- Common UI 이벤트 활용
- 입력 우선순위 설정
- 자동 네비게이션

## 개선 계획
- [ ] Common UI 기능 확장
- [ ] 위젯 블루프린트 최적화
- [ ] 레이어 구조 개선
- [ ] 커스텀 네비게이션 구현

*Common UI의 기본 구조를 활용하면서 게임에 필요한 기능을 확장하여 구현했습니다.*

이렇게 Common UI를 중심으로 한 시스템 설명으로 수정했습니다. 추가로 수정이 필요한 부분이 있다면 말씀해 주세요.
