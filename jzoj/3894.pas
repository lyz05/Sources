const maxn=100000;
type node=record
		l,r,x:longint;
	end;
var	i,j,m,n,x,y,tot,ans:longint;
	b,c:array[0..maxn+10] of longint;
	h:array[1..maxn+10] of node;
	p:array[1..maxn] of boolean;
procedure add(fa,ch,k:longint);
begin
	if ch=0 then begin
                h[fa].l:=k;
        end else begin
                h[fa].r:=k;
        end;
end;
procedure zxbl(x:longint);
var i:longint;
begin
	if h[x].l<>0 then zxbl(h[x].l);
	inc(b[0]);
	b[b[0]]:=h[x].x;
	if h[x].r<>0 then zxbl(h[x].r);
end;
function lis:longint;
var i,l,r,mid:longint;
begin
	c[1]:=b[1]-1;
	c[0]:=1;
	for i:=2 to n do begin
		b[i]:=b[i]-i;
		if c[c[0]]<=b[i] then begin
			inc(c[0]);
			c[c[0]]:=b[i];
		end else begin
			l:=1;r:=c[0];
			while l<=r do begin
				mid:=(l+r) div 2;
				if c[mid]>=b[i] then r:=mid-1;
				if c[mid]<=b[i] then l:=mid+1;
				if c[mid]=b[i] then break;
			end;
			mid:=(l+r) div 2+1;
			c[mid]:=b[i];
		end;
	end;
	exit(c[0]);
end;
begin
assign(input,'3894.in');reset(input);
	readln(n);
	for i:=1 to n do read(h[i].x);
	tot:=1;
	for i:=1 to n-1 do begin
		readln(x,y);
		add(x,y,i+1);
	end;
	zxbl(1);
	writeln(n-lis);
end.
