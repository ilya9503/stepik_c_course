#include <iostream>

using std::cout;
using std::endl;

int perimetr(unsigned a, unsigned b)
{
    return 2 * (a + b);
}

float perimetr(float a, float b)
{
    return 2.0f * (a + b);
}

int main()
{
    int res_1 = perimetr(10, 20);	


    float res_2 = perimetr(10, 20);	
    
    
    float res_3 = perimetr(10.0f, 20.0f);	
    
    
    int res_4 = perimetr(10u, 20u);	
    
    
    float res_5 = perimetr(10u, 20u);	
    
    
    float res_6 = perimetr(10.0, 20.0);	
    
    
    double res_7 = perimetr(10.0f, 20.0f);

    return 0;
}
