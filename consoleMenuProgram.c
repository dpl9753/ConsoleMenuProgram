#include "consoleMenuProgram.h"	// ����� ���� �������

int main()	// ���� �Լ�
{
	int nMainMenu;	// ����ڷκ��� �Է¹��� ���ڸ� �����ϴ� ����
	int bIterationFlag = TRUE;	// ���ѹݺ� Ż�������� ���� ���� ����, ó������ �ϴ� ������Ѿ� �ϴ� TRUE�� �ʱ�ȭ

	srand(time(NULL));	// ���� ���ڰ� ������ �ʰ� �ϱ� ���� ���� �ð����� ���̺��� �ҷ���

	while (bIterationFlag)	// (bIterationFlag == TRUE)�� ���� �ݺ�
	{
		system("cls");	// clear screen

		nMainMenu = displayMainMenu();	// ���θ޴��� ����ϰ� ����ڰ� �Է��� �޴� ��ȣ�� �޾Ƽ� nMainMenu ������ ����

		system("cls");	// clear screen
		switch (nMainMenu)	// ����� �Է¹޾Ҵ��Ŀ� ���� ������ �޴��� �޶�����.
		{
		case DIE_SIMULATION:	// 1���� �Է¹޾�����
			dieSimulation();	// �ֻ��� �ùķ��̼� �޴��� ����
			break;				// ������ switch�� Ż��
		case GAME_SHOW:			// 2���� �Է¹޾�����
			gameShow();			// ���� �� �޴��� ����
			break;				// ������ switch�� Ż��
		case UPDOWN_GAME:		// 3���� �Է¹޾�����
			upDownGame();		// ���ٿ� �������� ����
			break;				// ������ switch�� Ż��
		case WORD_GAME:			// 4���� �Է¹޾�����
			wordGame();			// �ܾ� ���߱� �������� ����
			break;				// ������ switch�� Ż��
		case OX_GAME:			// 5���� �Է¹޾�����
			OXGame();			// OX �������� ����
			break;				// ������ switch�� Ż��
		case ROCK_SCISSORS_PAPER_GAME:	// 6���� �Է¹޾�����
			rockScissorsPaperGame();	// ����� �������� ����
			break;				// ������ switch�� Ż��
		case ABOUT:				// 7���� �Է¹޾�����
			about();			// ���α׷� ���� �޴��� ����
			break;				// ������ switch�� Ż��
		case EXIT:				// 0���� �Է¹޾�����
			printf("\n\n");
			printf("\tGOOD-BYE~~\n");	// ������ �λ縻 ���
			// exit(0);				// ������ ���� ��ɾ�ε� ������ �� ����
			bIterationFlag = FALSE;	// escape condition, bIterationFlag�� FALSE�� �ٲ�鼭 ���ѹݺ����� Ż���ϰ� ��. (���α׷� ����)
			break;
		default:				// �Է¹��� ���� �� switch���� ������
			printf("\n\n");
			printf("\tWrong Input!!!\n");	// �߸��� �Է��̶�� �˷���
			break;				// switch�� Ż�� -> �ٷ� �� if���� ���� pause�� �� �Ŀ� �ٽ� �� ���� �ö󰡼� �ٽ� �Է¹���
		} //switch

		if (nMainMenu != 0)		// (switch���� Ż���� ��) ���α׷��� �����ϴ°� �ƴϸ�
			system("pause");	// press any key to continue
		// ��� �� �ڿ� �ݺ��� �� ���� �ٽ� �ö�. ��, ���θ޴��� �ٽ� ����
	} //while

	return 0;	// ���� ���Ḧ �ǹ��ϴ� ��ȯ �� : 0
} //main()

// implementation of user defined functions
int displayMainMenu()	// ���� ó�� ������ ȭ�鿡 ���õ� �Լ�
{
	int nSelectedMainMenu;	// ����ڰ� ���ϴ� �޴��� �Է¹޴� ����
	// ����ڰ� �޴��� �� �� �ְ� ��ȣ�� �޴����� ���
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
	scanf("%d", &nSelectedMainMenu);	// ����ڰ� ���ϴ� �޴��� �Է¹���

	return nSelectedMainMenu;			// �Է¹��� �޴� ��ȣ�� return
} // displayMainMenu()

void dieSimulation() // �ֻ��� �ùķ����� �Լ�
{
	int nFace, nSum = 0, nCount = 0;	// nFace: �ֻ����� �� / nSum�� nCount�� ���� �հ踦 ���ϰų� ī��Ʈ�ϴ� �����̹Ƿ� 0���� �ʱ�ȭ
	// ȭ�� ��ܿ� �޴����� ��� 
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t        DIE SIMULATION\n");
	printf("\t------------------------------\n\n");
	for (int i = 0; i < 100000; i++, nSum = 0) // �ùķ��̼��� ���� ������ 10���� �ݺ�
	{
		while (nSum < 100) // �հ谡 100���� ���� ����
		{
			nFace = (rand() % 6) + 1;	// �ѹ� ������ �� ������ �ֻ����� ��, ������ �����ϰ� 1 ~ 6
			nSum += nFace;	// �հ迡 ��� ���� �ֻ����� ���� �����ش�.
			nCount++;		// �ֻ����� ���� Ƚ���� ī��Ʈ�Ѵ�.
		} // while
	} // for

	printf("\t  ��ǻ�� �ùķ��̼� ���,\n");
	printf("\t  �ֻ����� ��������\n");
	printf("\t  100�� ��������\n");
	printf("\t  �� %dȸ���� ������ �˴ϴ�.\n\n", (int)((double) nCount/100000+0.5)); // 10���� ������ �� ��� ������ �������� 100�� �Ѵ��� ����� ���Ѵ�. 
	printf("\t==============================\n\n");							 // 0.5�� ���� �ݿø��� ���ش�. �Ǽ������� ����� �ڿ� ���������� �ٲپ� ���

} // dieSimulation()

void gameShow()	// ���� �� �Լ�
{
	int nPrizeDoor, nSelectDoor;	// ��ǰ�� �ִ� ��, ó���� �����ϴ� ��
	int nRevealDoor, nSwitchDoor;	// ��ȸ�ڰ� �����ִ� ��, ó�� ������ ���� �ƴϰ� ��ȸ�ڰ� ������ ���� �ƴ� ������ ��
	int nSelectCount = 0, nSwitchCount = 0;	// ���� �������� �� ��÷�Ǵ� Ƚ���� ���� ���� ����, ���� �������� �� ��÷�Ǵ� Ƚ���� ���� ���� ����
	// ȭ�� ��ܿ� �޴����� ��� 
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t           GAME SHOW\n");
	printf("\t------------------------------\n\n");

	// case 1
	for (int i = 0; i < 100000; i++) // �ùķ��̼��� ���� ���� ������ 10���� ����
	{	
		nPrizeDoor = rand() % 3;	// ������ 3���� ���� ������ -> 0~2 ������ ������ ����, ��ǰ�� �ִ� ���� ��ȣ
		nSelectDoor = rand() % 3;	// ������ 3���� ���� ������ -> 0~2 ������ ������ ����, ������ ���� ��ȣ
		if (nPrizeDoor == nSelectDoor) nSelectCount++;	// ��ǰ�� �ִ� ���� ������ ���� ��ȣ�� ������, �״�� �������� ���� ��÷ Ƚ���� 1 ������Ų��.
	} // for
	printf("\t  Select >> %.2lf %%\n\n", (double)nSelectCount / 1000);	// ���� �״�� ������ ��� ��÷�� Ȯ��

	// case 2
	for (int i = 0; i < 100000; i++)// �ùķ��̼��� ���� ���� ������ 10���� ����
	{
		nPrizeDoor = rand() % 3;	// ������ 3���� ���� ������ -> 0~2 ������ ������ ����, ��ǰ�� �ִ� ���� ��ȣ 
		nSelectDoor = rand() % 3;	// ������ 3���� ���� ������ -> 0~2 ������ ������ ����, ������ ���� ��ȣ

		nRevealDoor = 0;	// nRevealDoor�� 0���� �ʱ�ȭ
		while (nRevealDoor == nPrizeDoor || nRevealDoor == nSelectDoor)	// nRevealDoor�� ���� �� �� �ϳ��� ���� ���� ��쿡��
			nRevealDoor++;	// nRevealDoor�� ���� �������� nRevealDoor�� ���� nPrizeDoor�� ���̳� nSelectDoor�� ���� ���� �ʵ��� ����

		nSwitchDoor = 0;	// nRevealDoor�� 0���� �ʱ�ȭ
		while (nSwitchDoor == nSelectDoor || nSwitchDoor == nRevealDoor) // nSwitchDoor�� ���� �� �� �ϳ��� ���� ���� ��쿡��
			nSwitchDoor++;	// nSwitchDoor�� ���� �������� nSwitchDoor�� ���� nSelectDoor�� ���̳� nRevealDoor�� ���� ���� �ʵ��� ����

		if (nPrizeDoor == nSwitchDoor) nSwitchCount++;	// ��ǰ�� �ִ� ���� �ٲ� ���� ��ȣ�� ������, ���� �ٲ��� ���� ��÷ Ƚ���� 1 ������Ų��.
	} // for
	printf("\t  Switch >> %.2lf %%\n\n", (double)nSwitchCount / 1000);	// ���� �ٲ� ��� ��÷�� Ȯ��
	printf("\t==============================\n\n");

} // gameShow()

void upDownGame() // ���ٿ� ���� �Լ�
{
	int nAnswer, nInput;	// ������ ����, ����ڰ� �Է��ϴ� ����
	int nCount = 0;			// �õ� Ƚ���� ī��Ʈ�ϱ� ���� ����, �ѹ� �õ��� ������ 1�� �����ϹǷ� 0���� �ʱ�ȭ
	int nMin = 1, nMax = 100;	// �ּڰ��� 1, �ִ��� 100, ������ min�̻� max���Ͽ� �����Ѵ�.
	int bFlag = TRUE;		// ���ѹݺ� Ż���� ���� ���� ����, ó������ �ϴ� ������Ѿ� �ϴ� TRUE�� �ʱ�ȭ

	nAnswer = rand() % 100 + 1;	// 1~100�� ���� �� �������� �ϳ��� �������� ���� 

	while (bFlag) 
	{
		system("cls");
		printf("\n\n");	// ȭ�� ��ܿ� �޴����� ��� 
		printf("\t==============================\n");
		printf("\t          UPDOWN GAME\n");
		printf("\t------------------------------\n\n");
		printf("\t  %3d to %3d\n\n", nMin, nMax);	// ����ڰ� �Է��ؾ� �� ������ ������ ���
		printf("\t  input number >> ");
		scanf("%d", &nInput);	// ����ڰ� ������ ���߱� ���� ���ڸ� �ϳ� �Է��Ѵ�.
		nCount++;		// ������� ������� �˷��ֱ� ���ؼ� �ݺ����� ī��Ʈ�� ������Ų��.

		if (nInput < nAnswer) // ���亸�� ���� ���� �Է����� ���
		{	
			nMin = nInput + 1;		// ������ ������ (�Է��� �� + 1 <= ���� <= �ִ�)�� �ȴ�.
			printf("\n\t  UP\n\n");	// ������ �Է��� ������ ũ�ٰ� ���
		}
		else if (nInput > nAnswer)	// ���亸�� ū ���� �Է����� ���
		{	
			nMax = nInput - 1;		// ������ ������ (�ּڰ� <= ���� <= �Է��� �� - 1)�� �ȴ�.
			printf("\n\t  DOWN\n\n");	// ������ �Է��� ������ �۴ٰ� ���
		}
		else	// ������ ������ ���
		{
			printf("\n\t  RIGHT!! (%d times)\n\n", nCount);	// ������� ������� ������ش�.
			bFlag = FALSE; //break; // escape condition, ���ѹݺ����� Ż���Ѵ�.
		} // if...else

		printf("\t==============================\n\n");
		if (bFlag) system("pause");	// ������ �������� ��� ��� �ɾ��ش�. ��� �ɾ��ָ� ȭ���� �ʹ� ������ �������� UP! DOWN!�� Ȯ������ ���Ѵ�.
	} // while

} // upDownGame()

void wordGame()	// �ܾ� ���߱� ���� �Լ�
{
	char strWords[20][40] = {	// ���� ���ڿ��� 20�� �����س��� ���� ������ 2���� �迭
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
	// ���ʷ�: 20���� �ܾ� �� ���� �ܾ ���� / �������� ���õ� �ܾ��� ���� / ������� ������� ī��Ʈ�ϱ� ���� ���� / ����ڰ� �Է��� ���ڿ��� ����
	int nSelected, nWordLength, nCount = 0, nInputLength;
	char strInput[40], strEnter[40]; // �Է��� ���ڵ��� ȭ�鿡 ����ϱ� ���� �迭 / ����ڷκ��� �Է¹��� ���ڿ�
	char strAlphabet[27] = "abcdefghijklmnopqrstuvwxyz"; // ���ĺ��� ȭ�鿡 ����ϱ� ���� ���ڿ�

	nSelected = rand() % 20;	// 0~19�� �߿� �ϳ��� �����ؼ� ������ �� �ܾ �����Ѵ�.
	nWordLength = strlen(strWords[nSelected]);	// ���� �ܾ��� ���̸� ���Ѵ�.

	for (int i = 0; i < nWordLength; i++)	strInput[i] = '_';	// ������ ���̸�ŭ '_'(�����)�� strInput�� ����
	strInput[nWordLength] = '\0';	// �� ���ڿ��� ���� null character�� �־��ش�.

	while (TRUE)	// ���ѹݺ�
	{
		system("cls");	// clear screen
// printf("%s\n", strWords[nSelected]);	// ġ���ڵ�
		printf("\n\n");	// ȭ�� ��ܿ� �޴����� ��� 
		printf("\t==============================\n");
		printf("\t           WORD GAME\n");
		printf("\t------------------------------\n\n");

		printf("\t  ");	
		for (int i = 0; i < 26; i++) // ���ĺ��� 26��, 26�� �ݺ�
		{
			printf("%c ", strAlphabet[i]);			// ���ĺ� ���
			if (!((i + 1) % 13)) printf("\n\n\t  "); // if ((i+1) % 13 == 0) // ������ ���߱� ���� 13,26��°���� ���� �ٲ���
		}

		printf("\n\n\t    ");
		for (int i = 0; i < nWordLength; i++) printf("%c  ", strInput[i]); // ȭ�鿡 �����(���� �Է��ؼ� ���� ���ڿ��� ������ ���ڷ� �ٲ�)�� ����ϱ� ����
		// �Է¹��� ���� ����ϰ� ���� �� �ְ� �ϱ� ���� 
		if (!strcmp(strInput, strWords[nSelected])) // �Է��ߴ� ���ڿ��� ������ ���ؼ� ��ġ�ϸ� �ݺ��� Ż��
		{
			printf("\n\n\t    ");
			printf("Congratulations!!!!\n\n");
			printf("\t    You got the right answer in the %d time\n\n", nCount);	// ������� ������� �˷��ֱ� ���� ���
			printf("\t==============================\n");
			break; // escape condition
		} // if

		printf("\n\n\n");
		printf("\t    Input >> ");
		getchar();	// ���ڸ� �Է��� �Ŀ� ���Ͱ��� ��������, ������ ���� ���߱� ������ ���Ͱ��� ó���� �� �ִ�. // fflush()
		scanf("%s", strEnter); // ���ڿ��� �Է��� �޴´�.
		nCount++;	// �Է��� �ѹ� ���� ������ 1�� ī����
		
		nInputLength = strlen(strEnter);		// �Է¹��� ���ڿ��� ���̸� ���Ѵ�.
		for (int i = 0; i < nInputLength; i++)	// ���ڿ��� ���̸�ŭ �ݺ�
		{
			if (strEnter[i] >= 'A' && strEnter[i] <= 'Z')	// ��ҹ��� �������� �Է��� ó���� �� �ֵ���
				strEnter[i] = strEnter[i] + 32;				// �빮�ڸ� �ҹ��ڷ� ��ȯ�Ѵ�.
		} // for

		if (nInputLength == 1) // one character // ���ڸ� �Ѱ� �� �Է¹޾��� ��쿡
		{
			strAlphabet[strEnter[0] - 'a'] = ' ';	// ���ĸ� ��Ͽ��� ���ĺ��� �����

			for (int i = 0; i < nWordLength; i++)	// ���� �ܾ��� ���̸�ŭ �ݺ�
			{
				if (strEnter[0] == strWords[nSelected][i])	// ���� �ϳ��� ���信 �ִ��� Ž���Ѵ�.
				{
					strInput[i] = strEnter[0];	// ������ �Է��� ���ڸ� ����ٿ��� �Է��� ���ڷ� �ٲ۴�.
				} // if
			} // for(i) 
		} // if
		else // string // �Է¹��� ���� ���ڰ� �ƴ� ���ڿ��̸�
		{
			if (!strcmp(strEnter, strWords[nSelected]))	// �Է¹��� �����ϰ� ��
			{
				strcpy(strInput, strEnter);	// ������ �Է¹����� strInput�� ī������(����ٰ� �ִ� �ڸ����ٰ�)
			} // if
		} // else
	} // while
	printf("\n\t");

} // wordGame()

void OXGame()	// OX ���� �Լ�
{
	char strNumber[11] = "0123456789";	// ȭ�鿡 1~9�� ����ϱ� ���� ���ڿ�, 0�� ��ȣ�� ���߱� ���� ���� ������ �ǹ̴� ���� 
	char chPlayer = 'O', chWin;	// 'O'���� �����ϱ� ������ �ʱⰪ�� O�� ����, chWin�� ���ڸ� �޾ƿ��� ���� char�� ����
	int nRepetition = 0; // �ݺ� Ƚ�� üũ, 9�� �ݺ��Ǹ� ���̻� ���� ���ڰ� ����

	while (TRUE)	// ���ѹݺ�
	{
		displayNumber(strNumber);	// ���� �� ���� ���� ��Ȳ�� ���ڰ� ǥ���ϱ� ���� �Լ��� �ҷ��´�.
		// �Է¹��� ���� ����ϰ� ������ �����ϱ� ���ؼ� �տ� ��ġ
		chWin = winCheck(strNumber);	// ���ڰ� ������ chWin�� ���ڸ� ������
		if (chWin != NULL) // NULL�� �ƴϸ� ������ �̰���
		{
			printf("\t  WINNER IS %c\n\n", chWin);	// chWin�� ����� ���� �̰�ٰ� ���
			break;	// ������ �������Ƿ� ���� ����
		}
		else if (nRepetition == 9) // chWin == NULL������ �ݺ� Ƚ���� 9���� ä���� ���̻� ���� ���ڰ� ���� ��
		{
			printf("\t  DRAW!!\n\n"); // ��� ������ ó��
			break;	// ������ �������Ƿ� ���� ����
		} // if ~ else
		playOX(chPlayer, strNumber);	// OX ������ �����ϱ� ���� �Լ��� ���� ������ ����� 
		chPlayer = (chPlayer == 'O') ? 'X' : 'O';	// �÷��̾ O������ X�� �ٲٰ�, O�� �ƴϾ����� (��, X������) O�� ������
		nRepetition += 1;	// �ݺ� Ƚ���� 1 ������Ŵ
	} // while

} // OXGame()

void displayNumber(char str[])	// ���� �� ���� ���� ��Ȳ�� ���ڰ� ǥ���ϱ� ���� �Լ�
{
	system("cls");	// clear screen
	printf("\n\n");	// ȭ�� ��ܿ� �޴����� ��� 
	printf("\t==============================\n");
	printf("\t            OX GAME\n");
	printf("\t------------------------------\n\n\n");
	printf("\t      ");
	for (int i = 1; i < 10; i++)	// ������ ���ڰ� ����ϱ� ���� �ݺ���	(1~9 �ݺ�)
	{
		printf("%c", str[i]);		// 1~9���� ���� ���
		if (!(i % 3)) printf("\n\n\t      ");	// 3�� ����� ����ϸ� ���� �ٲ���
		else          printf("\t      ");		// ������ ���ڿ����� ���ݸ� �����
	} // for
	printf("\n\t------------------------------\n\n");
} // displayOX()

void playOX(char player, char str[])	// OX ���� ���࿡ �ʿ��� �Լ�
{
	char chInput;	// 1~9 ���� ���ڸ� �Է¹ޱ� ���� ����
	while (TRUE)	// ���ѹݺ�
	{
		printf("\t  %c's turn >> ", player);	// ���ʸ� ��Ÿ���ֱ� ���� �����
		getchar();	// ���۸� ����
		scanf("%c", &chInput);	// ���ڸ� �Է¹���
		if (str[chInput - '0'] == 'O' || str[chInput - '0'] == 'X')	// '3'-'0'= 3 �� �Ǵ� ������ �̿��Ͽ� ���� �ڸ��� O�� X�� ������
		{															// ��, ������ �Է��ؼ� O�� X�� �ٲ� ���ڸ� �Է��ϸ�
			printf("\n\t  ���� �Էµ� ���ڸ� �Է��߽��ϴ�.");	// ���� �Էµ� ���ڸ� �Է��߱� ������
			printf("\n\t  �ٽ� �Է����ּ���!\n\n\t  ");			// �ٽ� �Է��϶�� ���
			system("pause");		// �� �޼����� Ȯ���ؾ� �ϹǷ� ��� �Ǵ�.
			displayNumber(str);		// �ٽ� ���� ���÷��̸� �ҷ�����
			continue;				// �ݺ����� �������� �ǵ��ư��� �ٽ� �Է��� �� �ְ� ���ش�.
		} // if
		else	// �� ���� ���ڸ� ���������� �Է����� ��쿡��
		{
			str[chInput - '0'] = player; // '0'-'0'=0 �� �Ǵ� ������ �̿�(call by reference) �÷��̾�(O�� X)�� ���ڰ� �ִ� �ڸ��� ����
			break;	// �ݺ����� Ż���ؼ� ���� ����� ������ �Ѿ �� �ְ� �Ѵ�.
		} // else
	} // while
} // playOX()

char winCheck(char str[])	// �̱� ����� �ִ��� ������ üũ�ϴ� �Լ�
{
	char chReturn = NULL;	// chReturn�� �⺻�� : NULL
	// ���ӵ� 3���� ���ڿ��� ���� ��쿡 chReturn�� 'O' �Ǵ� 'X'�� �����Ѵ�. ����Ǵ� ���� �¸��ϰ� �ȴ�.
	if (str[1] == str[2] && str[2] == str[3]) chReturn = str[1];		// ù��° �� �� ����
	else if (str[4] == str[5] && str[5] == str[6]) chReturn = str[4];	// �ι�° �� �� ����
	else if (str[7] == str[8] && str[8] == str[9]) chReturn = str[7];	// ����° �� �� ����
	else if (str[1] == str[4] && str[4] == str[7]) chReturn = str[1];	// ù��° �� �� ����
	else if (str[2] == str[5] && str[5] == str[8]) chReturn = str[2];	// �ι�° �� �� ����
	else if (str[3] == str[6] && str[6] == str[9]) chReturn = str[3];	// ����° �� �� ����
	else if (str[1] == str[5] && str[5] == str[9]) chReturn = str[1];	// �� ���� �밢��
	else if (str[3] == str[5] && str[5] == str[7]) chReturn = str[3];	// �� ���� �밢��

	return chReturn;	// ���ӵ� 3���� ���ڿ��� ���� ��� ��� NULL�� return�ϹǷ� 'O' �Ǵ� 'X'�� return�ϸ� return�� ���� �¸��� 

} // winCheck()

void rockScissorsPaperGame()		// ����� ���� �Լ�
{
	char sUser[10], sComputer[10];	// ��������� ���� ���� ���ڿ��� ���� (sUser: ����(�����), sComputer: ��ǻ��)
	int nUser, nComputer;			// ��������� ���� ���� ���������� ���� (nUser: ����(�����), nComputer: ��ǻ��)

	getchar();			// ���� ����
	while (TRUE)		// ���ѹݺ�
	{
		RSPDisplay();	// ȭ�鿡 ����Ʈ�ϱ� ���� �Լ� �ҷ�����
		printf("\t  ���� ���� ��!!\n\n");
		printf("\t  User >> ");
		gets(sUser);	// ����ڰ� �� ���� ��, ��, �� �߿��� ���ڿ��� �Է¹ޱ�
		printf("\n");
		if (!strcmp(sUser, "��")) nUser = ROCK;				// ����ڰ� �Է��� ���ڿ��� "��"�� ��, ������ �������� ��� ROCK�� ����
		else if (!strcmp(sUser, "��")) nUser = SCISSORS;	// ����ڰ� �Է��� ���ڿ��� "��"�� ��, ������ �������� ��� SCISSORS�� ����
		else if (!strcmp(sUser, "��")) nUser = PAPER;		// ����ڰ� �Է��� ���ڿ��� "��"�� ��, ������ �������� ��� PAPER�� ����
		else if (strcmp(sUser, "��") || strcmp(sUser, "��") || strcmp(sUser, "��")) // ��, ��, ���� �ƴ� �ٸ� ���� �Է����� ��
		{
			printf("\t  �ٽ� �Է����ּ���!\n\n");	// �ٽ� �Է��ش޶�� ���
			printf("\t==============================\n\n");
			system("pause");		// ��� ��� �� �Ŀ� 
			continue;				// �ݺ��� �������� �ٽ� �ö� -> RSPDisplay()���� �ٽ� ����
		} // if ~ else

		nComputer = rand() % 3;		// ��ǻ�Ͱ� ��������� ���� ���� �������� �����ϱ� ���� rand()�Լ� ��� �� 3���� �����־� 0(��), 1(��), 2(��)�� ������ ����

		if (nComputer == ROCK) strcpy(sComputer, "��");				// �������� ���� ���� 0(ROCK)�̸� ���ڿ��� "��"�� ����
		else if (nComputer == SCISSORS) strcpy(sComputer, "��");	// �������� ���� ���� 1(SCISSORS)�̸� ���ڿ��� "��"�� ����
		else if (nComputer == PAPER) strcpy(sComputer, "��");		// �������� ���� ���� 2(PAPER)�̸� ���ڿ��� "��"�� ����

		printf("\t  Computer >> %s\n\n", sComputer);				// ��ǻ�Ͱ� ������ �´��� ���
		printf("\t------------------------------\n\n");
		if (nUser == nComputer)	// ����� ���
		{
			printf("\t  �����ϴ�! �ٽ� �����մϴ�.\n\n");	// ���ٴ� �޼����� ���
			printf("\t==============================\n\n");
			system("pause");	// ȭ���� ��� ������ �ڿ�
			continue;			// �ݺ��� �������� �ٽ� �ö� -> RSPDisplay()���� �ٽ� ����
		}
		else if ((nUser == ROCK && nComputer == SCISSORS) || (nUser == SCISSORS && nComputer == PAPER) || (nUser == PAPER && nComputer == ROCK))
		{ // �����(���)�� �̰��� ���
			printf("\t  User's turn!!\n\n");	// ������ ���̶�� ���� �˷��ش�.
			printf("\t==============================\n\n");
			system("pause");	// ȭ���� ��� ����
			userWin(sUser);		// ����ڰ� �� ���� computerWin() �Լ��� �����Ѵ�.
			break;				// �Լ��� ������(������ ������) ���ѹݺ����� Ż���Ѵ�.
		}
		else if ((nComputer == ROCK && nUser == SCISSORS) || (nComputer == SCISSORS && nUser == PAPER) || (nComputer == PAPER && nUser == ROCK))
		{ // ��ǻ�Ͱ� �̰��� ���
			printf("\t  Computer's turn!!\n\n");	// ��ǻ���� ���̶�� ���� �˷��ش�. 
			printf("\t==============================\n\n");
			system("pause");		// �� �޼����� Ȯ���� �� �ְ� ȭ���� ��� ����
			computerWin(sComputer);	// ��ǻ�Ͱ� �� ���� computerWin() �Լ��� �����Ѵ�.
			break;					// �Լ��� ������(������ ������) ���ѹݺ����� Ż���Ѵ�.
		} // if ~ else
	} // while (TRUE)
} // rockScissorsPaperGame()

void RSPDisplay()	// ȭ�鿡 ������ ���� ������ ������ִ� �Լ�
{
	system("cls");	// clear screen, ȭ�� ����
	printf("\n\n");
	printf("\t==============================\n");
	printf("\t   ROCK SCISSORS PAPER GAME\n");
	printf("\t------------------------------\n\n");
	printf("\t  ��ǻ�Ϳ� �ϴ� ����� ����\n\n");
	printf("\t  ��, ��, ���� �Է����ּ���.\n\n");
	printf("\t------------------------------\n\n");	// ��, ��, ���θ� �Է��� �� �ְ� �ȳ����ش�.
}

void computerWin(char str[]) // ��ǻ�Ͱ� �̰��� �� ���� �Լ�, str �迭�� ���� �´� ���� �ι� �������� ���ϴ� ���� �����ϱ� ���� �ҷ��´�.
{
	char sUserResult[10], sComputerResult[10];	// ��������� ���� ���� ���ڿ��� ���� (sUserResult: ����(�����), sComputerResult: ��ǻ��)
	int nUserResult, nComputerResult;			// ��������� ���� ���� ���������� ���� (nUserResult: ����(�����), nComputerResult: ��ǻ��)
	
	RSPDisplay();			// ȭ�鿡 ����ϱ� ���� �Լ�
	printf("\t  Computer >> %s, %s, ...\n\n", str, str);	// ������� �Ҷ� ó������ ���� ���� ��, �������ʹ� �ڱⰡ ���� �ι� ���ϰ� �����ϱ� ������ �̸� ����
	printf("\t  User >> ");
	gets(sUserResult);		// ����ڰ� �� ���� ��, ��, �� �߿��� ���ڿ��� �Է¹ޱ�
	printf("\n");
	if (!strcmp(sUserResult, "��")) nUserResult = ROCK;				// ����ڰ� �Է��� ���ڿ��� "��"�� ��, ������ �������� ��� ROCK�� ����
	else if (!strcmp(sUserResult, "��")) nUserResult = SCISSORS;	// ����ڰ� �Է��� ���ڿ��� "��"�� ��, ������ �������� ��� SCISSORS�� ����
	else if (!strcmp(sUserResult, "��")) nUserResult = PAPER;		// ����ڰ� �Է��� ���ڿ��� "��"�� ��, ������ �������� ��� PAPER�� ����
	else if (strcmp(sUserResult, "��") || strcmp(sUserResult, "��") || strcmp(sUserResult, "��")) // ��, ��, ���� �ƴ� �ٸ� ���� �Է����� �� (�߸� �Է����� ��) 
	{
		printf("\t  �ٽ� �Է����ּ���!\n\n");		// �ٽ� �Է��ش޶�� �����.
		printf("\t==============================\n\n");
		system("pause");	// �޼����� Ȯ���� �� �ְ� ��� �� �Ŀ�
		computerWin(str);	// ��� ȣ���ߴ� �Լ��� �ٽ� �ѹ� ȣ�������ν� 
	} // if ~ else

	nComputerResult = rand() % 3; // ��ǻ�Ͱ� ��������� ���� ���� �������� �����ϱ� ���� rand()�Լ� ��� �� 3���� �����־� 0(��), 1(��), 2(��)�� ������ ����

	if (nComputerResult == ROCK) strcpy(sComputerResult, "��");				// �������� ���� ���� 0(ROCK)�̸� ���ڿ��� "��"�� ����
	else if (nComputerResult == SCISSORS) strcpy(sComputerResult, "��");	// �������� ���� ���� 1(SCISSORS)�̸� ���ڿ��� "��"�� ����
	else if (nComputerResult == PAPER) strcpy(sComputerResult, "��");		// �������� ���� ���� 2(PAPER)�̸� ���ڿ��� "��"�� ����

	printf("\t  Computer >> %s, %s, %s!\n\n", str, str, sComputerResult);	// ��ǻ�Ͱ� �� ���� ����� �������� �����
	printf("\t------------------------------\n\n");
	if (nUserResult == nComputerResult)	// ���� �� ���� ������ 
	{
		printf("\t  ���������� ��ǻ���� �¸��Դϴ�!\n\n");	// ��ǻ���� �¸��� ����
		printf("\t  ������ �����մϴ�.\n\n");				// �Լ��� ������ �Լ��� ȣ���� �κ� �ڿ� �մ� break�� ���� ������ ������
		printf("\t==============================\n\n");
	}
	else if ((nUserResult == ROCK && nComputerResult == SCISSORS) || (nUserResult == SCISSORS && nComputerResult == PAPER) || (nUserResult == PAPER && nComputerResult == ROCK))
	{	// ����ڰ� �̹� �Ͽ� �̰��� ���
		printf("\t  User's turn!!\n\n");	// ������ ���̶�� �˷���
		printf("\t==============================\n\n");
		system("pause");		// �޼����� Ȯ���� �� �ְ� ����
		userWin(sUserResult);	// ������ ������ �Ѿ�� ���� ������ �̰��� �� �ҷ����� �Լ��� ȣ��
	}
	else if ((nComputerResult == ROCK && nUserResult == SCISSORS) || (nComputerResult == SCISSORS && nUserResult == PAPER) || (nComputerResult == PAPER && nUserResult == ROCK))
	{	// ��ǻ�Ͱ� �̹� �Ͽ� �̰��� ���
		printf("\t  Computer's turn!!\n\n");	// ��ǻ���� ���̶�� �˷���
		printf("\t==============================\n\n");
		system("pause");				// �޼����� Ȯ���� �� �ְ� ����
		computerWin(sComputerResult);	// ��ǻ���� ������ �Ѿ�� ���� ������ �̰��� �� �ҷ����� �Լ��� ȣ��
	} // if ~ else
} // computerWin()

////////////////////////////////////////////////////////////////////////////////////
// userWin �Լ��� computerWin �Լ��� ������ �����ϱ� ������ �ణ �ٸ� �κи� ���� //
////////////////////////////////////////////////////////////////////////////////////

void userWin(char str[]) // ����ڰ� �̰��� �� ���� �Լ���, str �迭�� ���� �´� ���� �ι� �������� ���ϴ� ���� �����ϱ� ���� �ҷ��´�.
{
	char sUserResult[10], sComputerResult[10];
	int nUserResult, nComputerResult;
	
	RSPDisplay();
	printf("\t  User >> %s, %s, \n\n\t  User >> ", str, str);	// �´� ���� �ι� ���ϰ�, (ex ��, ��, ...) 
	gets(sUserResult);			// �ٷ� ������ �� ���� �Է¹���
	printf("\n");
	if (!strcmp(sUserResult, "��")) nUserResult = ROCK;
	else if (!strcmp(sUserResult, "��")) nUserResult = SCISSORS;
	else if (!strcmp(sUserResult, "��")) nUserResult = PAPER;
	else if (strcmp(sUserResult, "��") || strcmp(sUserResult, "��") || strcmp(sUserResult, "��"))
	{
		printf("\t  �ٽ� �Է����ּ���!\n\n");
		printf("\t==============================\n\n");
		system("pause");
		userWin(str);
	} // if ~ else

	nComputerResult = rand() % 3;

	if (nComputerResult == ROCK) strcpy(sComputerResult, "��");
	else if (nComputerResult == SCISSORS) strcpy(sComputerResult, "��");
	else if (nComputerResult == PAPER) strcpy(sComputerResult, "��");

	printf("\t  Computer >> %s\n\n", sComputerResult);
	printf("\t------------------------------\n\n");
	if (nUserResult == nComputerResult)
	{
		printf("\t  ���������� ������ �¸��Դϴ�!!\n\n");	// ������� �¸��� ����
		printf("\t  ������ �����մϴ�.\n\n");
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

void about() // �������� �Ұ��� �� ���� �Լ�
{
	printf("\n\n");	// ���α׷� ������ ������ش�.
	printf("\t==============================\n");
	printf("\t   Console Menu Program v1.0\n");	// ���� ���� ���α׷��� �����Ƿ� ���� 1.0���� ���׷��̵�
	printf("\t------------------------------\n\n");
	printf("\t   Programmed by Kim Dongho\n\n");	
	printf("\t==============================\n\n");
} // about()