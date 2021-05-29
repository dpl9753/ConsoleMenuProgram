#include "consoleMenuProgram.h"	// 사용자 정의 헤더파일

int main()	// 메인 함수
{
	int nMainMenu;	// 사용자로부터 입력받을 숫자를 저장하는 변수
	int bIterationFlag = TRUE;	// 무한반복 탈출조건을 위한 변수 설정, 처음에는 일단 실행시켜야 하니 TRUE로 초기화

	srand(time(NULL));	// 같은 숫자가 뽑히지 않게 하기 위해 현재 시각으로 테이블을 불러옴

	while (bIterationFlag)	// (bIterationFlag == TRUE)일 동안 반복
	{
		system("cls");	// clear screen

		nMainMenu = displayMainMenu();	// 메인메뉴를 출력하고 사용자가 입력한 메뉴 번호를 받아서 nMainMenu 변수에 저장

		system("cls");	// clear screen
		switch (nMainMenu)	// 몇번을 입력받았느냐에 따라서 진입할 메뉴가 달라진다.
		{
		case DIE_SIMULATION:	// 1번을 입력받았으면
			dieSimulation();	// 주사위 시뮬레이션 메뉴로 진입
			break;				// 끝나면 switch문 탈출
		case GAME_SHOW:			// 2번을 입력받았으면
			gameShow();			// 게임 쇼 메뉴로 진입
			break;				// 끝나면 switch문 탈출
		case UPDOWN_GAME:		// 3번을 입력받았으면
			upDownGame();		// 업다운 게임으로 진입
			break;				// 끝나면 switch문 탈출
		case WORD_GAME:			// 4번을 입력받았으면
			wordGame();			// 단어 맞추기 게임으로 진입
			break;				// 끝나면 switch문 탈출
		case OX_GAME:			// 5번을 입력받았으면
			OXGame();			// OX 게임으로 진입
			break;				// 끝나면 switch문 탈출
		case ROCK_SCISSORS_PAPER_GAME:	// 6번을 입력받았으면
			rockScissorsPaperGame();	// 묵찌빠 게임으로 진입
			break;				// 끝나면 switch문 탈출
		case ABOUT:				// 7번을 입력받았으면
			about();			// 프로그램 정보 메뉴로 진입
			break;				// 끝나면 switch문 탈출
		case EXIT:				// 0번을 입력받았으면
			printf("\n\n");
			printf("\tGOOD-BYE~~\n");	// 마지막 인사말 출력
			// exit(0);				// 다음과 같은 명령어로도 종료할 수 있음
			bIterationFlag = FALSE;	// escape condition, bIterationFlag가 FALSE로 바뀌면서 무한반복문을 탈출하게 됨. (프로그램 종료)
			break;
		default:				// 입력받은 값이 위 switch문에 없으면
			printf("\n\n");
			printf("\tWrong Input!!!\n");	// 잘못된 입력이라고 알려줌
			break;				// switch문 탈출 -> 바로 밑 if문을 통해 pause를 건 후에 다시 맨 위로 올라가서 다시 입력받음
		} //switch

		if (nMainMenu != 0)		// (switch문을 탈출한 후) 프로그램을 종료하는게 아니면
			system("pause");	// press any key to continue
		// 퍼즈를 건 뒤에 반복문 맨 위로 다시 올라감. 즉, 메인메뉴로 다시 진입
	} //while

	return 0;	// 정상 종료를 의미하는 반환 값 : 0
} //main()

// implementation of user defined functions
int displayMainMenu()	// 가장 처음 나오는 화면에 관련된 함수
{
	int nSelectedMainMenu;	// 사용자가 원하는 메뉴를 입력받는 변수
	// 사용자가 메뉴를 고를 수 있게 번호와 메뉴명을 출력
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t          MAIN MENU\n");
	printf("\t------------------------------\n");
	printf("\t     1. DIE SIMULATION\n");
	printf("\t     2. GAME SHOW\n");
	printf("\t     3. UPDOWN GAME\n");
	printf("\t     4. WORD GAME\n");
	printf("\t     5. OX GAME\n");
	printf("\t     6. ROCK SCISSORS PAPER GAME\n");
	printf("\t     7. ABOUT\n");
	printf("\t------------------------------\n");
	printf("\t     0. EXIT\n");
	printf("\t==============================\n");
	printf("\t     >> ");
	scanf("%d", &nSelectedMainMenu);	// 사용자가 원하는 메뉴를 입력받음

	return nSelectedMainMenu;			// 입력받은 메뉴 번호를 return
} // displayMainMenu()

void dieSimulation() // 주사위 시뮬레이터 함수
{
	int nFace, nSum = 0, nCount = 0;	// nFace: 주사위의 눈 / nSum과 nCount는 각각 합계를 구하거나 카운트하는 변수이므로 0으로 초기화
	// 화면 상단에 메뉴명을 출력 
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t        DIE SIMULATION\n");
	printf("\t------------------------------\n\n");
	for (int i = 0; i < 100000; i++, nSum = 0) // 시뮬레이션을 위해 동작을 10만번 반복
	{
		while (nSum < 100) // 합계가 100보다 작을 동안
		{
			nFace = (rand() % 6) + 1;	// 한번 던졌을 때 나오는 주사위의 눈, 범위는 랜덤하게 1 ~ 6
			nSum += nFace;	// 합계에 방금 나온 주사위의 수를 더해준다.
			nCount++;		// 주사위를 굴린 횟수를 카운트한다.
		} // while
	} // for

	printf("\t  컴퓨터 시뮬레이션 결과,\n");
	printf("\t  주사위의 누적합이\n");
	printf("\t  100을 넘으려면\n");
	printf("\t  약 %d회정도 굴리면 됩니다.\n\n", (int)((double) nCount/100000+0.5)); // 10만번 던졌을 때 몇번 굴려야 누적합이 100을 넘는지 평균을 구한다. 
	printf("\t==============================\n\n");							 // 0.5를 더해 반올림을 해준다. 실수형으로 계산한 뒤에 정수형으로 바꾸어 출력

} // dieSimulation()

void gameShow()	// 게임 쇼 함수
{
	int nPrizeDoor, nSelectDoor;	// 상품이 있는 문, 처음에 선택하는 문
	int nRevealDoor, nSwitchDoor;	// 사회자가 보여주는 문, 처음 선택한 문이 아니고 사회자가 보여준 문이 아닌 변경한 문
	int nSelectCount = 0, nSwitchCount = 0;	// 문을 선택했을 때 당첨되는 횟수를 세기 위한 변수, 문을 변경했을 때 당첨되는 횟수를 세기 위한 변수
	// 화면 상단에 메뉴명을 출력 
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t           GAME SHOW\n");
	printf("\t------------------------------\n\n");

	// case 1
	for (int i = 0; i < 100000; i++) // 시뮬레이션을 위해 같은 동작을 10만번 수행
	{	
		nPrizeDoor = rand() % 3;	// 난수를 3으로 나눈 나머지 -> 0~2 사이의 값으로 설정, 상품이 있는 문의 번호
		nSelectDoor = rand() % 3;	// 난수를 3으로 나눈 나머지 -> 0~2 사이의 값으로 설정, 선택한 문의 번호
		if (nPrizeDoor == nSelectDoor) nSelectCount++;	// 상품이 있는 문과 선택한 문의 번호가 같으면, 그대로 선택했을 때의 당첨 횟수를 1 증가시킨다.
	} // for
	printf("\t  Select >> %.2lf %%\n\n", (double)nSelectCount / 1000);	// 문을 그대로 유지할 경우 당첨될 확률

	// case 2
	for (int i = 0; i < 100000; i++)// 시뮬레이션을 위해 같은 동작을 10만번 수행
	{
		nPrizeDoor = rand() % 3;	// 난수를 3으로 나눈 나머지 -> 0~2 사이의 값으로 설정, 상품이 있는 문의 번호 
		nSelectDoor = rand() % 3;	// 난수를 3으로 나눈 나머지 -> 0~2 사이의 값으로 설정, 선택한 문의 번호

		nRevealDoor = 0;	// nRevealDoor를 0으로 초기화
		while (nRevealDoor == nPrizeDoor || nRevealDoor == nSelectDoor)	// nRevealDoor의 값이 둘 중 하나의 값과 같은 경우에는
			nRevealDoor++;	// nRevealDoor의 값을 증가시켜 nRevealDoor의 값이 nPrizeDoor의 값이나 nSelectDoor의 값과 같지 않도록 만듦

		nSwitchDoor = 0;	// nRevealDoor를 0으로 초기화
		while (nSwitchDoor == nSelectDoor || nSwitchDoor == nRevealDoor) // nSwitchDoor의 값이 둘 중 하나의 값과 같은 경우에는
			nSwitchDoor++;	// nSwitchDoor의 값을 증가시켜 nSwitchDoor의 값이 nSelectDoor의 값이나 nRevealDoor의 값과 같지 않도록 만듦

		if (nPrizeDoor == nSwitchDoor) nSwitchCount++;	// 상품이 있는 문과 바꾼 문의 번호가 같으면, 문을 바꿨을 때의 당첨 횟수를 1 증가시킨다.
	} // for
	printf("\t  Switch >> %.2lf %%\n\n", (double)nSwitchCount / 1000);	// 문을 바꿀 경우 당첨될 확률
	printf("\t==============================\n\n");

} // gameShow()

void upDownGame() // 업다운 게임 함수
{
	int nAnswer, nInput;	// 정답인 숫자, 사용자가 입력하는 숫자
	int nCount = 0;			// 시도 횟수를 카운트하기 위한 변수, 한번 시도할 때마다 1씩 증가하므로 0으로 초기화
	int nMin = 1, nMax = 100;	// 최솟값은 1, 최댓값은 100, 정답은 min이상 max이하에 존재한다.
	int bFlag = TRUE;		// 무한반복 탈출을 위한 변수 설정, 처음에는 일단 실행시켜야 하니 TRUE로 초기화

	nAnswer = rand() % 100 + 1;	// 1~100의 숫자 중 랜덤으로 하나를 정답으로 설정 

	while (bFlag) 
	{
		system("cls");
		printf("\n\n");	// 화면 상단에 메뉴명을 출력 
		printf("\t==============================\n");
		printf("\t          UPDOWN GAME\n");
		printf("\t------------------------------\n\n");
		printf("\t  %3d to %3d\n\n", nMin, nMax);	// 사용자가 입력해야 할 숫자의 범위를 출력
		printf("\t  input number >> ");
		scanf("%d", &nInput);	// 사용자가 정답을 맞추기 위해 숫자를 하나 입력한다.
		nCount++;		// 몇번만에 맞췄는지 알려주기 위해서 반복마다 카운트를 증가시킨다.

		if (nInput < nAnswer) // 정답보다 작은 수를 입력했을 경우
		{	
			nMin = nInput + 1;		// 정답의 범위는 (입력한 수 + 1 <= 정답 <= 최댓값)이 된다.
			printf("\n\t  UP\n\n");	// 정답이 입력한 수보다 크다고 출력
		}
		else if (nInput > nAnswer)	// 정답보다 큰 수를 입력했을 경우
		{	
			nMax = nInput - 1;		// 정답의 범위는 (최솟값 <= 정답 <= 입력한 수 - 1)이 된다.
			printf("\n\t  DOWN\n\n");	// 정답이 입력한 수보다 작다고 출력
		}
		else	// 정답을 맞췄을 경우
		{
			printf("\n\t  RIGHT!! (%d times)\n\n", nCount);	// 몇번만에 맞췄는지 출력해준다.
			bFlag = FALSE; //break; // escape condition, 무한반복문을 탈출한다.
		} // if...else

		printf("\t==============================\n\n");
		if (bFlag) system("pause");	// 정답을 못맞췄을 경우 퍼즈를 걸어준다. 퍼즈를 걸어주면 화면이 너무 빠르게 지나가서 UP! DOWN!을 확인하지 못한다.
	} // while

} // upDownGame()

void wordGame()	// 단어 맞추기 게임 함수
{
	char strWords[20][40] = {	// 정답 문자열을 20개 저장해놓기 위해 선언한 2차원 배열
		"computer",
		"programming",
		"education",
		"mouse",
		"keyboard",		// 5
		"monitor",
		"president",
		"warning",
		"return",
		"studio",		// 10
		"outstanding",
		"different",
		"student",
		"university",
		"professor",	// 15
		"object",
		"class",
		"online",
		"community",
		"windows"		// 20
	};
	// 차례로: 20개의 단어 중 정답 단어를 선택 / 정답으로 선택된 단어의 길이 / 몇번만에 맞췄는지 카운트하기 위한 변수 / 사용자가 입력한 문자열의 길이
	int nSelected, nWordLength, nCount = 0, nInputLength;
	char strInput[40], strEnter[40]; // 입력한 문자들을 화면에 출력하기 위한 배열 / 사용자로부터 입력받을 문자열
	char strAlphabet[27] = "abcdefghijklmnopqrstuvwxyz"; // 알파벳을 화면에 출력하기 위한 문자열

	nSelected = rand() % 20;	// 0~19번 중에 하나를 선택해서 정답이 될 단어를 선정한다.
	nWordLength = strlen(strWords[nSelected]);	// 정답 단어의 길이를 구한다.

	for (int i = 0; i < nWordLength; i++)	strInput[i] = '_';	// 정답의 길이만큼 '_'(언더바)를 strInput에 넣음
	strInput[nWordLength] = '\0';	// 위 문자열의 끝에 null character를 넣어준다.

	while (TRUE)	// 무한반복
	{
		system("cls");	// clear screen
// printf("%s\n", strWords[nSelected]);	// 치팅코드
		printf("\n\n");	// 화면 상단에 메뉴명을 출력 
		printf("\t==============================\n");
		printf("\t           WORD GAME\n");
		printf("\t------------------------------\n\n");

		printf("\t  ");	
		for (int i = 0; i < 26; i++) // 알파벳은 26개, 26번 반복
		{
			printf("%c ", strAlphabet[i]);			// 알파벳 출력
			if (!((i + 1) % 13)) printf("\n\n\t  "); // if ((i+1) % 13 == 0) // 간격을 맞추기 위해 13,26번째에서 줄을 바꿔줌
		}

		printf("\n\n\t    ");
		for (int i = 0; i < nWordLength; i++) printf("%c  ", strInput[i]); // 화면에 언더바(문자 입력해서 정답 문자열에 있으면 문자로 바뀜)를 출력하기 위해
		// 입력받은 다음 출력하고 끝낼 수 있게 하기 위해 
		if (!strcmp(strInput, strWords[nSelected])) // 입력했던 문자열과 정답을 비교해서 일치하면 반복문 탈출
		{
			printf("\n\n\t    ");
			printf("Congratulations!!!!\n\n");
			printf("\t    You got the right answer in the %d time\n\n", nCount);	// 몇번만에 맞췄는지 알려주기 위해 출력
			printf("\t==============================\n");
			break; // escape condition
		} // if

		printf("\n\n\n");
		printf("\t    Input >> ");
		getchar();	// 숫자를 입력한 후에 엔터값을 날려버림, 변수를 대입 안했기 때문에 엔터값을 처리할 수 있다. // fflush()
		scanf("%s", strEnter); // 문자열로 입력을 받는다.
		nCount++;	// 입력을 한번 받을 때마다 1씩 카운팅
		
		nInputLength = strlen(strEnter);		// 입력받은 문자열의 길이를 구한다.
		for (int i = 0; i < nInputLength; i++)	// 문자열의 길이만큼 반복
		{
			if (strEnter[i] >= 'A' && strEnter[i] <= 'Z')	// 대소문자 구별없이 입력을 처리할 수 있도록
				strEnter[i] = strEnter[i] + 32;				// 대문자를 소문자로 변환한다.
		} // for

		if (nInputLength == 1) // one character // 문자를 한개 만 입력받았을 경우에
		{
			strAlphabet[strEnter[0] - 'a'] = ' ';	// 알파멧 목록에서 알파벳을 지운다

			for (int i = 0; i < nWordLength; i++)	// 정답 단어의 길이만큼 반복
			{
				if (strEnter[0] == strWords[nSelected][i])	// 문자 하나가 정답에 있는지 탐색한다.
				{
					strInput[i] = strEnter[0];	// 있으면 입력한 문자를 언더바에서 입력한 문자로 바꾼다.
				} // if
			} // for(i) 
		} // if
		else // string // 입력받은 것이 문자가 아닌 문자열이면
		{
			if (!strcmp(strEnter, strWords[nSelected]))	// 입력받은 정답하고 비교
			{
				strcpy(strInput, strEnter);	// 같으면 입력받은걸 strInput에 카피해줌(언더바가 있던 자리에다가)
			} // if
		} // else
	} // while
	printf("\n\t");

} // wordGame()

void OXGame()	// OX 게임 함수
{
	char strNumber[11] = "0123456789";	// 화면에 1~9를 출력하기 위한 문자열, 0은 번호를 맞추기 위해 넣은 것으로 의미는 없음 
	char chPlayer = 'O', chWin;	// 'O'부터 시작하기 때문에 초기값을 O로 설정, chWin은 승자를 받아오기 위한 char형 변수
	int nRepetition = 0; // 반복 횟수 체크, 9번 반복되면 더이상 남은 숫자가 없음

	while (TRUE)	// 무한반복
	{
		displayNumber(strNumber);	// 숫자 및 게임 진행 상황을 예쁘게 표현하기 위한 함수를 불러온다.
		// 입력받은 것을 출력하고 게임을 종료하기 위해서 앞에 위치
		chWin = winCheck(strNumber);	// 승자가 있으면 chWin에 승자를 저장함
		if (chWin != NULL) // NULL이 아니면 누군가 이겼음
		{
			printf("\t  WINNER IS %c\n\n", chWin);	// chWin에 저장된 값이 이겼다고 출력
			break;	// 게임이 끝났으므로 게임 종료
		}
		else if (nRepetition == 9) // chWin == NULL이지만 반복 횟수가 9번을 채워서 더이상 남은 숫자가 없을 때
		{
			printf("\t  DRAW!!\n\n"); // 비긴 것으로 처리
			break;	// 게임이 끝났으므로 게임 종료
		} // if ~ else
		playOX(chPlayer, strNumber);	// OX 게임을 진행하기 위한 함수에 지금 순서인 사람과 
		chPlayer = (chPlayer == 'O') ? 'X' : 'O';	// 플레이어가 O였으면 X로 바꾸고, O가 아니었으면 (즉, X였으면) O로 변경함
		nRepetition += 1;	// 반복 횟수를 1 증가시킴
	} // while

} // OXGame()

void displayNumber(char str[])	// 숫자 및 게임 진행 상황을 예쁘게 표현하기 위한 함수
{
	system("cls");	// clear screen
	printf("\n\n");	// 화면 상단에 메뉴명을 출력 
	printf("\t==============================\n");
	printf("\t            OX GAME\n");
	printf("\t------------------------------\n\n\n");
	printf("\t      ");
	for (int i = 1; i < 10; i++)	// 간격을 예쁘게 출력하기 위한 반복문	(1~9 반복)
	{
		printf("%c", str[i]);		// 1~9까지 각각 출력
		if (!(i % 3)) printf("\n\n\t      ");	// 3의 배수를 출력하면 줄을 바꿔줌
		else          printf("\t      ");		// 나머지 숫자에서는 간격만 띄워줌
	} // for
	printf("\n\t------------------------------\n\n");
} // displayOX()

void playOX(char player, char str[])	// OX 게임 진행에 필요한 함수
{
	char chInput;	// 1~9 중의 숫자를 입력받기 위한 변수
	while (TRUE)	// 무한반복
	{
		printf("\t  %c's turn >> ", player);	// 차례를 나타내주기 위해 출력함
		getchar();	// 버퍼를 제거
		scanf("%c", &chInput);	// 숫자를 입력받음
		if (str[chInput - '0'] == 'O' || str[chInput - '0'] == 'X')	// '3'-'0'= 3 이 되는 원리를 이용하여 숫자 자리에 O나 X가 있으면
		{															// 즉, 저번에 입력해서 O나 X로 바뀐 숫자를 입력하면
			printf("\n\t  전에 입력된 숫자를 입력했습니다.");	// 전에 입력된 숫자를 입력했기 때문에
			printf("\n\t  다시 입력해주세요!\n\n\t  ");			// 다시 입력하라고 출력
			system("pause");		// 위 메세지를 확인해야 하므로 퍼즈를 건다.
			displayNumber(str);		// 다시 숫자 디스플레이를 불러오고
			continue;				// 반복문의 위쪽으로 되돌아가서 다시 입력할 수 있게 해준다.
		} // if
		else	// 빈 곳의 숫자를 정상적으로 입력했을 경우에는
		{
			str[chInput - '0'] = player; // '0'-'0'=0 이 되는 원리를 이용(call by reference) 플레이어(O나 X)를 숫자가 있던 자리에 대입
			break;	// 반복문을 탈출해서 다음 사람의 턴으로 넘어갈 수 있게 한다.
		} // else
	} // while
} // playOX()

char winCheck(char str[])	// 이긴 사람이 있는지 없는지 체크하는 함수
{
	char chReturn = NULL;	// chReturn의 기본값 : NULL
	// 연속된 3개의 문자열이 있을 경우에 chReturn에 'O' 또는 'X'를 저장한다. 저장되는 값이 승리하게 된다.
	if (str[1] == str[2] && str[2] == str[3]) chReturn = str[1];		// 첫번째 행 → 방향
	else if (str[4] == str[5] && str[5] == str[6]) chReturn = str[4];	// 두번째 행 → 방향
	else if (str[7] == str[8] && str[8] == str[9]) chReturn = str[7];	// 세번째 행 → 방향
	else if (str[1] == str[4] && str[4] == str[7]) chReturn = str[1];	// 첫번째 열 ↓ 방향
	else if (str[2] == str[5] && str[5] == str[8]) chReturn = str[2];	// 두번째 열 ↓ 방향
	else if (str[3] == str[6] && str[6] == str[9]) chReturn = str[3];	// 세번째 열 ↓ 방향
	else if (str[1] == str[5] && str[5] == str[9]) chReturn = str[1];	// ↘ 방향 대각선
	else if (str[3] == str[5] && str[5] == str[7]) chReturn = str[3];	// ↙ 방향 대각선

	return chReturn;	// 연속된 3개의 문자열이 없을 경우 계속 NULL을 return하므로 'O' 또는 'X'를 return하면 return된 값이 승리함 

} // winCheck()

void rockScissorsPaperGame()		// 묵찌빠 게임 함수
{
	char sUser[10], sComputer[10];	// 묵찌빠에서 내는 것을 문자열로 저장 (sUser: 유저(사용자), sComputer: 컴퓨터)
	int nUser, nComputer;			// 묵찌빠에서 내는 것을 정수형으로 저장 (nUser: 유저(사용자), nComputer: 컴퓨터)

	getchar();			// 버퍼 비우기
	while (TRUE)		// 무한반복
	{
		RSPDisplay();	// 화면에 프린트하기 위한 함수 불러오기
		printf("\t  가위 바위 보!!\n\n");
		printf("\t  User >> ");
		gets(sUser);	// 사용자가 낼 것을 묵, 찌, 빠 중에서 문자열로 입력받기
		printf("\n");
		if (!strcmp(sUser, "묵")) nUser = ROCK;				// 사용자가 입력한 문자열이 "묵"일 때, 정수형 변수에다 상수 ROCK을 저장
		else if (!strcmp(sUser, "찌")) nUser = SCISSORS;	// 사용자가 입력한 문자열이 "찌"일 때, 정수형 변수에다 상수 SCISSORS을 저장
		else if (!strcmp(sUser, "빠")) nUser = PAPER;		// 사용자가 입력한 문자열이 "빠"일 때, 정수형 변수에다 상수 PAPER을 저장
		else if (strcmp(sUser, "묵") || strcmp(sUser, "찌") || strcmp(sUser, "빠")) // 묵, 찌, 빠가 아닌 다른 것을 입력했을 때
		{
			printf("\t  다시 입력해주세요!\n\n");	// 다시 입력해달라고 출력
			printf("\t==============================\n\n");
			system("pause");		// 잠시 퍼즈를 건 후에 
			continue;				// 반복문 위쪽으로 다시 올라감 -> RSPDisplay()부터 다시 실행
		} // if ~ else

		nComputer = rand() % 3;		// 컴퓨터가 묵찌빠에서 내는 값을 랜덤으로 지정하기 위해 rand()함수 사용 → 3으로 나눠주어 0(묵), 1(찌), 2(빠)만 나오게 설정

		if (nComputer == ROCK) strcpy(sComputer, "묵");				// 랜덤으로 뽑은 수가 0(ROCK)이면 문자열로 "묵"을 저장
		else if (nComputer == SCISSORS) strcpy(sComputer, "찌");	// 랜덤으로 뽑은 수가 1(SCISSORS)이면 문자열로 "찌"를 저장
		else if (nComputer == PAPER) strcpy(sComputer, "빠");		// 랜덤으로 뽑은 수가 2(PAPER)이면 문자열로 "빠"를 저장

		printf("\t  Computer >> %s\n\n", sComputer);				// 컴퓨터가 무엇을 냈는지 출력
		printf("\t------------------------------\n\n");
		if (nUser == nComputer)	// 비겼을 경우
		{
			printf("\t  비겼습니다! 다시 진행합니다.\n\n");	// 비겼다는 메세지를 출력
			printf("\t==============================\n\n");
			system("pause");	// 화면을 잠시 퍼즈한 뒤에
			continue;			// 반복문 위쪽으로 다시 올라감 -> RSPDisplay()부터 다시 실행
		}
		else if ((nUser == ROCK && nComputer == SCISSORS) || (nUser == SCISSORS && nComputer == PAPER) || (nUser == PAPER && nComputer == ROCK))
		{ // 사용자(사람)가 이겼을 경우
			printf("\t  User's turn!!\n\n");	// 유저의 턴이라는 것을 알려준다.
			printf("\t==============================\n\n");
			system("pause");	// 화면을 잠시 퍼즈
			userWin(sUser);		// 사용자가 낸 것을 computerWin() 함수로 전달한다.
			break;				// 함수가 끝나면(게임이 끝나면) 무한반복문을 탈출한다.
		}
		else if ((nComputer == ROCK && nUser == SCISSORS) || (nComputer == SCISSORS && nUser == PAPER) || (nComputer == PAPER && nUser == ROCK))
		{ // 컴퓨터가 이겼을 경우
			printf("\t  Computer's turn!!\n\n");	// 컴퓨터의 턴이라는 것을 알려준다. 
			printf("\t==============================\n\n");
			system("pause");		// 위 메세지를 확인할 수 있게 화면을 잠시 퍼즈
			computerWin(sComputer);	// 컴퓨터가 낸 것을 computerWin() 함수로 전달한다.
			break;					// 함수가 끝나면(게임이 끝나면) 무한반복문을 탈출한다.
		} // if ~ else
	} // while (TRUE)
} // rockScissorsPaperGame()

void RSPDisplay()	// 화면에 다음과 같은 내용을 출력해주는 함수
{
	system("cls");	// clear screen, 화면 정리
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t   ROCK SCISSORS PAPER GAME\n");
	printf("\t------------------------------\n\n");
	printf("\t  컴퓨터와 하는 묵찌빠 게임\n\n");
	printf("\t  묵, 찌, 빠로 입력해주세요.\n\n");
	printf("\t------------------------------\n\n");	// 묵, 찌, 빠로만 입력할 수 있게 안내해준다.
}

void computerWin(char str[]) // 컴퓨터가 이겼을 때 쓰는 함수, str 배열은 전에 냈던 것을 두번 연속으로 말하는 것을 구현하기 위해 불러온다.
{
	char sUserResult[10], sComputerResult[10];	// 묵찌빠에서 내는 것을 문자열로 저장 (sUserResult: 유저(사용자), sComputerResult: 컴퓨터)
	int nUserResult, nComputerResult;			// 묵찌빠에서 내는 것을 정수형으로 저장 (nUserResult: 유저(사용자), nComputerResult: 컴퓨터)
	
	RSPDisplay();			// 화면에 출력하기 위한 함수
	printf("\t  Computer >> %s, %s, ...\n\n", str, str);	// 묵찌빠를 할때 처음에는 가위 바위 보, 다음부터는 자기가 낸것 두번 말하고 진행하기 때문에 이를 구현
	printf("\t  User >> ");
	gets(sUserResult);		// 사용자가 낼 것을 묵, 찌, 빠 중에서 문자열로 입력받기
	printf("\n");
	if (!strcmp(sUserResult, "묵")) nUserResult = ROCK;				// 사용자가 입력한 문자열이 "묵"일 때, 정수형 변수에다 상수 ROCK을 저장
	else if (!strcmp(sUserResult, "찌")) nUserResult = SCISSORS;	// 사용자가 입력한 문자열이 "찌"일 때, 정수형 변수에다 상수 SCISSORS를 저장
	else if (!strcmp(sUserResult, "빠")) nUserResult = PAPER;		// 사용자가 입력한 문자열이 "빠"일 때, 정수형 변수에다 상수 PAPER를 저장
	else if (strcmp(sUserResult, "묵") || strcmp(sUserResult, "찌") || strcmp(sUserResult, "빠")) // 묵, 찌, 빠가 아닌 다른 것을 입력했을 때 (잘못 입력했을 때) 
	{
		printf("\t  다시 입력해주세요!\n\n");		// 다시 입력해달라고 출력함.
		printf("\t==============================\n\n");
		system("pause");	// 메세지를 확인할 수 있게 퍼즈를 건 후에
		computerWin(str);	// 방금 호출했던 함수를 다시 한번 호출함으로써 
	} // if ~ else

	nComputerResult = rand() % 3; // 컴퓨터가 묵찌빠에서 내는 값을 랜덤으로 지정하기 위해 rand()함수 사용 → 3으로 나눠주어 0(묵), 1(찌), 2(빠)만 나오게 설정

	if (nComputerResult == ROCK) strcpy(sComputerResult, "묵");				// 랜덤으로 뽑은 수가 0(ROCK)이면 문자열로 "묵"을 저장
	else if (nComputerResult == SCISSORS) strcpy(sComputerResult, "찌");	// 랜덤으로 뽑은 수가 1(SCISSORS)이면 문자열로 "찌"를 저장
	else if (nComputerResult == PAPER) strcpy(sComputerResult, "빠");		// 랜덤으로 뽑은 수가 2(PAPER)이면 문자열로 "빠"를 저장

	printf("\t  Computer >> %s, %s, %s!\n\n", str, str, sComputerResult);	// 컴퓨터가 낸 것을 묵찌빠 느낌으로 출력함
	printf("\t------------------------------\n\n");
	if (nUserResult == nComputerResult)	// 서로 낸 것이 같으면 
	{
		printf("\t  최종적으로 컴퓨터의 승리입니다!\n\n");	// 컴퓨터의 승리로 끝남
		printf("\t  게임을 종료합니다.\n\n");				// 함수가 끝나고 함수를 호출한 부분 뒤에 잇는 break를 통해 게임을 종료함
		printf("\t==============================\n\n");
	}
	else if ((nUserResult == ROCK && nComputerResult == SCISSORS) || (nUserResult == SCISSORS && nComputerResult == PAPER) || (nUserResult == PAPER && nComputerResult == ROCK))
	{	// 사용자가 이번 턴에 이겼을 경우
		printf("\t  User's turn!!\n\n");	// 유저의 턴이라고 알려줌
		printf("\t==============================\n\n");
		system("pause");		// 메세지를 확인할 수 있게 퍼즈
		userWin(sUserResult);	// 유저의 턴으로 넘어가기 위해 유저가 이겼을 때 불러오는 함수를 호출
	}
	else if ((nComputerResult == ROCK && nUserResult == SCISSORS) || (nComputerResult == SCISSORS && nUserResult == PAPER) || (nComputerResult == PAPER && nUserResult == ROCK))
	{	// 컴퓨터가 이번 턴에 이겼을 경우
		printf("\t  Computer's turn!!\n\n");	// 컴퓨터의 턴이라고 알려줌
		printf("\t==============================\n\n");
		system("pause");				// 메세지를 확인할 수 있게 퍼즈
		computerWin(sComputerResult);	// 컴퓨터의 턴으로 넘어가기 위해 유저가 이겼을 때 불러오는 함수를 호출
	} // if ~ else
} // computerWin()

////////////////////////////////////////////////////////////////////////////////////
// userWin 함수는 computerWin 함수와 로직이 동일하기 때문에 약간 다른 부분만 서술 //
////////////////////////////////////////////////////////////////////////////////////

void userWin(char str[]) // 사용자가 이겼을 때 쓰는 함수로, str 배열은 전에 냈던 것을 두번 연속으로 말하는 것을 구현하기 위해 불러온다.
{
	char sUserResult[10], sComputerResult[10];
	int nUserResult, nComputerResult;
	
	RSPDisplay();
	printf("\t  User >> %s, %s, \n\n\t  User >> ", str, str);	// 냈던 것을 두번 말하고, (ex 묵, 묵, ...) 
	gets(sUserResult);			// 바로 유저가 낼 것을 입력받음
	printf("\n");
	if (!strcmp(sUserResult, "묵")) nUserResult = ROCK;
	else if (!strcmp(sUserResult, "찌")) nUserResult = SCISSORS;
	else if (!strcmp(sUserResult, "빠")) nUserResult = PAPER;
	else if (strcmp(sUserResult, "묵") || strcmp(sUserResult, "찌") || strcmp(sUserResult, "빠"))
	{
		printf("\t  다시 입력해주세요!\n\n");
		printf("\t==============================\n\n");
		system("pause");
		userWin(str);
	} // if ~ else

	nComputerResult = rand() % 3;

	if (nComputerResult == ROCK) strcpy(sComputerResult, "묵");
	else if (nComputerResult == SCISSORS) strcpy(sComputerResult, "찌");
	else if (nComputerResult == PAPER) strcpy(sComputerResult, "빠");

	printf("\t  Computer >> %s\n\n", sComputerResult);
	printf("\t------------------------------\n\n");
	if (nUserResult == nComputerResult)
	{
		printf("\t  최종적으로 유저의 승리입니다!!\n\n");	// 사용자의 승리로 끝남
		printf("\t  게임을 종료합니다.\n\n");
		printf("\t==============================\n\n");
	}
	else if ((nUserResult == ROCK && nComputerResult == SCISSORS) || (nUserResult == SCISSORS && nComputerResult == PAPER) || (nUserResult == PAPER && nComputerResult == ROCK))
	{
		printf("\t  User's turn!!\n\n");
		printf("\t==============================\n\n");
		system("pause");
		userWin(sUserResult);
	}
	else if ((nComputerResult == ROCK && nUserResult == SCISSORS) || (nComputerResult == SCISSORS && nUserResult == PAPER) || (nComputerResult == PAPER && nUserResult == ROCK))
	{
		printf("\t  Computer's turn!!\n\n");
		printf("\t==============================\n\n");
		system("pause");
		computerWin(sComputerResult);
	} // if ~ else
} // userWin()

void about() // 만든사람을 소개할 때 쓰는 함수
{
	printf("\n\n");	// 프로그램 정보를 출력해준다.
	printf("\t==============================\n");
	printf("\t   Console Menu Program v1.0\n");	// 직접 만든 프로그램도 있으므로 버전 1.0으로 업그레이드
	printf("\t------------------------------\n\n");
	printf("\t   Programmed by Kim Dongho\n\n");	
	printf("\t==============================\n\n");
} // about()