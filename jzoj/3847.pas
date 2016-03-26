uses math;
const mo=10086;
type sz=array[0..70,1..70] of longint;
var	i,j,k,m,n,t,u,v,ans:longint;
	h:array[1..70] of longint;
        map,f,tmp:sz;
procedure mult(a,b:sz;var c:sz);
var	i,j,k:longint;
begin
	fillchar(c,sizeof(c),0);
	for i:=1 to n do
		for j:=1 to n do
			for k:=1 to n do
				c[i,j]:=(c[i,j]+a[i,k]*b[k,j]) mod mo;
end;
begin
	read(n,m,t);
	for i:=1 to n do begin
	    map[i,i]:=1;
	    read(h[i]);
	end;
	for i:=1 to m do begin
		read(u,v);
		inc(map[u,v]);
	end;

	f[0,1]:=1;
	for i:=1 to min(t,70) do
		for j:=1 to n do
			for k:=1 to n do
				if (map[k,j]>0) and (i>=h[j]) then
					f[i,j]:=(f[i,j]+f[i-1,k]*map[k,j]) mod mo;
	if t<=70 then writeln(f[t,n]) else begin
		t:=t-71;
                tmp:=map;
		while t>0 do begin
			if t mod 2=1 then mult(tmp,map,tmp);
			mult(map,map,map);
			t:=t div 2;
		end;
		for j:=1 to n do
			ans:=(ans+f[70,j]*tmp[j,n]) mod mo;
		writeln(ans);
	end;
end.
