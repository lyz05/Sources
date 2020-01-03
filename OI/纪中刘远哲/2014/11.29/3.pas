const	maxn=8000;maxm=100000;maxc=100;
	printf:array[1..5] of string=(	'No such cable.',
					'Already owned.',
					'Forbidden: monopoly.',
					'Forbidden: redundant.',
					'Sold.');
type	node=record
		y,k,next:longint;
	end;
var	i,k,m,n,tot,x,y,c,t:longint;
	e:array[1..maxn] of longint;
	h:array[1..2*maxm] of node;
	jd:array[1..maxc,1..maxn] of longint;
procedure print(x:longint);
begin
	writeln(printf[x]);
end;
function getfather(k,x:longint):longint;
begin
	if x=jd[k,x] then exit(jd[k,x]);
	getfather:=getfather(k,jd[k,x]);
	jd[k,x]:=getfather;
end;
procedure lj(k,x,y:longint);
begin
	jd[k,getfather(k,y)]:=jd[k,getfather(k,x)];
end;
procedure swap(var x,y:longint);
var	t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure add(x,y,k:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].k:=k;
	h[tot].next:=e[x];
	e[x]:=tot;
	lj(k,x,y);
end;
function pd(x:longint;i:node;k:longint):boolean;
begin
	if getfather(k,x)=getfather(k,i.y) then exit(true);
	lj(k,x,i.y);
	exit(false);
end;
procedure judge(x,y,k:longint);
var	i,j,totk,t:longint;
begin
	totk:=0;t:=0;
	i:=e[x];
	while i<>0 do begin
		j:=h[i].y;
		if j=y then begin
			if h[i].k=k then begin
				print(2);
				exit;
			end;
			t:=i;
		end;
		if h[i].k=k then inc(totk);
		i:=h[i].next;
	end;
	if totk>=2 then print(3) else
	if t=0 then print(1) else
	if pd(x,h[t],k) then print(4) else begin
		h[t].k:=k;
		print(5);
	end;
end;
procedure prepar;
var	i,j:longint;
begin
	for i:=1 to c do
		for j:=1 to n do jd[i,j]:=j;
end;
begin
	readln(n,m,c,t);
	prepar;
	for i:=1 to m do begin
		readln(x,y,k);
		if x>y then swap(x,y);
		add(x,y,k);
	end;
	for i:=1 to t do begin
		readln(x,y,k);
		if x>y then swap(x,y);
		judge(x,y,k);
	end;
end.
