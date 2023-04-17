default:
	g++ -Wzero-as-null-pointer-constant *.cpp -g -o test -lgmp -lgmpxx
