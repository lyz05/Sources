uses	math;
const	maxn=200000+2;oo=2105376125;
var	a,h:array[0..10*maxn] of extended;
	i,n,z:longint;
	ans,m,x,y:extended;

procedure build(x,l,r:longint);
var	mid:longint;
begin
	if (l=r) then begin
		h[x]:=a[l];
		exit;
	end;
	mid:=(l+r)>>1;
	build(x+x,l,mid);
	build(x+x+1,mid+1,r);
	h[x]:=min(h[x+x],h[x+x+1]);
end;
function del(x:longint;val:extended):longint;
begin
	if (h[x+x]<>val) and (h[x+x+1]<>val) then begin
		h[x]:=oo;
		exit(x);
	end;
	if h[x+x]=val then del:=del(x+x,val) else del:=del(x+x+1,val);
	h[x]:=min(h[x+x],h[x+x+1]);
end;
procedure insert(x:longint);
begin
	if x=0 then exit;
	h[x]:=min(h[x+x],h[x+x+1]);
	insert(x div 2);
end;
begin
	assign(input,'1776.in');reset(input);


	readln(n,m);
	for i:=1 to 10*n do h[i]:=oo;
	h[0]:=-oo;
	m:=1/m;
	for i:=1 to n do begin
		read(a[i]);
		a[i]:=a[i]*m;
	end;
	build(1,1,n);
	ans:=0;
	for i:=1 to n-1 do begin
		x:=h[1];del(1,x);
		y:=h[1];z:=del(1,y);
		h[z]:=x+y;
		ans:=ans+h[z];
		insert(z div 2);
	end;
	writeln(ans:0:6);
end.

