uses	math;
const	list:array[1..3] of char=('T','L','R');
	maxn=30;
var	i,j,k,m,n:longint;
	ans:longint;
	s1,s2:string;
	mi:array[0..maxn] of longint;
function get(x,y:char):char;
var	i:longint;
begin
	for i:=1 to 3 do begin
		if (list[i]<>x) and (list[i]<>y) then exit(list[i]);
	end;
end;
function change(x,y:char;len:longint):string;
var	i:longint;
begin
	change:=x;
	for i:=1 to len-1 do change:=change+y;
end;
function getans(x,y:string):longint;
var	len:longint;
	tmp1,tmp2:longint;
	z:char;
begin	
	if x=y then exit(0);
	while (x[1]=y[1]) do begin
		delete(x,1,1);delete(y,1,1);
	end;
	len:=length(x);
	if (len=1) then exit(1);


	z:=get(x[1],y[1]);
	tmp1:=getans(x,change(x[1],y[1],len))+1+
		getans(change(y[1],x[1],len),y);
	tmp2:=getans(x,change(x[1],z,len))+1+
		mi[len-1]+
		getans(change(y[1],z,len),y);
	getans:=min(tmp1,tmp2);
	//getans(change(z,x[1],len),change(z,y[1],len))
end;
begin
	assign(input,'tri.in');reset(input);
	assign(output,'tri.out');rewrite(output);

	mi[0]:=1;
	for i:=1 to maxn do mi[i]:=mi[i-1]*2;

	readln(n);
	readln(s1);
	readln(s2);
	ans:=getans(s1,s2);
	writeln(ans);
	
	close(input);close(output);
end.
