const	maxn=100007;
	pri:array[1..2] of longint=(99991,67901);
var	i,m,n,root1,root2:longint;
	a:Array[1..2,1..maxn,1..2] of longint;
	u:array[1..2,0..maxn] of int64;
	s1:array[1..maxn] of int64;
	ha:array[1..2,1..2,-1..maxn] of int64;
	p:array[1..2,1..maxn] of boolean;
	h:array[0..maxn,0..2] of int64;
	ans:int64;
procedure init(x,len:longint);
var	i:longint;
begin
	for i:=1 to len do begin
		readln(a[x,i,1],a[x,i,2]);
		p[x,a[x,i,1]]:=true;
		p[x,a[x,i,2]]:=true;
	end;
end;
function getroot(x,len:longint):longint;
var	i:longint;
begin
	for i:=1 to len do
		if not p[x,i] then exit(i);
end;
procedure getha(x,root:longint);
var	flag:longint;
begin
	if a[x,root,1]>0 then getha(x,a[x,root,1]);
	if a[x,root,2]>0 then getha(x,a[x,root,2]);
	s1[root]:=s1[a[x,root,1]]+s1[a[x,root,2]]+1;
	flag:=s1[root];
	ha[x,1,root]:=
	(ha[x,1,a[x,root,1]]*u[1][s1[a[x,root,2]]+1]) mod maxn+
	flag*u[1][s1[a[x,root,2]]] mod maxn+
	(ha[x,1,a[x,root,2]]) mod maxn;
	ha[x,2,root]:=
	(ha[x,2,a[x,root,1]]*u[2][s1[a[x,root,2]]+1]) mod maxn+
	flag*u[2][s1[a[x,root,2]]] mod maxn+
	(ha[x,2,a[x,root,2]]) mod maxn;
end;
function hash(a,b:longint):longint;
var	x:longint;
begin
        x:=((a*10007 mod maxn)+b)mod maxn;
        while (h[x,0]>0)and
        ((h[x,1]<>a)or(h[x,2]<>b))do x:=(x+1)mod maxn;
        exit(x);
end;

procedure prepar(x:longint;len:longint);
var	i:longint;
begin
	u[x,0]:=1;
	for i:=1 to len do u[x,i]:=u[x,i-1]*pri[x] mod maxn;
end;
procedure calc;
var	hh:longint;
begin
	for i:=1 to n do
        begin
                hh:=hash(ha[1,1,i],ha[1,2,i]);
                inc(h[hh,0]);
                h[hh,1]:=ha[1,1,i];
                h[hh,2]:=ha[1,2,i];
        end;
        for i:=1 to m do
        begin
                hh:=hash(ha[2,1,i],ha[2,2,i]);
                ans:=ans+h[hh,0];
        end;
end;
begin
	//assign(input,'3957.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	fillchar(p,sizeof(p),0);
	init(1,n);
	init(2,m);
	root1:=getroot(1,n);
	root2:=getroot(2,m);
	fillchar(s1,sizeof(s1),0);
	prepar(1,n);
	prepar(2,m);
	getha(1,root1);
	getha(2,root2);
	calc;
	writeln(ans);
end.
