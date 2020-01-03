const	mo=1000000007;
var	f:array[-10..500000] of int64;
	n,i:longint;
begin
	f[1]:=1;f[2]:=2;f[3]:=6;f[4]:=14;f[5]:=31;
	readln(n);
	for i:=6 to n do f[i]:=(2*f[i-1]+2*f[i-3]-f[i-5]) mod mo;
	//for i:=1 to n do writeln(f[i]);
	writeln(f[i]);
end.
