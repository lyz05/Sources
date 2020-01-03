var	i,j,k,n,step:longint;
	m:string;
function val(x:char):longint;
begin
	case x of 
		'0'..'9':val:=ord(x)-ord('0');
		'A'..'F':val:=ord(x)-ord('A')+10;
	end;
end;
function str(x:longint):char;
begin
	case x of 
		0..9:str:=chr(ord('0')+x);
		10..15:str:=chr(ord('A')+x-10);
	end;
end;
procedure add(var x,y,z:string);
var	i,len:longint;
	a,b,c,k:longint;
begin
	a:=0;b:=0;c:=0;k:=0;
	while length(x)<length(y) do x:=x+'0';
	while length(x)>length(y) do y:=y+'0';
	len:=length(x);
	for i:=1 to len do begin
		a:=val(x[i]);b:=val(y[i]);
		c:=a+b+k;
		k:=c div n;
		c:=c mod n;
		z:=z+str(c);	
	end;
	if k<>0 then z:=z+str(k);
end;
function work(var x:string):boolean;
var	y,z:string;
	len,i:longint;
	flag:boolean;
begin
	len:=length(x);
	y:='';z:='';
	for i:=len downto 1 do y:=y+x[i];
	add(y,x,z);
	len:=length(z);flag:=true;
	for i:=1 to len div 2 do 
		if z[i]<>z[len-i+1] then flag:=false;
	x:=z;
	exit(flag);
end;
begin
	step:=1;
	readln(n);
	readln(m);
	while (not work(m)) and (step<=30) do inc(step);
	if step=31 then writeln('Impossible!') else writeln('STEP=',step);
end.
