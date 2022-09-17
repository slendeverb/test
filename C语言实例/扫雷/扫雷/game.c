//#include"game.h"
//
//void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
//{
//	int i = 0;
//	for (i = 0; i < rows; i++)
//	{
//		int j = 0;
//		for (j = 0; j < cols; j++)
//		{
//			board[i][j] = set;
//		}
//	}
//}
//
//void DisplayBoard(char board[ROWS][COLS], int row, int col)
//{
//	printf("----------ɨ����Ϸ----------\n");
//	int i = 0;
//	for (i = 0; i <= col; i++)
//	{
//		printf("%d ", i);
//	}
//	printf("\n");
//	for (i = 1; i <= row; i++)
//	{
//		printf("%d ", i);
//		int j = 0;
//		for (j = 1; j <= col; j++)
//		{
//			printf("%c ", board[i][j]);
//		}
//		printf("\n");
//	}
//	printf("----------ɨ����Ϸ----------\n");
//
//}
//
//void SetMine(char board[ROWS][COLS], int row, int col)
//{
//	//����10����
//	int count = EASY_COUNT;
//	while (count)
//	{
//		//����������±�
//		int x = rand() % row + 1;
//		int y = rand() % col + 1;
//		if (board[x][y] == '0')
//		{
//			board[x][y] = '1';
//			count--;
//		}
//		
//	}
//}
//
//static int get_mine_count(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y)
//{	
//	if (mine[x - 1][y - 1] +
//		mine[x - 1][y] +
//		mine[x - 1][y + 1] +
//		mine[x][y - 1] +
//		mine[x][y + 1] +
//		mine[x + 1][y - 1] +
//		mine[x + 1][y] +
//		mine[x + 1][y + 1] - 8 * '0' == 0)
//	{
//		if (show[x][y] != '0')
//		{
//			get_mine_count(mine, show, x - 1, y);
//			get_mine_count(mine, show, x, y - 1);
//			get_mine_count(mine, show, x - 1, y - 1);
//			get_mine_count(mine, show, x + 1, y);
//			get_mine_count(mine, show, x, y + 1);
//			get_mine_count(mine, show, x + 1, y + 1);
//
//		}
//		return mine[x - 1][y - 1] +
//			mine[x - 1][y] +
//			mine[x - 1][y + 1] +
//			mine[x][y - 1] +
//			mine[x][y + 1] +
//			mine[x + 1][y - 1] +
//			mine[x + 1][y] +
//			mine[x + 1][y + 1] - 8 * '0';
//		
//	}
//	else
//	{
//		return mine[x - 1][y - 1] +
//			mine[x - 1][y] +
//			mine[x - 1][y + 1] +
//			mine[x][y - 1] +
//			mine[x][y + 1] +
//			mine[x + 1][y - 1] +
//			mine[x + 1][y] +
//			mine[x + 1][y + 1] - 8 * '0';
//	}
//	//����
//	/*int i = 0;
//	int j = 0;
//	int count = 0;
//	for (i = -1; i <= 1; i++)
//	{
//		for (j = -1; j <= 1; j++)
//		{
//			if (mine[x + i][y + j] == 1)
//			{
//				count++;
//			}
//		}
//	}*/
//}
//
//
////ը��ʽչ������
//void explode_spread(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
//{
//	//���ƷǷ������չ��
//	if (x >= 1 && x <= row && y >= 1 && y <= col)
//	{
//		//�����λ�ø������ܵ��׵ĸ���
//		int count = get_mine_count(mine, x, y);
//		//������û��һ�����ף�����Ҫ���λ�õ�����չ����ֱ��չ����ĳ��λ�ø������ڵ���Ϊֹ
//		if (count == 0)
//		{
//			//�Ѹ���û�е��׵�λ�ñ���ַ� ���ո�
//			show[x][y] = ' ';
//			int i = 0;
//			//�����ܹ�8��λ�õݹ����
//			for (i = x - 1; i <= x + 1; i++)
//			{
//				int j = 0;
//				for (j = y - 1; j <= y + 1; j++)
//				{
//					//���ƶԵ�λ�õ��ظ�չ�����ã�ʹ��ÿһ��λ��ֻ��������չ��һ��
//					if (show[i][j] == '*')
//					{
//						explode_spread(mine, show, row, col, i, j);
//					}
//				}
//			}
//		}
//		//�����ܴ��ڵ�����Ӧ�������λ���ϱ�ע�ϵ��׵ĸ���
//		else
//		{
//			show[x][y] = count + '0';
//		}
//	}
//}
//
//
//void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	int input = 0;
//	int win = 0;
//	while (win<row*col-EASY_COUNT)
//	{
//		/*printf("�Ų�����1���������2��ȡ���������3��");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:*/
//			printf("���������꣬ʾ����1 1��");
//			scanf("%d %d", &x, &y);
//			if (x >= 1 && x <= row && y >= 1 && y <= col)
//			{
//				if (mine[x][y] == '1')
//				{
//					printf("��Ϸ����!\n");
//					DisplayBoard(mine, row, col);
//					break;
//				}
//				else
//				{
//					int count = get_mine_count(mine,show, x, y);
//					show[x][y] = count + '0';
//					DisplayBoard(show, row, col);
//					win++;
//				}
//			}
//			else
//			{
//				printf("������Ч������������\n");
//			}
//		/*	break;
//		case 2:
//			printf("���������꣬ʾ����1 1��");
//			scanf("%d %d", &x, &y);
//			if (x < 1 || x > row || y < 1 && y > col)
//			{
//				printf("������Ч������������\n");
//
//			}
//			else
//			{
//				if (show[x][y] == '*')
//				{
//					show[x][y] = '#';
//				}
//				else if(show[x][y]=='0')
//				{
//					printf("�������ѱ��Ų飬�޷����\n");
//				}
//				else
//				{
//					printf("�������ѱ����\n");
//				}
//			}
//			break;
//		case 3:
//			printf("���������꣬ʾ����1 1��");
//			scanf("%d %d", &x, &y);
//			if (x < 1 || x > row || y < 1 && y > col)
//			{
//				printf("������Ч������������\n");
//
//			}
//			else
//			{
//				if (show[x][y] == '#')
//				{
//					show[x][y] = '*';
//				}
//				else if (show[x][y] == '0')
//				{
//					printf("�������ѱ��Ų飬�޷�ȡ�����\n");
//				}
//				else
//				{
//					printf("������δ����ǣ��޷�ȡ�����\n");
//				}
//			}
//			break;*/
//		}
//	}
//	if (win == row * col - EASY_COUNT)
//	{
//		printf("��ϲ�㣬�ɹ��Ų���������ף�\n");
//		DisplayBoard(mine, row, col);
//	}
//}

#include"game.h"

//��ʼ������
void init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//���õ���
void set_mine(char mine[ROWS][COLS], int row, int col)
{
	int count = COUNT;
	while (count)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//��ӡ����
void display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	printf("---------------ɨ����Ϸ----------------\n");
	//��ӡ�к�
	for (i = 0; i <= row; i++)
	{
		printf(" %d  ", i);
	}
	printf("\n");
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		//��ӡ�к�
		printf(" %d  ", i);
		//��ӡ������
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j <= col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//��ӡ�ָ���
		if (i <= row - 1)
		{
			printf("    ");
			for (j = 1; j <= col; j++)
			{
				printf("---");
				if (j <= col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
	printf("---------------ɨ����Ϸ----------------\n");
}

//������ΧһȦ��Χ�ڴ��ڵ��׵ĸ���
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//��3��3���������е��ַ�����1����0������������Ȼ����ͳһ��ȥ9���ַ���0�����õ��Ľ�����ǵ��׵ĸ���
	int i = 0;
	int sum = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		int j = 0;
		for (j = y - 1; j <= y + 1; j++)
		{
			sum += mine[i][j];
		}
	}
	return (sum - 9 * '0');
}

//������mine�е���ȫ����ʾ��show��
void show_all_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			if (mine[i][j] == '1')
			{
				show[i][j] = '@';//�������ַ���@�����û������ʾ
			}
		}
	}
}

//ը��ʽչ������
void explode_spread(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	//���ƷǷ������չ��
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		//�����λ�ø������ܵ��׵ĸ���
		int count = get_mine_count(mine, x, y);
		//������û��һ�����ף�����Ҫ���λ�õ�����չ����ֱ��չ����ĳ��λ�ø������ڵ���Ϊֹ
		if (count == 0)
		{
			//�Ѹ���û�е��׵�λ�ñ���ַ� ���ո�
			show[x][y] = ' ';
			int i = 0;
			//�����ܹ�8��λ�õݹ����
			for (i = x - 1; i <= x + 1; i++)
			{
				int j = 0;
				for (j = y - 1; j <= y + 1; j++)
				{
					//���ƶԵ�λ�õ��ظ�չ�����ã�ʹ��ÿһ��λ��ֻ��������չ��һ��
					if (show[i][j] == '*')
					{
						explode_spread(mine, show, row, col, i, j);
					}
				}
			}
		}
		//�����ܴ��ڵ�����Ӧ�������λ���ϱ�ע�ϵ��׵ĸ���
		else
		{
			show[x][y] = count + '0';
		}
	}
}

//��ǵ���λ�ã������Ų���Ϸ�еĵ��ף�
void sign_mine(char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("������Ҫ��ǵ����꣺");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				show[x][y] = '!';
				break;
			}
			else
			{
				printf("��λ�ò��ܱ���ǣ����������룺\n");
			}
		}
		else
		{
			printf("��������Ƿ�������������:\n");
		}
	}
	system("cls");
	display_board(show, row, col);
}

//��ʼɨ��
void find_mind(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//��¼�Ų�����ǵ���λ�õĸ���
	char ch = 0;
	while (win < row * col - COUNT)
	{
		printf("������Ҫ�Ų��λ���±꣺");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж������±��Ƿ���Ч
		{
			if (mine[x][y] == '1')//�Ų鵽�˵���
			{
				break;
			}
			//��ʱû���Ų鵽����
			else
			{
				//ը��ʽչ��
				explode_spread(mine, show, row, col, x, y);
				system("cls");
				//��ӡ����
				display_board(show, row, col);
				printf("��Ҫ��ע���׾����룺Y������Ҫ��ע���������룺N\n");
				//���һ�»�����
				while ((ch = getchar()) != '\n');
				scanf("%c", &ch);
				switch (ch)
				{
				case 'Y':
					//����׵�λ��
					sign_mine(show, row, col);
					break;
				default:
					break;
				}
			}
		}
		else
		{
			printf("�����±�Ƿ������������룺\n");
		}
	}
	//������mine�е���ȫ����ʾ��show��
	show_all_mine(mine, show, row, col);
	system("cls");
	//��ӡ����
	display_board(show, row, col);
	//�ж��Ƿ��Ų�ɹ�
	if (win >= row * col - COUNT)
	{
		printf("��ϲ���Ų�����еĵ��ף�����\n");
	}
	else
	{
		printf("ɨ��ʧ�ܣ��㱻ը���ˣ�����\n");
	}
}
