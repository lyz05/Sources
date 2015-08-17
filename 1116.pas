const	maxn=50000+5;
var	i,n,l,st,en:longint;
	c,s,f,q:array[0..maxn] of int64;
function com(x,y:longint):double;
begin
	exit( (f[x]-f[y]+(s[x]+s[y]+2*l+2)*(s[x]-s[y])) / (2*(s[x]-s[y])) );
end;
begin
	assign(input,'1116.in');reset(input);
	
	readln(n,l);
	s[0]:=-1;
	for i:=1 to n do begin
		readln(c[i]);
		s[i]:=s[i-1]+c[i]+1;
	end;
	f[0]:=0;
	st:=1;en:=1;
	q[1]:=0;
	for i:=1 to n do begin
		while (st<en) and (com(q[st],q[st+1]) <= s[i]) do inc(st);
		f[i]:=f[q[st]]+sqr(s[i]-s[q[st]]-l-1);
		while (st<en) and (com(q[en-1],q[en]) >= com(q[en],i)) do dec(en);
		inc(en);
		q[en]:=i;
	end;
	writeln(f[n]);
end.
