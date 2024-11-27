# 🤖 AI 시스템

## 📝 목차
- [시스템 개요](#시스템-개요)
- [AI 행동 패턴](#ai-행동-패턴)
- [기술적 구현](#기술적-구현)
- [개발 과정](#개발-과정)

## 시스템 개요
언리얼 엔진의 비헤이비어 트리를 활용하여 도깨비(고블린) AI를 구현했습니다. 플레이어를 추적하고 공격하는 간단한 AI로, 기본적인 게임플레이 경험을 제공합니다.

### 주요 특징
![AI 시스템](/docs/assets/images/ai/ai_bp_goblin_base.JPG)
*AI 시스템의 기본 구조도*

## AI 행동 패턴
### 1. 기본 행동 패턴
![기본 행동](/docs/assets/images/ai/ai_bp_behavior_tree.JPG)
*기본 AI 행동 패턴 구조도*

- **감지**: 일정 거리 내 플레이어 감지
- **추적**: 감지된 플레이어를 향해 이동
- **공격**: 근접 시 기본 공격 실행
- **배회**: 플레이어 미감지시 주변 배회

### 2. 비헤이비어 트리 구조
![비헤이비어 트리](/docs/assets/images/ai/ai_bp_chase_task.JPG)
*AI 비헤이비어 트리 구조*

### 3. 실제 게임플레이
![도깨비 AI 추적](/docs/assets/videos/M_Chase_Goblin.mp4)
*실제 게임에서 플레이어를 추적하고 공격하는 AI 모습*

## 기술적 구현
### 1. AI 작업(Task) 시스템
```cpp
// AI Task 기본 구조
BTTask_ChasePlayer    // 플레이어 추적
BTTask_AttackPlayer   // 플레이어 공격
BTTask_Patrol         // 기본 배회
```

![공격 Task](/docs/assets/images/ai/ai_bp_attack_task.JPG)
*AI 공격 Task 구현 구조도*

### 2. AI 제어 시스템
![애니메이션 시스템](/docs/assets/images/ai/ai_bp_goblin_anim.JPG)
*AI 제어 및 애니메이션 시스템*

### 3. 트리거 설정
![트리거 시스템](/docs/assets/images/ai/ai_bp_cinematic_trigger.JPG)
*AI 트리거 및 감지 시스템*

## 개발 과정
### 1. 구현된 기능
- 기본적인 추적/공격 AI
- 간단한 배회 시스템
- 플레이어 감지 시스템

![기본 동작](/docs/assets/images/ai/ai_bp_roam_task.JPG)
*AI 기본 동작 구현*

### 2. 최적화 과정
- 이동 속도 조절
- 공격 범위/타이밍 조정
- AI 수 제한을 통한 최적화

![AI 베이스](/docs/assets/images/ai/ai_bp_goblin_base.JPG)
*AI 기본 시스템 최적화*

## 기술 스택
- Unreal Engine Behavior Tree
- Navigation Mesh
- AI Controller
- Blackboard System

## 개선 계획
- [ ] 다양한 공격 패턴 추가
- [ ] AI 반응성 개선
- [ ] 성능 최적화
- [ ] 그룹 전투 시스템 구현

*모든 이미지는 개발 과정에서 실제 구현된 시스템을 캡처한 것입니다.*

이미지와 내용의 맥락을 더 잘 맞추어 수정했습니다. 파일 이름을 보고 각 이미지의 실제 내용에 맞게 재배치했고, 영상 경로도 수정했습니다. 추가로 각 섹션의 설명과 이미지의 연관성을 높이기 위해 캡션도 더 구체적으로 수정했습니다.
