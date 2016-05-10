uses	math;
const	maxn=10000+2;oo=2105376125;
var	a,h:array[0..10*maxn] of longint;
	i,n,k,kk:longint;
	ans:int64;
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
function del(x,val:longint):longint;
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
procedure work(x:longint);
var	i,tot,z:longint;
begin
	tot:=0;
	for i:=1 to x do begin
		inc(tot,h[1]);
		z:=del(1,h[1]);
	end;
	h[z]:=tot;
	inc(ans,h[z]);
	insert(z div 2);
end;
begin
	assign(input,'1775.in');reset(input);

	readln(n,k);
	fillchar(h,sizeof(h),125);
	h[0]:=-oo;
	for i:=1 to n do read(a[i]);
	build(1,1,n);
	kk:=(n-1) mod (k-1)+1;
	if kk<>1 then work(kk);
	for i:=1 to (n-1) div (k-1) do begin
		work(k);
	end;
	{ans:=0;
	for i:=1 to n-1 do begin
		x:=h[1];del(1,x);
		y:=h[1];z:=del(1,y);
		h[z]:=x+y;
		inc(ans,h[z]);
		insert(z div 2);
	end;}
	writeln(ans);
end.
