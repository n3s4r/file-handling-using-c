#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculateArea(int r);
float calculatePerimeter(int r);

int main()
{
    int rows = 5;
    int cols = 5;

    int radius[5][5];
    float area[5][5];

    int i,j;
    int serial = 1;

    FILE *file;

    file = fopen("circle.txt", "w");
    if(file == NULL)
    {
        printf("Error\n");
        return 1;
    }

    fprintf(file, "Serial No.\tRadius\t\tArea\t\tPerimeter\n");
    fprintf(file, "..........................................................\n");



    printf("Enter the radius values for a 5X5 matrix: \n");

    for(int i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            printf("Enter radius[%d][%d]: ", i, j);
            scanf("%d", &radius[i][j]);
        }
    }

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j< cols; j++)
        {
            area[i][j] = calculateArea(radius[i][j]);
            float perimeter = calculatePerimeter(radius[i][j]);

            fprintf(file, "%d\t\t%d\t\t%.2f\t\t%.2f\n", serial++, radius[i][j], area[i][j], perimeter);
        }
    }

    fclose(file);


    printf("\n2D Array of Radius and Corresponding Areas:\n");

    for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++) {
            printf("(%d, %.2f)\t", radius[i][j], area[i][j]);
        }
            printf("\n");
    }

    printf("\nResults successfully written to 'circle.txt'\n");

    return 0;
}


    float calculateArea(int r)
    {
        return M_PI * r * r;
    }


    float calculatePerimeter(int r)
    {
        return 2 * M_PI * r;
    }

