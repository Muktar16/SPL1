#include<math.h>

float calculate_geometric_probability(int x,float p)
{
    return p*pow(1-p,x-1);
}
