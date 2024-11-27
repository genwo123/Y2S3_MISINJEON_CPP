
# 💻 게임 시스템 관리

## 📝 목차
- [시스템 개요](#시스템-개요)
- [게임모드](#게임모드)
- [플레이어 컨트롤러](#플레이어-컨트롤러)
- [대화 시스템](#대화-시스템)

## 시스템 개요
게임의 진행과 플레이어 입력을 관리하는 핵심 시스템입니다. 게임모드를 통한 전반적인 게임 진행 관리와 플레이어 컨트롤러를 통한 입력 및 상호작용 처리를 담당합니다.

## 게임모드
### 1. 기본 구조
게임의 진행 상태와 데이터를 관리하는 시스템입니다.

![게임모드 초기화](/docs/assets/images/GM2PC/system_controller_input_mode.JPG)
*게임모드 베이스의 기본 설정 구조*

### 2. 주요 기능
```cpp
// 게임모드의 주요 변수들
- Chapter (현재 챕터)
- Level (현재 레벨)
- Index (진행 상황 인덱스)
- CurrentScript (현재 스크립트)
- CurrentAnswer (현재 답변)
```

### 3. 데이터 관리
- 게임 진행 상태 추적
- 스크립트 및 답변 관리
- 레벨 시스템 연동

## 플레이어 컨트롤러
### 1. 입력 처리
![입력 모드 관리](/docs/assets/images/GM2PC/system_controller_input_mode.JPG)
*게임/UI 입력 모드 전환 시스템*

### 2. 대화 시스템 제어
![대화창 열기](/docs/assets/images/GM2PC/system_controller_dialogue_open.JPG)
*대화창 활성화 및 스크립트 처리*

![대화창 닫기](/docs/assets/images/GM2PC/system_controller_dialogue_close.JPG)
*대화창 종료 및 정리 프로세스*

### 3. 독백 시스템
![독백 시스템](/docs/assets/images/GM2PC/system_controller_monologue.JPG)
*플레이어 독백 처리 시스템*

## 대화 시스템
### 1. 대화 처리
- NPC와의 대화 관리
- 스크립트 진행 제어
- 선택지 처리

### 2. 기술적 구현
```cpp
// 대화 시스템 주요 함수들
- OpenDialogue: 대화창 열기
- CloseDialogue: 대화창 닫기
- SetCurrentScript: 현재 스크립트 설정
- SetCurrentAnswer: 현재 답변 설정
- CallNextScript: 다음 스크립트 호출
```

### 3. 시스템 특징
- Enhanced Input System 활용
- Common UI 기반 UI 스택 관리
- 게임/UI 입력 모드 분리

## 개선 계획
- [ ] C++ 마이그레이션 검토
- [ ] 입력 시스템 최적화
- [ ] 대화 시스템 기능 확장
- [ ] 데이터 테이블 연동 강화

*모든 시스템은 블루프린트로 구현되어 있으며, 향후 C++ 마이그레이션을 고려하여 설계되었습니다.*
