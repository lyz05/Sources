uses	math;
const	maxn=110;
type	node=array[0..70] of integer;
var	i,j,k,m,n:longint;
	c:array[0..maxn] of node;
procedure add(var x:node;y:node);
var	i,len,jw:integer;
begin
	jw:=0;
	len:=max(x[0],y[0]);
	for i:=1 to len+1 do begin
		x[i]:=x[i]+y[i]+jw;
		jw:=x[i] div 10;
		x[i]:=x[i] mod 10;
	end;
	if x[len+1]<>0 then x[0]:=len+1 else x[0]:=len;
end;
begin
	readln(n);
	c[0,0]:=1;c[0,1]:=1;
	c[1,0]:=1;c[1,1]:=3;
	for i:=2 to n do begin
		add(c[i],c[i-2]);
		add(c[i],c[i-1]);
		add(c[i],c[i-1]);
	end;	
	for i:=c[n][0] downto 1 do write(c[n][i]);
	writeln;
end.
