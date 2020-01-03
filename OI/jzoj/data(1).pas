program d297;
uses	math;
var	i,j,k,m,n,t,t1,t2:longint;
begin
	randomize;
	n:=100000;m:=100000;
	writeln(n,' ',m);
	k:=min(n,m);
	for i:=1 to k do write(random(500000000),' ');
	writeln;
	T:=100000;
	writeln(T);
	for i:=1 to T do 
	begin
		t1:=random(k-1)+1;t2:=t1+random(k-t1-1)+1;
		writeln(t1,' ',t2,' ',random(500000000));
	end;
end.
program oj42220;
var	i,j,k,m,n,t:longint;
begin
	randomize;
	m:=1;k:=10000000;
	writeln(i,' ',m,' ',k);
end.
program oj3493;
var	i,j,k,m,n,c:longint;
begin
	randomize;
	n:=random(100);
	writeln(n);
	for i:=1 to n do writeln(random(2*10000)-10000,' ',random(2*10000)-10000);
end.
program oj3484;
var	i,j,k,m,n,c:longint;
begin
	randomize;
	n:=random(100);
	for i:=1 to n do write(chr(random(26)+1+ord('a')-1));
	writeln;
	n:=random(5);
	for i:=1 to n do write(chr(random(26)+1+ord('a')-1));
	writeln;
end.
program oj3478;
var	i,j,k,m,n,c:longint;
begin
	randomize;
	n:=100000;
	writeln(n);
	for i:=1 to n do write(random(10000000),' ');
	writeln;
end.
program oj3479;
var	i,j,k,m,n,c:longint;
begin
	randomize;
	n:=random(1000)+1;k:=random(n)+1;c:=random(1000000000)+1;
	writeln(n,' ',k,' ',c);
	for i:=1 to n do write(random(1000000000),' ');
	writeln;
end.

program oj3958;
var	i,n,m:longint;
begin
	randomize;
	n:=random(5000)+1;
	m:=random(10000)+1;
	//n:=5;m:=5;
	writeln(n,' ',m);
	for i:=1 to m do begin
		writeln(random(n)+1,' ',random(n)+1);
	end;
end.
program bird;
var n,m,i,j,k,na,nb:longint;
begin
	randomize;
	n:=random(15)+6;
	m:=random(5)+6;
	k:=random(n);
	writeln(n,' ',m,' ',k);

	for i:=1 to n do writeln(random(m)+1,' ',random(m)+1);
	for i:=1 to k do writeln(random(n-2)+1,' ',random(m),' ',random(m));
end.
program link;
var n,m,i,j:longint;
begin
	randomize;
	n:=200000;
	writeln(n);
	for i:=1 to n-1 do writeln(random(n-1)+1,' ',random(n-1)+1);
	for i:=1 to n do write(random(5000)+5000,' ');
	writeln;
end.
program rps;
var n,m,i,j,na,nb:longint;
begin
	randomize;
	n:=200;
	na:=random(200)+1;
	nb:=random(200)+1;
	writeln(n,' ',na,' ',nb);
	for i:=1 to na do write(random(5),' ');
	writeln;
	for i:=1 to nb do write(random(5),' ');
	writeln;
end.
