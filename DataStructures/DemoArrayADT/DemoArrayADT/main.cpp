#include "Array20.h"
#include "Array10.h"
#include "Array.h"

int main()
{
	int tmp[]{ 1,2,3,4,5 };
	Array arr( tmp, 10, 5 );
	arr.display();
	arr.append(10);
	arr.insert(0, 90);
	arr.set(1, 2);
	arr.display();

	return 0;
}