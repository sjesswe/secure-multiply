#include<stdio.h>
#include<limits.h>
_Bool checkVal(const int numa, const int numb)
{
	if((numa != 0)&&(numb != 0)&&(numa * numb==0)){
		return 0; //Checks for x * y = 2^32
	}
	else if((numa==-2147483648)||(numb==-2147483648)){
		return 0; //Checks for neg # with no corresponding pos #
	}
	else if((numa > 2147483647) || (numb > 2147483947)){
		return 0; //Checks for out of bounds positive numbers
	}
	else if((numa < -2147483647) || (numb < -2147483947)){
		return 0; //Checks for out of bounds negative numbers
	}
	else 
		return 1;
}
int safe_multiply(const int num1, const int num2)
{	
	if(checkVal(num1, num2))//checks both inputs
	{	
		int value = 0;
	
		value = num1 * num2;
		return value;
	}
	else printf("Error.  Returning 0.\n");
	return 0; //value returned for errors
}

int main()
{

	int test = 0;//value decleration to clear out garbage value
	test = safe_multiply(20, 30);// passes 20 and 30 to safe_multiply to be operated on. Should return 600.
	printf("Multiplication value = %d\n", test);//outputs the returned value
	test = safe_multiply(2147483648, 40);
	printf("Multiplication value = %d\n", test);//outputs the returned value
	test = safe_multiply(-2147483648, 40);//Tests neg # with no positive complement
	printf("Multiplication value = %d\n", test);//outputs the returned value
	test = safe_multiply(65536, 65536);//Sends different value that equals 2^32
	printf("Multiplication value = %d\n", test);//outputs the returned value
	test = safe_multiply(256, 16777216);//Sends value that equals 2^32
	printf("Multiplication value = %d\n", test);//outputs the returned value
	test = safe_multiply(200, 2999999999);//Sends out of bounds value
	printf("Multiplication value = %d\n", test);//outputs the returned value
	return 0;
}
