#include "rule.h"
#include <stdio.h>
extern int chessData[10][9];
int CanDownPos[10][9];
int state = 0;
int turn = -1;
int GetRowChess(int start_row, int start_column, bool direct)
{


	if (!direct)
	{
		for (int i = start_column; i > 0; i--)
		{
			if (chessData[start_row][i] != 0)	return i;
		}
	}
	else
	{
		for (int i = start_column; i < 9 - start_row; i++)
		{
			if (chessData[start_row][i] != 0)	return i;
		}
	}
	return -1;
}

int GetColumnChess(int start_row, int start_column, bool direct)
{



	if (!direct)
	{
		for (int i = start_row; i > 0; i--)
		{
			if (chessData[i][start_column] != 0)	return i;
		}
	}
	else
	{
		for (int i = start_column; i < 10 - start_row; i++)
		{
			if (chessData[i][start_column] != 0)	return i;
		}
	}
	return -1;
}

int GetFlag(int row, int column)
{
	//ͨ���ϰ�������˧��λ�����ж���ѡ���ӵĹ�����Χ �ϰ����� �°�����
	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (abs(chessData[j][i]) == 5)
			{
				if (chessData[j][i] * chessData[row][column] > 0)
				{
					return 1;
				}
				else
				{
					return -1;
				}
				
				break;
			}
		}
	}

	return 0;
}

void RuleChoose(int row, int column)
{
	int data = chessData[row][column];

	
	switch (data)
	{
	case -10:
	case 10:
		//�ڵĹ���
		RulePao(row, column);
		break;
	case 9:
	case -9:
		//���Ĺ���
		RuleChe(row, column);
		break;
	case 8:
	case -8:
		//��Ĺ���
		RuleMa(row, column);
		break;
	case 7:
	case -7:
		//��Ĺ���
		RuleXiang(row, column);
		break;
	case 6:
	case -6:
		//ʿ�Ĺ���
		RuleShi(row, column);
		break;
	case 5:
	case -5:
		//����˧�Ĺ���
		RuleCommander(row, column);
		break;
	case 1:
	case -1:
		//������Ĺ���
		RuleBin(row, column);
		break;
	}

	RenderCanDownPos();

}

void InitDownPos()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			CanDownPos[i][j] = 0;
		}
	}
}

void RulePao(int row, int column)
{
	//�еĴ���
		//�����ж�
	for (int i = row-1; i >= 0; i--)
	{
		if (chessData[i][column] == 0)
		{
			CanDownPos[i][column] = 1;
		}
		else 
		{
			//�����赲����
			for (int j = i-1; j >= 0; j--)
			{
				
				if (chessData[j][column] * chessData[row][column] < 0)
				{

					//���ϱ������ĵ�һ����ɫ�壬��ǿɳԣ����ҽ���λ�ø�Ϊ������
					CanDownPos[j][column] = 1;
					break;
				}
			}
			//����,��Ϊ�����Ѿ����˱�������
			break;
		}
	}
		
		//�����ж�
	for (int i = row + 1; i < 10; i++)
	{
		if (chessData[i][column] == 0)
		{
			CanDownPos[i][column] = 1;
		}
		else
		{
			//�����赲����
			for (int j = i + 1; j < 10; j++)
			{
				if (chessData[j][column] * chessData[row][column] < 0)
				{
					//���ϱ������ĵ�һ����ɫ�壬��ǿɳԣ����ҽ���λ�ø�Ϊ������
					CanDownPos[j][column] = 1;
					break;
				}
			}
			//����,��Ϊ�����Ѿ����˱�������
			break;
		}
	}

	//�еĴ���
		//�����ж�
	for (int i = column - 1; i >= 0; i--)
	{
		if (chessData[row][i] == 0)
		{
			CanDownPos[row][i] = 1;
		}
		else
		{
			//�����赲����
			for (int j = i - 1; j >= 0; j--)
			{
				if (chessData[row][j] * chessData[row][column] < 0)
				{
					//���ϱ������ĵ�һ����ɫ�壬��ǿɳԣ����ҽ���λ�ø�Ϊ������
					CanDownPos[row][j] = 1;
					break;
				}
			}
			//����,��Ϊ�����Ѿ����˱�������
			break;
		}
	}
		//�����ж�
	for (int i = column + 1; i < 9 ; i++)
	{
		if (chessData[row][i] == 0)
		{
			CanDownPos[row][i] = 1;
		}
		else
		{
			//�����赲����
			for (int j = i + 1; j < 9; j++)
			{
				if (chessData[row][j] * chessData[row][column] < 0)
				{
					//���ϱ������ĵ�һ����ɫ�壬��ǿɳԣ����ҽ���λ�ø�Ϊ������
					CanDownPos[row][j] = 1;
					break;
				}
			}
			//����,��Ϊ�����Ѿ����˱�������
			break;
		}
	}
}

void RuleChe(int row, int column)
{
	//�еĴ���
		//�����ж�
	for (int i = column - 1; i >= 0; i--)
	{
		if (chessData[row][i] * chessData[row][column] <= 0)
		{
			CanDownPos[row][i] = 1;
			if (chessData[row][i] != 0) break;

		}
		else
		{
			break;
		}

	}


	//�����ж�
	for (int i = column + 1; i < 9; i++)
	{
		if (chessData[row][i] * chessData[row][column] <= 0)
		{
			CanDownPos[row][i] = 1;
			if (chessData[row][i] != 0) break;
		}
		else
		{
			break;
		}
	}


	//�еĴ��� 
	//�����ж�
	for (int i = row - 1; i >= 0; i--)
	{
		if (chessData[i][column] * chessData[row][column] <= 0)
		{
			CanDownPos[i][column] = 1;
			if (chessData[i][column] != 0) break;
		}
		else
		{
			break;
		}
	}

	//�����ж�
	for (int i = row + 1; i < 10; i++)
	{
		if (chessData[i][column] * chessData[row][column] <= 0)
		{
			CanDownPos[i][column] = 1;
			if (chessData[i][column] != 0) break;
		}
		else
		{
			break;
		}
	}
}

void RuleBin(int row, int column)
{
	int flag = GetFlag(row, column);
	
	
	if (flag == -1) 
	{
		//�Ƿ���ӵ��ж�
		if (row < 5) 
		{
			//ǰ
			if ((row - 1) >= 0)
			{
				if (chessData[row - 1][column] * chessData[row][column] <= 0)	CanDownPos[row - 1][column] = 1;
			}
			//��
			if ((column - 1) >= 0)
			{
				if (chessData[row][column - 1] * chessData[row][column] <= 0)	CanDownPos[row][column - 1] = 1;
			}
			//��
			if ((column + 1) < 9)
			{
				if (chessData[row][column + 1] * chessData[row][column] <= 0)	CanDownPos[row][column + 1] = 1;
			}
		}
		else 
		{
			//ǰ
			if (chessData[row - 1][column] * chessData[row][column] <= 0)	CanDownPos[row - 1][column] = 1;
		}
	}
	else
	{
		//�Ƿ���ӵ��ж�
		if (row > 4)
		{
			//ǰ
			if ((row + 1) < 10)
			{
				if (chessData[row + 1][column] * chessData[row][column] <= 0)	CanDownPos[row + 1][column] = 1;
			}
			//��
			if ((column - 1) >= 0)
			{
				if (chessData[row][column - 1] * chessData[row][column] <= 0)	CanDownPos[row][column - 1] = 1;
			}
			//��
			if ((column + 1) < 9)
			{
				if (chessData[row][column + 1] * chessData[row][column] <= 0)	CanDownPos[row][column + 1] = 1;
			}
		}
		else
		{
			//ǰ
			if (chessData[row + 1][column] * chessData[row][column] <= 0)	CanDownPos[row + 1][column] = 1;
		}
	}

}

void RuleMa(int row, int column)
{
	//����
	if ((row - 2) >= 0)
	{
		//�ж��Ƿ�Ʋ���
		if (chessData[row - 1][column] == 0)
		{
			//��
			if ((column - 1) >= 0)
			{
				if (chessData[row - 2][column - 1] * chessData[row][column] <= 0)		CanDownPos[row - 2][column - 1] = 1;
			}
			//��
			if ((column + 1) < 9)
			{
				if (chessData[row - 2][column + 1] * chessData[row][column] <= 0)		CanDownPos[row - 2][column + 1] = 1;
			}
		}
	}
	//����
	if ((row + 2) < 10)
	{
		//�ж��Ƿ�Ʋ���
		if (chessData[row + 1][column] == 0)
		{
			//��
			if ((column - 1) >= 0)
			{
				if (chessData[row + 2][column - 1] * chessData[row][column] <= 0)		CanDownPos[row + 2][column - 1] = 1;
			}
			//��
			if ((column + 1) < 9)
			{
				if (chessData[row + 2][column + 1] * chessData[row][column] <= 0)		CanDownPos[row + 2][column + 1] = 1;
			}
		}
	}

	//����
	if ((column - 2) >= 0)
	{
		//�ж��Ƿ�Ʋ���
		if (chessData[row][column - 1] == 0)
		{
			//��
			if ((row - 1) >= 0)
			{
				if (chessData[row - 1][column - 2] * chessData[row][column] <= 0)		CanDownPos[row - 1][column - 2] = 1;
			}
			//��
			if ((row + 1) < 10)
			{
				if (chessData[row + 1][column - 2] * chessData[row][column] <= 0)		CanDownPos[row + 1][column - 2] = 1;
			}
		}
	}

	//����
	if ((column + 2) < 9)
	{
		//�ж��Ƿ�Ʋ���
		if (chessData[row][column + 1] == 0)
		{
			//��
			if ((row - 1) >= 0)
			{
				if (chessData[row - 1][column + 2] * chessData[row][column] <= 0)		CanDownPos[row - 1][column + 2] = 1;
			}
			//��
			if ((row + 1) < 10)
			{
				if (chessData[row + 1][column + 2] * chessData[row][column] <= 0)		CanDownPos[row + 1][column + 2] = 1;
			}
		}
	}

}

void RuleShi(int row, int column)
{
	int flag = GetFlag(row, column);

	if (flag == -1) 
	{
	//�°�����
		//��
		if ((row - 1) >= 7)
		{
			//��
			if ((column - 1) >= 3)
			{
				if (chessData[row - 1][column - 1] * chessData[row][column] <= 0)	CanDownPos[row - 1][column - 1] = 1;
			}
			//��
			if ((column + 1) <= 5)
			{
				if (chessData[row - 1][column + 1] * chessData[row][column] <= 0)	CanDownPos[row - 1][column + 1] = 1;

			}
		}
		//��
		if ((row + 1) < 9)
		{
			//��
			if ((column - 1) >= 3)
			{
				if (chessData[row + 1][column - 1] * chessData[row][column] <= 0)	CanDownPos[row + 1][column - 1] = 1;
			}
			//��
			if ((column + 1) <= 5)
			{
				if (chessData[row + 1][column + 1] * chessData[row][column] <= 0)	CanDownPos[row + 1][column + 1] = 1;
			}
		}
	}
	if (flag == 1)
	{
	//�ϰ�����
		//��
		if ((row - 1) >= 0)
		{
			//��
			if ((column - 1) >= 3)
			{
				if (chessData[row - 1][column - 1] * chessData[row][column] <= 0)	CanDownPos[row - 1][column - 1] = 1;
			}
			//��
			if ((column + 1) <= 5)
			{
				if (chessData[row - 1][column + 1] * chessData[row][column] <= 0)	CanDownPos[row - 1][column + 1] = 1;
			}
		}
		//��
		if ((row + 1) < 3)
		{
			//��
			if ((column - 1) >= 3)
			{
				if (chessData[row + 1][column - 1] * chessData[row][column] <= 0)	CanDownPos[row + 1][column - 1] = 1;
			}
			//��
			if ((column + 1) <= 5)
			{
				if (chessData[row + 1][column + 1] * chessData[row][column] <= 0)	CanDownPos[row + 1][column + 1] = 1;
			}
		}
	}
	

}

void RuleCommander(int row, int column)
{
	int flag = GetFlag(row, column);
	if (flag == -1)	//�ϰ���
	{
		//��
		if ((row - 1) >= 7)
		{
			if (chessData[row - 1][column] * chessData[row][column] <= 0)	CanDownPos[row - 1][column] = 1;
		}
		//��
		if ((row + 1) < 10)
		{
			if (chessData[row + 1][column] * chessData[row][column] <= 0)	CanDownPos[row + 1][column] = 1;
		}
	}
	if (flag == 1)	//�°���
	{
		//��
		if ((row - 1) >= 0)
		{
			if (chessData[row - 1][column] * chessData[row][column] <= 0)	CanDownPos[row - 1][column] = 1;
		}
		//��
		if ((row + 1) < 3)
		{
			if (chessData[row + 1][column] * chessData[row][column] <= 0)	CanDownPos[row + 1][column] = 1;
		}
	}
	//��
	if ((column - 1) >= 3)
	{
		if (chessData[row][column - 1] * chessData[row][column] <= 0)	CanDownPos[row][column - 1] = 1;
	}
	//��
	if ((column + 1) < 6)
	{
		if (chessData[row][column + 1] * chessData[row][column] <= 0)	CanDownPos[row][column + 1] = 1;
	}
	
	
}

void RuleXiang(int row, int column)
{
	int flag = GetFlag(row, column);
	
	if (flag == -1)
	{
		//����
		if ((row - 2) >= 5)
		{

			//��
			if ((column - 2) >= 0)
			{
				if (chessData[row - 1][column - 1] == 0 && chessData[row - 2][column - 2] * chessData[row][column] <= 0) CanDownPos[row - 2][column - 2] = 1;
			}
			//��
			if ((column + 2) < 9)
			{
				if (chessData[row - 1][column + 1] == 0 && chessData[row - 2][column + 2] * chessData[row][column] <= 0) CanDownPos[row - 2][column + 2] = 1;
			}
		}

		//����
		if ((row + 2) < 10)
		{

			//��
			if ((column - 2) >= 0)
			{
				if (chessData[row + 1][column - 1] == 0 && chessData[row + 2][column - 2] * chessData[row][column] <= 0) CanDownPos[row + 2][column - 2] = 1;
			}
			//��
			if ((column + 2) < 9)
			{
				if (chessData[row + 1][column + 1] == 0 && chessData[row + 2][column + 2] * chessData[row][column] <= 0) CanDownPos[row + 2][column + 2] = 1;
			}
		}
	}
	if (flag == 1)
	{
		//����
		if ((row - 2) >= 0)
		{

			//��
			if ((column - 2) >= 0)
			{
				if (chessData[row - 1][column - 1] == 0 && chessData[row - 2][column - 2] * chessData[row][column] <= 0) CanDownPos[row - 2][column - 2] = 1;
			}
			//��
			if ((column + 2) < 9)
			{
				if (chessData[row - 1][column + 1] == 0 && chessData[row - 2][column + 2] * chessData[row][column] <= 0) CanDownPos[row - 2][column + 2] = 1;
			}
		}

		//����
		if ((row + 2) < 5)
		{

			//��
			if ((column - 2) >= 0)
			{
				if (chessData[row + 1][column - 1] == 0 && chessData[row + 2][column - 2] * chessData[row][column] <= 0) CanDownPos[row + 2][column - 2] = 1;
			}
			//��
			if ((column + 2) < 9)
			{
				if (chessData[row + 1][column + 1] == 0 && chessData[row + 2][column + 2] * chessData[row][column] <= 0) CanDownPos[row + 2][column + 2] = 1;
			}
		}
	}


}


