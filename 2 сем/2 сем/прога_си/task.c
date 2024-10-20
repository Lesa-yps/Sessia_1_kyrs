#include <stdio.h>
#include <math.h>
#define N 16
struct point
{
    char name;
    int x;
    int y;
};
double distance(struct point a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}
void delete(struct point points[], int *n, int k)
{
    for (int i = k; i < (*n) - 1; i++)
    {
        points[i] = points[i + 1];
    }
    (*n)--;
}
void clear_buffer()
{
    char c;
    do
    {
        scanf("%c", &c);
    } while(c == EOF);
}
int main(void)
{
    int n;
    scanf("%d", &n);
    struct point points[10];
    for (int i = 0; i < n; i++)
    {
        clear_buffer();
        points[i].name = getchar();
        scanf("%d%d", &points[i].x, &points[i].y);
    }
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += distance(points[i]);
    }
    double average = sum / n;
    printf("average = %lf\n", average);
    for (int i = 0; i < n; i++)
    {
        if (distance(points[i]) < average)
        {
            delete(points, &n, i);
            i--;
        }
    }
    printf("-------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%c %d %d\n", points[i].name, points[i].x, points[i].y);

}
