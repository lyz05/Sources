program p2;
const	maxn=1000;
var	n,m,i,j:longint;
begin
	randomize;
	n:=random(maxn)+3;
	n:=maxn;
	writeln(n);
	for i:=1 to n do writeln(random(100){+10000});
end.
