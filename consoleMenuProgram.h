				//////////////////////////////////////
				/* 컴퓨터교육과  2020313232  김동호 */
				//////////////////////////////////////

#pragma once							// 헤더 파일을 중복으로 컴파일되지 않게 선행적으로 처리한다.
#pragma warning(disable:4996)			// scanf 오류 등이 안나도록 처리한다. 
#include <stdio.h>						// printf() 함수 등이 포함되어 있는 헤더파일
#include <time.h>						// 시간을 불러오기 위한 헤더 파일(시간은 srand() 함수에서 테이블을 불러올때 사용됨)
#include <string.h>						// 문자열 처리를 위한 헤더 파일

// declaration of CONSTANTS (상수 선언)
#define TRUE						1	// TRUE에 해당하는 값은 0을 제외한 모든 수이나, 여기서는 보편적으로 1로 선언한다. (참의 값이 출력될 때는 1로 출력된다.)
#define FALSE						0	// FALSE에 해당하는 값은 0임

// 선언한 숫자를 입력하면 해당 메뉴로 진입하도록 메인 함수에서 구현했는데, 이를 직관적으로 표현하기 위하여 상수로 선언함.
#define DIE_SIMULATION				1
#define GAME_SHOW					2
#define UPDOWN_GAME					3
#define WORD_GAME					4
#define OX_GAME						5
#define ROCK_SCISSORS_PAPER_GAME	6
#define ABOUT						7
#define EXIT						0

// 묵찌빠 게임에서 묵, 찌, 빠에 대응하는 상수를 0, 1, 2로 선언한다. 컴퓨터가 묵, 찌, 빠를 고를 때 0~2 중에서 랜덤한 숫자를 뽑도록 구현했기 때문이다.
#define ROCK						0
#define SCISSORS					1
#define PAPER						2

// declaration of user defined functions (사용자 정의 함수 선언)

int displayMainMenu();		// 가장 처음 화면을 보여주는 함수로, 사용자가 입력한 메뉴 번호를 반환해 준다.
void dieSimulation();		// 주사위 시뮬레이션 함수 (주사위의 합이 100을 넘는 횟수)
void gameShow();			// 게임쇼 함수 (문 3개중 하나에 상품이 있음, 사용자가 문을 하나 선택, 사회자가 상품이 없는 문을 보여줌, 바꿀 것인가, 바꾸지 않을 것인가?)
void upDownGame();			// 업다운 게임 함수 (1~100까지의 숫자 중에서 
void wordGame();			// 단어 게임 함수 (행맨과 비슷)

// 아래 네개는 OX Game을 구현할 때 필요한 함수
void OXGame();				// OX GAME 기본 함수
void displayNumber(char strOX[]);		// 화면에 숫자들을 정돈되게 출력하기 위핞 함수
void playOX(char player, char str[]);	// OX 게임을 진행하는 데에 필요한 함수
char winCheck(char str[]);	// 승리자가 나오는 경우를 체크해주는 함수

// 아래 네개는 묵찌빠 게임을 구현할 때 필요한 함수
void rockScissorsPaperGame();	// 묵찌빠 게임 기본 함수
void RSPDisplay();				// 처음 보이는 화면을 출력할 때 쓰이는 함수
void computerWin(char str[]);	// 가위바위보에서 컴퓨터가 이겼을 경우 실행되는 함수 
void userWin(char str[]);		// 가위바위보에서 사용자가 이겼을 경우 실행되는 함수

void about();					// 프로그램 정보를 띄워주는 함수
