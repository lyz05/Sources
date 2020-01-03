var a,b:longint;
procedure swap(var a,b:longint);
begin
	a:=a xor b;
	b:=a xor b;
	a:=a xor b;
end;	
begin
	readln(a,b);
	swap(a,b);
	writeln(a,' ',b);
end.
	
