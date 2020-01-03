var	i,j,m,n,t,aa,bb,cc,dd:longint;
	a:array[1..1000,1..3] of longint;
	b:array[1..1000,0..1000] of longint;
	c:array[1..1000] of integer;
	ok:boolean;
procedure swap(var x,y:longint);
var t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
function pd(a,b,c,d:longint):boolean;
begin
	if (a<b) and (b<c) and (c<d) then exit(true) else exit(false);
end;
procedure dfs(x:longint);
var i:longint;
begin
	for i:=1 to b[x,0] do begin
		if c[b[x,i]]=-1 then begin
			c[b[x,i]]:=c[x] xor 1;
			dfs(b[x,i]);
		end;
	end;
end;
begin
	readln(t);
	for t:=1 to t do begin
		fillchar(b,sizeof(b),0);
		fillchar(a,sizeof(a),0);
		readln(n,m);
		for j:=1 to m do begin
			readln(a[j,1],a[j,2]);
			if a[j,1]>a[j,2] then swap(a[j,1],a[j,2]);
		end;
		for i:=1 to m do
			for j:=1 to m do begin
				aa:=a[i,1];bb:=a[i,2];cc:=a[j,1];dd:=a[j,2];
                                if pd(aa,cc,bb,dd) or pd(cc,aa,dd,bb) then begin
					inc(b[i,0]);
					b[i,b[i,0]]:=j;
				end;
			end;
		for i:=1 to m do c[i]:=-1;
		for i:=1 to m do begin
			if c[i]=-1 then begin
				c[i]:=0;
				dfs(i);
			end;
		end;
		ok:=true;
		for i:=1 to m do begin
			for j:=1 to b[i,0] do begin
				if c[i] xor c[b[i,j]]=0 then begin
					ok:=false;
				end;
			end;
                end;
		if ok then writeln('sane') else writeln('non');
	end;
end.
