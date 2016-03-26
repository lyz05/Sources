program p1123;
const	mx=1000000000;
var	n,i,j,m,t:longint;
begin
	randomize;
	n:=5;
	m:=n*(random(10)+1);
	writeln(n);
	for i:=1 to n do begin
		if i=n then j:=m else j:=random(m-(n-i))+1;
		dec(m,j);
		write(j,' ');
	end;
	writeln;
end.

program p??;
const	mx=1000000000;
var	n,i,j,m,t:longint;
begin
end.

program p??;
const	mx=1000000000;
var	n,i,j,m,t:longint;
begin
	randomize;
	t:=5;
	writeln(t);
	for i:=1 to t do begin
		n:=random(1000)+100000-1000;
		m:=random(1000)+100000-1000;
		writeln(n,' ',m);
		for j:=1 to n do 
			writeln(random(1000)+mx,' ',random(1000)+mx,' ',
			random(1000)+mx);
	end;
end.
