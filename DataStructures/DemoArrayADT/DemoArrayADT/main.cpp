#include "Array20.h"
#include "Array10.h"

int main()
{
	int tmp[]{ 1,2,3,4,5 };
	Array10 arr( tmp, 5 );
	arr.display();
	arr.append(10);
	arr.insert(0, 90);
	arr.display();

	return 0;
}