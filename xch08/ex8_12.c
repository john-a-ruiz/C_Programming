/*
 *  ex8_12.c
 *  xch08
 *
 *	get 5 quiz grades for each of 5 students 
 *	compute total & average score for each student
 *	compute average, high, low score for each quiz
 */

#include <stdio.h>

int main()
{
	float matrix[5][5] = {0.0};
	int stud, quiz;
	float total, ave, high, low;
	stud = quiz = 0;
	total = ave = high = low = 0.0;
	
	printf("\n\n");
	for (stud = 0; stud < 5; stud++)
	{
		printf("Enter student %d quiz grades: ", stud + 1);
		for (quiz = 0; quiz < 5; quiz++)
			scanf("%f", &matrix[stud][quiz]);
	}
	
	//computing total, average for each student
	for (stud = 0; stud < 5; stud++)
	{
		for (quiz = total = 0; quiz < 5; quiz++)
			total += matrix[stud][quiz];
		
		printf("\nStudent %d's quiz total: %5.2f, quiz average: %3.2f", 
			   stud + 1, total, total / 5);
	}
	
	//computing average, high, low for each quiz
	printf("\n");
	for (quiz = 0; quiz < 5; quiz++)
	{
		for (stud = total = high = 0, low = 100; stud < 5; stud++)
		{
			total += matrix[stud][quiz];
			
			if (matrix[stud][quiz] > high)
				high = matrix[stud][quiz];
			if (matrix[stud][quiz] < low)
				low = matrix[stud][quiz];
		}
		printf("\nQuiz %d average: %3.2f, high score: %3.2f, low score: %3.2f",
			   quiz + 1, total / 5.0, high, low);
	}
	
	printf("\n\n");
	return 0;
}


