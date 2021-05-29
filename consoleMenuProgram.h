				//////////////////////////////////////
				/* ��ǻ�ͱ�����  2020313232  �赿ȣ */
				//////////////////////////////////////

#pragma once							// ��� ������ �ߺ����� �����ϵ��� �ʰ� ���������� ó���Ѵ�.
#pragma warning(disable:4996)			// scanf ���� ���� �ȳ����� ó���Ѵ�. 
#include <stdio.h>						// printf() �Լ� ���� ���ԵǾ� �ִ� �������
#include <time.h>						// �ð��� �ҷ����� ���� ��� ����(�ð��� srand() �Լ����� ���̺��� �ҷ��ö� ����)
#include <string.h>						// ���ڿ� ó���� ���� ��� ����

// declaration of CONSTANTS (��� ����)
#define TRUE						1	// TRUE�� �ش��ϴ� ���� 0�� ������ ��� ���̳�, ���⼭�� ���������� 1�� �����Ѵ�. (���� ���� ��µ� ���� 1�� ��µȴ�.)
#define FALSE						0	// FALSE�� �ش��ϴ� ���� 0��

// ������ ���ڸ� �Է��ϸ� �ش� �޴��� �����ϵ��� ���� �Լ����� �����ߴµ�, �̸� ���������� ǥ���ϱ� ���Ͽ� ����� ������.
#define DIE_SIMULATION				1
#define GAME_SHOW					2
#define UPDOWN_GAME					3
#define WORD_GAME					4
#define OX_GAME						5
#define ROCK_SCISSORS_PAPER_GAME	6
#define ABOUT						7
#define EXIT						0

// ����� ���ӿ��� ��, ��, ���� �����ϴ� ����� 0, 1, 2�� �����Ѵ�. ��ǻ�Ͱ� ��, ��, ���� �� �� 0~2 �߿��� ������ ���ڸ� �̵��� �����߱� �����̴�.
#define ROCK						0
#define SCISSORS					1
#define PAPER						2

// declaration of user defined functions (����� ���� �Լ� ����)

int displayMainMenu();		// ���� ó�� ȭ���� �����ִ� �Լ���, ����ڰ� �Է��� �޴� ��ȣ�� ��ȯ�� �ش�.
void dieSimulation();		// �ֻ��� �ùķ��̼� �Լ� (�ֻ����� ���� 100�� �Ѵ� Ƚ��)
void gameShow();			// ���Ӽ� �Լ� (�� 3���� �ϳ��� ��ǰ�� ����, ����ڰ� ���� �ϳ� ����, ��ȸ�ڰ� ��ǰ�� ���� ���� ������, �ٲ� ���ΰ�, �ٲ��� ���� ���ΰ�?)
void upDownGame();			// ���ٿ� ���� �Լ� (1~100������ ���� �߿��� 
void wordGame();			// �ܾ� ���� �Լ� (��ǰ� ���)

// �Ʒ� �װ��� OX Game�� ������ �� �ʿ��� �Լ�
void OXGame();				// OX GAME �⺻ �Լ�
void displayNumber(char strOX[]);		// ȭ�鿡 ���ڵ��� �����ǰ� ����ϱ� ���� �Լ�
void playOX(char player, char str[]);	// OX ������ �����ϴ� ���� �ʿ��� �Լ�
char winCheck(char str[]);	// �¸��ڰ� ������ ��츦 üũ���ִ� �Լ�

// �Ʒ� �װ��� ����� ������ ������ �� �ʿ��� �Լ�
void rockScissorsPaperGame();	// ����� ���� �⺻ �Լ�
void RSPDisplay();				// ó�� ���̴� ȭ���� ����� �� ���̴� �Լ�
void computerWin(char str[]);	// �������������� ��ǻ�Ͱ� �̰��� ��� ����Ǵ� �Լ� 
void userWin(char str[]);		// �������������� ����ڰ� �̰��� ��� ����Ǵ� �Լ�

void about();					// ���α׷� ������ ����ִ� �Լ�
