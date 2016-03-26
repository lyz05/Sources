uses	math;
const	maxn=100000;maxm=100000;
var	a,b,c,d,ans:array[1..maxn] of int64;
	n,m,i:longint;
function ksm(x,y,id:int64):int64;
begin
	ksm:=1;
	while y<>0 do begin
		if odd(y) then ksm:=(ksm*x) mod d[id];
		x:=(x*x) mod d[id];
		y:=y>>1;
	end;
end;
function get(id,x:longint):int64;
begin
	get:=((a[id] mod d[id]*ksm(b[id],x,id))mod d[id]+c[id])mod d[id];
end;
function get1(id,x:longint):int64;
begin
	get1:=(a[id] mod d[id]*ksm(b[id],x,id))mod d[id];
end;
procedure solve(l,r,x,y:longint);
var	mid,i,kk:longint;
	minn,tmp,t:int64;
begin
	if l>r then exit;
	mid:=(l+r)>>1;
	minn:=1<<62;
	tmp:=get(mid,x);
	if minn>tmp then begin
		minn:=tmp;
		kk:=x;
	end;
	t:=get1(mid,x);
	for i:=x+1 to y do begin
		t:=(t*b[mid]) mod d[mid];
		tmp:=(t+c[mid]) mod d[mid];
		if minn>tmp then begin
			minn:=tmp;
			kk:=i;
		end;
	end;
	ans[mid]:=kk;
	solve(l,mid-1,x,kk);
	solve(mid+1,r,kk,y);
end;
begin
	assign(input,'1333.in');reset(input);
	//assign(output,'1.out');rewrite(output);

	readln(n,m);
	for i:=1 to n do readln(a[i],b[i],c[i],d[i]);
	solve(1,n,1,m);
	for i:=1 to n do writeln(ans[i]);
end.
