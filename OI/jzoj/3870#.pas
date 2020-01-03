const maxn=2005;
	 maxm=1000005;
	 minmod=999973;
	 maxmod=49499999999999993;	//error
type
	node=record
		no,cnt:longint;
		s:int64;
		next:longint;
	end;
var	n,m,l,tot,ans:longint;
	first:array[0..maxm] of longint;
	str:array[0..maxn] of string;
	h:array[1..maxm] of node;
procedure add(u,x:longint;s:int64);
begin
	inc(tot);
	h[tot].s:=s;
	h[tot].cnt:=1;
	h[tot].no:=x;
	h[tot].next:=first[u];
	first[u]:=tot;
end;
procedure hash(x,u:longint;s:int64);
var i:longint;
begin
	i:=first[u];
	while (i<>0) do begin
		if s=h[i].s then begin
			if (h[i].no=x) then exit;
			h[i].no:=x;
			inc(h[i].cnt);
			exit;
		end;
		i:=h[i].next;
	end;
	add(u,x,s);
end;
procedure init;
var i:longint;
begin
	readln(n,m,l);
	for i:=1 to n do readln(str[i]);
	ans:=0;
end;
procedure work;
var	i,j,u,k,k1:longint;
	s,k2:int64;
begin
	k1:=1;
	k2:=1;
	for j:=0 to l-2 do begin
		k1:=(k1*26) mod minmod;
		k2:=(k2*26) mod maxmod;
	end;
	for i:=1 to N do begin
		u:=0;
		s:=0;
		for j:=0 to L-1 do begin
			u:=(u*26+ord(str[i][j])) mod MinMod;
			s:=(s*26+ord(str[i][j])) mod MaxMod;
		end;
	end;
	hash(i,u,s);
	k:=length(str[i]);
	for j:=l to k-1 do begin
		u:=((u-ord(str[i][j-L])*k1) mod MinMod+MinMod) mod MinMod;
		s:=((s-ord(str[i][j-L])*k2) mod MaxMod+MaxMod) mod MaxMod;
		u:=(u*26+ord(str[i][j])) mod MinMod;
		s:=(s*26+ord(str[i][j])) mod MaxMod;
		hash(i,u,s);
	end;
end;
procedure output;
var i:longint;
begin
	for i:=1 to tot do
		if h[i].cnt>=m then inc(ans);
	writeln(ans);
end;
begin
	init;
	work;
	output;
end.
