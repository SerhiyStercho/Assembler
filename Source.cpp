#include <iostream>
using namespace std;
void main()
{
	float a;
	float b;
	float c=-1;
	float g = 5;
	float g1 = 255;
	float rezult;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;

	__asm
	{
		fld a
		fld b
		fxch st(1)
		fcom st(1)
		fstsw ax
		sahf
		ja r1
		jb r2
		je r3
		jmp exit1
		r1 :
		fmul st(0), st(1)
			fld1
			fsub st(0),st(1)
			fld a
			fxch st(1)
			fdiv st(0), st(1)
			fld c
			fxch st(1)
			fmul st(0),st(1)
			fst rezult

			jmp exit1
			r2 :
		    fld g
			fxch st(1)
			fsub st(0), st(1)
			fdiv st(0), st(2)
			fst rezult
			jmp exit1
			r3 :
		fld g1
			fstp rezult
			exit1 :


	}
	cout << rezult << endl;
	system("pause");

}